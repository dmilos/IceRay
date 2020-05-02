
import IceRayPy


Coord3D  = IceRayPy.type.math.coord.Scalar3D

class Spot:
    def __init__( self, P_center = None: Coord3D ):
        I_point = IceRayPy.core.light.Point( P_center )
        self.m_implementation = IceRayPy.core.light.SunG( I_point )

    def __del__( self ):
         pass # TODO

class Area:
    def __init__( self ):
        self.m_implementation = IceRayPy.core.light.SunG( IceRayPy.core.light.Area(  ) )

    def __del__( self ):
         pass # TODO

class Line:
    def __init__( self ):
        self.m_implementation = IceRayPy.core.light.SunG( IceRayPy.core.light.Line( P_center ) )

    def __del__( self ):
         pass # TODO

class Circle:
    def __init__( self ):
        self.m_implementation = IceRayPy.core.light.SunG( IceRayPy.core.light.Circle() )

    def __del__( self ):
         pass # TODO

class Disc:
    def __init__( self ):
        self.m_implementation = IceRayPy.core.light.SunG( IceRayPy.core.light.Disc() )

    def __del__( self ):
         pass # TODO

