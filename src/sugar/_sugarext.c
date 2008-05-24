/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 4 "_sugarext.override"
#include <Python.h>

#include "pygobject.h"
#include "sugar-address-entry.h"
#include "sugar-key-grabber.h"
#include "sugar-menu.h"
#include "sugar-preview.h"
#include "sexy-icon-entry.h"

#include <pygtk/pygtk.h>
#include <glib.h>

#line 21 "_sugarext.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkEntry_Type;
#define PyGtkEntry_Type (*_PyGtkEntry_Type)
static PyTypeObject *_PyGtkMenu_Type;
#define PyGtkMenu_Type (*_PyGtkMenu_Type)
static PyTypeObject *_PyGtkContainer_Type;
#define PyGtkContainer_Type (*_PyGtkContainer_Type)
static PyTypeObject *_PyGdkWindow_Type;
#define PyGdkWindow_Type (*_PyGdkWindow_Type)
static PyTypeObject *_PyGdkDrawable_Type;
#define PyGdkDrawable_Type (*_PyGdkDrawable_Type)
static PyTypeObject *_PyGtkImage_Type;
#define PyGtkImage_Type (*_PyGtkImage_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PySugarAddressEntry_Type;
PyTypeObject G_GNUC_INTERNAL PySugarKeyGrabber_Type;
PyTypeObject G_GNUC_INTERNAL PySugarMenu_Type;
PyTypeObject G_GNUC_INTERNAL PySugarPreview_Type;
PyTypeObject G_GNUC_INTERNAL PySexyIconEntry_Type;

#line 48 "_sugarext.c"



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

static PyObject *
_wrap_sugar_key_grabber_grab(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:SugarKeyGrabber.grab", kwlist, &key))
        return NULL;
    
    sugar_key_grabber_grab(SUGAR_KEY_GRABBER(self->obj), key);
    
    Py_INCREF(Py_None);
    return Py_None;
}

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

static const PyMethodDef _PySugarKeyGrabber_methods[] = {
    { "grab", (PyCFunction)_wrap_sugar_key_grabber_grab, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_key", (PyCFunction)_wrap_sugar_key_grabber_get_key, METH_VARARGS|METH_KEYWORDS,
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



/* ----------- SugarPreview ----------- */

static PyObject *
_wrap_sugar_preview_take_screenshot(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "drawable", NULL };
    PyGObject *drawable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:SugarPreview.take_screenshot", kwlist, &PyGdkDrawable_Type, &drawable))
        return NULL;
    
    sugar_preview_take_screenshot(SUGAR_PREVIEW(self->obj), GDK_DRAWABLE(drawable->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_preview_set_size(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "width", "height", NULL };
    int width, height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:SugarPreview.set_size", kwlist, &width, &height))
        return NULL;
    
    sugar_preview_set_size(SUGAR_PREVIEW(self->obj), width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_preview_clear(PyGObject *self)
{
    
    sugar_preview_clear(SUGAR_PREVIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_sugar_preview_get_pixbuf(PyGObject *self)
{
    GdkPixbuf *ret;

    
    ret = sugar_preview_get_pixbuf(SUGAR_PREVIEW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PySugarPreview_methods[] = {
    { "take_screenshot", (PyCFunction)_wrap_sugar_preview_take_screenshot, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_size", (PyCFunction)_wrap_sugar_preview_set_size, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "clear", (PyCFunction)_wrap_sugar_preview_clear, METH_NOARGS,
      NULL },
    { "get_pixbuf", (PyCFunction)_wrap_sugar_preview_get_pixbuf, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PySugarPreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "sugar._sugarext.Preview",                   /* tp_name */
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
    (struct PyMethodDef*)_PySugarPreview_methods, /* tp_methods */
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



/* ----------- functions ----------- */

const PyMethodDef py_sugarext_functions[] = {
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
        _PyGdkDrawable_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Drawable");
        if (_PyGdkDrawable_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Drawable from gtk.gdk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk.gdk");
        return ;
    }


#line 692 "_sugarext.c"
    pygobject_register_class(d, "SugarAddressEntry", SUGAR_TYPE_ADDRESS_ENTRY, &PySugarAddressEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pygobject_register_class(d, "SugarKeyGrabber", SUGAR_TYPE_KEY_GRABBER, &PySugarKeyGrabber_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(SUGAR_TYPE_KEY_GRABBER);
    pygobject_register_class(d, "SugarMenu", SUGAR_TYPE_MENU, &PySugarMenu_Type, Py_BuildValue("(O)", &PyGtkMenu_Type));
    pygobject_register_class(d, "SugarPreview", SUGAR_TYPE_PREVIEW, &PySugarPreview_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(SUGAR_TYPE_PREVIEW);
    pygobject_register_class(d, "SexyIconEntry", SEXY_TYPE_ICON_ENTRY, &PySexyIconEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pyg_set_object_has_new_constructor(SEXY_TYPE_ICON_ENTRY);
}
