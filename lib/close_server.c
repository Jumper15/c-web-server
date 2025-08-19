#include "_module.h"

static PyObject* _close_server(PyObject* self, PyObject* args)
{
    int cli_sock;

    if(!PyArg_ParseTuple(args, "i", &cli_sock))
    {
        return NULL;
    }

     if (close(cli_sock) < 0)
    {
        PyErr_SetString(PyExc_SystemError, "Error deallocating socket"); // find better error code later 
        return NULL; 
    }

    return PyLong_FromLong(0);
}