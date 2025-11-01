import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math.affine
import IceRayPy.type.math.coord

Pointer = ctypes.POINTER
AddressOf = ctypes.addressof


#Scalar  = IceRayPy.type.basic.Scalar
Size  = IceRayPy.type.basic.Size
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D
Matrix4D = IceRayPy.type.math.matrix.Scalar4D

class Center:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Center0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Release( self.m_cargo['this'] )

class Grid:
    m_cargo  = {}

    def __init__( self, P_dll, P_size = None ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Grid0()

        #if( None != P_size )
        #    self.size( P_size )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Release( self.m_cargo['this'] )

    def size( self, P_size ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Grid_Size( self.m_cargo['this'], Size(P_size) )


class Random:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Random0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Release( self.m_cargo['this'] )

    def size( self, P_size ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Random_Size( self.m_cargo['this'], Size(P_size) )

class Sobol:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Sobol0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Release( self.m_cargo['this'] )

    def size( self, P_size ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Strategy_Sobol_Size( self.m_cargo['this'], Size(P_size) )

