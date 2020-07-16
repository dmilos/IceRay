print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )
import ctypes

import IceRayPy 

Scalar = IceRayPy.type.basic.Scalar
Size_T = IceRayPy.type.basic.Size

AddresOf = ctypes.addressof

class Scalar1D(ctypes.Structure):
    _fields_ = [("x", Scalar)
                ]

    def __getitem__(self, key):
        return self.x

    def __setitem__(self, key, value):
        self.x = Scalar( value )


class Scalar2D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar)
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y
        return 0

    def __setitem__(self, key, value):
        if( 0 == key ): self.x = Scalar( value )
        if( 1 == key ): self.y = Scalar( value )

class Scalar3D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar),
                ("z", Scalar),
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y
        if( 2 == key ): return self.z
        return 0;

    def __setitem__(self, key, value):
        if( 0 == key ): self.x = Scalar( value )
        if( 1 == key ): self.y = Scalar( value )
        if( 2 == key ): self.z = Scalar( value )


class Scalar4D(ctypes.Structure):
    _fields_ = [("x", Scalar),
                ("y", Scalar),
                ("z", Scalar),
                ("t", Scalar)
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y
        if( 2 == key ): return self.z
        if( 3 == key ): return self.t
        return 0;

    def __setitem__(self, key, value):
        if( 0 == key ): self.x = Scalar( value )
        if( 1 == key ): self.y = Scalar( value )
        if( 2 == key ): self.z = Scalar( value )
        if( 3 == key ): self.t = Scalar( value )

class Size1D(ctypes.Structure):
    _fields_ = [("x", Scalar)
                ]
    def __getitem__(self, key):
        if( 0 == key ): return self.x
        return 0;


class Size2D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T)
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y


class Size3D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T),
                ("z", Size_T),
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y
        if( 2 == key ): return self.z


class Size4D(ctypes.Structure):
    _fields_ = [("x", Size_T),
                ("y", Size_T),
                ("z", Size_T),
                ("t", Size_T)
                ]

    def __getitem__(self, key):
        if( 0 == key ): return self.x
        if( 1 == key ): return self.y
        if( 2 == key ): return self.z
        if( 3 == key ): return self.t

    def __setitem__(self, key, value : Size_T ):
        if( 0 == key ): self.x = Size_T( value )
        if( 1 == key ): self.y = Size_T( value )
        if( 2 == key ): self.z = Size_T( value )
        if( 3 == key ): self.t = Size_T( value )


def fill3D( P_dll, P_scalar ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Coord3D_Fill( AddresOf( result ), Scalar( P_scalar ) )
    return result

def load3D( P_dll, P_x, P_y, P_z ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Coord3D_Load( AddresOf( result ), Scalar( P_x ), Scalar( P_y ), Scalar( P_z ) )
    return result

def length3D( P_dll, P_coord: Scalar3D ):
    return P_dll.IceRayC_Type_Math_Coord3D_Length( AddresOf( P_coord ) )

def distance3D( P_dll, P_left: Scalar3D, P_right: Scalar3D  ):
    return P_dll.IceRayC_Type_Math_Coord3D_Distance( AddresOf( P_left ), AddresOf( P_right ) )

def cross3D( P_dll, P_left: Scalar3D, P_right: Scalar3D  ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Coord3D_Cross( result, AddresOf( P_left ), AddresOf( P_right ) )
    return result

def subtraction3D( P_dll, P_left: Scalar3D, P_right: Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Coord3D_Subtraction( result, AddresOf( P_left ), AddresOf( P_right ) )
    return result

def scale3D( P_dll, P_scalar, P_coord: Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Coord3D_Scale( result, Scalar( P_scalar ), AddresOf( P_coord )  )
    return result
    
print( '<' + __name__ + ' file=\'' +   __file__ + '\'/>' )
