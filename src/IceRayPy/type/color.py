import ctype

class ColorRGB(Structure):
    _fields_ = [("r", c_double),
                ("g", c_double),
                ("b", c_double)
                ]

class ColorRGBA(Structure):
    _fields_ = [("r", c_double),
                ("g", c_double),
                ("b", c_double),
                ("a", c_double)
                ]