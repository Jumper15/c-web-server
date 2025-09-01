#include "_module.h"
// #include "server_config.c"
#include "server_launch.c"

static struct PyMethodDef methods[] = {
    // {"server_config", (PyCFunction)_server_config, METH_VARARGS},
    {"server_launch", (PyCFunction)_server_launch, METH_VARARGS},
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
