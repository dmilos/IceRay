import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math.affine
import IceRayPy.type.math.coord

Pointer = ctypes.POINTER
AddressOf = ctypes.addressof


#Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Scalar = IceRayPy.type.basic.Scalar

Coord3D = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D
Matrix4D = IceRayPy.type.math.matrix.Scalar4D


class Identity:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Identity0()
        self.child( IceRayPy.core.geometry.simple.Sphere( P_dll ) ) #<! default

        if( None != P_child ) and ( hasattr( P_child, 'm_cargo' ) ):
            self.child( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Identity_Child( self.m_cargo['this'], P_child.m_cargo['this'] )


class Translate:
    def __init__( self, P_dll,  P_child = None , P_move = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate0()
        self.child(  IceRayPy.core.geometry.simple.Sphere( P_dll ) )

        if( None != P_child ) and ( hasattr( P_child, 'm_cargo' ) ):
            self.child( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def move(self, P_move : Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Move( self.m_cargo['this'], AddressOf( P_move ) )


class Affine:
    def __init__( self, P_dll,  P_child = None, P_affine = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine0()

        self.child( IceRayPy.core.geometry.simple.Sphere( P_dll ) ) #<! default

        if( None != P_child ) and ( hasattr( P_child, 'm_cargo' ) ):
            self.child( P_child )

        tO = Coord3D( -1, -1, -0.5 )
        tX = Coord3D(  1, -1, -0.5 )
        tY = Coord3D( -1, +1, -0.5 )
        tZ = Coord3D( -1, -1, +0.5 )

        sO = Coord3D( -1, -1, -1 )
        sX = Coord3D(  1, -1, -1 )
        sY = Coord3D( -1, +1, -1 )
        sZ = Coord3D( -1, -1, +1 )

        result = IceRayPy.type.math.affine.construct3D( P_dll, tO, tX, tY, tZ, sO, sX, sY, sZ )

        self.toWorld( result )
        if( None != P_affine ):
            self.toWorld( P_affine )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def toWorld( self, P_2world = None ):  #P_2world = None: Affine3D
        if( None != P_2world ):
            self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2World_Set( self.m_cargo['this'], AddressOf( P_2world ) )

        result = Affine3D()
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2World_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def toLocalGet( self ):
        result = Affine3D()
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2Local_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def toLocalSet( self, P_2local: Affine3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2Local_Set( self.m_cargo['this'], AddressOf( P_2local ) )

    def move( self, P_move : Coord3D ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.move( self.m_cargo['dll'], P_move )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def scaleV(self, P_scaleV : Coord3D ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.scaleV( self.m_cargo['dll'], P_scaleV )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def rotateX( self, P_angle ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.rotateX( self.m_cargo['dll'], P_angle )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def rotateY( self, P_angle ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.rotateY( self.m_cargo['dll'], P_angle )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def rotateZ( self, P_angle ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.rotateZ( self.m_cargo['dll'], P_angle )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def rotateA( self, P_direction : Coord3D, P_angle ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.rotateA( self.m_cargo['dll'], P_direction, P_angle )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return

    def rotateD( self, P_pivot : Coord3D, P_direction : Coord3D, P_angle ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.rotateD( self.m_cargo['dll'], P_pivot, P_direction, P_angle )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )
        return


class Homography:
    def __init__( self, P_dll, P_child = None, P_homography = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography0()

        self.child(  IceRayPy.core.geometry.simple.Cylinder( P_dll ) )
        self.child(  IceRayPy.core.geometry.flat.Box( P_dll, Coord3D( -1, -1, -1 ), Coord3D( +1, +1, +1 ) ) )
        self.child(  IceRayPy.core.geometry.simple.Sphere( P_dll ) )   #<! default

        #self.m_cargo['object'] = IceRayPy.library.geometry.Grid( P_dll )
        #self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_Child( self.m_cargo['this'], self.m_cargo['object'].cast2Geometry() )

        if( None != P_child ) and ( hasattr( P_child, 'm_cargo' ) ):
            self.child( P_child )

        move = Coord3D( 1, 0*1, 0 )

        tO = Coord3D( -1, -1, -0.5 )
        tX = Coord3D(  1, -1, -0.5 )
        tY = Coord3D( -1, +1, -0.5 )
        tZ = Coord3D( -1, -1, +0.5 )
        tT = Coord3D(  1,  1, +0.5 )

        sO = Coord3D( -1, -1, -1 )
        sX = Coord3D(  1, -1, -1 )
        sY = Coord3D( -1, +1, -1 )
        sZ = Coord3D( -1, -1, +1 )
        sT = Coord3D(  1,  1,  1 )

        result = IceRayPy.type.math.homography.construct3D( P_dll, tO, tX, tY, tZ, tT, sO, sX, sY, sZ, sT )

        self.toWorld( result )
        if( None != P_homography ):
            self.toWorld( P_homography )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def toWorld( self, P_2world = None ):
        if( None != P_2world ):
            self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_2World_Set( self.m_cargo['this'], AddressOf( P_2world ) )
        result = Matrix4D()
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_2World_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def toLocal( self, P_2local : Matrix4D ):
        if( None != P_2local ):
            self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_2Local_Set( self.m_cargo['this'], AddressOf( P_2local ) )
        result = Matrix4D()
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Homography_2Local_Get( self.m_cargo['this'], AddressOf( result ) )
        return result


class MotionBlur:
    def __init__( self, P_dll, P_child = None , P_direction = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_MotionBlur0()
        self.child(  IceRayPy.core.geometry.simple.Sphere( P_dll ) )

        if( None != P_child ) and ( hasattr( P_child, 'm_cargo' ) ):
            self.child( P_child )

        if( None != P_direction ):
            self.direction( P_direction )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_MotionBlur_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def direction(self, P_move : Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Transform_MotionBlur_Direction( self.m_cargo['this'], AddressOf( P_move ) )


