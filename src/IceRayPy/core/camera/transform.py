import ctypes
import inspect

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord
import IceRayPy.type.math.affine

Pointer = ctypes.POINTER
AddresOf = ctypes.addressof

Integer  = IceRayPy.type.basic.Integer
Coord3D  = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D


class Pin:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        self.m_cargo['child']= {}
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Transform_Pin0()

        if( None != P_child ):
            self.chid( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_Transform_Pin_Child(self.m_cargo['this'], P_child.m_cargo['this'] )

    def origin( self, P_origin : Coord3D ):
        self.m_cargo['dll'].IceRayC_Camera_Transform_Pin_Origin( self.m_cargo['this'], AddresOf( P_origin ) )

class Invert:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        self.m_cargo['child']= {}
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Transform_Invert0()

        if( None != P_child ):
            self.chid( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_Transform_Invert_Child(self.m_cargo['this'], P_child.m_cargo['this'] )

class Affine:
    def __init__( self, P_dll, P_child = None, P_2world = None ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Transform_Affine0()
        if( None != P_child ):
            self.chid( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_Transform_Affine_Child(self.m_cargo['this'], P_child.m_cargo['this'] )
        pass

    def toWorldGet( self ):
        I_2world = Affine3D()
        self.m_cargo['dll'].IceRayC_Camera_Transform_Affine_2World_Get( self.m_cargo['this'], AddresOf( I_2world ) )
        return I_2world

    def toWorldSet( self, P_2world : Affine3D ):
        return self.m_cargo['dll'].IceRayC_Camera_Transform_Affine_2World_Set( self.m_cargo['this'], AddresOf( P_2world ) )

    def toLocalGet( self ):
        I_2local = Affine3D()
        self.m_cargo['dll'].IceRayC_Camera_Transform_Affine_2Local_Get( self.m_cargo['this'], AddresOf( I_2local ) )
        return I_2local

    def toLocalSet( self, P_2local : Affine3D ):
        return self.m_cargo['dll'].IceRayC_Camera_Transform_Affine_2Local_Set( self.m_cargo['this'], AddresOf( P_2local ) )


    def lookAt( self, P_eye : Coord3D, P_view: Coord3D, P_up: Coord3D ):
        self.toWorldSet( IceRayPy.type.math.affine.lookAt( self.m_cargo['dll'], P_eye, P_view, P_up ) )
        return True

    def move( self, P_move : Coord3D ):
        I_2world = self.toWorldGet()
        I_move = IceRayPy.type.math.affine.move3D( self.m_cargo['dll'], P_move )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_2world )
        self.toWorldSet( I_result )

    def scale( self, P_scale ):
        pass

    def rotateX( self, P_angle ):
        pass

    def rotateY( self, P_angle ):
        pass

    def rotateZ( self, P_angle ):
        pass

    def rotateA( self, P_direction : Coord3D, P_alpha ):
        pass

    def rotatePitch( self, P_angle ):
        pass

    def rotateJaw( self, P_angle ):
        pass

    def rotateRoll( self, P_angle ):
        pass
