# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_decision_interfaces:msg/AllyRobotHP.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AllyRobotHP(type):
    """Metaclass of message 'AllyRobotHP'."""

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
            module = import_type_support('rm_decision_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_decision_interfaces.msg.AllyRobotHP')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ally_robot_hp
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ally_robot_hp
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ally_robot_hp
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ally_robot_hp
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ally_robot_hp

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AllyRobotHP(metaclass=Metaclass_AllyRobotHP):
    """Message class 'AllyRobotHP'."""

    __slots__ = [
        '_ally_1_robot_hp',
        '_ally_2_robot_hp',
        '_ally_3_robot_hp',
        '_ally_4_robot_hp',
        '_ally_7_robot_hp',
        '_ally_outpost_hp',
        '_ally_base_hp',
    ]

    _fields_and_field_types = {
        'ally_1_robot_hp': 'uint16',
        'ally_2_robot_hp': 'uint16',
        'ally_3_robot_hp': 'uint16',
        'ally_4_robot_hp': 'uint16',
        'ally_7_robot_hp': 'uint16',
        'ally_outpost_hp': 'uint16',
        'ally_base_hp': 'uint16',
    }

    SLOT_TYPES = (
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
        self.ally_1_robot_hp = kwargs.get('ally_1_robot_hp', int())
        self.ally_2_robot_hp = kwargs.get('ally_2_robot_hp', int())
        self.ally_3_robot_hp = kwargs.get('ally_3_robot_hp', int())
        self.ally_4_robot_hp = kwargs.get('ally_4_robot_hp', int())
        self.ally_7_robot_hp = kwargs.get('ally_7_robot_hp', int())
        self.ally_outpost_hp = kwargs.get('ally_outpost_hp', int())
        self.ally_base_hp = kwargs.get('ally_base_hp', int())

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
        if self.ally_1_robot_hp != other.ally_1_robot_hp:
            return False
        if self.ally_2_robot_hp != other.ally_2_robot_hp:
            return False
        if self.ally_3_robot_hp != other.ally_3_robot_hp:
            return False
        if self.ally_4_robot_hp != other.ally_4_robot_hp:
            return False
        if self.ally_7_robot_hp != other.ally_7_robot_hp:
            return False
        if self.ally_outpost_hp != other.ally_outpost_hp:
            return False
        if self.ally_base_hp != other.ally_base_hp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ally_1_robot_hp(self):
        """Message field 'ally_1_robot_hp'."""
        return self._ally_1_robot_hp

    @ally_1_robot_hp.setter
    def ally_1_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_1_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_1_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_1_robot_hp = value

    @builtins.property
    def ally_2_robot_hp(self):
        """Message field 'ally_2_robot_hp'."""
        return self._ally_2_robot_hp

    @ally_2_robot_hp.setter
    def ally_2_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_2_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_2_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_2_robot_hp = value

    @builtins.property
    def ally_3_robot_hp(self):
        """Message field 'ally_3_robot_hp'."""
        return self._ally_3_robot_hp

    @ally_3_robot_hp.setter
    def ally_3_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_3_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_3_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_3_robot_hp = value

    @builtins.property
    def ally_4_robot_hp(self):
        """Message field 'ally_4_robot_hp'."""
        return self._ally_4_robot_hp

    @ally_4_robot_hp.setter
    def ally_4_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_4_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_4_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_4_robot_hp = value

    @builtins.property
    def ally_7_robot_hp(self):
        """Message field 'ally_7_robot_hp'."""
        return self._ally_7_robot_hp

    @ally_7_robot_hp.setter
    def ally_7_robot_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_7_robot_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_7_robot_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_7_robot_hp = value

    @builtins.property
    def ally_outpost_hp(self):
        """Message field 'ally_outpost_hp'."""
        return self._ally_outpost_hp

    @ally_outpost_hp.setter
    def ally_outpost_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_outpost_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_outpost_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_outpost_hp = value

    @builtins.property
    def ally_base_hp(self):
        """Message field 'ally_base_hp'."""
        return self._ally_base_hp

    @ally_base_hp.setter
    def ally_base_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ally_base_hp' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'ally_base_hp' field must be an unsigned integer in [0, 65535]"
        self._ally_base_hp = value
