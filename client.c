#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <memory.h>

#define PORT 8080

int main(void)
{
    int serverfd;
    struct sockaddr_in serveraddr;
    socklen_t addrlen = sizeof(serveraddr);
    char buffer[1024] = {0};

    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr("192.168.1.9");
    serveraddr.sin_family = AF_INET;

    if ( (serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return -1;
    }

    if ( (connect(serverfd, (struct sockaddr *)&serveraddr, addrlen)) < 0)
    {
        perror("connect");
        return -1;
    }

    printf("Conectado ao servidor!\n");

    while (1) 
    {
        fgets(buffer, 1024, stdin);

        int msgsend = send(serverfd, buffer, sizeof(buffer), 0);

        if (msgsend < 0) 
        {
            perror("send");
            return -1;
        }

        memset(buffer, '\0', sizeof(buffer));

        int msgrecv = recv(serverfd, buffer, sizeof(buffer), 0);

        if (msgrecv < 0) 
        {
            perror("recv");
            return -1;
        }
        
        if (msgrecv == 0) 
        {
            printf("Servidor desconectado\n");
            return -1;
        }

        printf("%s: %s", inet_ntoa(serveraddr.sin_addr), buffer);

        memset(buffer, '\0', sizeof(buffer));

    }

    return 0;
}
