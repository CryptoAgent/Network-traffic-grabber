#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int LISS_LENGHT = 131072;

int main(){

	int sock_fd=socket(AF_INET , SOCK_RAW , IPPROTO_TCP);
	if(sock_fd<0){
		printf("Can't create socket\r\n");
		return 1;
	}
	struct sockaddr empty_addr;
	int sizz = sizeof(empty_addr);
	if(sock_fd<0){
		printf("Can't create socket!\r\n");
	}
	unsigned char buffer[LISS_LENGHT];
	memset(buffer,0,LISS_LENGHT);
	int status = 0;
	int old = 0;
	while(1){
		int recieved = recvfrom(sock_fd,buffer,LISS_LENGHT,0,&empty_addr,&sizz);
		if(recieved>=LISS_LENGHT){
			break;
		}
	}
	FILE * logs;
	logs=fopen("logs.txt","w");
	fwrite(buffer,1,LISS_LENGHT,logs);
	fclose(logs);



	return 0;
}