#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 12245

void main()
{

	int sockfd,newsockfd,portno,clilen,n=1;
	char * servertime;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	time_t t;
	time(&t);
	listen(sockfd,1);
	clilen = sizeof(clilen);
	while(1)
	{
	newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
	int flag=fork();
	if(flag==0)
	{
	int pid=getpid();
	char ch[256];
  recv(sockfd,ch,256,0);
  printf("%s",ch);
}
}
close(sockfd);
}
