#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
import ctypes



import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord
import IceRayPy.core.geometry

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D


class Box: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll, P_lo = None , P_hi = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Box0()
        if None != P_lo:
            self.lo( P_lo )
        if None != P_hi:
            self.hi( P_hi )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def lo( self, P_lo: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Box_Lo( self.m_cargo['this'], AddressOf( P_lo ) )

    def hi( self, P_hi: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Box_Hi( self.m_cargo['this'], AddressOf( P_hi ) )

    def box( self, P_lo: Coord3D, P_hi: Coord3D ):
        self.lo( P_lo )
        self.hi( P_hi )


class Disc: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll, P_center = None, P_normal = None, P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Disc0()

        if None != P_center:
            self.center( P_center )
        if None != P_normal:
            self.normal( P_normal )
        if None != P_radius:
            self.radius( P_radius )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Disc_Center( self.m_cargo['this'], AddressOf( P_center ) )

    def normal( self, P_normal: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Disc_Normal( self.m_cargo['this'], AddressOf( P_normal ) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Disc_Radius( self.m_cargo['this'], Scalar( P_radius ) )


class UDisc: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_UDisc0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_UDisc_Radius( self.m_cargo['this'], Scalar( P_radius ) )


class Plane:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll, P_origin = None, P_normal = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Plane0()

        if( None != P_origin ):
            self.origin( P_origin )

        if( None != P_normal ):
            self.normal( P_normal )


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def origin( self, P_origin: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Plane_Origin( self.m_cargo['this'], AddressOf( P_origin ) )

    def normal( self, P_normal: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Plane_Normal( self.m_cargo['this'], AddressOf( P_normal ) )


class Triangle:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Triangle0()

        #self.origin( Coord3D( -1, -1, -1) )#!< debug
        #self.pX(     Coord3D( +1.0, -1.0, -1.0 ) )#!< debug
        #self.pY(     Coord3D( -0.5, -0.5,  1.0 ) )#!< debug

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def origin( self, P_origin: Coord3D  ): #TODO
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_Origin( self.m_cargo['this'], AddressOf( P_origin ) )

    def eX( self, P_eX: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_eX( self.m_cargo['this'], AddressOf( P_eX ) )

    def eY( self, P_eY: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_eY( self.m_cargo['this'], AddressOf( P_eY ) )

    def pX( self, P_pX: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_pX( self.m_cargo['this'], AddressOf( P_pX ) )

    def pY( self, P_pY: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_pY( self.m_cargo['this'], AddressOf( P_pY ) )


class TriangleU:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_TriangleU0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
