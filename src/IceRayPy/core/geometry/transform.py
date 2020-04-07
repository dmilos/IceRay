import IceRayPy
import IceRayPy.type
import IceRayPy.type.math.affine
import IceRayPy.type.math.coord

Coord3D  = IceRayPy.type.math.coord.Scalar3D
Affine3D = IceRayPy.type.math.affine.Scalar3D


class Identity:

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Identity0()

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

        if( None != P_child ):
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Child(  self.m_cargo['this'], P_child.m_cargo['this'] )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def move(self, P_move : Coord3D ):
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Move( self.m_cargo['this'], P_move )


class Affine:

    def __init__( self, P_dll,  P_child = None , P_affine = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine0()

        if( None != P_child ):
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_Child(  self.m_cargo['this'], self.m_cargo['child']['this'])

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def toWorldGet( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2World( self.m_cargo['this'] )

    def toWorldSet( self, P_2wolrd: Affine3D ):
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_2World( self.m_cargo['this'], P_2wolrd )

    def move(self, P_move : Coord3D ):
        pass #TODO;

    def scaleV(self, P_move : Coord3D ):
        pass #TODO;

    def rotateX(self, P_alpha ):
        pass #TODO;

    def rotateY(self, P_alpha ):
        pass #TODO;

    def rotateZ(self, P_alpha ):
        pass #TODO;
    def rotateA(self, P_direction : Coord3D, P_alpha ):
        pass #TODO;
