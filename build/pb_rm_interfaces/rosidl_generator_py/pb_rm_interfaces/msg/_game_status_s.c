// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
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
#include "pb_rm_interfaces/msg/detail/game_status__struct.h"
#include "pb_rm_interfaces/msg/detail/game_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool pb_rm_interfaces__msg__game_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("pb_rm_interfaces.msg._game_status.GameStatus", full_classname_dest, 44) == 0);
  }
  pb_rm_interfaces__msg__GameStatus * ros_message = _ros_message;
  {  // game_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "game_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->game_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // game_progress
    PyObject * field = PyObject_GetAttrString(_pymsg, "game_progress");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->game_progress = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // stage_remain_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "stage_remain_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->stage_remain_time = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sync_time_stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "sync_time_stamp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sync_time_stamp = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pb_rm_interfaces__msg__game_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GameStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pb_rm_interfaces.msg._game_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GameStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pb_rm_interfaces__msg__GameStatus * ros_message = (pb_rm_interfaces__msg__GameStatus *)raw_ros_message;
  {  // game_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->game_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "game_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // game_progress
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->game_progress);
    {
      int rc = PyObject_SetAttrString(_pymessage, "game_progress", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stage_remain_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->stage_remain_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stage_remain_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sync_time_stamp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->sync_time_stamp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sync_time_stamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
