# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_decision_interfaces:msg/FriendLocation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FriendLocation(type):
    """Metaclass of message 'FriendLocation'."""

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
                'rm_decision_interfaces.msg.FriendLocation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__friend_location
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__friend_location
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__friend_location
            cls._TYPE_SUPPORT = module.type_support_msg__msg__friend_location
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__friend_location

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FriendLocation(metaclass=Metaclass_FriendLocation):
    """Message class 'FriendLocation'."""

    __slots__ = [
        '_hero_x',
        '_hero_y',
        '_engineer_x',
        '_engineer_y',
        '_standard_3_x',
        '_standard_3_y',
        '_standard_4_x',
        '_standard_4_y',
        '_standard_5_x',
        '_standard_5_y',
    ]

    _fields_and_field_types = {
        'hero_x': 'double',
        'hero_y': 'double',
        'engineer_x': 'double',
        'engineer_y': 'double',
        'standard_3_x': 'double',
        'standard_3_y': 'double',
        'standard_4_x': 'double',
        'standard_4_y': 'double',
        'standard_5_x': 'double',
        'standard_5_y': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.hero_x = kwargs.get('hero_x', float())
        self.hero_y = kwargs.get('hero_y', float())
        self.engineer_x = kwargs.get('engineer_x', float())
        self.engineer_y = kwargs.get('engineer_y', float())
        self.standard_3_x = kwargs.get('standard_3_x', float())
        self.standard_3_y = kwargs.get('standard_3_y', float())
        self.standard_4_x = kwargs.get('standard_4_x', float())
        self.standard_4_y = kwargs.get('standard_4_y', float())
        self.standard_5_x = kwargs.get('standard_5_x', float())
        self.standard_5_y = kwargs.get('standard_5_y', float())

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
        if self.hero_x != other.hero_x:
            return False
        if self.hero_y != other.hero_y:
            return False
        if self.engineer_x != other.engineer_x:
            return False
        if self.engineer_y != other.engineer_y:
            return False
        if self.standard_3_x != other.standard_3_x:
            return False
        if self.standard_3_y != other.standard_3_y:
            return False
        if self.standard_4_x != other.standard_4_x:
            return False
        if self.standard_4_y != other.standard_4_y:
            return False
        if self.standard_5_x != other.standard_5_x:
            return False
        if self.standard_5_y != other.standard_5_y:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def hero_x(self):
        """Message field 'hero_x'."""
        return self._hero_x

    @hero_x.setter
    def hero_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hero_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'hero_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._hero_x = value

    @builtins.property
    def hero_y(self):
        """Message field 'hero_y'."""
        return self._hero_y

    @hero_y.setter
    def hero_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hero_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'hero_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._hero_y = value

    @builtins.property
    def engineer_x(self):
        """Message field 'engineer_x'."""
        return self._engineer_x

    @engineer_x.setter
    def engineer_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'engineer_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'engineer_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._engineer_x = value

    @builtins.property
    def engineer_y(self):
        """Message field 'engineer_y'."""
        return self._engineer_y

    @engineer_y.setter
    def engineer_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'engineer_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'engineer_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._engineer_y = value

    @builtins.property
    def standard_3_x(self):
        """Message field 'standard_3_x'."""
        return self._standard_3_x

    @standard_3_x.setter
    def standard_3_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_3_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_3_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_3_x = value

    @builtins.property
    def standard_3_y(self):
        """Message field 'standard_3_y'."""
        return self._standard_3_y

    @standard_3_y.setter
    def standard_3_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_3_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_3_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_3_y = value

    @builtins.property
    def standard_4_x(self):
        """Message field 'standard_4_x'."""
        return self._standard_4_x

    @standard_4_x.setter
    def standard_4_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_4_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_4_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_4_x = value

    @builtins.property
    def standard_4_y(self):
        """Message field 'standard_4_y'."""
        return self._standard_4_y

    @standard_4_y.setter
    def standard_4_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_4_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_4_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_4_y = value

    @builtins.property
    def standard_5_x(self):
        """Message field 'standard_5_x'."""
        return self._standard_5_x

    @standard_5_x.setter
    def standard_5_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_5_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_5_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_5_x = value

    @builtins.property
    def standard_5_y(self):
        """Message field 'standard_5_y'."""
        return self._standard_5_y

    @standard_5_y.setter
    def standard_5_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'standard_5_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'standard_5_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._standard_5_y = value
