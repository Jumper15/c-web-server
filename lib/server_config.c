#include "_module.h"

static PyObject* _server_config(PyObject* self, PyObject* args)
{
    int port, sockfd;
    struct sockaddr_in server_addr;

    if (!PyArg_ParseTuple(args, "i", &port)) 
    {
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == 0)
    {
        PyErr_SetString(PyExc_SystemError, "Error in creating socket"); // find better error code later
        return NULL; 
    }

    if (bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) 
    {
        PyErr_SetString(PyExc_SystemError, "Error in binding socket"); // find better error code later
        return NULL; 
    } 

    return PyLong_FromLong(sockfd);
}