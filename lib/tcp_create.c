#include "_module.h"

int tcp_create(struct sockaddr_in server_addr)
{
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == 0)
    {
        return -1;
    }

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == ERR_VAL) 
    {
        return -1;
    } 
    return sockfd;
}