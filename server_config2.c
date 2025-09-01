#include "_module.h"
#include "server_config/create_socket.c"
#include "server_config/http_parse_options.c"
#include "server_launch/socket_accept.c"

// server_config(int port, str socket_type)
int main()
{
    int port, sockfd;

    port = 30001;

    sockfd = create_socket(port);
    printf("%d\n", sockfd);

    // // dictionary storing routes and methods
    // struct LinkedList* res_dict = ll_constructor();

    struct http_request_options* res_opts_ptr;
    struct http_request_options res_opts;
    res_opts.route = "/foo/bar";
    res_opts.method = "GET";
    res_opts.res_file_name = "homepage.html";

    res_opts_ptr = &res_opts;

    struct LinkedList* res_dict = http_parse_options(res_opts_ptr);

    char* ret = socket_accept(sockfd, res_dict);

    return 0;
}