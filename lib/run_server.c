#include "_module.h"

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