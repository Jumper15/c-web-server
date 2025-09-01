#include "server_config/create_socket.c"
#include "server_config/http_parse_options.c"

// server_config(int port, str socket_type)
static PyObject* _server_config(PyObject* self, PyObject* args)
{
    int port, sockfd;

    if (!PyArg_ParseTuple(args, "i", &port)) 
    {
        return NULL;
    }

    sockfd = create_socket(port);

    // // dictionary storing routes and methods
    // struct LinkedList* res_dict = ll_constructor();

    struct http_request_options* res_opts_ptr;
    struct http_request_options res_opts;
    res_opts.route = "/foo/bar";
    res_opts.method = "GET";
    res_opts.res_file_name = "homepage.html";

    res_opts_ptr = &res_opts;

    http_parse_options(res_opts);

    return PyLong_FromLong(sockfd);
}