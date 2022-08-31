#include "check.h"

#include <iostream>


int main()
{
	Result res;
	while (true)
	{
		res.recvNum();
		if (res.isCorrect())
		{
			std::cout << "OK\n";
		}
		else
		{
			std::cout << "ERROR\n";
		}
	}
	
	return 0;
}

