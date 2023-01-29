
import IceRayPy


Coord3D  = IceRayPy.type.math.coord.Scalar3D

class Point:
    def __init__( self, P_dll, P_center = None ):
        self.m_implementation = IceRayPy.core.light.SunG( P_dll, IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( Coord3D( 0, 0, 10 ) ) ) )
        #self.m_implementation = IceRayPy.core.light.SunS( P_dll  )
        self.m_cargo = self.m_implementation.m_cargo
        if( None != P_center ):
            self.m_cargo.center( P_center )

    def __del__( self ):
         pass # Do nothing

class Area:
    def __init__( self, P_dll, P_origin = None ):
        self.m_implementation = IceRayPy.core.light.SunG( P_dll, IceRayPy.core.light.Area( P_dll ) )
        self.m_cargo = self.m_implementation.m_cargo
        if( None != P_origin ):
            self.m_implementation.origin( P_origin )

    def __del__( self ):
         pass # Do nothing

class Line:
    def __init__( self, P_dll, P_start = None , P_end = None  ):
        self.m_implementation = IceRayPy.core.light.SunG( P_dll, IceRayPy.core.light.Line( P_dll ) )
        self.m_cargo = self.m_implementation.m_cargo
        if( None != P_start ):
            self.m_implementation.start( P_start )
        if( None != P_end ):
            self.m_implementation.end( P_end )

    def __del__( self ):
         pass # Do nothing

class Circle:
    def __init__( self, P_dll, P_center = None  ):
        self.m_implementation = IceRayPy.core.light.SunG( P_dll, IceRayPy.core.light.Circle( P_dll ) )
        self.m_cargo = self.m_implementation.m_cargo
        if( None != P_center ):
            self.m_implementation.center( P_center )

    def __del__( self ):
         pass # Do nothing

class Disc:
    def __init__( self, P_dll, P_center = None  ):
        self.m_implementation = IceRayPy.core.light.SunG( P_dll, IceRayPy.core.light.Disc( P_dll ) )
        self.m_cargo = self.m_implementation.m_cargo
        if( None != P_center ):
            self.m_implementation.center( P_center )
        if( None != P_center ):
            self.m_implementation.center( P_center )

    def __del__( self ):
         pass # Do nothing

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )