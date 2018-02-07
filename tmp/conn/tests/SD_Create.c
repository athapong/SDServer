#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <arpa/inet.h>

#define MAX_TRANSMISSION 65536
#define SOCKET_ERROR -1
void error(const char *msg) {
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]) {
	/* first what are we going to send and where are we going to send it? */
	char *portno = "9801";
	char *host = "10.200.115.196";
	char message_fmt[65536] ="POST /CoreGL/SD_Create HTTP/1.1\r\n";
	strcat(message_fmt,"POST http://10.200.115.196:9801/CoreGL/SD_Create HTTP/1.1\r\n");
	strcat(message_fmt,"Accept-Encoding: gzip,deflat\r\n");
	strcat(message_fmt,"Content-Type: application/xml\r\n");
	strcat(message_fmt,"Content-Length: 598\r\n");
	strcat(message_fmt,"Host: 10.200.115.196:9801\r\n");
	strcat(message_fmt,"Connection: Keep-Alive\r\n");
	strcat(message_fmt,"User-Agent: Apache-HttpClient/4.1.1 (java 1.5)\r\n\r\n");
	strcat(message_fmt, "<ns:TMB_WS_PKG_MSG_Input xmlns:ns=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/tmb_sd_create/\" xmlns:ns1=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/header\">");
	strcat(message_fmt, "<ns1:RESTHeader/>");
	strcat(message_fmt, "<ns:InputParameters>");
	strcat(message_fmt, "<ns:IN_DATA>");
	strcat(message_fmt, "<TMBInput>");
	strcat(message_fmt, "<Header>");
	strcat(message_fmt, "<TELLER_ID>1</TELLER_ID>");
	strcat(message_fmt, "<AUTHORIZE_ID>1</AUTHORIZE_ID>");
	strcat(message_fmt, "<WORKSTATION_ID>1</WORKSTATION_ID>");
	strcat(message_fmt, "<DATE>11052016</DATE>");
	strcat(message_fmt, "</Header>");
	strcat(message_fmt, "<Details>");
	strcat(message_fmt, "<TRANSACTION_CODE>7130</TRANSACTION_CODE>");
	strcat(message_fmt, "<HOBR_BALANCING>H001</HOBR_BALANCING>");
	strcat(message_fmt, "<OFFICE_CODE>0000</OFFICE_CODE>");
	strcat(message_fmt, "<ACCOUNT_SUMMARY_TYPE>0</ACCOUNT_SUMMARY_TYPE>");
	strcat(message_fmt, "</Details>");
	strcat(message_fmt, "</TMBInput>");
	strcat(message_fmt, "</ns:IN_DATA>");
	strcat(message_fmt, "</ns:InputParameters>");
	strcat(message_fmt, "</ns:TMB_WS_PKG_MSG_Input>");


	struct hostent *server;
	//struct sockaddr_in serv_addr;
	int sockfd, bytes, sent, received, total;
	char response[4096];
	long ret = -1;
	/* fill in the parameters */
	char *message = (char *)malloc(1024 * sizeof(char));
	sprintf(message, message_fmt);
	printf("Request:\n%s\n", message);

	struct sockaddr_in local_sin;      //Local socket address
	struct sockaddr_in remote_sin;     //Remote socket address

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) != 0) {
		local_sin.sin_family = AF_INET;
		local_sin.sin_port = htons(0);
		local_sin.sin_addr.s_addr = htonl(INADDR_ANY);

		if (bind(sockfd, (struct sockaddr*) &local_sin, sizeof(local_sin)) == SOCKET_ERROR) {
			close(sockfd);
		} else {
			remote_sin.sin_family = AF_INET;
			remote_sin.sin_port = htons(atoi(portno));
			remote_sin.sin_addr.s_addr = inet_addr(host);

			ret = connect(sockfd, (struct sockaddr *) &remote_sin, sizeof(remote_sin));

			if (ret != SOCKET_ERROR) {
				int nVal = MAX_TRANSMISSION;
				int nLen = sizeof(int);
				setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *) &nVal, nLen);
				ret = 0;
			}
		}
	}
	printf("message size:%d\n", strlen(message));
	send(sockfd, message, strlen(message), 0);
	printf("socket open : %d\n",sockfd);
	/* receive the response */
	memset(response, 0, sizeof(response));
	/*total = sizeof(response) - 1;
	received = 0;
	do {
		bytes = read(sockfd, response + received, total - received);
		printf("recieve=%d\n",bytes);
		if (bytes < 0)
			printf("ERROR reading response from socket");
		if (bytes == 0)
			break;
		received += bytes;
	} while (received < total);*/


	/* receive the response */
	long recv_ret = 1;
	char szRecvBuffer[65536];

	while (recv_ret > 0) {
		recv_ret = recv(sockfd, szRecvBuffer, sizeof(szRecvBuffer), 0);
		if (recv_ret != -1 && recv_ret != 0) {
			szRecvBuffer[recv_ret] = 0;
			sprintf(response, szRecvBuffer);
			szRecvBuffer[0] = 0;
		}
	}

	//if (received == total)
	//	printf("ERROR storing complete response from socket");

	/* close the socket */
	close(sockfd);

	/* process response */
	printf("Response:\n%s\n", response);
	return 0;
}
