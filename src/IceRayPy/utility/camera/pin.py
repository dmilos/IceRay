#print( '<' + __name__ + ' name=\'' +   __file__ + '>' )

import ctypes
import inspect

import IceRayPy

Coord3D     = IceRayPy.type.math.coord.Scalar3D



class CylinderVertical:
    def __init__( self, P_dll, P_config = None ):

        self.m_implementation = IceRayPy.core.camera.transform.Pin( P_dll )
        self.m_cargo = self.m_implementation.m_cargo

        self.child( IceRayPy.core.camera.cylinder.Vertical( P_dll ) );

    def __del__( self ):
        pass # Do nothing

    def child( self, P_child ):
        self.m_implementation.child( P_child )

    def origin( self, P_origin : Coord3D ):
        self.m_implementation.origin( P_origin )

class CylinderHorizontal:
    def __init__( self, P_dll, P_config = None ):
        self.m_implementation = IceRayPy.core.camera.transform.Pin( P_dll )
        self.m_cargo = self.m_implementation.m_cargo

        self.child( IceRayPy.core.camera.cylinder.Horizontal( P_dll ) );

    def __del__( self ):
        pass # Do nothing

    def child( self, P_child ):
        self.m_implementation.child( P_child )

    def origin( self, P_origin : Coord3D ):
        self.m_implementation.origin( P_origin )


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )