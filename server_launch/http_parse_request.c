// #include "_module.h"

struct http_request_line* http_request_line_constructor(char* request_line) {
    struct http_request_line req_line;
    struct http_request_line* req_line_ptr;

    char* method = strtok((char*) request_line, " ");
    char* uri = strtok(NULL, " ");
    char* version = strtok(NULL, " ");

    req_line.method = method;
    req_line.uri = uri;
    req_line.version = version;

    req_line_ptr = &req_line;

    return req_line_ptr;
}

struct http_request_line* http_parse_request(char* req_string)
{
    // char parse_string[3000]; 
    // strcpy(parse_string, req_string);

    // for (int i = 0; i < 3000; i++) 
    // {
    //     if (parse_string[i] == '\r' && parse_string[i+1] == '\n' && parse_string[i+2] == '\r' && parse_string[i+3] == '\n') 
    //     {
    //         parse_string[i+3] = '|';
    //         break;
    //     }
    // }

    char* header_line = strtok(req_string, "\n");
    // char* header_line = strtok(parse_string, "\n");
    char* header_fields = strtok(NULL, "|"); 
    char* content_body = strtok(NULL, "|");

    struct http_request_line* req = http_request_line_constructor(header_line);
    
    return req;

}