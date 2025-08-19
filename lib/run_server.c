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
        return PyErr_SetFromErrno(PyExc_OSError);
    } 

    while(1)
    {
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0)
        {
            return PyErr_SetFromErrno(PyExc_OSError);
            
        }

        if (read(newsockfd, buffer, sizeof(buffer)) < 0) 
        {
            return PyErr_SetFromErrno(PyExc_OSError);
        }
   
        return Py_BuildValue("is", newsockfd, buffer);
    }
}