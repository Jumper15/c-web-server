// #include "_module.h"
#include "Date.c"
#include "File.c"

char* build_response(struct http_request_line* req_line, struct LinkedList* res_dict)
{
    char* date_header_content = get_date();
    char* fileName = getNodeByKey(res_dict, req_line->method);
    char* html_body = readFile(fileName);
     
    char res_buf[1024];
    sprintf(res_buf, "HTTP/1.1 200 OK\r\nDate: %s GMT\r\nMethod: POST\r\nContent-Type: text/plain charset=UTF-8\r\nContent-Length: 12\r\n\r\n%s", date_header_content, html_body);
    char* res_buf_ptr = res_buf;
    return res_buf_ptr;
}