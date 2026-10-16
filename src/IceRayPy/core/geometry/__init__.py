#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

#__all__ =[
#'complex',
#'rtss',
#'simple',
#'transform',
#'volumetric'
#]

import IceRayPy.core.geometry.complex
import IceRayPy.core.geometry.rtss
import IceRayPy.core.geometry.simple
import IceRayPy.core.geometry.transform
import IceRayPy.core.geometry.volumetric
import IceRayPy.core.geometry.hfield
import IceRayPy.core.geometry.blobby
import IceRayPy.core.geometry.flat



class Generic:
    def __init__( self, P_dll, P_this = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        if( None != P_this ):
            self.set( P_this )

    def set( self, P_this ):
        self.m_cargo['this'] = P_this

    def get( self ):
        return self.m_cargo['this']

    def __del__( self ):
        pass

    def box( self, P_box = None ):
        if( None != P_box ):
            self.m_cargo['dll'].IceRayC_Geometry__Base_Box_Set( self.m_cargo['this'], AddressOf( P_box ) )
        result = IceRayPy.type.math.interval.Scalar3D()
        self.m_cargo['dll'].IceRayC_Geometry__Base_Box_Get( self.m_cargo['this'], AddressOf( P_box ) )
        return result

class Pretender:
    def __init__( self, P_dll, P_this, P_that ):
        self.m_cargo = {}
        self.m_cargo['this'] = P_this
        self.m_cargo['that'] = P_that

    def set( self, P_this ):
        self.m_cargo['this'] = P_this

    def get( self ):
        return self.m_cargo['this']


import ctypes
import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.interval

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof


class Implicit:
    def __init__( self, P_dll, P_expression = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Implicit0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    #def hull( self, P_hull ):
    #    self.m_cargo['dll'].IceRayC_Geometry_Implicit_Hull( self.m_cargo['this'], P_hull.m_cargo['this'] )
    #    self.m_cargo['hull'] = P_hull

    def expression( self, P_expression ):
        self.m_cargo['dll'].IceRayC_Geometry_Implicit_Expression( self.m_cargo['this'],  P_expression.encode('utf-8') )

    def interval( self, P_interval ):
        self.m_cargo['dll'].IceRayC_Geometry_Implicit_Interval( self.m_cargo['this'],  AddressOf( P_interval ) )

    def box( self, P_box ):
        self.m_cargo['dll'].IceRayC_Geometry__Base_Box_Set( self.m_cargo['this'], AddressOf( P_box ) )

    def delta( self, P_delta ):
        self.m_cargo['dll'].IceRayC_Geometry_Implicit_Delta( self.m_cargo['this'],   P_delta )

    def sampling( self, P_sampling ):
        self.m_cargo['dll'].IceRayC_Geometry_Implicit_Sampling( self.m_cargo['this'],   P_sampling )

    def iteration( self, P_iteration ):
        self.m_cargo['dll'].IceRayC_Geometry_Implicit_Iteration( self.m_cargo['this'],   P_iteration )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
