#include "recv.h"


void ReceiveData::recvData(std::string& buff, std::mutex& mtx)
{
	std::cin >> data;
	
	mtx.lock();
	if (this->isCorrect())
	{
		this->convert();
		buff = data;
	}

	mtx.unlock();
}

bool ReceiveData::isCorrect()
{
	if (data.length() == 0 || data.length() > 64)
		return false;
	
    for (auto i: data)
    {
        switch (i)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                continue;
            default:
                return false;
        }
    }
    return true;
}

void ReceiveData::convert()
{
	int arr[10] = {0};
	
	int pos, count;
	for (auto i: data)
    {
    	pos = int(i) - 48;
    	arr[pos] += 1;
    	count += ((pos + 1) % 2);
    }
    
	char* s = new char[data.length() + count + 1];
	int i = 0;
    for (int j = 9; j >= 0; j--) 
    {
    	if (j % 2)
    	{
    		while (arr[j]-- > 0)
    		{
    			s[i] = j + 48;
    			i++;
    		}
    	}
    	else
    	{
    		while (arr[j]-- > 0)
    		{
    			s[i] = 'K'; s[i + 1] = 'B';
    			i += 2;
    		}
    	}
    }
    s[i] = '\0';
    
    data = s;
    
    delete [] s;
}

