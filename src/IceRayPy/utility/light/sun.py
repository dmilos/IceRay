#print( '<' + __name__ + ' name=\'' +   __file__ + '>' )

import IceRayPy


Coord3D  = IceRayPy.type.math.coord.Scalar3D

class Point:
    def __init__( self, P_dll, P_config = None ):

        if( None != P_config ):
            if( 'child' in P_config ):
                self.m_child = IceRayPy.library.light.Point( P_dll, P_config['child'] )
            else:
                self.m_child = IceRayPy.library.light.Point( P_dll, None )

            if( 'center' in P_config ):
               self.m_child.center( P_config['center'] )

        else:
            self.m_child = IceRayPy.library.light.Point( P_dll, None  )

        self.m_implementation = IceRayPy.core.light.SunG( P_dll, self.m_child )
        self.m_cargo = self.m_implementation.m_cargo
        pass

    def __del__( self ):
         pass # Do nothing

class Area:
    def __init__( self, P_dll, P_config = None ):

        if( None != P_config ):
            if( 'child' in P_config ):
                self.m_child = IceRayPy.library.light.Area( P_dll, P_config['child'] )
            else:
                self.m_child = IceRayPy.library.light.Area( P_dll, None )

            if( 'origin' in P_config ):
               self.m_child.origin( P_config['origin'] )
            if( 'X' in P_config ):
               self.m_child.X( P_config['X'] )
            if( 'Y' in P_config ):
               self.m_child.Y( P_config['Y'] )
        else:
             self.m_child = IceRayPy.core.light.Area( P_dll )

        self.m_implementation = IceRayPy.core.light.SunG( P_dll, self.m_child )
        self.m_cargo = self.m_implementation.m_cargo
        pass

    def __del__( self ):
         pass # Do nothing

class Line:
    def __init__( self, P_dll, P_config = None ):
        if( None != P_config ):
            if( 'child' in P_config ):
                self.m_child = IceRayPy.library.light.Line( P_dll, P_config['child'] )
            else:
                self.m_child = IceRayPy.library.light.Line( P_dll, None )

            if( 'start' in P_config ):
                self.m_child.start( P_config['start'] )
            if( 'end' in P_config ):
                self.m_child.end( P_config['end'] )
        else:
             self.m_child = IceRayPy.library.light.Line( P_dll, None )

        self.m_implementation = IceRayPy.core.light.SunG( P_dll, self.m_child )
        self.m_cargo = self.m_implementation.m_cargo
        pass

    def __del__( self ):
         pass # Do nothing

class Circle:
    def __init__( self, P_dll, P_config = None ):

        if( None != P_config ):
            if( 'child' in P_config ):
                self.m_child = IceRayPy.library.light.Circle( P_dll, P_config['child'] )
            else:
                self.m_child = IceRayPy.library.light.Circle( P_dll, None )

            if( 'center' in P_config ):
               self.m_child.center( P_config[ 'center' ] )
            if( 'X' in P_config ):
               self.m_child.X( P_config['X'] )
            if( 'Y' in P_config ):
               self.m_child.Y( P_config['Y'] )
        else:
             self.m_child = IceRayPy.library.light.Circle( P_dll, None )

        self.m_implementation = IceRayPy.core.light.SunG( P_dll, self.m_child )
        self.m_cargo = self.m_implementation.m_cargo
        pass

    def __del__( self ):
         pass # Do nothing

class Disc:
    def __init__( self, P_dll, P_config = None ):

        if( None != P_config ):
            if( 'child' in P_config ):
                self.m_child = IceRayPy.library.light.Disc( P_dll, P_config['child'] )
            else:
                self.m_child = IceRayPy.library.light.Disc( P_dll, None )
            if( 'center' in P_config ):
                self.m_child.center( P_config[ 'center' ] )
            if( 'X' in P_config ):
                self.m_child.X( P_config['X'] )
            if( 'Y' in P_config ):
                self.m_child.Y( P_config['Y'] )

        self.m_implementation = IceRayPy.core.light.SunG( P_dll, self.m_child )
        self.m_cargo = self.m_implementation.m_cargo
        pass

    def __del__( self ):
         pass # Do nothing

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )