import ctypes

Scalar = ctypes.c_double

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