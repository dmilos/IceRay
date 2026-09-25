#print( '<' + __name__ + ' name=\'' +   __file__ + '>' )

import ctypes
import inspect

import IceRayPy


class CylinderVertical:
    def __init__( self, P_dll, P_config = None ):

        self.m_implementation = IceRayPy.core.camera.transform.Invert( P_dll )
        self.m_cargo          = self.m_implementation.m_cargo

        self.child( IceRayPy.core.camera.cylinder.Vertical( P_dll ) );

    def __del__( self ):
        pass

    def child( self, P_child ):
        self.m_implementation.child( P_child )

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )