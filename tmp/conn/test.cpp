#include <iostream>
#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <arpa/inet.h>

#include <cstring>
#include <unistd.h>	

using namespace std;
#define INVALID_SOCKET -1

#define SOCKET_ERROR -1

typedef unsigned int SOCKET; 
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr *LPSOCKADDR;
typedef struct SESS_DATA{ 
	char *szPreferredServer; 
	int szPreferredPort; 
	char *pPreferredURI; 
	SOCKET Sock; 
} SESS_DATA;

void initSessData(SESS_DATA *s){ 
	s->szPreferredPort = 9801; 
	s->szPreferredServer = "10.200.115.196"; 
	s->pPreferredURI = "/CoreGL/SD_ALL_IO";	
}

void SocketConnect(SESS_DATA *sess){ 
	long ret = SOCKET_ERROR; // assume failure. 
	SOCKADDR_IN local_sin; SOCKADDR_IN remote_sin;
	if( (sess->Sock = socket(AF_INET, SOCK_STREAM,0) ) != INVALID_SOCKET){
	    cout << "Successful local port connection" << endl;
	    local_sin.sin_family = AF_INET;
	    local_sin.sin_port = htons(0);
	    local_sin.sin_addr.s_addr = htonl(INADDR_ANY);

	    if( bind( sess->Sock, (struct sockaddr*) &local_sin, sizeof(local_sin) )== SOCKET_ERROR){
		   close(sess->Sock); // close local socket if bind fails
		   cout << "Bind failed. closing connection ..." << endl;
	    }
	    else{
		   remote_sin.sin_family = AF_INET;
		   remote_sin.sin_port = htons(sess->szPreferredPort);
		   remote_sin.sin_addr.s_addr = inet_addr(sess->szPreferredServer);

		   ret = connect(sess->Sock, (LPSOCKADDR) &remote_sin, sizeof(remote_sin));

		   if(ret != SOCKET_ERROR){
			  cout << "Successful connection to ETE. ";
			  cout << "Closing successful connection to ETE ..." << endl;
			  close(sess->Sock);
			  return;
		   }

	    }
	 }
	if(ret == -1){
        cout << "Remote connection failed.";
	}
    close(sess->Sock); // close local socket
}

int main() { 
	cout << "Initiate ETE Post Request Test ... " << endl; 
	SESS_DATA sess; initSessData(&sess);
	SocketConnect(&sess);

	return 0;
	
}
