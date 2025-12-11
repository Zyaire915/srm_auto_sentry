// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_decision_interfaces:msg/AllyRobotHP.idl
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
#include "rm_decision_interfaces/msg/detail/ally_robot_hp__struct.h"
#include "rm_decision_interfaces/msg/detail/ally_robot_hp__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_decision_interfaces__msg__ally_robot_hp__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("rm_decision_interfaces.msg._ally_robot_hp.AllyRobotHP", full_classname_dest, 53) == 0);
  }
  rm_decision_interfaces__msg__AllyRobotHP * ros_message = _ros_message;
  {  // ally_1_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_1_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_1_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_2_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_2_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_2_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_3_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_3_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_3_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_4_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_4_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_4_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_7_robot_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_7_robot_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_7_robot_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_outpost_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_outpost_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_outpost_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ally_base_hp
    PyObject * field = PyObject_GetAttrString(_pymsg, "ally_base_hp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ally_base_hp = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_decision_interfaces__msg__ally_robot_hp__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AllyRobotHP */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_decision_interfaces.msg._ally_robot_hp");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AllyRobotHP");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_decision_interfaces__msg__AllyRobotHP * ros_message = (rm_decision_interfaces__msg__AllyRobotHP *)raw_ros_message;
  {  // ally_1_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_1_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_1_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_2_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_2_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_2_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_3_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_3_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_3_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_4_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_4_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_4_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_7_robot_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_7_robot_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_7_robot_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_outpost_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_outpost_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_outpost_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ally_base_hp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ally_base_hp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ally_base_hp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
