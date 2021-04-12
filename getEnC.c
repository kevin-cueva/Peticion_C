#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h> 

//SOCK_STREAM -> TCP
//SOCK_DGRAM -> UDP

int main(){
    
    int conection = 0;
    int socket_id = 0; // Identificador de socket devuelto por la función socket()
    char msg[] = "GET / HTTP/1.1\r\n"
                 "Host: localhost\r\n"
                 "Connection: Keep-alive\r\n"
                 "Cache-Control: max-age=0\r\n"
                 "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,;q=0.8\r\n"
                 "User-Agent: Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.114 Safari/537.36\r\n"
                 "Accept-Encoding: gzip, deflate, sdch\r\n"
                 "Accept-Language: en-US,en;q=0.8\r\n\r\n";

  //socket(int dominio, int tipo, int protocolo)
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    /* La estructura TCP/IP es la sockaddr_in, equivalente a la estructura sockaddr, pero que permite
     referenciar a sus elementos de forma más sencilla.*/
    
    struct sockaddr_in server; //nombre de structura
    server.sin_family = AF_INET; //Dominio donde se realiza la conexion
    server.sin_addr.s_addr = inet_addr("172.217.173.196"); //Esta es una ip de unos de los servidores de google
    server.sin_port = htons(80); //el puerto de internet


/*connect () se usa para conectarse a una dirección de [servidor] remota
                        identificador, puntero a una estructura sockaddr,  tamaño de la estructura*/
    conection = connect(socket_id, (struct sockaddr*)&server, sizeof(server)); 
    if(conection < 0){
        printf("Error al realizar la conexión\r\n");
        return(-1);
    }

    printf("Conexión realizada con éxito\r\n");
    send(socket_id, msg, sizeof(msg), 0); //Enviar datos al servidor
    //close(socket_id);                    //Cierre el socket
    return(0);  
}