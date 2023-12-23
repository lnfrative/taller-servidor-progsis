// defines in_addr structure 
#include <arpa/inet.h> 
#include "funciones.h"
// contains constants and structures 
// needed for internet domain addresses 
#include <netinet/in.h> 

// standard input and output library 
#include <stdio.h> 

// contains string functions 
#include <string.h> 

// for socket creation 
#include <sys/socket.h> 

// contains constructs that facilitate getting 
// information about files attributes. 
#include <sys/stat.h> 

// contains a number of basic derived types 
// that should be used whenever appropriate 
#include <sys/types.h> 

main() 
{ 
  struct sockaddr_in client; 
  int s, flag1,flag2; 
  char buffer1[20],buffer2[20];

  // socket create 
  s = socket(AF_INET, SOCK_STREAM, 0); 

  // assign IP, PORT 
  client.sin_family = AF_INET; 
  client.sin_port = 2000; 
  client.sin_addr.s_addr = inet_addr("127.0.0.1"); 

  // connect the client socket to server socket 
  connect(s, (struct sockaddr*)&client, sizeof client); 

  for (;;) { 
    printf("\nIngrese los Datos: "); 
    scanf("%s", buffer1); 
    
    printf("\n: %s", buffer1); 
    send(s, buffer1, sizeof(buffer1), 0); 
    recv(s, &flag1, sizeof(int), 0); 

    if (flag1 == 1) { 
      printf("\nDato Validado\n"); 
      printf("\ningrese la matricula del estudiante: "); 
      scanf("%s", buffer2); 
    
      printf("\n: %s", buffer2); 
      send(s, buffer2, sizeof(buffer2), 0); 
      recv(s, &flag2, sizeof(int), 0); 
      break; 
    } 
    else { 
      printf("\nDatos Equivocados\n"); 
      break; 
    } 
  } 

  // close the socket 
  close(s); 
} 
