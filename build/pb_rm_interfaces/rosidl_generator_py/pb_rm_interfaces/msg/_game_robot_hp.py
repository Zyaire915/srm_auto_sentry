# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/GameRobotHP.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameRobotHP(type):
    """Metaclass of message 'GameRobotHP'."""

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
                'pb_rm_interfaces.msg.GameRobotHP')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_robot_hp
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_robot_hp
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_robot_hp
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_robot_hp
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_robot_hp

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GameRobotHP(metaclass=Metaclass_GameRobotHP):
    """Message class 'GameRobotHP'."""

    __slots__ = [
        '_red_1_robot_hp',
        '_red_2_robot_hp',
        '_red_3_robot_hp',
        '_red_4_robot_hp',
        '_red_5_robot_hp',
        '_red_7_robot_hp',
        '_red_outpost_hp',
        '_red_base_hp',
        '_blue_1_robot_hp',
        '_blue_2_robot_hp',
        '_blue_3_robot_hp',
        '_blue_4_robot_hp',
        '_blue_5_robot_hp',
        '_blue_7_robot_hp',
        '_blue_outpost_hp',
        '_blue_base_hp',
    ]

    _fields_and_field_types = {
        'red_1_robot_hp': 'uint16',
        'red_2_robot_hp': 'uint16',
        'red_3_robot_hp': 'uint16',
        'red_4_robot_hp': 'uint16',
        'red_5_robot_hp': 'uint16',
        'red_7_robot_hp': 'uint16',
        'red_outpost_hp': 'uint16',
        'red_base_hp': 'uint16',
        'blue_1_robot_hp': 'uint16',
        'blue_2_robot_hp': 'uint16',
        'blue_3_robot_hp': 'uint16',
        'blue_4_robot_hp': 'uint16',
        'blue_5_robot_hp': 'uint16',
        'blue_7_robot_hp': 'uint16',
        'blue_outpost_hp': 'uint16',
        'blue_base_hp': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.red_1_robot_hp = kwargs.get('red_1_robot_hp', int())
        self.red_2_robot_hp = kwargs.get('red_2_robot_hp', int())
        self.red_3_robot_hp = kwargs.get('red_3_robot_hp', int())
        self.red_4_robot_hp = kwargs.get('red_4_robot_hp', int())
        self.red_5_robot_hp = kwargs.get('red_5_robot_hp', int())
        self.red_7_robot_hp = kwargs.get('red_7_robot_hp', int())
        self.red_outpost_hp = kwargs.get('red_outpost_hp', int())
        self.red_base_hp = kwargs.get('red_base_hp', int())
        self.blue_1_robot_hp = kwargs.get('blue_1_robot_hp', int())
        self.blue_2_robot_hp = kwargs.get('blue_2_robot_hp', int())
        self.blue_3_robot_hp = kwargs.get('blue_3_robot_hp', int())
        self.blue_4_robot_hp = kwargs.get('blue_4_robot_hp', int())
        self.blue_5_robot_hp = kwargs.get('blue_5_robot_hp', int())
        self.blue_7_robot_hp = kwargs.get('blue_7_robot_hp', int())
        self.blue_outpost_hp = kwargs.get('blue_outpost_hp', int())
        self.blue_base_hp = kwargs.get('blue_base_hp', int())

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
        if self.red_1_robot_hp != other.red_1_robot_hp:
            return False
        if self.red_2_robot_hp != other.red_2_robot_hp:
            return False
        if self.red_3_robot_hp != other.red_3_robot_hp:
            return False
        if self.red_4_robot_hp != other.red_4_robot_hp:
            return False
        if self.red_5_robot_hp != other.red_5_robot_hp:
            return False
        if self.red_7_robot_hp != other.red_7_robot_hp:
            return False
        if self.red_outpost_hp != other.red_outpost_hp:
            return False
        if self.red_base_hp != other.red_base_hp:
            return False
        if self.blue_1_robot_hp != other.blue_1_robot_hp:
            return False
        if self.blue_2_robot_hp != other.blue_2_robot_hp:
            return False
        if self.blue_3_robot_hp != other.blue_3_robot_hp:
            return False
        if self.blue_4_robot_hp != other.blue_4_robot_hp:
            return False
        if self.blue_5_robot_hp != other.blue_5_robot_hp:
            return False
        if self.blue_7_robot_hp != other.blue_7_robot_hp:
            return False
        if self.blue_outpost_hp != other.blue_outpost_hp:
            return False
        if self.blue_base_hp != other.blue_base_hp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def red_1_robot_hp(self):
        """Message field 'red_1_robot_hp'."""
        return self._red_1_robot_hp

    @red_1_robot_hp.setter
    def red_1_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_1_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_1_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_1_robot_hp = value

    @builtins.property
    def red_2_robot_hp(self):
        """Message field 'red_2_robot_hp'."""
        return self._red_2_robot_hp

    @red_2_robot_hp.setter
    def red_2_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_2_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_2_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_2_robot_hp = value

    @builtins.property
    def red_3_robot_hp(self):
        """Message field 'red_3_robot_hp'."""
        return self._red_3_robot_hp

    @red_3_robot_hp.setter
    def red_3_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_3_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_3_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_3_robot_hp = value

    @builtins.property
    def red_4_robot_hp(self):
        """Message field 'red_4_robot_hp'."""
        return self._red_4_robot_hp

    @red_4_robot_hp.setter
    def red_4_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_4_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_4_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_4_robot_hp = value

    @builtins.property
    def red_5_robot_hp(self):
        """Message field 'red_5_robot_hp'."""
        return self._red_5_robot_hp

    @red_5_robot_hp.setter
    def red_5_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_5_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_5_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_5_robot_hp = value

    @builtins.property
    def red_7_robot_hp(self):
        """Message field 'red_7_robot_hp'."""
        return self._red_7_robot_hp

    @red_7_robot_hp.setter
    def red_7_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_7_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_7_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._red_7_robot_hp = value

    @builtins.property
    def red_outpost_hp(self):
        """Message field 'red_outpost_hp'."""
        return self._red_outpost_hp

    @red_outpost_hp.setter
    def red_outpost_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_outpost_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_outpost_hp' field must be an unsigned integer in [0, 65535]"
        self._red_outpost_hp = value

    @builtins.property
    def red_base_hp(self):
        """Message field 'red_base_hp'."""
        return self._red_base_hp

    @red_base_hp.setter
    def red_base_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'red_base_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'red_base_hp' field must be an unsigned integer in [0, 65535]"
        self._red_base_hp = value

    @builtins.property
    def blue_1_robot_hp(self):
        """Message field 'blue_1_robot_hp'."""
        return self._blue_1_robot_hp

    @blue_1_robot_hp.setter
    def blue_1_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_1_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_1_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_1_robot_hp = value

    @builtins.property
    def blue_2_robot_hp(self):
        """Message field 'blue_2_robot_hp'."""
        return self._blue_2_robot_hp

    @blue_2_robot_hp.setter
    def blue_2_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_2_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_2_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_2_robot_hp = value

    @builtins.property
    def blue_3_robot_hp(self):
        """Message field 'blue_3_robot_hp'."""
        return self._blue_3_robot_hp

    @blue_3_robot_hp.setter
    def blue_3_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_3_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_3_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_3_robot_hp = value

    @builtins.property
    def blue_4_robot_hp(self):
        """Message field 'blue_4_robot_hp'."""
        return self._blue_4_robot_hp

    @blue_4_robot_hp.setter
    def blue_4_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_4_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_4_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_4_robot_hp = value

    @builtins.property
    def blue_5_robot_hp(self):
        """Message field 'blue_5_robot_hp'."""
        return self._blue_5_robot_hp

    @blue_5_robot_hp.setter
    def blue_5_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_5_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_5_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_5_robot_hp = value

    @builtins.property
    def blue_7_robot_hp(self):
        """Message field 'blue_7_robot_hp'."""
        return self._blue_7_robot_hp

    @blue_7_robot_hp.setter
    def blue_7_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_7_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_7_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_7_robot_hp = value

    @builtins.property
    def blue_outpost_hp(self):
        """Message field 'blue_outpost_hp'."""
        return self._blue_outpost_hp

    @blue_outpost_hp.setter
    def blue_outpost_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_outpost_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_outpost_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_outpost_hp = value

    @builtins.property
    def blue_base_hp(self):
        """Message field 'blue_base_hp'."""
        return self._blue_base_hp

    @blue_base_hp.setter
    def blue_base_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'blue_base_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'blue_base_hp' field must be an unsigned integer in [0, 65535]"
        self._blue_base_hp = value
