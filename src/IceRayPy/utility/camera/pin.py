import ctypes
import inspect

import IceRayPy


class PinCylinderVertical:
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        self.m_cargo['child']= {}
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Transform_Pin0()

        self.child( IceRayPy.core.camera.cylinder.Vertical( P_dll ) );

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_Transform_Pin_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        P_child.height( 4 ) #<! TODO delete me 
