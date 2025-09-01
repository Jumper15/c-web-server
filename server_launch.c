#include "_module.h"
#include "server_config/create_socket.c"
#include "server_config/http_parse_options.c"
#include "server_launch/socket_accept.c"

int server_launch(int port, char* route, char* method, char* res_file_name) 
{    
    int sockfd;
    sockfd = create_socket(port);

    struct http_request_options* res_opts_ptr;
    struct http_request_options res_opts;
    res_opts.route = route;
    res_opts.method = method;
    res_opts.res_file_name = res_file_name;

    res_opts_ptr = &res_opts;

    struct LinkedList* res_dict = http_parse_options(&res_opts);

    char* ret = socket_accept(sockfd, res_dict);

    return 0;
}
