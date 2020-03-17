import ctype

class POINT(Structure):
    _fields_ = [("x", c_double),
                ("y", c_double),
                ("z", c_double),
                ("t", c_double)
                ]