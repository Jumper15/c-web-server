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
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    return PyLong_FromLong(0);
}