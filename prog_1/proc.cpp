#include "proc.h"
#define PORT 80


void ProcessData::procData(std::string &buff, std::mutex &mtx)
{
	if (!buff.empty())
	{
		mtx.lock();
		{
			data = buff;
			buff.clear();
		}
		mtx.unlock();
		
		std::cout << data << '\n';
		int amount = sum();
		send(amount);
	}
}

int ProcessData::sum()
{
	int k = 0;
	for (auto i: data)
    {
        if (i != 'K' && i != 'B')
        	k += i - 48;
    }
    
    return k;
}

void ProcessData::send(int k)
{
	int sockfd, servlen, n;
	struct sockaddr_un  serv_addr;
	int buf = k;
	
	bzero((char *)&serv_addr,sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, (std::to_string(PORT)).c_str());
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
	if ((sockfd = socket(AF_UNIX, SOCK_STREAM,0)) < 0)
	{
		perror("Creating socket");
		exit(0);
	}
	if (connect(sockfd, (struct sockaddr *) &serv_addr, servlen) < 0)
	{
		perror("Connecting");
		exit(0);
	}
	
	write(sockfd, &buf, sizeof(int));

	close(sockfd);	
}


