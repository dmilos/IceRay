import ctypes

print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.type.basic

Scalar = ctypes.c_double # TODO

class RGB(ctypes.Structure):
    _fields_ = [("r", Scalar),
                ("g", Scalar),
                ("b", Scalar)
                ]

class RGBA(ctypes.Structure):
    _fields_ = [("r", Scalar),
                ("g", Scalar),
                ("b", Scalar),
                ("a", Scalar)
                ]

print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
