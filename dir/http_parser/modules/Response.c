#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Date.c"

char* build_http_response(char* method)
{
    
    char* date_header_content = get_date();

    if (strcmp(method, "GET") == 0)
    {
        char* response = malloc(256);
        snprintf(response, 256, "HTTP/1.1 200 OK\r\nDate: %s GMT\r\nMethod: POST\r\nContent-Type: text/plain; charset=UTF-8\r\nContent-Length: 12\r\n\r\nHello World", date_header_content);
        return response;
    }
    else if (strcmp(method, "POST") == 0)
    {
        char* response = malloc(256);
        snprintf(response, 256, "HTTP/1.1 200 OK\r\nDate: %s GMT\r\nMethod: POST\r\n\r\n", date_header_content);
        return response;
    }
    else 
    {
        char* response = malloc(256);
        snprintf(response, 256, "HTTP/1.1 404 Not Found\r\nDate: %s GMT\r\nMethod: NULL\r\n\r\n", date_header_content);
        return response;
    }
}
