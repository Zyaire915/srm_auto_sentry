# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:pb_rm_interfaces__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:pb_rm_interfaces__rosidl_typesupport_fastrtps_c;__rosidl_typesupport_introspection_c:pb_rm_interfaces__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:pb_rm_interfaces__rosidl_typesupport_c;__rosidl_generator_cpp:pb_rm_interfaces__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:pb_rm_interfaces__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_cpp:pb_rm_interfaces__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:pb_rm_interfaces__rosidl_typesupport_cpp;__rosidl_generator_py:pb_rm_interfaces__rosidl_generator_py")

# populate pb_rm_interfaces_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "pb_rm_interfaces::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'pb_rm_interfaces' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND pb_rm_interfaces_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
