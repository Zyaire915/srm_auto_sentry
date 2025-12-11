# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/RfidStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RfidStatus(type):
    """Metaclass of message 'RfidStatus'."""

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
                'pb_rm_interfaces.msg.RfidStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rfid_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rfid_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rfid_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rfid_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rfid_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RfidStatus(metaclass=Metaclass_RfidStatus):
    """Message class 'RfidStatus'."""

    __slots__ = [
        '_friendly_base_gain_point',
        '_friendly_central_highland_gain_point',
        '_enemy_central_highland_gain_point',
        '_friendly_trapezoidal_gain_point',
        '_enemy_trapezoidal_gain_point',
        '_friendly_fly_slope_pre_gain',
        '_friendly_fly_slope_post_gain',
        '_enemy_fly_slope_pre_gain',
        '_enemy_fly_slope_post_gain',
        '_friendly_central_highland_under',
        '_friendly_central_highland_upper',
        '_enemy_central_highland_under',
        '_enemy_central_highland_upper',
        '_friendly_highway_under',
        '_friendly_highway_upper',
        '_enemy_highway_under',
        '_enemy_highway_upper',
        '_friendly_fortress_gain',
        '_friendly_outpost_gain',
        '_friendly_supply_zone_non_overlap',
        '_friendly_supply_zone_overlap',
        '_friendly_energy_mechanism_gain',
        '_enemy_energy_mechanism_gain',
        '_center_gain_point_rmul',
        '_enemy_fortress_gain',
        '_enemy_outpost_gain',
        '_friendly_tunnel_highway_under',
        '_friendly_tunnel_highway_upper',
        '_friendly_tunnel_trapezoid_low',
        '_friendly_tunnel_trapezoid_high',
        '_enemy_tunnel_highway_under',
        '_enemy_tunnel_highway_upper',
        '_enemy_tunnel_trapezoid_low',
        '_enemy_tunnel_trapezoid_high',
    ]

    _fields_and_field_types = {
        'friendly_base_gain_point': 'uint8',
        'friendly_central_highland_gain_point': 'uint8',
        'enemy_central_highland_gain_point': 'uint8',
        'friendly_trapezoidal_gain_point': 'uint8',
        'enemy_trapezoidal_gain_point': 'uint8',
        'friendly_fly_slope_pre_gain': 'uint8',
        'friendly_fly_slope_post_gain': 'uint8',
        'enemy_fly_slope_pre_gain': 'uint8',
        'enemy_fly_slope_post_gain': 'uint8',
        'friendly_central_highland_under': 'uint8',
        'friendly_central_highland_upper': 'uint8',
        'enemy_central_highland_under': 'uint8',
        'enemy_central_highland_upper': 'uint8',
        'friendly_highway_under': 'uint8',
        'friendly_highway_upper': 'uint8',
        'enemy_highway_under': 'uint8',
        'enemy_highway_upper': 'uint8',
        'friendly_fortress_gain': 'uint8',
        'friendly_outpost_gain': 'uint8',
        'friendly_supply_zone_non_overlap': 'uint8',
        'friendly_supply_zone_overlap': 'uint8',
        'friendly_energy_mechanism_gain': 'uint8',
        'enemy_energy_mechanism_gain': 'uint8',
        'center_gain_point_rmul': 'uint8',
        'enemy_fortress_gain': 'uint8',
        'enemy_outpost_gain': 'uint8',
        'friendly_tunnel_highway_under': 'uint8',
        'friendly_tunnel_highway_upper': 'uint8',
        'friendly_tunnel_trapezoid_low': 'uint8',
        'friendly_tunnel_trapezoid_high': 'uint8',
        'enemy_tunnel_highway_under': 'uint8',
        'enemy_tunnel_highway_upper': 'uint8',
        'enemy_tunnel_trapezoid_low': 'uint8',
        'enemy_tunnel_trapezoid_high': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.friendly_base_gain_point = kwargs.get('friendly_base_gain_point', int())
        self.friendly_central_highland_gain_point = kwargs.get('friendly_central_highland_gain_point', int())
        self.enemy_central_highland_gain_point = kwargs.get('enemy_central_highland_gain_point', int())
        self.friendly_trapezoidal_gain_point = kwargs.get('friendly_trapezoidal_gain_point', int())
        self.enemy_trapezoidal_gain_point = kwargs.get('enemy_trapezoidal_gain_point', int())
        self.friendly_fly_slope_pre_gain = kwargs.get('friendly_fly_slope_pre_gain', int())
        self.friendly_fly_slope_post_gain = kwargs.get('friendly_fly_slope_post_gain', int())
        self.enemy_fly_slope_pre_gain = kwargs.get('enemy_fly_slope_pre_gain', int())
        self.enemy_fly_slope_post_gain = kwargs.get('enemy_fly_slope_post_gain', int())
        self.friendly_central_highland_under = kwargs.get('friendly_central_highland_under', int())
        self.friendly_central_highland_upper = kwargs.get('friendly_central_highland_upper', int())
        self.enemy_central_highland_under = kwargs.get('enemy_central_highland_under', int())
        self.enemy_central_highland_upper = kwargs.get('enemy_central_highland_upper', int())
        self.friendly_highway_under = kwargs.get('friendly_highway_under', int())
        self.friendly_highway_upper = kwargs.get('friendly_highway_upper', int())
        self.enemy_highway_under = kwargs.get('enemy_highway_under', int())
        self.enemy_highway_upper = kwargs.get('enemy_highway_upper', int())
        self.friendly_fortress_gain = kwargs.get('friendly_fortress_gain', int())
        self.friendly_outpost_gain = kwargs.get('friendly_outpost_gain', int())
        self.friendly_supply_zone_non_overlap = kwargs.get('friendly_supply_zone_non_overlap', int())
        self.friendly_supply_zone_overlap = kwargs.get('friendly_supply_zone_overlap', int())
        self.friendly_energy_mechanism_gain = kwargs.get('friendly_energy_mechanism_gain', int())
        self.enemy_energy_mechanism_gain = kwargs.get('enemy_energy_mechanism_gain', int())
        self.center_gain_point_rmul = kwargs.get('center_gain_point_rmul', int())
        self.enemy_fortress_gain = kwargs.get('enemy_fortress_gain', int())
        self.enemy_outpost_gain = kwargs.get('enemy_outpost_gain', int())
        self.friendly_tunnel_highway_under = kwargs.get('friendly_tunnel_highway_under', int())
        self.friendly_tunnel_highway_upper = kwargs.get('friendly_tunnel_highway_upper', int())
        self.friendly_tunnel_trapezoid_low = kwargs.get('friendly_tunnel_trapezoid_low', int())
        self.friendly_tunnel_trapezoid_high = kwargs.get('friendly_tunnel_trapezoid_high', int())
        self.enemy_tunnel_highway_under = kwargs.get('enemy_tunnel_highway_under', int())
        self.enemy_tunnel_highway_upper = kwargs.get('enemy_tunnel_highway_upper', int())
        self.enemy_tunnel_trapezoid_low = kwargs.get('enemy_tunnel_trapezoid_low', int())
        self.enemy_tunnel_trapezoid_high = kwargs.get('enemy_tunnel_trapezoid_high', int())

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
        if self.friendly_base_gain_point != other.friendly_base_gain_point:
            return False
        if self.friendly_central_highland_gain_point != other.friendly_central_highland_gain_point:
            return False
        if self.enemy_central_highland_gain_point != other.enemy_central_highland_gain_point:
            return False
        if self.friendly_trapezoidal_gain_point != other.friendly_trapezoidal_gain_point:
            return False
        if self.enemy_trapezoidal_gain_point != other.enemy_trapezoidal_gain_point:
            return False
        if self.friendly_fly_slope_pre_gain != other.friendly_fly_slope_pre_gain:
            return False
        if self.friendly_fly_slope_post_gain != other.friendly_fly_slope_post_gain:
            return False
        if self.enemy_fly_slope_pre_gain != other.enemy_fly_slope_pre_gain:
            return False
        if self.enemy_fly_slope_post_gain != other.enemy_fly_slope_post_gain:
            return False
        if self.friendly_central_highland_under != other.friendly_central_highland_under:
            return False
        if self.friendly_central_highland_upper != other.friendly_central_highland_upper:
            return False
        if self.enemy_central_highland_under != other.enemy_central_highland_under:
            return False
        if self.enemy_central_highland_upper != other.enemy_central_highland_upper:
            return False
        if self.friendly_highway_under != other.friendly_highway_under:
            return False
        if self.friendly_highway_upper != other.friendly_highway_upper:
            return False
        if self.enemy_highway_under != other.enemy_highway_under:
            return False
        if self.enemy_highway_upper != other.enemy_highway_upper:
            return False
        if self.friendly_fortress_gain != other.friendly_fortress_gain:
            return False
        if self.friendly_outpost_gain != other.friendly_outpost_gain:
            return False
        if self.friendly_supply_zone_non_overlap != other.friendly_supply_zone_non_overlap:
            return False
        if self.friendly_supply_zone_overlap != other.friendly_supply_zone_overlap:
            return False
        if self.friendly_energy_mechanism_gain != other.friendly_energy_mechanism_gain:
            return False
        if self.enemy_energy_mechanism_gain != other.enemy_energy_mechanism_gain:
            return False
        if self.center_gain_point_rmul != other.center_gain_point_rmul:
            return False
        if self.enemy_fortress_gain != other.enemy_fortress_gain:
            return False
        if self.enemy_outpost_gain != other.enemy_outpost_gain:
            return False
        if self.friendly_tunnel_highway_under != other.friendly_tunnel_highway_under:
            return False
        if self.friendly_tunnel_highway_upper != other.friendly_tunnel_highway_upper:
            return False
        if self.friendly_tunnel_trapezoid_low != other.friendly_tunnel_trapezoid_low:
            return False
        if self.friendly_tunnel_trapezoid_high != other.friendly_tunnel_trapezoid_high:
            return False
        if self.enemy_tunnel_highway_under != other.enemy_tunnel_highway_under:
            return False
        if self.enemy_tunnel_highway_upper != other.enemy_tunnel_highway_upper:
            return False
        if self.enemy_tunnel_trapezoid_low != other.enemy_tunnel_trapezoid_low:
            return False
        if self.enemy_tunnel_trapezoid_high != other.enemy_tunnel_trapezoid_high:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def friendly_base_gain_point(self):
        """Message field 'friendly_base_gain_point'."""
        return self._friendly_base_gain_point

    @friendly_base_gain_point.setter
    def friendly_base_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_base_gain_point' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_base_gain_point' field must be an unsigned integer in [0, 255]"
        self._friendly_base_gain_point = value

    @builtins.property
    def friendly_central_highland_gain_point(self):
        """Message field 'friendly_central_highland_gain_point'."""
        return self._friendly_central_highland_gain_point

    @friendly_central_highland_gain_point.setter
    def friendly_central_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_central_highland_gain_point' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_central_highland_gain_point' field must be an unsigned integer in [0, 255]"
        self._friendly_central_highland_gain_point = value

    @builtins.property
    def enemy_central_highland_gain_point(self):
        """Message field 'enemy_central_highland_gain_point'."""
        return self._enemy_central_highland_gain_point

    @enemy_central_highland_gain_point.setter
    def enemy_central_highland_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_central_highland_gain_point' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_central_highland_gain_point' field must be an unsigned integer in [0, 255]"
        self._enemy_central_highland_gain_point = value

    @builtins.property
    def friendly_trapezoidal_gain_point(self):
        """Message field 'friendly_trapezoidal_gain_point'."""
        return self._friendly_trapezoidal_gain_point

    @friendly_trapezoidal_gain_point.setter
    def friendly_trapezoidal_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_trapezoidal_gain_point' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_trapezoidal_gain_point' field must be an unsigned integer in [0, 255]"
        self._friendly_trapezoidal_gain_point = value

    @builtins.property
    def enemy_trapezoidal_gain_point(self):
        """Message field 'enemy_trapezoidal_gain_point'."""
        return self._enemy_trapezoidal_gain_point

    @enemy_trapezoidal_gain_point.setter
    def enemy_trapezoidal_gain_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_trapezoidal_gain_point' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_trapezoidal_gain_point' field must be an unsigned integer in [0, 255]"
        self._enemy_trapezoidal_gain_point = value

    @builtins.property
    def friendly_fly_slope_pre_gain(self):
        """Message field 'friendly_fly_slope_pre_gain'."""
        return self._friendly_fly_slope_pre_gain

    @friendly_fly_slope_pre_gain.setter
    def friendly_fly_slope_pre_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_fly_slope_pre_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_fly_slope_pre_gain' field must be an unsigned integer in [0, 255]"
        self._friendly_fly_slope_pre_gain = value

    @builtins.property
    def friendly_fly_slope_post_gain(self):
        """Message field 'friendly_fly_slope_post_gain'."""
        return self._friendly_fly_slope_post_gain

    @friendly_fly_slope_post_gain.setter
    def friendly_fly_slope_post_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_fly_slope_post_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_fly_slope_post_gain' field must be an unsigned integer in [0, 255]"
        self._friendly_fly_slope_post_gain = value

    @builtins.property
    def enemy_fly_slope_pre_gain(self):
        """Message field 'enemy_fly_slope_pre_gain'."""
        return self._enemy_fly_slope_pre_gain

    @enemy_fly_slope_pre_gain.setter
    def enemy_fly_slope_pre_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_fly_slope_pre_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_fly_slope_pre_gain' field must be an unsigned integer in [0, 255]"
        self._enemy_fly_slope_pre_gain = value

    @builtins.property
    def enemy_fly_slope_post_gain(self):
        """Message field 'enemy_fly_slope_post_gain'."""
        return self._enemy_fly_slope_post_gain

    @enemy_fly_slope_post_gain.setter
    def enemy_fly_slope_post_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_fly_slope_post_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_fly_slope_post_gain' field must be an unsigned integer in [0, 255]"
        self._enemy_fly_slope_post_gain = value

    @builtins.property
    def friendly_central_highland_under(self):
        """Message field 'friendly_central_highland_under'."""
        return self._friendly_central_highland_under

    @friendly_central_highland_under.setter
    def friendly_central_highland_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_central_highland_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_central_highland_under' field must be an unsigned integer in [0, 255]"
        self._friendly_central_highland_under = value

    @builtins.property
    def friendly_central_highland_upper(self):
        """Message field 'friendly_central_highland_upper'."""
        return self._friendly_central_highland_upper

    @friendly_central_highland_upper.setter
    def friendly_central_highland_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_central_highland_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_central_highland_upper' field must be an unsigned integer in [0, 255]"
        self._friendly_central_highland_upper = value

    @builtins.property
    def enemy_central_highland_under(self):
        """Message field 'enemy_central_highland_under'."""
        return self._enemy_central_highland_under

    @enemy_central_highland_under.setter
    def enemy_central_highland_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_central_highland_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_central_highland_under' field must be an unsigned integer in [0, 255]"
        self._enemy_central_highland_under = value

    @builtins.property
    def enemy_central_highland_upper(self):
        """Message field 'enemy_central_highland_upper'."""
        return self._enemy_central_highland_upper

    @enemy_central_highland_upper.setter
    def enemy_central_highland_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_central_highland_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_central_highland_upper' field must be an unsigned integer in [0, 255]"
        self._enemy_central_highland_upper = value

    @builtins.property
    def friendly_highway_under(self):
        """Message field 'friendly_highway_under'."""
        return self._friendly_highway_under

    @friendly_highway_under.setter
    def friendly_highway_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_highway_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_highway_under' field must be an unsigned integer in [0, 255]"
        self._friendly_highway_under = value

    @builtins.property
    def friendly_highway_upper(self):
        """Message field 'friendly_highway_upper'."""
        return self._friendly_highway_upper

    @friendly_highway_upper.setter
    def friendly_highway_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_highway_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_highway_upper' field must be an unsigned integer in [0, 255]"
        self._friendly_highway_upper = value

    @builtins.property
    def enemy_highway_under(self):
        """Message field 'enemy_highway_under'."""
        return self._enemy_highway_under

    @enemy_highway_under.setter
    def enemy_highway_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_highway_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_highway_under' field must be an unsigned integer in [0, 255]"
        self._enemy_highway_under = value

    @builtins.property
    def enemy_highway_upper(self):
        """Message field 'enemy_highway_upper'."""
        return self._enemy_highway_upper

    @enemy_highway_upper.setter
    def enemy_highway_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_highway_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_highway_upper' field must be an unsigned integer in [0, 255]"
        self._enemy_highway_upper = value

    @builtins.property
    def friendly_fortress_gain(self):
        """Message field 'friendly_fortress_gain'."""
        return self._friendly_fortress_gain

    @friendly_fortress_gain.setter
    def friendly_fortress_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_fortress_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_fortress_gain' field must be an unsigned integer in [0, 255]"
        self._friendly_fortress_gain = value

    @builtins.property
    def friendly_outpost_gain(self):
        """Message field 'friendly_outpost_gain'."""
        return self._friendly_outpost_gain

    @friendly_outpost_gain.setter
    def friendly_outpost_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_outpost_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_outpost_gain' field must be an unsigned integer in [0, 255]"
        self._friendly_outpost_gain = value

    @builtins.property
    def friendly_supply_zone_non_overlap(self):
        """Message field 'friendly_supply_zone_non_overlap'."""
        return self._friendly_supply_zone_non_overlap

    @friendly_supply_zone_non_overlap.setter
    def friendly_supply_zone_non_overlap(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_supply_zone_non_overlap' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_supply_zone_non_overlap' field must be an unsigned integer in [0, 255]"
        self._friendly_supply_zone_non_overlap = value

    @builtins.property
    def friendly_supply_zone_overlap(self):
        """Message field 'friendly_supply_zone_overlap'."""
        return self._friendly_supply_zone_overlap

    @friendly_supply_zone_overlap.setter
    def friendly_supply_zone_overlap(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_supply_zone_overlap' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_supply_zone_overlap' field must be an unsigned integer in [0, 255]"
        self._friendly_supply_zone_overlap = value

    @builtins.property
    def friendly_energy_mechanism_gain(self):
        """Message field 'friendly_energy_mechanism_gain'."""
        return self._friendly_energy_mechanism_gain

    @friendly_energy_mechanism_gain.setter
    def friendly_energy_mechanism_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_energy_mechanism_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_energy_mechanism_gain' field must be an unsigned integer in [0, 255]"
        self._friendly_energy_mechanism_gain = value

    @builtins.property
    def enemy_energy_mechanism_gain(self):
        """Message field 'enemy_energy_mechanism_gain'."""
        return self._enemy_energy_mechanism_gain

    @enemy_energy_mechanism_gain.setter
    def enemy_energy_mechanism_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_energy_mechanism_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_energy_mechanism_gain' field must be an unsigned integer in [0, 255]"
        self._enemy_energy_mechanism_gain = value

    @builtins.property
    def center_gain_point_rmul(self):
        """Message field 'center_gain_point_rmul'."""
        return self._center_gain_point_rmul

    @center_gain_point_rmul.setter
    def center_gain_point_rmul(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'center_gain_point_rmul' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'center_gain_point_rmul' field must be an unsigned integer in [0, 255]"
        self._center_gain_point_rmul = value

    @builtins.property
    def enemy_fortress_gain(self):
        """Message field 'enemy_fortress_gain'."""
        return self._enemy_fortress_gain

    @enemy_fortress_gain.setter
    def enemy_fortress_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_fortress_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_fortress_gain' field must be an unsigned integer in [0, 255]"
        self._enemy_fortress_gain = value

    @builtins.property
    def enemy_outpost_gain(self):
        """Message field 'enemy_outpost_gain'."""
        return self._enemy_outpost_gain

    @enemy_outpost_gain.setter
    def enemy_outpost_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_outpost_gain' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_outpost_gain' field must be an unsigned integer in [0, 255]"
        self._enemy_outpost_gain = value

    @builtins.property
    def friendly_tunnel_highway_under(self):
        """Message field 'friendly_tunnel_highway_under'."""
        return self._friendly_tunnel_highway_under

    @friendly_tunnel_highway_under.setter
    def friendly_tunnel_highway_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_tunnel_highway_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_tunnel_highway_under' field must be an unsigned integer in [0, 255]"
        self._friendly_tunnel_highway_under = value

    @builtins.property
    def friendly_tunnel_highway_upper(self):
        """Message field 'friendly_tunnel_highway_upper'."""
        return self._friendly_tunnel_highway_upper

    @friendly_tunnel_highway_upper.setter
    def friendly_tunnel_highway_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_tunnel_highway_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_tunnel_highway_upper' field must be an unsigned integer in [0, 255]"
        self._friendly_tunnel_highway_upper = value

    @builtins.property
    def friendly_tunnel_trapezoid_low(self):
        """Message field 'friendly_tunnel_trapezoid_low'."""
        return self._friendly_tunnel_trapezoid_low

    @friendly_tunnel_trapezoid_low.setter
    def friendly_tunnel_trapezoid_low(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_tunnel_trapezoid_low' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_tunnel_trapezoid_low' field must be an unsigned integer in [0, 255]"
        self._friendly_tunnel_trapezoid_low = value

    @builtins.property
    def friendly_tunnel_trapezoid_high(self):
        """Message field 'friendly_tunnel_trapezoid_high'."""
        return self._friendly_tunnel_trapezoid_high

    @friendly_tunnel_trapezoid_high.setter
    def friendly_tunnel_trapezoid_high(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'friendly_tunnel_trapezoid_high' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'friendly_tunnel_trapezoid_high' field must be an unsigned integer in [0, 255]"
        self._friendly_tunnel_trapezoid_high = value

    @builtins.property
    def enemy_tunnel_highway_under(self):
        """Message field 'enemy_tunnel_highway_under'."""
        return self._enemy_tunnel_highway_under

    @enemy_tunnel_highway_under.setter
    def enemy_tunnel_highway_under(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_tunnel_highway_under' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_tunnel_highway_under' field must be an unsigned integer in [0, 255]"
        self._enemy_tunnel_highway_under = value

    @builtins.property
    def enemy_tunnel_highway_upper(self):
        """Message field 'enemy_tunnel_highway_upper'."""
        return self._enemy_tunnel_highway_upper

    @enemy_tunnel_highway_upper.setter
    def enemy_tunnel_highway_upper(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_tunnel_highway_upper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_tunnel_highway_upper' field must be an unsigned integer in [0, 255]"
        self._enemy_tunnel_highway_upper = value

    @builtins.property
    def enemy_tunnel_trapezoid_low(self):
        """Message field 'enemy_tunnel_trapezoid_low'."""
        return self._enemy_tunnel_trapezoid_low

    @enemy_tunnel_trapezoid_low.setter
    def enemy_tunnel_trapezoid_low(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_tunnel_trapezoid_low' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_tunnel_trapezoid_low' field must be an unsigned integer in [0, 255]"
        self._enemy_tunnel_trapezoid_low = value

    @builtins.property
    def enemy_tunnel_trapezoid_high(self):
        """Message field 'enemy_tunnel_trapezoid_high'."""
        return self._enemy_tunnel_trapezoid_high

    @enemy_tunnel_trapezoid_high.setter
    def enemy_tunnel_trapezoid_high(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enemy_tunnel_trapezoid_high' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enemy_tunnel_trapezoid_high' field must be an unsigned integer in [0, 255]"
        self._enemy_tunnel_trapezoid_high = value
