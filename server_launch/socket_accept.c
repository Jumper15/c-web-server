// #include "_module.h"
#include "http_parse_request.c"
#include "build_response.c"

char* socket_accept(int sockfd, struct LinkedList* res_dict)
{
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    char buffer[2048];

    if (listen(sockfd, 5) < 0) 
    {
      return NULL;
    } 
    // while (1)
    // {
          newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
          if (newsockfd == ERR_VAL)
          {
               return NULL;
          }

          if (read(newsockfd, buffer, sizeof(buffer)) == ERR_VAL) 
          {
               return NULL;
          }
          struct http_request_line* req_line = http_parse_request(buffer);
          char* res = build_response(req_line, res_dict);
          int write_val = write(newsockfd, res, strlen(res)); // n is return value of writing to client
          if (write_val < 0) // error in writing
          {
              return NULL;
          }

          return res;


    // }
}