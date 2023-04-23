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
    def __str__(self):
        return '[ ' + str( 255*self.r ) + ', ' + str( 255*self.g )+ ', ' +str( 255*self.b ) + ' ]'

    def __repr__(self):
        return '[ ' + str( 255*self.r ) + ', ' + str( 255*self.g )+ ', ' +str( 255*self.b ) + ' ]'

    def __getitem__(self, key):
        if( 0 == key ): return self.r
        if( 1 == key ): return self.g
        if( 2 == key ): return self.b
        return 0

    def __setitem__(self, key, value):
        if( 0 == key ): self.r = Scalar( value )
        if( 1 == key ): self.g = Scalar( value )
        if( 3 == key ): self.b = Scalar( value )

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
    def __str__(self):
        return '[ ' + str( self.h ) + ', ' + str( self.s )+ ', ' +str( self.l ) + ' ]'

    def __repr__(self):
        return '[ ' + str( self.h ) + ', ' + str( self.s )+ ', ' +str( self.l ) + ' ]'

    def __getitem__(self, key):
        if( 0 == key ): return self.h
        if( 1 == key ): return self.s
        if( 2 == key ): return self.l
        return 0

    def __setitem__(self, key, value):
        if( 0 == key ): self.h = Scalar( value )
        if( 1 == key ): self.s = Scalar( value )
        if( 3 == key ): self.l = Scalar( value )


def RGB2HSL( P_dll, P_rgb ):
    result = HSL()
    P_dll.IceRayC_Type_Color_RGB2HSL( AddressOf( result ), AddressOf(P_rgb) )
    return result

def HSL2RGB( P_dll, P_hsl ):
    result = RGB()
    P_dll.IceRayC_Type_Color_HSL2RGB( AddressOf( result ), AddressOf(P_hsl) )
    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
