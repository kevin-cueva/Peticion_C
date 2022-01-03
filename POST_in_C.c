#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

//SOCK_STREAM -> TCP
//SOCK_DGRAM -> UDP

int main(){

    int conection = 0;
    int socket_id = 0; // Identificador de socket devuelto por la función socket()
    char msg[] = "POST /item HTTP/1.1\r\n"
                 "Host: 127.0.0.1\r\n"
                 "Accept: application/json\r\n"
                 "Content-Type: application/json\r\n"
                 "Content-Length: 93\r\n"
                 "\r\n"
                 "{\"ubicacion\": \"idea\", \"temperatura\": \"35\", \"time\": \"21/12/2021\", \"unidad\": \"°F\", \"id\": \"31\"}";


  //socket(int dominio, int tipo, int protocolo)
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    /* La estructura TCP/IP es la sockaddr_in, equivalente a la estructura sockaddr, pero que permite
     referenciar a sus elementos de forma más sencilla.*/

    struct sockaddr_in server; //nombre de structura
    server.sin_family = AF_INET; //Dominio donde se realiza la conexion
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //Esta es la ip interna del equipo
    server.sin_port = htons(5000); //el puerto de del equipo


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
