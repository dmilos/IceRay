import ctypes

Scalar = ctypes.c_double
Size_T = ctypes.c_uint

class Scalar1D(ctypes.Structure):
    _fields_ = [("x", Scalar)
                ]
                
class Scalar2D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar),
                ("z", Scalar),
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar),
                ("z", Scalar),
                ("t", Scalar)
                ]

class Size1D(ctypes.Structure):
    _fields_ = [("x", Scalar)
                ]
                
class Size2D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T)
                ]

class Size3D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T),
                ("z", Size_T),
                ]

class Size4D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T),
                ("z", Size_T),
                ("t", Size_T)
                ]
