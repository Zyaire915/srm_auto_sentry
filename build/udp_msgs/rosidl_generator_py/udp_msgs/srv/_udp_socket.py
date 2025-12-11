# generated from rosidl_generator_py/resource/_idl.py.em
# with input from udp_msgs:srv/UdpSocket.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UdpSocket_Request(type):
    """Metaclass of message 'UdpSocket_Request'."""

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
            module = import_type_support('udp_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'udp_msgs.srv.UdpSocket_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__udp_socket__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__udp_socket__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__udp_socket__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__udp_socket__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__udp_socket__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UdpSocket_Request(metaclass=Metaclass_UdpSocket_Request):
    """Message class 'UdpSocket_Request'."""

    __slots__ = [
        '_local_address',
        '_local_port',
        '_remote_address',
        '_remote_port',
        '_is_broadcast',
    ]

    _fields_and_field_types = {
        'local_address': 'string',
        'local_port': 'uint16',
        'remote_address': 'string',
        'remote_port': 'uint16',
        'is_broadcast': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.local_address = kwargs.get('local_address', str())
        self.local_port = kwargs.get('local_port', int())
        self.remote_address = kwargs.get('remote_address', str())
        self.remote_port = kwargs.get('remote_port', int())
        self.is_broadcast = kwargs.get('is_broadcast', bool())

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
        if self.local_address != other.local_address:
            return False
        if self.local_port != other.local_port:
            return False
        if self.remote_address != other.remote_address:
            return False
        if self.remote_port != other.remote_port:
            return False
        if self.is_broadcast != other.is_broadcast:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def local_address(self):
        """Message field 'local_address'."""
        return self._local_address

    @local_address.setter
    def local_address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'local_address' field must be of type 'str'"
        self._local_address = value

    @builtins.property
    def local_port(self):
        """Message field 'local_port'."""
        return self._local_port

    @local_port.setter
    def local_port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'local_port' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'local_port' field must be an unsigned integer in [0, 65535]"
        self._local_port = value

    @builtins.property
    def remote_address(self):
        """Message field 'remote_address'."""
        return self._remote_address

    @remote_address.setter
    def remote_address(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'remote_address' field must be of type 'str'"
        self._remote_address = value

    @builtins.property
    def remote_port(self):
        """Message field 'remote_port'."""
        return self._remote_port

    @remote_port.setter
    def remote_port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remote_port' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'remote_port' field must be an unsigned integer in [0, 65535]"
        self._remote_port = value

    @builtins.property
    def is_broadcast(self):
        """Message field 'is_broadcast'."""
        return self._is_broadcast

    @is_broadcast.setter
    def is_broadcast(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_broadcast' field must be of type 'bool'"
        self._is_broadcast = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_UdpSocket_Response(type):
    """Metaclass of message 'UdpSocket_Response'."""

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
            module = import_type_support('udp_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'udp_msgs.srv.UdpSocket_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__udp_socket__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__udp_socket__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__udp_socket__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__udp_socket__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__udp_socket__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UdpSocket_Response(metaclass=Metaclass_UdpSocket_Response):
    """Message class 'UdpSocket_Response'."""

    __slots__ = [
        '_socket_created',
    ]

    _fields_and_field_types = {
        'socket_created': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.socket_created = kwargs.get('socket_created', bool())

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
        if self.socket_created != other.socket_created:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def socket_created(self):
        """Message field 'socket_created'."""
        return self._socket_created

    @socket_created.setter
    def socket_created(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'socket_created' field must be of type 'bool'"
        self._socket_created = value


class Metaclass_UdpSocket(type):
    """Metaclass of service 'UdpSocket'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('udp_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'udp_msgs.srv.UdpSocket')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__udp_socket

            from udp_msgs.srv import _udp_socket
            if _udp_socket.Metaclass_UdpSocket_Request._TYPE_SUPPORT is None:
                _udp_socket.Metaclass_UdpSocket_Request.__import_type_support__()
            if _udp_socket.Metaclass_UdpSocket_Response._TYPE_SUPPORT is None:
                _udp_socket.Metaclass_UdpSocket_Response.__import_type_support__()


class UdpSocket(metaclass=Metaclass_UdpSocket):
    from udp_msgs.srv._udp_socket import UdpSocket_Request as Request
    from udp_msgs.srv._udp_socket import UdpSocket_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
