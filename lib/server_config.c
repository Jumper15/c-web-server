#include "_module.h"
#include "tcp_create.c"
#include "udp_create.c"

// server_config(int port, str socket_type)
static PyObject* _server_config(PyObject* self, PyObject* args)
{
    char* sock_in; 
    int sock_type = SOCK_STREAM;
    // // AF_INET or ipv4 is exclusively used rn
    // int addr_type = AF_INET;
    // // standard protocols exclusively used
    // int protocol = 0;
    int port, sockfd;
    struct sockaddr_in server_addr;

    if (!PyArg_ParseTuple(args, "i|s", &port, &sock_in)) 
    {
        return NULL;
    }

    if (sock_in == "SOCK_STREAM")
    {
        sock_type = SOCK_STREAM;
    }
    if (sock_in == "SOCK_DGRAM")
    {
        sock_type = SOCK_DGRAM;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (sock_type == SOCK_STREAM)
    {
        sockfd = tcp_create(server_addr);
        if (sockfd == -1) {
            return PyErr_SetFromErrno(PyExc_OSError);
        }
        return PyLong_FromLong(sockfd);
    }
    else if (sock_type == SOCK_DGRAM)
    {
        sockfd = udp_create(server_addr);
        if (sockfd == -1) {
        return PyErr_SetFromErrno(PyExc_OSError);
        }
        return PyLong_FromLong(sockfd);
    }
    else {
        PyErr_SetString(PyExc_ValueError, "Invalid socket type");
        return NULL;
    }
}