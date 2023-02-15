#print( '<' + __name__ + ' file=\'' +   __file__ + ' >' )

import ctypes

import IceRayPy

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Coord3D  = IceRayPy.type.math.coord.Scalar3D
Color    = IceRayPy.type.color.RGB
SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar


class Spot(ctypes.Structure):
    _fields_ = [("m_center", Coord3D)
                ,("m_c0", Color)
                ,("m_c1", Color)
                ,("m_c2", Color)
                ]

    def __init__( self, P_center: Coord3D = None, P_c0 : Color = None, P_c1 :Color = None, P_c2 :Color = None ):
        if( None != P_center ):
           self.center( P_center )

        if( None != P_c0 ):
           self.c0( P_c0 )

        if( None != P_c1 ):
           self.c1( P_c1 )

        if( None != P_c2 ):
           self.c2( P_c2 )

    def __del__( self ):
        pass # do nothing

    def center( self, P_center : Coord3D ):
        self.m_center = P_center
        pass

    def c0( self, P_c0 :Color ):
        self.m_c0 = P_c0

    def c1( self, P_c1 :Color ):
        self.m_c1 = P_c1

    def c2( self, P_c2 :Color ):
        self.m_c2 = P_c2

    def c( self, P_c0 : Color, P_c1 :Color, P_c2 :Color ):
        self.m_c0 = P_c0
        self.m_c1 = P_c1
        self.m_c2 = P_c2


class Area:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Area0()
        self.sample( 32 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def origin( self, P_origin ):
        self.m_cargo['dll'].IceRayC_Light_Area_Origin( self.m_cargo['this'], AddressOf( P_origin ) )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Area_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Area_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def X( self, P_X: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Area_X( self.m_cargo['this'], AddressOf( P_X ) )

    def Y( self, P_Y: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Area_Y( self.m_cargo['this'], AddressOf(P_Y) )


class Chandelier:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Chandelier0()
        self.m_cargo['list'] = []

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def push( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Chandelier_Push( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['list'].append( P_child )


class Circle:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Circle0()
        self.sample( 32 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot : Spot ):
        self.m_cargo['dll'].IceRayC_Light_Circle_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def center( self, P_center):
        self.m_cargo['dll'].IceRayC_Light_Circle_Center( self.m_cargo['this'], AddressOf( P_center ) )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Circle_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def X( self, P_X: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Circle_X( self.m_cargo['this'], AddressOf( P_X ) )

    def Y( self, P_Y: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Circle_Y( self.m_cargo['this'], AddressOf(P_Y) )


class Confine:
    def __init__( self, P_dll, P_child = None, P_shell = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Confine0()

        P_child = Point( P_dll )

        if( None != P_child ):
            self.child( P_child )
        if( None != P_shell ):
            self.shell( P_shell )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Confine_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def shell( self, P_shell ):
        self.m_cargo['dll'].IceRayC_Light_Confine_Shell( self.m_cargo['this'], P_shell.m_cargo['this'] )
        self.m_cargo['shell'] = P_shell

    def location( self, P_location ):
        self.m_cargo['dll'].IceRayC_Light_Confine_Location( self.m_cargo['this'], SizeType(  self, P_location ) )


class Dark:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Dark0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Disc:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Disc0()
        self.sample( 32 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot : Spot ):
        self.m_cargo['dll'].IceRayC_Light_Circle_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def center( self, P_center):
        self.m_cargo['dll'].IceRayC_Light_Circle_Center( self.m_cargo['this'],AddressOf( P_center ) )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Disc_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def X( self, P_X: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Disc_X( self.m_cargo['this'], AddressOf( P_X ) )

    def Y( self, P_Y: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Disc_Y( self.m_cargo['this'], AddressOf(P_Y) )


class Line:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Line0()
        self.sample( 32 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Line_Sample( self.m_cargo['this'], SizeType ( P_sample ) )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Line_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def start( self, P_start ):
        self.m_cargo['dll'].IceRayC_Light_Line_Start( self.m_cargo['this'], AddressOf( P_start ) )

    def end( self, P_end ):
        self.m_cargo['dll'].IceRayC_Light_Line_End( self.m_cargo['this'], AddressOf( P_end ) )


class Point:
    def __init__( self, P_dll, P_spot: Spot = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Point0()
        if( None != P_spot ):
            self.spot( P_spot )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Point_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def center( self, P_center: Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Point_Center( self.m_cargo['this'], AddressOf( P_center ) )


class Obstruct:
    def __init__( self, P_dll, P_child = None, P_barrier = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Obstruct0()
        if( None == P_child ):
            P_child = Point( P_dll )
        if( None != P_child ):
            self.child( P_child )
        if( None != P_barrier ):
            self.barrier( P_barrier )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def barrier( self, P_barrier ):
        self.m_cargo['dll'].IceRayC_Light_Obstruct_Barrier( self.m_cargo['this'], P_barrier.m_cargo['this'] )
        self.m_cargo['barrier'] = P_barrier

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Obstruct_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['barrier'] = P_child


class Reflector:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Reflector0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Reflector_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def center( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Reflector_Center( self.m_cargo['this'], AddressOf( P_spot ) )

    def inner( self, P_inner ):
        self.m_cargo['dll'].IceRayC_Light_Reflector_Inner( self.m_cargo['this'], ScalarType( P_inner ) )

    def outter( self, P_outter ):
        self.m_cargo['dll'].IceRayC_Light_Reflector_Outter( self.m_cargo['this'], ScalarType( P_outter ) )


class Sphere:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Sphere0()
        self.sample( 100 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Sphere_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Sphere_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Light_Sphere_Radius( self.m_cargo['this'], P_radius )


class Spline:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Spline0()
        self.sample( 100 )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_Spline_Spot( self.m_cargo['this'], AddressOf( P_spot ) )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Light_Spline_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def cp( self, P_index, P_p0 : Coord3D ):
        self.m_cargo['dll'].IceRayC_Light_Spline_CP( self.m_cargo['this'], SizeType( P_index ), AddressOf( P_p0 ) )


class SunS:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_SunS0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def spot( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_SunS_Spot( self.m_cargo['this'], AddressOf( P_spot ) )
    def center( self, P_spot: Spot ):
        self.m_cargo['dll'].IceRayC_Light_SunS_Center( self.m_cargo['this'], AddressOf( P_spot ) )


class SunG:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_SunG0()
        if( None != P_child ):
            self.child( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_SunG_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child


import IceRayPy.core.light.transform


#print( '</' + __name__ + ' file=\'' +   __file__ + '\' >' )