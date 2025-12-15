import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math.affine
import IceRayPy.type.math.coord

Pointer = ctypes.POINTER
AddressOf = ctypes.addressof


#Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D
Matrix4D = IceRayPy.type.math.matrix.Scalar4D