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

    def box( self, P_box = None ): #!< TODO
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



#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
