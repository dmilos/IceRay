import ctypes

#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes
import IceRayPy

AddressOf = ctypes.addressof
Scalar = IceRayPy.type.basic.Scalar

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

class HSL(ctypes.Structure):
    _fields_ = [("h", Scalar),
                ("s", Scalar),
                ("l", Scalar)
                ]

def RGB2HSL( P_dll, P_rgb ):
    result = HSL()
    P_dll.IceRayC_Type_Color_RGB2HSL( AddressOf( result ), AddressOf(P_rgb) )
    return result

def HSL2RGB( P_dll, P_hsl ):
    result = RGB()
    P_dll.IceRayC_Type_Color_HSL2RGB( AddressOf( result ), AddressOf(P_hsl) )
    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
