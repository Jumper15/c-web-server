#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>
#include "Parser.c"

void err(char error_message[])
{
    perror(error_message);
    exit(1);
}

int main()
{
    char buffer[2048]; 
    size_t buffer_len = sizeof(buffer);

    struct sockaddr_in server_addr, cli_addr;
    int port = 3001; 
    socklen_t clilen = sizeof(cli_addr); 
    int sockfd, newsockfd; 

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == 0) err("error in socket creation\n");

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) err("error in socket binding\n"); 

    if (listen(sockfd, 5) < 0) err("error during socket listening\n"); 

    while(1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0) err("error in socket accepting\n");

        if (read(newsockfd, buffer, buffer_len) < 0) err("error in socket reading\n");

        char* response = parse_request(buffer);

        if (write(newsockfd, response, strlen(response)) < 0) err("error when writing to server\n");



    }

    return 0;
}