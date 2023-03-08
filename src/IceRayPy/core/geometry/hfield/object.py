#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy.core.geometry.complex
import IceRayPy.core.geometry.rtss
import IceRayPy.core.geometry.simple
import IceRayPy.core.geometry.transform
import IceRayPy.core.geometry.volumetric

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D


class Flat:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Flat0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Release( self.m_cargo['this'] )

class Quad:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Quad0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Release( self.m_cargo['this'] )

class Triangle:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Triangle0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Release( self.m_cargo['this'] )

class Vacuum:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Vacuuum0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Object_Release( self.m_cargo['this'] )

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )