# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pb_rm_interfaces:msg/GameStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GameStatus(type):
    """Metaclass of message 'GameStatus'."""

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
                'pb_rm_interfaces.msg.GameStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__game_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__game_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__game_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__game_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__game_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GameStatus(metaclass=Metaclass_GameStatus):
    """Message class 'GameStatus'."""

    __slots__ = [
        '_game_type',
        '_game_progress',
        '_stage_remain_time',
        '_sync_time_stamp',
    ]

    _fields_and_field_types = {
        'game_type': 'uint8',
        'game_progress': 'uint8',
        'stage_remain_time': 'uint16',
        'sync_time_stamp': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.game_type = kwargs.get('game_type', int())
        self.game_progress = kwargs.get('game_progress', int())
        self.stage_remain_time = kwargs.get('stage_remain_time', int())
        self.sync_time_stamp = kwargs.get('sync_time_stamp', int())

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
        if self.game_type != other.game_type:
            return False
        if self.game_progress != other.game_progress:
            return False
        if self.stage_remain_time != other.stage_remain_time:
            return False
        if self.sync_time_stamp != other.sync_time_stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def game_type(self):
        """Message field 'game_type'."""
        return self._game_type

    @game_type.setter
    def game_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'game_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_type' field must be an unsigned integer in [0, 255]"
        self._game_type = value

    @builtins.property
    def game_progress(self):
        """Message field 'game_progress'."""
        return self._game_progress

    @game_progress.setter
    def game_progress(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'game_progress' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'game_progress' field must be an unsigned integer in [0, 255]"
        self._game_progress = value

    @builtins.property
    def stage_remain_time(self):
        """Message field 'stage_remain_time'."""
        return self._stage_remain_time

    @stage_remain_time.setter
    def stage_remain_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stage_remain_time' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'stage_remain_time' field must be an unsigned integer in [0, 65535]"
        self._stage_remain_time = value

    @builtins.property
    def sync_time_stamp(self):
        """Message field 'sync_time_stamp'."""
        return self._sync_time_stamp

    @sync_time_stamp.setter
    def sync_time_stamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sync_time_stamp' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'sync_time_stamp' field must be an unsigned integer in [0, 18446744073709551615]"
        self._sync_time_stamp = value
