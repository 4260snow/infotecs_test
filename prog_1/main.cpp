#include "recv.h"
#include "proc.h"

#include <string>
#include <thread>
#include <mutex>


int main()
{
	std::mutex mtx;
	
	std::string buff;

	ReceiveData input;
	std::thread t1([&input, &buff, &mtx]()
	{
		while (true)
		{
			input.recvData(buff, mtx);
		}
	});
	
	ProcessData proc;
	std::thread t2([&proc, &buff, &mtx]()
	{
		while (true)
		{
			proc.procData(buff, mtx);
		}
	});
	
	t1.join();
	t2.join();
	
	return 0;
}
