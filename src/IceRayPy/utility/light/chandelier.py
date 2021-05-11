
import ctypes

import IceRayPy

Pointer  = ctypes.POINTER
AddresOf = ctypes.addressof

Coord3D  = IceRayPy.type.math.coord.Scalar3D
Color  = IceRayPy.type.color.RGB

class Hexa:
    def __init__( self, P_dll ):

        center = Coord3D( 0, 0, -2 )
        radius = 2

        c0 = 0.0 * 0.8
        c1 = 1.4 * 0.8
        c2 = 1.6 * 0.8

        color0 = { "-X" : Color( c0, c0, c0 ), "+X" : Color( c0, c0, c0 ), "-Y" : Color( c0, c0, c0 ), "+Y" : Color( c0, c0, c0), "+Z" : Color( c0, c0, c0), "-Z" : Color( c0, c0, c0) }
        color1 = { "-X" : Color( c1, c1, c1 ), "+X" : Color( c1, c1, c1 ), "-Y" : Color( c1, c1, c1 ), "+Y" : Color( c1, c1, c1), "+Z" : Color( c1, c1, c1), "-Z" : Color( c1, c1, c1) }
        color2 = { "-X" : Color( c2, c2, c2 ), "+X" : Color( c2, c2, c2 ), "-Y" : Color( c2, c2, c2 ), "+Y" : Color( c2, c2, c2), "+Z" : Color( c2, c2, c2), "-Z" : Color( c2, c2, c2) }

        self.m_implementation = IceRayPy.core.light.Chandelier( P_dll )
        self.m_cargo = self.m_implementation.m_cargo

        spot = IceRayPy.core.light.Spot( Coord3D( radius+center[0], 0, 0 ),  color0['+X'], color1['+X'], color2['+X'] )
        self.m_implementation.push( IceRayPy.core.light.Point( P_dll, spot ) )

        spot = IceRayPy.core.light.Spot( Coord3D( -radius+center[0], 0, 0 ), color0['-X'], color1['-X'], color2['-X'] )
        self.m_implementation.push( IceRayPy.core.light.Point( P_dll, spot ) )

        spot = IceRayPy.core.light.Spot( Coord3D( 0, radius+center[1], 0 ),  color0['+Y'], color1['+Y'], color2['+Y'] )
        self.m_implementation.push( IceRayPy.core.light.Point( P_dll, spot ) )

        spot = IceRayPy.core.light.Spot( Coord3D( 0, -radius+center[1], 0 ), color0['-Y'], color1['-Y'], color2['-Y'] )
        self.m_implementation.push( IceRayPy.core.light.Point( P_dll, spot ) )

        spot = IceRayPy.core.light.Spot( Coord3D( 0, 0, radius+center[2] ),  color0['+Z'], color1['+Z'], color2['+Z'] )
        self.m_implementation.push( IceRayPy.core.light.Point( P_dll, spot ) )

    def __del__( self ):
        pass # Do nothing

class Octa:
    def __init__( self, P_dll ):
        self.m_implementation = IceRayPy.core.light.Chandelier( P_dll )
        self.m_cargo = self.m_implementation.m_cargo

    def __del__( self ):
        pass # Do nothing



class Tetra:
    def __init__( self, P_dll ):
        self.m_implementation = IceRayPy.core.light.Chandelier( P_dll )
        self.m_cargo = self.m_implementation.m_cargo

    def __del__( self ):
        pass # Do nothing

