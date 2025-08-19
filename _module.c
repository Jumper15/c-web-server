#include <Python.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>

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

static PyObject* _run_server(PyObject* self, PyObject* args) 
{
    int sockfd, newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    char buffer[2048];

    if (!PyArg_ParseTuple(args, "i", &sockfd))
    {
        return NULL;
    }

    if (listen(sockfd, 1) < 0) 
    {
        PyErr_SetString(PyExc_ConnectionError, "Error in socket listening"); // find better error code later
        return NULL; 
    } 

    while(1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0)
        {
            PyErr_SetString(PyExc_ConnectionError, "Error in socket accepting"); // find better error code later 
            return NULL; 
        }

        if (read(newsockfd, buffer, sizeof(buffer)) < 0) 
        {
            PyErr_SetString(PyExc_ConnectionError, "Error in socket accepting"); // find better error code later 
            return NULL; 
        }
   
        return Py_BuildValue("is", newsockfd, buffer);

        // return struct client_token: metadata, data transmitted, way to callbakc (function pointer, by calling, calls another func to send msg)
    }
}

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


static struct PyMethodDef methods[] = {
    {"server_config", (PyCFunction)_server_config, METH_VARARGS},
    {"run_server", (PyCFunction)_run_server, METH_VARARGS},
    {"send_response", (PyCFunction)_send_response, METH_VARARGS},
    {"close_server", (PyCFunction)_close_server, METH_VARARGS},
    {NULL, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "_module",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit__module(void) {
    return PyModule_Create(&module);
}