// #include "_module.h"

int create_socket(int port)
{
    struct sockaddr_in server_addr;
    int sockfd;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == 0)
    {
        return -1;
    }
    printf("%d\n", sockfd);

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) 
    {
        return -1;
    } 
    return sockfd;
}