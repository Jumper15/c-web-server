#include "_module.h"


// server_config(int port, str socket_type, str address family)
static PyObject* _server_config(PyObject* self, PyObject* args)
{
    char* sock_type = "SOCK_STREAM";
    char* addr_type = "AF_INET";
    int port, sockfd;
    struct sockaddr_in server_addr;

    if (!PyArg_ParseTuple(args, "i|ss", &port, &sock_type, &addr_type)) 
    {
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == 0)
    {
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) 
    {
        return PyErr_SetFromErrno(PyExc_OSError);
    } 

    return PyLong_FromLong(sockfd);
}