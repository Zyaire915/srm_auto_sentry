// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "udp_msgs/srv/detail/udp_socket__struct.h"
#include "udp_msgs/srv/detail/udp_socket__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool udp_msgs__srv__udp_socket__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("udp_msgs.srv._udp_socket.UdpSocket_Request", full_classname_dest, 42) == 0);
  }
  udp_msgs__srv__UdpSocket_Request * ros_message = _ros_message;
  {  // local_address
    PyObject * field = PyObject_GetAttrString(_pymsg, "local_address");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->local_address, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // local_port
    PyObject * field = PyObject_GetAttrString(_pymsg, "local_port");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->local_port = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // remote_address
    PyObject * field = PyObject_GetAttrString(_pymsg, "remote_address");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->remote_address, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // remote_port
    PyObject * field = PyObject_GetAttrString(_pymsg, "remote_port");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remote_port = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_broadcast
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_broadcast");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_broadcast = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * udp_msgs__srv__udp_socket__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UdpSocket_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("udp_msgs.srv._udp_socket");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UdpSocket_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  udp_msgs__srv__UdpSocket_Request * ros_message = (udp_msgs__srv__UdpSocket_Request *)raw_ros_message;
  {  // local_address
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->local_address.data,
      strlen(ros_message->local_address.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "local_address", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // local_port
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->local_port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "local_port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remote_address
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->remote_address.data,
      strlen(ros_message->remote_address.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "remote_address", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remote_port
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->remote_port);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remote_port", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_broadcast
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_broadcast ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_broadcast", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "udp_msgs/srv/detail/udp_socket__struct.h"
// already included above
// #include "udp_msgs/srv/detail/udp_socket__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool udp_msgs__srv__udp_socket__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("udp_msgs.srv._udp_socket.UdpSocket_Response", full_classname_dest, 43) == 0);
  }
  udp_msgs__srv__UdpSocket_Response * ros_message = _ros_message;
  {  // socket_created
    PyObject * field = PyObject_GetAttrString(_pymsg, "socket_created");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->socket_created = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * udp_msgs__srv__udp_socket__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UdpSocket_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("udp_msgs.srv._udp_socket");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UdpSocket_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  udp_msgs__srv__UdpSocket_Response * ros_message = (udp_msgs__srv__UdpSocket_Response *)raw_ros_message;
  {  // socket_created
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->socket_created ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "socket_created", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
