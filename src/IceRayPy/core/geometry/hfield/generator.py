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


class Image:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Image0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Release( self.m_cargo['this'] )

    def picture( self, P_picture ):
        self.m_cargo['picture'] = P_picture
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Image_Picture( self.m_cargo['this'], P_picture.m_cargo['this'] )

class Expression:
    def __init__( self, P_dll, P_pattern = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        if( None != P_pattern ):
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Expression1( P_pattern )
        else:
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Expression0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Release( self.m_cargo['this'] )

    def size( self, P_coord ):
         self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Expression_Size( self.m_cargo['this'], AddressOf(P_coord) )
         self.m_cargo['size']  = P_coord;
         return True

    def pattern( self, P_pattern ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Expression_Pattern( self.m_cargo['this'], P_pattern.encode('utf-8') )
        self.m_cargo['pattern']  = P_pattern;

    def interval( self, P_interval ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Expression_Interval( self.m_cargo['this'], AddressOf( P_interval ) )
        self.m_cargo['interval']  = P_interval;

class Table:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Table0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Release( self.m_cargo['this'] )

    def size( self, P_coord ):
         self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Table_Size( self.m_cargo['this'], AddressOf(P_coord) )
         return True

    def value( self, P_coord, P_value ):
         self.m_cargo['dll'].IceRayC_Geometry_HField_Generator_Table_Value( self.m_cargo['this'], AddressOf(P_coord), Scalar( P_value ) )
         return True

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )