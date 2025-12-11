// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rm_decision_interfaces:msg/RfidStatus.idl
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
#include "rm_decision_interfaces/msg/detail/rfid_status__struct.h"
#include "rm_decision_interfaces/msg/detail/rfid_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool rm_decision_interfaces__msg__rfid_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
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
    assert(strncmp("rm_decision_interfaces.msg._rfid_status.RfidStatus", full_classname_dest, 50) == 0);
  }
  rm_decision_interfaces__msg__RfidStatus * ros_message = _ros_message;
  {  // friendly_base_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_base_gain_point");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_base_gain_point = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_central_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_central_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_central_highland_gain_point = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_gain_point");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_central_highland_gain_point = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_trapezoidal_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_trapezoidal_gain_point");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_trapezoidal_gain_point = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_trapezoidal_gain_point
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_trapezoidal_gain_point");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_trapezoidal_gain_point = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_fly_slope_pre_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fly_slope_pre_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_fly_slope_pre_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_fly_slope_post_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fly_slope_post_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_fly_slope_post_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_fly_slope_pre_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_fly_slope_pre_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_fly_slope_pre_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_fly_slope_post_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_fly_slope_post_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_fly_slope_post_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_central_highland_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_central_highland_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_central_highland_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_central_highland_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_central_highland_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_central_highland_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_central_highland_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_central_highland_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_central_highland_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_central_highland_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_highway_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_highway_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_highway_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_highway_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_highway_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_highway_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_highway_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_highway_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_highway_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_highway_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_highway_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_highway_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_fortress_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_fortress_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_fortress_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_outpost_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_outpost_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_outpost_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_supply_zone_non_overlap
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_supply_zone_non_overlap");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_supply_zone_non_overlap = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_supply_zone_overlap
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_supply_zone_overlap");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_supply_zone_overlap = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_energy_mechanism_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_energy_mechanism_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_energy_mechanism_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_energy_mechanism_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_energy_mechanism_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_energy_mechanism_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // center_gain_point_rmul
    PyObject * field = PyObject_GetAttrString(_pymsg, "center_gain_point_rmul");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->center_gain_point_rmul = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_fortress_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_fortress_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_fortress_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_outpost_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_outpost_gain");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_outpost_gain = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_tunnel_highway_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_tunnel_highway_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_tunnel_highway_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_tunnel_highway_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_tunnel_highway_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_tunnel_highway_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_tunnel_trapezoid_low
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_tunnel_trapezoid_low");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_tunnel_trapezoid_low = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // friendly_tunnel_trapezoid_high
    PyObject * field = PyObject_GetAttrString(_pymsg, "friendly_tunnel_trapezoid_high");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->friendly_tunnel_trapezoid_high = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_tunnel_highway_under
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_tunnel_highway_under");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_tunnel_highway_under = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_tunnel_highway_upper
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_tunnel_highway_upper");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_tunnel_highway_upper = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_tunnel_trapezoid_low
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_tunnel_trapezoid_low");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_tunnel_trapezoid_low = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enemy_tunnel_trapezoid_high
    PyObject * field = PyObject_GetAttrString(_pymsg, "enemy_tunnel_trapezoid_high");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enemy_tunnel_trapezoid_high = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rm_decision_interfaces__msg__rfid_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RfidStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rm_decision_interfaces.msg._rfid_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RfidStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rm_decision_interfaces__msg__RfidStatus * ros_message = (rm_decision_interfaces__msg__RfidStatus *)raw_ros_message;
  {  // friendly_base_gain_point
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_base_gain_point);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_base_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_central_highland_gain_point
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_central_highland_gain_point);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_central_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_gain_point
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_central_highland_gain_point);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_trapezoidal_gain_point
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_trapezoidal_gain_point);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_trapezoidal_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_trapezoidal_gain_point
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_trapezoidal_gain_point);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_trapezoidal_gain_point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fly_slope_pre_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_fly_slope_pre_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fly_slope_pre_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fly_slope_post_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_fly_slope_post_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fly_slope_post_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_fly_slope_pre_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_fly_slope_pre_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_fly_slope_pre_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_fly_slope_post_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_fly_slope_post_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_fly_slope_post_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_central_highland_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_central_highland_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_central_highland_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_central_highland_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_central_highland_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_central_highland_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_central_highland_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_central_highland_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_central_highland_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_central_highland_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_highway_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_highway_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_highway_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_highway_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_highway_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_highway_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_highway_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_highway_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_highway_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_highway_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_highway_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_highway_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_fortress_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_fortress_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_fortress_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_outpost_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_outpost_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_outpost_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_supply_zone_non_overlap
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_supply_zone_non_overlap);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_supply_zone_non_overlap", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_supply_zone_overlap
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_supply_zone_overlap);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_supply_zone_overlap", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_energy_mechanism_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_energy_mechanism_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_energy_mechanism_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_energy_mechanism_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_energy_mechanism_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_energy_mechanism_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // center_gain_point_rmul
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->center_gain_point_rmul);
    {
      int rc = PyObject_SetAttrString(_pymessage, "center_gain_point_rmul", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_fortress_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_fortress_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_fortress_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_outpost_gain
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_outpost_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_outpost_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_tunnel_highway_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_tunnel_highway_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_tunnel_highway_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_tunnel_highway_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_tunnel_highway_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_tunnel_highway_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_tunnel_trapezoid_low
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_tunnel_trapezoid_low);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_tunnel_trapezoid_low", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // friendly_tunnel_trapezoid_high
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->friendly_tunnel_trapezoid_high);
    {
      int rc = PyObject_SetAttrString(_pymessage, "friendly_tunnel_trapezoid_high", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_tunnel_highway_under
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_tunnel_highway_under);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_tunnel_highway_under", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_tunnel_highway_upper
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_tunnel_highway_upper);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_tunnel_highway_upper", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_tunnel_trapezoid_low
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_tunnel_trapezoid_low);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_tunnel_trapezoid_low", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enemy_tunnel_trapezoid_high
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enemy_tunnel_trapezoid_high);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enemy_tunnel_trapezoid_high", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
