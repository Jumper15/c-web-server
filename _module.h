#ifndef _MODULE_H
#define _MODULE_H

// #include <Python.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>
#include <assert.h>

#include "data_structs/node/node.c"
#include "data_structs/linkedlist/linkedlist.c"

#define ERR_VAL -1

struct http_request_options {
     char* route;
     char* method;
     char* res_file_name;
};
    
struct http_request_line 
{
    char* method;
    char* uri;
    char* version;
};

// struct http_header_fields
// {
     
// }

#endif