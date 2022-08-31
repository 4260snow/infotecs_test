#ifndef PROC_H
#define PROC_H

#include <iostream>
#include <string>
#include <mutex>

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>


class ProcessData
{
	public:
		ProcessData() = default;
		void procData(std::string&, std::mutex&);
	private:
		std::string data;
		
		int sum();
		void send(int);
};

#endif
