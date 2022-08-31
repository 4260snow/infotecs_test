#include "check.h"
#define PORT 80

void Result::recvNum()
{
	int sockfd, newsockfd, servlen, n;
	socklen_t clilen;
	struct sockaddr_un  cli_addr, serv_addr;
	int* buf;

	if ((sockfd = socket(AF_UNIX,SOCK_STREAM,0)) < 0)
	{
		perror("creating socket");
		exit(0);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sun_family = AF_UNIX;
	strcpy(serv_addr.sun_path, (std::to_string(PORT)).c_str());
	servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);
	if(bind(sockfd,(struct sockaddr *)&serv_addr,servlen)<0)
	{
		perror("binding socket");
		exit(0);
	}

	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	if (newsockfd < 0)
	{
		perror("accepting");
		exit(0);
	}
	n = read(newsockfd, buf, sizeof(buf));
	res = *buf;
	std::cout << res << '\n';
	

	close(newsockfd);
	close(sockfd);
}

bool Result::isCorrect()
{
	if (res > 99 && res % 32 == 0)
		return true;
	return false;
}
