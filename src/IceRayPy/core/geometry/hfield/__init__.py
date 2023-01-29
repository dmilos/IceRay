#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy
import IceRayPy.core.geometry.hfield.generator
import IceRayPy.core.geometry.hfield.object

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D


class System:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_System0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def generator( self, P_generator ):
        self.m_cargo['generator'] = P_generator;
        return self.m_cargo['dll'].IceRayC_Geometry_HField_System_Generator( self.m_cargo['this'], P_generator.m_cargo['this'] )

    def object( self, P_object ):
        self.m_cargo['object'] = P_object;
        return self.m_cargo['dll'].IceRayC_Geometry_HField_System_Object( self.m_cargo['this'], P_object.m_cargo['this'] )

    def lo( self, P_lo: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_HField_System_Lo( self.m_cargo['this'], AddressOf( P_lo ) )

    def hi( self, P_hi: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_HField_System_Hi( self.m_cargo['this'], AddressOf( P_hi ) )

    def box( self, P_lo: Coord3D, P_hi: Coord3D ):
        self.lo( P_lo )
        self.hi( P_hi )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
