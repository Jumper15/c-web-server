#include "_module.h"

// read data from a file to return to send_response (add support for different extensions)
void* read_from_file(char* fname)
{
    // limited to 256 
    char* buf = malloc(256);

    FILE* fptr = fopen(fname, "r");

    if(fgets(buf, 256, fptr) == NULL)
    {
        return NULL;
    }

    return buf;
}

static PyObject* _send_from_file(PyObject* self, PyObject* args)
{
    int cli_sock;
    char* fname;

    if (!PyArg_ParseTuple(args, "is", &cli_sock, &fname))
    {
        return NULL;
    }

    // limited to 256 
    char* fcontent = read_from_file(fname);

    // send reponse to client
    int r = write(cli_sock, fcontent, 256);
    if (r == ERR_VAL)
    {   
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    return PyLong_FromLong(0);
}

static PyObject* _send_response_text(PyObject* self, PyObject* args)
{
    int cli_sock;
    const char* res;

    if (!PyArg_ParseTuple(args, "is", &cli_sock, &res))
    {
        return NULL;
    }

    // send reponse to client
    int r = write(cli_sock, res, 2048);
    if (r == ERR_VAL)
    {   
        return PyErr_SetFromErrno(PyExc_OSError);
    }

    return PyLong_FromLong(0);
}