import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.math.affine
import IceRayPy.type.math.coord

Pointer = ctypes.POINTER
AddresOf = ctypes.addressof


#Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D
Matrix4D = IceRayPy.type.math.matrix.Scalar4D



class Identity:

    def __init__( self, P_dll, P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Transform_Identity0()
        if( None != P_child ):
            self.child( P_child )


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Transform_Identity_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child


class Translate:
    def __init__( self, P_dll, P_child = None , P_move = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Transform_Translate0()

        if( None != P_child ):
            self.child( P_child )

        if( None != P_move ):
            self.toWorldSet( P_move )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Transform_Translate_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def toWorldGet( self ):
        result = Coord3D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Translate_2World_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toWorldSet( self, P_2world: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Translate_2World_Set( self.m_cargo['this'], AddresOf( P_2world ) )

    def toLocalGet( self ):
        result = Coord3D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Translate_2Local_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toLocalSet( self, P_2local: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Translate_2Local_Set( self.m_cargo['this'], AddresOf( P_2local ) )


class Affine:

    def __init__( self, P_dll,  P_child = None, P_2world = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Transform_Affine0()

        if( None != P_child ):
            self.child( P_child )

        if( None != P_2world ):
            self.toWorldSet( P_2world )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Light_Transform_Affine_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def toWorldGet( self ):
        result = Affine3D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Affine_2World_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toWorldSet( self, P_2world: Affine3D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Affine_2World_Set( self.m_cargo['this'], AddresOf( P_2world ) )

    def toLocalGet( self ):
        result = Affine3D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Affine_2Local_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toLocalSet( self, P_2local: Affine3D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Affine_2Local_Set( self.m_cargo['this'], AddresOf( P_2local ) )


class Homography:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Transform_Homography0()
        if( None != P_child ):
            self.child( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def toWorldGet( self ):
        result = Matrix4D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Homography_2World_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toWorldSet( self, P_2world: Matrix4D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Homography_2World_Set( self.m_cargo['this'], AddresOf( P_2world ) )

    def toLocalGet( self ):
        result = Matrix4D()
        self.m_cargo['dll'].IceRayC_Light_Transform_Homography_2Local_Get( self.m_cargo['this'], AddresOf( result ) )
        return result

    def toLocalSet( self, P_2local: Matrix4D ):
        return self.m_cargo['dll'].IceRayC_Light_Transform_Homography_2Local_Set( self.m_cargo['this'], AddresOf( P_2local ) )

