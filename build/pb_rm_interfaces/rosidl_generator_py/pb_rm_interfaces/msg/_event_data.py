# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/EventData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EventData(type):
    """Metaclass of message 'EventData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pb_rm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pb_rm_interfaces.msg.EventData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__event_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__event_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__event_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__event_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__event_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EventData(metaclass=Metaclass_EventData):
    """Message class 'EventData'."""

    __slots__ = [
        '_supply_zone_non_overlap',
        '_supply_zone_overlap',
        '_supply_zone_rmul',
        '_small_energy_status',
        '_big_energy_status',
        '_central_highland_status',
        '_trapezoidal_highland_status',
        '_dart_last_hit_time',
        '_dart_last_hit_target',
        '_center_gain_point_status',
        '_fortress_gain_point_status',
        '_outpost_gain_point_status',
        '_base_gain_point_status',
    ]

    _fields_and_field_types = {
        'supply_zone_non_overlap': 'uint8',
        'supply_zone_overlap': 'uint8',
        'supply_zone_rmul': 'uint8',
        'small_energy_status': 'uint8',
        'big_energy_status': 'uint8',
        'central_highland_status': 'uint8',
        'trapezoidal_highland_status': 'uint8',
        'dart_last_hit_time': 'uint16',
        'dart_last_hit_target': 'uint8',
        'center_gain_point_status': 'uint8',
        'fortress_gain_point_status': 'uint8',
        'outpost_gain_point_status': 'uint8',
        'base_gain_point_status': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.supply_zone_non_overlap = kwargs.get('supply_zone_non_overlap', int())
        self.supply_zone_overlap = kwargs.get('supply_zone_overlap', int())
        self.supply_zone_rmul = kwargs.get('supply_zone_rmul', int())
        self.small_energy_status = kwargs.get('small_energy_status', int())
        self.big_energy_status = kwargs.get('big_energy_status', int())
        self.central_highland_status = kwargs.get('central_highland_status', int())
        self.trapezoidal_highland_status = kwargs.get('trapezoidal_highland_status', int())
        self.dart_last_hit_time = kwargs.get('dart_last_hit_time', int())
        self.dart_last_hit_target = kwargs.get('dart_last_hit_target', int())
        self.center_gain_point_status = kwargs.get('center_gain_point_status', int())
        self.fortress_gain_point_status = kwargs.get('fortress_gain_point_status', int())
        self.outpost_gain_point_status = kwargs.get('outpost_gain_point_status', int())
        self.base_gain_point_status = kwargs.get('base_gain_point_status', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.supply_zone_non_overlap != other.supply_zone_non_overlap:
            return False
        if self.supply_zone_overlap != other.supply_zone_overlap:
            return False
        if self.supply_zone_rmul != other.supply_zone_rmul:
            return False
        if self.small_energy_status != other.small_energy_status:
            return False
        if self.big_energy_status != other.big_energy_status:
            return False
        if self.central_highland_status != other.central_highland_status:
            return False
        if self.trapezoidal_highland_status != other.trapezoidal_highland_status:
            return False
        if self.dart_last_hit_time != other.dart_last_hit_time:
            return False
        if self.dart_last_hit_target != other.dart_last_hit_target:
            return False
        if self.center_gain_point_status != other.center_gain_point_status:
            return False
        if self.fortress_gain_point_status != other.fortress_gain_point_status:
            return False
        if self.outpost_gain_point_status != other.outpost_gain_point_status:
            return False
        if self.base_gain_point_status != other.base_gain_point_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def supply_zone_non_overlap(self):
        """Message field 'supply_zone_non_overlap'."""
        return self._supply_zone_non_overlap

    @supply_zone_non_overlap.setter
    def supply_zone_non_overlap(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'supply_zone_non_overlap' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_zone_non_overlap' field must be an unsigned integer in [0, 255]"
        self._supply_zone_non_overlap = value

    @builtins.property
    def supply_zone_overlap(self):
        """Message field 'supply_zone_overlap'."""
        return self._supply_zone_overlap

    @supply_zone_overlap.setter
    def supply_zone_overlap(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'supply_zone_overlap' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_zone_overlap' field must be an unsigned integer in [0, 255]"
        self._supply_zone_overlap = value

    @builtins.property
    def supply_zone_rmul(self):
        """Message field 'supply_zone_rmul'."""
        return self._supply_zone_rmul

    @supply_zone_rmul.setter
    def supply_zone_rmul(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'supply_zone_rmul' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'supply_zone_rmul' field must be an unsigned integer in [0, 255]"
        self._supply_zone_rmul = value

    @builtins.property
    def small_energy_status(self):
        """Message field 'small_energy_status'."""
        return self._small_energy_status

    @small_energy_status.setter
    def small_energy_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'small_energy_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'small_energy_status' field must be an unsigned integer in [0, 255]"
        self._small_energy_status = value

    @builtins.property
    def big_energy_status(self):
        """Message field 'big_energy_status'."""
        return self._big_energy_status

    @big_energy_status.setter
    def big_energy_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'big_energy_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'big_energy_status' field must be an unsigned integer in [0, 255]"
        self._big_energy_status = value

    @builtins.property
    def central_highland_status(self):
        """Message field 'central_highland_status'."""
        return self._central_highland_status

    @central_highland_status.setter
    def central_highland_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'central_highland_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'central_highland_status' field must be an unsigned integer in [0, 255]"
        self._central_highland_status = value

    @builtins.property
    def trapezoidal_highland_status(self):
        """Message field 'trapezoidal_highland_status'."""
        return self._trapezoidal_highland_status

    @trapezoidal_highland_status.setter
    def trapezoidal_highland_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trapezoidal_highland_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trapezoidal_highland_status' field must be an unsigned integer in [0, 255]"
        self._trapezoidal_highland_status = value

    @builtins.property
    def dart_last_hit_time(self):
        """Message field 'dart_last_hit_time'."""
        return self._dart_last_hit_time

    @dart_last_hit_time.setter
    def dart_last_hit_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dart_last_hit_time' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'dart_last_hit_time' field must be an unsigned integer in [0, 65535]"
        self._dart_last_hit_time = value

    @builtins.property
    def dart_last_hit_target(self):
        """Message field 'dart_last_hit_target'."""
        return self._dart_last_hit_target

    @dart_last_hit_target.setter
    def dart_last_hit_target(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dart_last_hit_target' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dart_last_hit_target' field must be an unsigned integer in [0, 255]"
        self._dart_last_hit_target = value

    @builtins.property
    def center_gain_point_status(self):
        """Message field 'center_gain_point_status'."""
        return self._center_gain_point_status

    @center_gain_point_status.setter
    def center_gain_point_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_gain_point_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'center_gain_point_status' field must be an unsigned integer in [0, 255]"
        self._center_gain_point_status = value

    @builtins.property
    def fortress_gain_point_status(self):
        """Message field 'fortress_gain_point_status'."""
        return self._fortress_gain_point_status

    @fortress_gain_point_status.setter
    def fortress_gain_point_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fortress_gain_point_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fortress_gain_point_status' field must be an unsigned integer in [0, 255]"
        self._fortress_gain_point_status = value

    @builtins.property
    def outpost_gain_point_status(self):
        """Message field 'outpost_gain_point_status'."""
        return self._outpost_gain_point_status

    @outpost_gain_point_status.setter
    def outpost_gain_point_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'outpost_gain_point_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'outpost_gain_point_status' field must be an unsigned integer in [0, 255]"
        self._outpost_gain_point_status = value

    @builtins.property
    def base_gain_point_status(self):
        """Message field 'base_gain_point_status'."""
        return self._base_gain_point_status

    @base_gain_point_status.setter
    def base_gain_point_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'base_gain_point_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'base_gain_point_status' field must be an unsigned integer in [0, 255]"
        self._base_gain_point_status = value
