print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )
import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord


CoordScalar1D = IceRayPy.type.math.coord.Scalar1D
CoordScalar2D = IceRayPy.type.math.coord.Scalar2D
CoordScalar3D = IceRayPy.type.math.coord.Scalar3D
CoordScalar4D = IceRayPy.type.math.coord.Scalar4D

CoordSize1D = IceRayPy.type.math.coord.Size1D
CoordSize2D = IceRayPy.type.math.coord.Size2D
CoordSize3D = IceRayPy.type.math.coord.Size3D
CoordSize4D = IceRayPy.type.math.coord.Size4D


class Scalar1D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordScalar1D), ("hi", CoordScalar1D)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordScalar2D), ("hi", CoordScalar2D)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordScalar3D), ("hi", CoordScalar3D)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordScalar4D), ("hi", CoordScalar4D)
                ]

class Size1D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordSize1D), ("hi", CoordSize1D )
                ]

class Size2D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordSize2D), ("hi", CoordSize2D )
                ]

class Size3D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordSize3D), ("hi", CoordSize3D )
                ]

class Size4D(ctypes.Structure):
    _fields_ = [
                ("lo", CoordSize4D), ("hi", CoordSize4D )
                ]
print( '<' + __name__ + ' file=\'' +   __file__ + '\'/>' )
