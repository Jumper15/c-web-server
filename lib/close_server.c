#include "_module.h"

static PyObject* _close_server(PyObject* self, PyObject* args)
{
    int cli_sock;

    if(!PyArg_ParseTuple(args, "i", &cli_sock))
    {
        return NULL;
    }

     if (close(cli_sock) == ERR_VAL)
    {
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    return PyLong_FromLong(0);
}