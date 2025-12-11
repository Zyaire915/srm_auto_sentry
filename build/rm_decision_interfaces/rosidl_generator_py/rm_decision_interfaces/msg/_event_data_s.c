// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_decision_interfaces:msg/EventData.idl
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
#include "rm_decision_interfaces/msg/detail/event_data__struct.h"
#include "rm_decision_interfaces/msg/detail/event_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_decision_interfaces__msg__event_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("rm_decision_interfaces.msg._event_data.EventData", full_classname_dest, 48) == 0);
  }
  rm_decision_interfaces__msg__EventData * ros_message = _ros_message;
  {  // supply_zone_non_overlap
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_zone_non_overlap");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_zone_non_overlap = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // supply_zone_overlap
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_zone_overlap");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_zone_overlap = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // supply_zone_rmul
    PyObject * field = PyObject_GetAttrString(_pymsg, "supply_zone_rmul");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->supply_zone_rmul = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // small_energy_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "small_energy_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->small_energy_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // big_energy_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "big_energy_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->big_energy_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // central_highland_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "central_highland_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->central_highland_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trapezoidal_highland_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "trapezoidal_highland_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trapezoidal_highland_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dart_last_hit_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "dart_last_hit_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dart_last_hit_time = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // dart_last_hit_target
    PyObject * field = PyObject_GetAttrString(_pymsg, "dart_last_hit_target");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->dart_last_hit_target = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // center_gain_point_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_gain_point_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_gain_point_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fortress_gain_point_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "fortress_gain_point_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fortress_gain_point_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // outpost_gain_point_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "outpost_gain_point_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->outpost_gain_point_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // base_gain_point_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "base_gain_point_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->base_gain_point_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_decision_interfaces__msg__event_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EventData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_decision_interfaces.msg._event_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EventData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_decision_interfaces__msg__EventData * ros_message = (rm_decision_interfaces__msg__EventData *)raw_ros_message;
  {  // supply_zone_non_overlap
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_zone_non_overlap);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_zone_non_overlap", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // supply_zone_overlap
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_zone_overlap);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_zone_overlap", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // supply_zone_rmul
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->supply_zone_rmul);
    {
      int rc = PyObject_SetAttrString(_pymessage, "supply_zone_rmul", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // small_energy_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->small_energy_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "small_energy_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // big_energy_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->big_energy_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "big_energy_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // central_highland_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->central_highland_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "central_highland_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trapezoidal_highland_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trapezoidal_highland_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trapezoidal_highland_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dart_last_hit_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dart_last_hit_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dart_last_hit_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dart_last_hit_target
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->dart_last_hit_target);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dart_last_hit_target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_gain_point_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->center_gain_point_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_gain_point_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fortress_gain_point_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fortress_gain_point_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fortress_gain_point_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // outpost_gain_point_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->outpost_gain_point_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "outpost_gain_point_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // base_gain_point_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->base_gain_point_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "base_gain_point_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
