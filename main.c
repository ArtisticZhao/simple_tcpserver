#include <stdio.h>
#include <stdlib.h>

#include "c_socket.h"

#define BUFSIZ 20
int main()
{
    char buf[BUFSIZ];

    int server_sockfd;
    int client_sockfd;
    int message_len;
    printf("Hello world!\n");
    server_sockfd = start_tcpserver(9999);
    client_sockfd = wait_client_in(server_sockfd);
    send_to_client(client_sockfd, "hello\n", 6);
    message_len = recv_from_client(client_sockfd, buf, BUFSIZ);
    buf[message_len] = '\0';
    printf(buf);

    close_all(server_sockfd, client_sockfd);
    return 0;
}
