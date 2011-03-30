#include <stdio.h>
#include <stdlib.h>

// network stuff 
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "../include/huch/mavlink.h"

int sock;
struct sockaddr_in server_addr;
struct hostent *host;
uint8_t txbuf[1024];

int main() {
	int txbytes;
	mavlink_message_t msg_i;
	mavlink_huch_attitude_t huch_attitude;

	// init network
	host = (struct hostent *) gethostbyname((char *)"127.0.0.1");

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5555);
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_addr.sin_zero),8);

	txbuf[0] = 'a';
	txbuf[1] = '\n';

	huch_attitude.xacc = 1234;
	huch_attitude.yacc = 5678;

	mavlink_msg_huch_attitude_encode(23, 42, &msg_i, &huch_attitude);
	uint16_t len = mavlink_msg_to_send_buffer(txbuf, &msg_i);

	printf("len: %d\n", len);

	while(1) {
		txbytes = sendto(sock, &msg_i, len, 0,
										 (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
		sleep(1);
	}
}
