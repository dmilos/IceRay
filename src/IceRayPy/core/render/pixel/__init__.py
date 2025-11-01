#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy.core.render.pixel.filter
import IceRayPy.core.render.pixel.strategy


Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Coord3D  = IceRayPy.type.math.coord.Scalar3D
Color    = IceRayPy.type.color.RGB
SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )

class Constant:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Constant0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )

class UV:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_UV0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )

class Basic:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Basic0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )

    def filter( self, P_filter ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Basic_Filter( self.m_cargo['this'], P_filter.m_cargo['this']  )
        self.m_cargo['pixel'] = P_filter

    def strategy( self, P_strategy ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Basic_Strategy( self.m_cargo['this'], P_strategy.m_cargo['this']  )
        self.m_cargo['pixel'] = P_strategy

