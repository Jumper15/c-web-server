#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Parser.h"
#include "Response.c"
// #include "ParseBody.c"

int resolve_header(char* header)
{
    char* header_name = strtok(header, ":");
    char* header_value = strtok(NULL, "");
    printf("Header name: %s\n", header_name);

    return 0;
}

int parse_header_field(char* header_fields)
{
    printf("Header fields are: %s", header_fields);
    char* header = strtok(header_fields, "\n");
    printf("Header field: %s\n", header);    

    while (header != NULL)
    {
        bzero(header, strlen(header_fields));
        header = strtok(NULL, "\n");
        printf("Header field: %s\n", header);
        // resolve_header(header);
    }
    return 0;
}

struct http_request_line http_request_line_constructor(char* request_line) {
    struct http_request_line http_request_line;

    char* method = strtok((char*) request_line, " ");
    char* uri = strtok(NULL, " ");
    char* version = strtok(NULL, " ");

    http_request_line.method = method;
    http_request_line.uri = uri;
    http_request_line.version = version;

    return http_request_line;
}

char* parse_request(char parse_string[])
{

    for (int i = 0; i < strlen(parse_string) - 1; i++) 
    {
        if (parse_string[i] == '\r' && parse_string[i+1] == '\n' && parse_string[i+2] == '\r' && parse_string[i+3] == '\n') 
        {
            parse_string[i+3] = '|';
        }
    }

    char* request_line = strtok(parse_string, "\n");
    char* header_fields = strtok(NULL, "|"); 
    char* content_body = strtok(NULL, "|");

    // printf("rl: %s\n\n", request_line);
    // printf("hf: %s\n\n", header_fields);
    // printf("cb: %s\n\n", content_body);

    struct http_request_line req_line = http_request_line_constructor(request_line);
    // parse_header_field(header_fields);
    // char* parse_body = parse_body(content_body);

    char* method = req_line.method;

    char* response = build_http_response(method);

    printf("%s\n\n", response);
    return response;
}