import ctypes

import IceRayPy
import IceRayPy.type.math.coord

Coord1D = IceRayPy.type.math.coord.Scalar1D
Coord2D = IceRayPy.type.math.coord.Scalar2D
Coord3D = IceRayPy.type.math.coord.Scalar3D
Coord4D = IceRayPy.type.math.coord.Scalar4D

class Interval1D(ctypes.Structure):
    _fields_ = [
                ("lo", Coord1D), ("hi", Coord1D)
                ]

class Interval2D(ctypes.Structure):
    _fields_ = [
                ("lo", Coord2D), ("hi", Coord2D)
                ]

class Interval3D(ctypes.Structure):
    _fields_ = [
                ("lo", Coord3D), ("hi", Coord3D)
                ]

class Interval4D(ctypes.Structure):
    _fields_ = [
                ("lo", Coord4D), ("hi", Coord4D)
                ]

