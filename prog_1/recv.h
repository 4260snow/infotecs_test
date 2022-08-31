#ifndef RECV_H
#define RECV_H

#include <iostream>
#include <string>
#include <mutex>


class ReceiveData
{
	public:
		ReceiveData() = default;		
		void recvData(std::string&, std::mutex&);
	private:
		std::string data;
		
		bool isCorrect();
		void convert();
};

#endif
