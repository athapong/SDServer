#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <arpa/inet.h>
#include <iostream.h>

#define MAX_TRANSMISSION 65536
#define SOCKET_ERROR -1
void error(const char *msg) {
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]) {
	/* first what are we going to send and where are we going to send it? */
	char *portno = "9101";
	char *host = "10.200.115.196";
	char message_fmt[65536] = "POST /CoreGL/SD_Acct_Sum HTTP/1.1\r\n";
	//strcat(message_fmt, "POST http://10.200.115.196:9801/CoreGL/SD_Acct_Sum HTTP/1.1\r\n");
	strcat(message_fmt, "Accept-Encoding: gzip,deflat\r\n");
	strcat(message_fmt, "Content-Type: application/xml\r\n");
	strcat(message_fmt, "Content-Length: 598\r\n");
	strcat(message_fmt, "Host: 10.200.115.196:9100\r\n");
	strcat(message_fmt, "Connection: Keep-Alive\r\n");
	strcat(message_fmt, "User-Agent: Apache-HttpClient/4.1.1 (java 1.5)\r\n\r\n");
	strcat(message_fmt,
			"<ns:TMB_WS_PKG_MSG_Input xmlns:ns=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/tmb_sd_acct_sum/\" xmlns:ns1=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/header\">");
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
	char response[10240];
	long ret = -1;
	/* fill in the parameters */
	char *message = (char *) malloc(1024 * sizeof(char));
	sprintf(message, message_fmt);

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

				struct timeval tv;
				tv.tv_sec = 60;  /* 60 Secs Timeout */
				tv.tv_usec = 0;  // Not init'ing this can cause strange errors
				setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv,sizeof(struct timeval));
				setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char *) &nVal, nLen);
				ret = 0;
			}
		}
	}

	/* read file */
	char *filename = (char *) malloc(50 * sizeof(char));
	cout << "Please enter an integer based on what you would like to test." << endl;
	cout << "Quit = 0" << endl;
	cout << "(CA001-4260) 	All Inter-Office Outstanding = 1" << endl;
	cout << "(CA001-4250) 	Specific Inter-Office Outstanding = 2" << endl;
	cout << "(CA001-7120) 	All Outstanding = 3" << endl;
	cout << "(CA001-7110) 	Specific Outstanding = 4" << endl;
	cout << "(CA002-7130)	Account Summary  = 5" << endl;
	cout << "(CA003)		Create a journal entry = 6" << endl;
	cout << ">>> ";
	int TestIn = 1;
	cin >> TestIn;
	switch (TestIn) {
	case 0:
		return 0;
		break;

	case 1:
		filename = "CA001_4260.txt";
		break;

	case 2:
		filename = "CA001_4250.txt";
		break;

	case 3:
		filename = "CA001_7120.txt";
		break;

	case 4:
		filename = "CA001_7110.txt";
		break;

	case 5:
		filename = "CA002_7130.txt";
		break;
	case 6:
		filename= "CA003.txt";
		break;
	default:
		cout << "Invalid argument." << endl;
		break;
	}

	if (filename != NULL) {
		FILE *fp;
		char buff[1024];
		fp = fopen(filename, "r");
		char c;
		int i = 0;
		char str[9000];
		if (fp == NULL) {
			perror("Error in opening file");
			return (-1);
		}
		do {
			c = fgetc(fp);
			if (feof(fp)) {
				str[i++] = '\0';
				break;
			} else {
				str[i++] = c;
			}
		} while (1);
		strncpy(message, str, sizeof(str));
	}
	printf("Request:\n%s\n", message);
	printf("String len:%d\n", strlen(message));
	/* end read file */

	send(sockfd, message, strlen(message), 0);
	printf("Request has been sent!!!\n");
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
		cout << "Reading socket " << recv_ret << endl;
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
