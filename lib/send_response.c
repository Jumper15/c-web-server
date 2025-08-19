#include "_module.h"

static PyObject* _send_response(PyObject* self, PyObject* args)
{
    int cli_sock;
    const char* res;

    if (!PyArg_ParseTuple(args, "is", &cli_sock, &res))
    {
        return NULL;
    }

    // send reponse to client
    int r = write(cli_sock, res, 2048);
    if (r < 0)
    {
        PyErr_SetString(PyExc_ConnectionError, "Error in writing to socket"); // find better error code later 
        return NULL; 
    }

    // if (close(cli_sock) < 0)
    // {
    //     PyErr_SetString(PyExc_SystemError, "Error deallocating socket"); // find better error code later 
    //     return NULL; 
    // }

    // returns 0 on success
    return PyLong_FromLong(0);
}