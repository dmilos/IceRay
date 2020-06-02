
import math
import IceRayPy


def Nuke( P_dll ):
    return IceRayPy.core.geometry.simple.Hyperboloid( P_dll, 0.5 )


def Sphere( P_dll ):
    return IceRayPy.core.geometry.simple.Hyperboloid( P_dll, math.sqrt(2) )


def Cone( P_dll ):
    return IceRayPy.core.geometry.simple.Hyperboloid( P_dll, 0 )


def Cylinder( P_dll ):
    return IceRayPy.core.geometry.simple.Hyperboloid( P_dll, 1 )


def Negative( P_dll ):
    return IceRayPy.core.geometry.simple.Hyperboloid( P_dll, -0.5 )

