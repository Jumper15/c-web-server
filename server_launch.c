#include "server_launch/socket_accept.c"


static PyObject* _server_launch(PyObject* self, PyObject* args) 
{
    int sockfd;

    if (!PyArg_ParseTuple(args, "i", &sockfd))
    {
        return NULL;
    }

    char* ret = socket_accept(sockfd);
    return PyUnicode_FromString(ret);
}
