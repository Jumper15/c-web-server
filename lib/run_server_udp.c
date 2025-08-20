#include "_module.h"

static PyObject* _run_server_udp(PyObject* self, PyObject* args) 
{
    int sockfd;
    char buffer[2048];

    if (!PyArg_ParseTuple(args, "i", &sockfd))
    {
        return NULL;
    }

     if (recvfrom(sockfd, buffer, 2048, MSG_WAITALL, 0, 0) == ERR_VAL)
     {
        return PyErr_SetFromErrno(PyExc_OSError);
     }

     return Py_BuildValue("s", buffer);
}