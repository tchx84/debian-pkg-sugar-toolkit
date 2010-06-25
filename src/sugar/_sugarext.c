/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 4 "_sugarext.override"
#include <Python.h>

#include "pygobject.h"
#include "sugar-address-entry.h"
#include "sugar-grid.h"
#include "sugar-key-grabber.h"
#include "sugar-menu.h"
#include "sexy-icon-entry.h"
#include "gsm-session.h"
#include "gsm-xsmp.h"
#include "acme-volume-alsa.h"

#include "eggsmclient.h"
#include "eggsmclient-private.h"

#include <pygtk/pygtk.h>
#include <glib.h>

#line 27 "_sugarext.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGtkEntry_Type;
#define PyGtkEntry_Type (*_PyGtkEntry_Type)
static PyTypeObject *_PyGtkMenu_Type;
#define PyGtkMenu_Type (*_PyGtkMenu_Type)
static PyTypeObject *_PyGtkContainer_Type;
#define PyGtkContainer_Type (*_PyGtkContainer_Type)
static PyTypeObject *_PyGdkWindow_Type;
#define PyGdkWindow_Type (*_PyGdkWindow_Type)
static PyTypeObject *_PyGtkImage_Type;
#define PyGtkImage_Type (*_PyGtkImage_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PySugarAddressEntry_Type;
PyTypeObject G_GNUC_INTERNAL PySugarKeyGrabber_Type;
PyTypeObject G_GNUC_INTERNAL PySugarMenu_Type;
PyTypeObject G_GNUC_INTERNAL PySugarGrid_Type;
PyTypeObject G_GNUC_INTERNAL PySexyIconEntry_Type;
PyTypeObject G_GNUC_INTERNAL PyEggSMClientXSMP_Type;
PyTypeObject G_GNUC_INTERNAL PyEggSMClient_Type;
PyTypeObject G_GNUC_INTERNAL PyGsmSession_Type;
PyTypeObject G_GNUC_INTERNAL PyAcmeVolume_Type;
PyTypeObject G_GNUC_INTERNAL PyAcmeVolumeAlsa_Type;

#line 59 "_sugarext.c"



/* ----------- SugarAddressEntry ----------- */

PyTypeObject G_GNUC_INTERNAL PySugarAddressEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.AddressEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- SugarKeyGrabber ----------- */

#line 38 "_sugarext.override"
static PyObject *
_wrap_sugar_key_grabber_grab_keys(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
	PyObject *py_keys;
	char **keys;
	int i, len;

    if (!PyArg_ParseTupleAndKeywords(args,kwargs,
                                     "O:SugarKeyGrabber.grab_keys",
                                     kwlist, &py_keys))
        return NULL;

    if (!PySequence_Check(py_keys) || (len = PySequence_Size(py_keys)) < 0) {
        PyErr_SetString(PyExc_ValueError,
                        "keys should be a sequence of strings");
        return NULL;
    }

    keys = g_new(char*, len + 1);
    for (i = 0; i < len; i++) {
        PyObject *item = PySequence_GetItem(py_keys, i);
        if (!item) {
            g_free(keys);
            return NULL;
        }
        if (!PyString_Check(item)) {
            PyErr_SetString(PyExc_TypeError, "key must be a string");
            g_free(keys);
            Py_DECREF(item);
            return NULL;
        }
        keys[i] = PyString_AsString(item);
        Py_DECREF(item);
    }
    keys[len] = NULL;

    sugar_key_grabber_grab_keys (SUGAR_KEY_GRABBER(self->obj), (const char**) keys);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 158 "_sugarext.c"


static PyObject *
_wrap_sugar_key_grabber_get_key(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keycode", "state", NULL };
    PyObject *py_keycode = NULL, *py_state = NULL;
    gchar *ret;
    guint keycode = 0, state = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:SugarKeyGrabber.get_key", kwlist, &py_keycode, &py_state))
        return NULL;
    if (py_keycode) {
        if (PyLong_Check(py_keycode))
            keycode = PyLong_AsUnsignedLong(py_keycode);
        else if (PyInt_Check(py_keycode))
            keycode = PyInt_AsLong(py_keycode);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'keycode' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_state) {
        if (PyLong_Check(py_state))
            state = PyLong_AsUnsignedLong(py_state);
        else if (PyInt_Check(py_state))
            state = PyInt_AsLong(py_state);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'state' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = sugar_key_grabber_get_key(SUGAR_KEY_GRABBER(self->obj), keycode, state);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_key_grabber_is_modifier(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "keycode", "mask", NULL };
    PyObject *py_keycode = NULL, *py_mask = NULL;
    int ret;
    guint keycode = 0, mask = -1;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O|O:SugarKeyGrabber.is_modifier", kwlist, &py_keycode, &py_mask))
        return NULL;
    if (py_keycode) {
        if (PyLong_Check(py_keycode))
            keycode = PyLong_AsUnsignedLong(py_keycode);
        else if (PyInt_Check(py_keycode))
            keycode = PyInt_AsLong(py_keycode);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'keycode' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_mask) {
        if (PyLong_Check(py_mask))
            mask = PyLong_AsUnsignedLong(py_mask);
        else if (PyInt_Check(py_mask))
            mask = PyInt_AsLong(py_mask);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'mask' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = sugar_key_grabber_is_modifier(SUGAR_KEY_GRABBER(self->obj), keycode, mask);
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PySugarKeyGrabber_methods[] = {
    { "grab_keys", (PyCFunction)_wrap_sugar_key_grabber_grab_keys, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_key", (PyCFunction)_wrap_sugar_key_grabber_get_key, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_modifier", (PyCFunction)_wrap_sugar_key_grabber_is_modifier, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PySugarKeyGrabber_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.KeyGrabber",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PySugarKeyGrabber_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- SugarMenu ----------- */

static PyObject *
_wrap_sugar_menu_set_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "active", NULL };
    int active;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:SugarMenu.set_active", kwlist, &active))
        return NULL;
    
    sugar_menu_set_active(SUGAR_MENU(self->obj), active);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_menu_embed(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "container", NULL };
    PyGObject *container;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:SugarMenu.embed", kwlist, &PyGtkContainer_Type, &container))
        return NULL;
    
    sugar_menu_embed(SUGAR_MENU(self->obj), GTK_CONTAINER(container->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_menu_unembed(PyGObject *self)
{
    
    sugar_menu_unembed(SUGAR_MENU(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PySugarMenu_methods[] = {
    { "set_active", (PyCFunction)_wrap_sugar_menu_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "embed", (PyCFunction)_wrap_sugar_menu_embed, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unembed", (PyCFunction)_wrap_sugar_menu_unembed, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PySugarMenu_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.Menu",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PySugarMenu_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- SugarGrid ----------- */

static PyObject *
_wrap_sugar_grid_setup(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "width", "height", NULL };
    int width, height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:SugarGrid.setup", kwlist, &width, &height))
        return NULL;
    
    sugar_grid_setup(SUGAR_GRID(self->obj), width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_grid_add_weight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "rect", NULL };
    PyObject *py_rect;
    GdkRectangle rect = { 0, 0, 0, 0 };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:SugarGrid.add_weight", kwlist, &py_rect))
        return NULL;
    if (!pygdk_rectangle_from_pyobject(py_rect, &rect))
        return NULL;
    
    sugar_grid_add_weight(SUGAR_GRID(self->obj), &rect);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_grid_remove_weight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "rect", NULL };
    PyObject *py_rect;
    GdkRectangle rect = { 0, 0, 0, 0 };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:SugarGrid.remove_weight", kwlist, &py_rect))
        return NULL;
    if (!pygdk_rectangle_from_pyobject(py_rect, &rect))
        return NULL;
    
    sugar_grid_remove_weight(SUGAR_GRID(self->obj), &rect);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_grid_compute_weight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "rect", NULL };
    PyObject *py_rect;
    GdkRectangle rect = { 0, 0, 0, 0 };
    guint ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:SugarGrid.compute_weight", kwlist, &py_rect))
        return NULL;
    if (!pygdk_rectangle_from_pyobject(py_rect, &rect))
        return NULL;
    
    ret = sugar_grid_compute_weight(SUGAR_GRID(self->obj), &rect);
    
    return PyLong_FromUnsignedLong(ret);
}

static const PyMethodDef _PySugarGrid_methods[] = {
    { "setup", (PyCFunction)_wrap_sugar_grid_setup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "add_weight", (PyCFunction)_wrap_sugar_grid_add_weight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove_weight", (PyCFunction)_wrap_sugar_grid_remove_weight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "compute_weight", (PyCFunction)_wrap_sugar_grid_compute_weight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PySugarGrid_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.Grid",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PySugarGrid_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- SexyIconEntry ----------- */

static int
_wrap_sexy_icon_entry_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":sugar._sugarext.IconEntry.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create sugar._sugarext.IconEntry object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_sexy_icon_entry_set_icon(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "position", "icon", NULL };
    PyObject *py_position = NULL;
    PyGObject *py_icon;
    SexyIconEntryPosition position;
    GtkImage *icon = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:SexyIconEntry.set_icon", kwlist, &py_position, &py_icon))
        return NULL;
    if (pyg_enum_get_value(SEXY_TYPE_ICON_ENTRY_POSITION, py_position, (gpointer)&position))
        return NULL;
    if (py_icon && pygobject_check(py_icon, &PyGtkImage_Type))
        icon = GTK_IMAGE(py_icon->obj);
    else if ((PyObject *)py_icon != Py_None) {
        PyErr_SetString(PyExc_TypeError, "icon should be a GtkImage or None");
        return NULL;
    }
    
    sexy_icon_entry_set_icon(SEXY_ICON_ENTRY(self->obj), position, (GtkImage *) icon);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sexy_icon_entry_set_icon_highlight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "position", "highlight", NULL };
    PyObject *py_position = NULL;
    int highlight;
    SexyIconEntryPosition position;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oi:SexyIconEntry.set_icon_highlight", kwlist, &py_position, &highlight))
        return NULL;
    if (pyg_enum_get_value(SEXY_TYPE_ICON_ENTRY_POSITION, py_position, (gpointer)&position))
        return NULL;
    
    sexy_icon_entry_set_icon_highlight(SEXY_ICON_ENTRY(self->obj), position, highlight);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sexy_icon_entry_get_icon(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "position", NULL };
    PyObject *py_position = NULL;
    SexyIconEntryPosition position;
    GtkImage *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:SexyIconEntry.get_icon", kwlist, &py_position))
        return NULL;
    if (pyg_enum_get_value(SEXY_TYPE_ICON_ENTRY_POSITION, py_position, (gpointer)&position))
        return NULL;
    
    ret = sexy_icon_entry_get_icon(SEXY_ICON_ENTRY(self->obj), position);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_sexy_icon_entry_get_icon_highlight(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "position", NULL };
    PyObject *py_position = NULL;
    int ret;
    SexyIconEntryPosition position;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:SexyIconEntry.get_icon_highlight", kwlist, &py_position))
        return NULL;
    if (pyg_enum_get_value(SEXY_TYPE_ICON_ENTRY_POSITION, py_position, (gpointer)&position))
        return NULL;
    
    ret = sexy_icon_entry_get_icon_highlight(SEXY_ICON_ENTRY(self->obj), position);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_sexy_icon_entry_add_clear_button(PyGObject *self)
{
    
    sexy_icon_entry_add_clear_button(SEXY_ICON_ENTRY(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PySexyIconEntry_methods[] = {
    { "set_icon", (PyCFunction)_wrap_sexy_icon_entry_set_icon, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_icon_highlight", (PyCFunction)_wrap_sexy_icon_entry_set_icon_highlight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_icon", (PyCFunction)_wrap_sexy_icon_entry_get_icon, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_icon_highlight", (PyCFunction)_wrap_sexy_icon_entry_get_icon_highlight, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "add_clear_button", (PyCFunction)_wrap_sexy_icon_entry_add_clear_button, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PySexyIconEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.IconEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PySexyIconEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_sexy_icon_entry_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- EggSMClient ----------- */

static PyObject *
_wrap_egg_sm_client_is_resumed(PyGObject *self)
{
    int ret;

    
    ret = egg_sm_client_is_resumed(EGG_SM_CLIENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_egg_sm_client_startup(PyGObject *self)
{
    
    egg_sm_client_startup(EGG_SM_CLIENT(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_egg_sm_client_will_quit(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "will_quit", NULL };
    int will_quit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:EggSMClient.will_quit", kwlist, &will_quit))
        return NULL;
    
    egg_sm_client_will_quit(EGG_SM_CLIENT(self->obj), will_quit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyEggSMClient_methods[] = {
    { "is_resumed", (PyCFunction)_wrap_egg_sm_client_is_resumed, METH_NOARGS,
      NULL },
    { "startup", (PyCFunction)_wrap_egg_sm_client_startup, METH_NOARGS,
      NULL },
    { "will_quit", (PyCFunction)_wrap_egg_sm_client_will_quit, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyEggSMClient_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.SMClient",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyEggSMClient_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- EggSMClientXSMP ----------- */

PyTypeObject G_GNUC_INTERNAL PyEggSMClientXSMP_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.SMClientXSMP",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GsmSession ----------- */

static PyObject *
_wrap_gsm_session_set_name(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", NULL };
    char *name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:GsmSession.set_name", kwlist, &name))
        return NULL;
    
    gsm_session_set_name(GSM_SESSION(self->obj), name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_session_start(PyGObject *self)
{
    
    gsm_session_start(GSM_SESSION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_session_initiate_shutdown(PyGObject *self)
{
    
    gsm_session_initiate_shutdown(GSM_SESSION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_session_cancel_shutdown(PyGObject *self)
{
    
    gsm_session_cancel_shutdown(GSM_SESSION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGsmSession_methods[] = {
    { "set_name", (PyCFunction)_wrap_gsm_session_set_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "start", (PyCFunction)_wrap_gsm_session_start, METH_NOARGS,
      NULL },
    { "initiate_shutdown", (PyCFunction)_wrap_gsm_session_initiate_shutdown, METH_NOARGS,
      NULL },
    { "cancel_shutdown", (PyCFunction)_wrap_gsm_session_cancel_shutdown, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGsmSession_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.Session",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGsmSession_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- AcmeVolume ----------- */

static int
_wrap_acme_volume_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":sugar._sugarext.Volume.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create sugar._sugarext.Volume object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_acme_volume_get_volume(PyGObject *self)
{
    int ret;

    
    ret = acme_volume_get_volume(ACME_VOLUME(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_acme_volume_set_volume(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "val", NULL };
    int val;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:AcmeVolume.set_volume", kwlist, &val))
        return NULL;
    
    acme_volume_set_volume(ACME_VOLUME(self->obj), val);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_acme_volume_get_mute(PyGObject *self)
{
    int ret;

    
    ret = acme_volume_get_mute(ACME_VOLUME(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_acme_volume_set_mute(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "val", NULL };
    int val;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:AcmeVolume.set_mute", kwlist, &val))
        return NULL;
    
    acme_volume_set_mute(ACME_VOLUME(self->obj), val);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_acme_volume_mute_toggle(PyGObject *self)
{
    
    acme_volume_mute_toggle(ACME_VOLUME(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_acme_volume_get_threshold(PyGObject *self)
{
    int ret;

    
    ret = acme_volume_get_threshold(ACME_VOLUME(self->obj));
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyAcmeVolume_methods[] = {
    { "get_volume", (PyCFunction)_wrap_acme_volume_get_volume, METH_NOARGS,
      NULL },
    { "set_volume", (PyCFunction)_wrap_acme_volume_set_volume, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_mute", (PyCFunction)_wrap_acme_volume_get_mute, METH_NOARGS,
      NULL },
    { "set_mute", (PyCFunction)_wrap_acme_volume_set_mute, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "mute_toggle", (PyCFunction)_wrap_acme_volume_mute_toggle, METH_NOARGS,
      NULL },
    { "get_threshold", (PyCFunction)_wrap_acme_volume_get_threshold, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyAcmeVolume_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.Volume",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyAcmeVolume_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_acme_volume_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- AcmeVolumeAlsa ----------- */

PyTypeObject G_GNUC_INTERNAL PyAcmeVolumeAlsa_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.VolumeAlsa",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_gsm_xsmp_init(PyObject *self)
{
    gchar *ret;

    
    ret = gsm_xsmp_init();
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_xsmp_run(PyObject *self)
{
    
    gsm_xsmp_run();
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_xsmp_shutdown(PyObject *self)
{
    
    gsm_xsmp_shutdown();
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gsm_session_create_global(PyObject *self)
{
    GsmSession *ret;

    
    ret = gsm_session_create_global();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

const PyMethodDef py_sugarext_functions[] = {
    { "xsmp_init", (PyCFunction)_wrap_gsm_xsmp_init, METH_NOARGS,
      NULL },
    { "xsmp_run", (PyCFunction)_wrap_gsm_xsmp_run, METH_NOARGS,
      NULL },
    { "xsmp_shutdown", (PyCFunction)_wrap_gsm_xsmp_shutdown, METH_NOARGS,
      NULL },
    { "session_create_global", (PyCFunction)_wrap_gsm_session_create_global, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
py_sugarext_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "IconEntryPosition", strip_prefix, SEXY_TYPE_ICON_ENTRY_POSITION);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
py_sugarext_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkEntry_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Entry");
        if (_PyGtkEntry_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Entry from gtk");
            return ;
        }
        _PyGtkMenu_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Menu");
        if (_PyGtkMenu_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Menu from gtk");
            return ;
        }
        _PyGtkContainer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Container");
        if (_PyGtkContainer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Container from gtk");
            return ;
        }
        _PyGtkImage_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Image");
        if (_PyGtkImage_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Image from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk.gdk")) != NULL) {
        _PyGdkWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyGdkWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from gtk.gdk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk.gdk");
        return ;
    }


#line 1307 "_sugarext.c"
    pygobject_register_class(d, "SugarAddressEntry", SUGAR_TYPE_ADDRESS_ENTRY, &PySugarAddressEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pygobject_register_class(d, "SugarKeyGrabber", SUGAR_TYPE_KEY_GRABBER, &PySugarKeyGrabber_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(SUGAR_TYPE_KEY_GRABBER);
    pygobject_register_class(d, "SugarMenu", SUGAR_TYPE_MENU, &PySugarMenu_Type, Py_BuildValue("(O)", &PyGtkMenu_Type));
    pygobject_register_class(d, "SugarGrid", SUGAR_TYPE_GRID, &PySugarGrid_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(SUGAR_TYPE_GRID);
    pygobject_register_class(d, "SexyIconEntry", SEXY_TYPE_ICON_ENTRY, &PySexyIconEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pyg_set_object_has_new_constructor(SEXY_TYPE_ICON_ENTRY);
    pygobject_register_class(d, "EggSMClient", EGG_TYPE_SM_CLIENT, &PyEggSMClient_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(EGG_TYPE_SM_CLIENT);
    pygobject_register_class(d, "EggSMClientXSMP", EGG_TYPE_SM_CLIENT_XSMP, &PyEggSMClientXSMP_Type, Py_BuildValue("(O)", &PyEggSMClient_Type));
    pyg_set_object_has_new_constructor(EGG_TYPE_SM_CLIENT_XSMP);
    pygobject_register_class(d, "GsmSession", GSM_TYPE_SESSION, &PyGsmSession_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(GSM_TYPE_SESSION);
    pygobject_register_class(d, "AcmeVolume", ACME_TYPE_VOLUME, &PyAcmeVolume_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(ACME_TYPE_VOLUME);
    pygobject_register_class(d, "AcmeVolumeAlsa", ACME_TYPE_VOLUME_ALSA, &PyAcmeVolumeAlsa_Type, Py_BuildValue("(O)", &PyAcmeVolume_Type));
    pyg_set_object_has_new_constructor(ACME_TYPE_VOLUME_ALSA);
}
