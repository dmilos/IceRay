import ctypes

print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

Scalar   = ctypes.c_double
Unsigned = ctypes.c_uint
Integer  = ctypes.c_int
Size     = ctypes.c_uint
VoidPtr  = ctypes.c_void_p

print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
