#ifndef CHECK_H
#define CHECK_H

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>
#include <stdio.h>


class Result
{
	public:
		Result() = default;
		void recvNum();
		bool isCorrect();
	private:
		int res;
};

#endif
