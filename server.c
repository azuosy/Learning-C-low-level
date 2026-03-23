#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <memory.h>

#define PORT 8080

int main(void)
{
    int serverfd, clientfd;
    struct sockaddr_in servaddr, clientaddr;
    socklen_t addrlen = sizeof(clientaddr);
    int size = sizeof(servaddr);
    char buffer[1024] = {0};

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if ( (serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return -1;
    }

    if ( (bind(serverfd, (struct sockaddr *) &servaddr, size)) < 0)
    {
        perror("bind");
        return -1;
    }

    if ( (listen(serverfd, 1)) ) 
    {
        perror("listen");
        return -1;
    }

    // aguardar conexao

    if ( (clientfd = accept(serverfd, (struct sockaddr *)&clientaddr, &addrlen)) < 0)
    {
        perror("accept");
        return -1;
    }

    printf("Cliente conectado!\n");

    while (1) 
    {
        int msgrecv = recv(clientfd, buffer, sizeof(buffer), 0);

        if (msgrecv < 0) 
        {
            perror("recv");
            return -1;
        }

        if (msgrecv == 0) 
        {
            printf("Cliente desconectado!");
            break;
        }

        printf("%s: %s", inet_ntoa(clientaddr.sin_addr), buffer);
        memset(buffer, '\0', sizeof(buffer));

        fgets(buffer, sizeof(buffer), stdin);

        int msgsend = send(clientfd, buffer, sizeof(buffer), 0);

        if (msgsend < 0) 
        {
            perror("send");
            return -1;
        }

        memset(buffer, '\0', sizeof(buffer));

    }

    close(clientfd);
    close(serverfd);

    return 0;
}
