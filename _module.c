#include "lib/_module.h"
#include "lib/server_config.c"
#include "lib/run_server.c"
#include "lib/send_response.c"
#include "lib/close_server.c"

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
