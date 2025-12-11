// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_decision_interfaces:msg/GameRobotHP.idl
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
#include "rm_decision_interfaces/msg/detail/game_robot_hp__struct.h"
#include "rm_decision_interfaces/msg/detail/game_robot_hp__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_decision_interfaces__msg__game_robot_hp__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
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
    assert(strncmp("rm_decision_interfaces.msg._game_robot_hp.GameRobotHP", full_classname_dest, 53) == 0);
  }
  rm_decision_interfaces__msg__GameRobotHP * ros_message = _ros_message;
  {  // red_1_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_1_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_1_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_2_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_2_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_2_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_3_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_3_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_3_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_4_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_4_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_4_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_5_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_5_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_5_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_7_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_7_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_7_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_outpost_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_outpost_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_outpost_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // red_base_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "red_base_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->red_base_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_1_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_1_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_1_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_2_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_2_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_2_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_3_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_3_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_3_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_4_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_4_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_4_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_5_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_5_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_5_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_7_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_7_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_7_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_outpost_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_outpost_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_outpost_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // blue_base_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "blue_base_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->blue_base_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_decision_interfaces__msg__game_robot_hp__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GameRobotHP */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_decision_interfaces.msg._game_robot_hp");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GameRobotHP");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_decision_interfaces__msg__GameRobotHP * ros_message = (rm_decision_interfaces__msg__GameRobotHP *)raw_ros_message;
  {  // red_1_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_1_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_1_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_2_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_2_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_2_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_3_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_3_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_3_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_4_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_4_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_4_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_5_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_5_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_5_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_7_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_7_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_7_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_outpost_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_outpost_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_outpost_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // red_base_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->red_base_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "red_base_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_1_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_1_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_1_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_2_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_2_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_2_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_3_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_3_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_3_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_4_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_4_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_4_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_5_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_5_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_5_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_7_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_7_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_7_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_outpost_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_outpost_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_outpost_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blue_base_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->blue_base_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "blue_base_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
