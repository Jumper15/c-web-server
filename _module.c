#include "lib/_module.h"
#include "lib/server_config.c"
#include "lib/run_server_tcp.c"
#include "lib/send_response.c"
#include "lib/close_server.c"

static struct PyMethodDef methods[] = {
    {"server_config", (PyCFunction)_server_config, METH_VARARGS},
    {"run_server_tcp", (PyCFunction)_run_server_tcp, METH_VARARGS},
    {"send_response_text", (PyCFunction)_send_response_text, METH_VARARGS},
    {"send_from_file", (PyCFunction)_send_from_file, METH_VARARGS},
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
