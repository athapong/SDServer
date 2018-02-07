#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */

void error(const char *msg) { perror(msg); exit(0); }

int main(int argc,char *argv[])
{
    /* first what are we going to send and where are we going to send it? */
    int portno =        9801;
    char *host =        "10.200.115.196";
    //char *message_fmt = "POST /apikey=%s&command=%s HTTP/1.0\r\n\r\n";
	char message_fmt[1024]="POST /CoreGL/SD_Acct_Sum HTTP/1.0\r\n\r\n";
					strcat(message_fmt,"<ns:TMB_WS_PKG_MSG_Input  xmlns:ns=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/tmb_sd_acct_sum/\"");
		   strcat(message_fmt,"<xmlns:ns1=\"http://xmlns.oracle.com/apps/gl/rest/TMB_WS_PKG/header\">");
			strcat(message_fmt,"<ns1:RESTHeader/>");
strcat(message_fmt,"<ns:InputParameters>");
strcat(message_fmt,"<ns:IN_DATA>");
strcat(message_fmt,"<TMBInput>");
strcat(message_fmt,"<Header>");
strcat(message_fmt,"<TELLER_ID>1/TELLER_ID>");
strcat(message_fmt,"<AUTHORIZE_ID>1/AUTHORIZE_ID>");
strcat(message_fmt,"<WORKSTATION_ID>1</WORKSTATION_ID>");
strcat(message_fmt,"<DATE>11052016</DATE>");
strcat(message_fmt,"</Header>");
strcat(message_fmt,"<Details>");
strcat(message_fmt,"<TRANSACTION_CODE>7130</TRANSACTION_CODE>");
strcat(message_fmt,"<HOBR_BALANCING>H001</HOBR_BALANCING>");
strcat(message_fmt,"<OFFICE_CODE>0000</OFFICE_CODE>");
strcat(message_fmt,"<ACCOUNT_SUMMARY_TYPE>0</ACCOUNT_SUMMARY_TYPE>");
strcat(message_fmt,"</Details>");
strcat(message_fmt,"</TMBInput>");
strcat(message_fmt,"</ns:IN_DATA>");
strcat(message_fmt,"</ns:InputParameters>");
strcat(message_fmt,"</ns:TMB_WS_PKG_MSG_Input>");

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char message[1024],response[4096];

    //if (argc < 3) { puts("Parameters: <apikey> <command>"); exit(0); }

    /* fill in the parameters */
    sprintf(message,message_fmt,argv[1],argv[2]);
    printf("Request:\n%s\n",message);

    /* create the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    /* lookup the ip address */
    server = gethostbyname(host);
    if (server == NULL) error("ERROR, no such host");

    /* fill in the structure */
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    /* connect the socket */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    /* send the request */
    total = strlen(message);
    sent = 0;
    do {
        bytes = write(sockfd,message+sent,total-sent);
        if (bytes < 0)
            error("ERROR writing message to socket");
        if (bytes == 0){
		  error("EMPTY RESPONSE");
            break;
	 }
        sent+=bytes;
    } while (sent < total);

    /* receive the response */
    memset(response,0,sizeof(response));
    total = sizeof(response)-1;
    received = 0;
    do {
        bytes = read(sockfd,response+received,total-received);
        if (bytes < 0)
            error("ERROR reading response from socket");
        if (bytes == 0){
           error("ERROR empty response from socket"); 
	    break;
	 }
        received+=bytes;
    } while (received < total);

    if (received == total)
        error("ERROR storing complete response from socket");

    /* close the socket */
    close(sockfd);

    /* process response */
    printf("Response:\n%s\n",response);

    return 0;
}
