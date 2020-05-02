print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

#__all__ =[
#'complex',
#'rtss',
#'simple',
#'transform',
#'volumetric'
#]

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


class Pretender:
    def __init__( self, P_dll, P_this, P_that ):
        self.m_cargo = {}
        self.m_cargo['this'] = P_this
        self.m_cargo['that'] = P_that

    def set( self, P_this ):
        self.m_cargo['this'] = P_this

    def get( self ):
        return self.m_cargo['this']



import IceRayPy.core.geometry.complex
import IceRayPy.core.geometry.rtss
import IceRayPy.core.geometry.simple
import IceRayPy.core.geometry.transform
import IceRayPy.core.geometry.volumetric

print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
