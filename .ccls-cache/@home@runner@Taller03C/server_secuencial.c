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

int main() 
{ 
  struct sockaddr_in server, client; 
  int s, n, sock, g, j, left, right, flag1,flag2; 
  char b1[30], b2[30], b3[10], b4[10]; 
  char validacion[20];

  // creating socket 
  s = socket(AF_INET, SOCK_STREAM, 0); 

  if (s == -1) {
    fprintf(stderr, "[SERVER ERROR] Socket creation failed\n");
    return -1;
  } else {
    printf("[SERVER] Socket successfully created!");
  }

  /* clear structure */
  memset(&server, 0, sizeof(server));
  
  // assign IP, PORT 
  server.sin_family = AF_INET; 

  // this is the port number of running server 
  server.sin_port = htons(2000); 
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); 

  // Binding newly created socket 
  // to given IP and verification 
  bind(s, (struct sockaddr*)&server, sizeof server); 

  
  if (listen(s, 1) != 0) {
    printf("[SERVER ERROR] Socket listened failed\n");
    return -1;
  } else {
    printf("[SERVER] Server listened!\n");
  }    
  
  n = sizeof(client); 

  sock = accept(s, (struct sockaddr*)&client, &n); 
  //Requerimientos del cliente
  //Validacion de facultad/carrera
  for (;;) { 
    recv(sock, b1, sizeof(b1), 0); 
    //validacion
    
    //comparacion
    if (strcmp(b1, validacion) == 0) {
        flag1 = 1;
    } else {
        flag1 = 0;
    }
    send(sock, &flag1, sizeof(int), 0); 
    break; 
}
  //Datos del estudiante
    for (;;) { 
    recv(sock, b2, sizeof(b2), 0); 

    FILE *archivo = fopen("estudiantes", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
    }

    while (fscanf(archivo, "%s %s %s %d %f %d",
                  &Estudiante.nombre,
                  &Estudiante.apellido,
                  6Estudiante.facultad,
                  &Estudiante.carrera,
                  &Estudiante.promedio,
                  &Estudiante.materias_ap,
                  &Estudiante.materias_rp,
                              {
    }

    fclose(archivo);
}
    send(sock, &flag2, sizeof(int), 0); 
    break; 
}
  
  close(sock); 

  // close the socket 
  close(s); 
} 
