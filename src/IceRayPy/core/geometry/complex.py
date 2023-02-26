import ctypes

import IceRayPy.type.math.interval

SizeType    = ctypes.c_size_t
IntegerType = ctypes.c_int
AddressOf = ctypes.addressof


class Intersect:
    IN          = 1 #,
    OUT         = 2 #,
    SYMMETRIC   = 3 #, // = En_in + En_out
    SURFACE     = 4 #,
    CLOSURE     = 5 #, // = En_surface + En_in
    COMPLEMENT  = 6 #, // = En_surface + En_out
    EVERYWHERE  = 7 #  // = En_in + En_out + En_surface

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def left( self, P_left, P_where = None ):
        if( None == P_where ):
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Left0( self.m_cargo['this'], P_left.m_cargo['this'] )
        else:
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Left1( self.m_cargo['this'], P_left.m_cargo['this'], IntegerType( P_where ) )
        self.m_cargo['left'] = P_left

    def right( self, P_right, P_where = None ):
        if( None == P_where ):
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Right0( self.m_cargo['this'], P_right.m_cargo['this'] )
        else:
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Right1( self.m_cargo['this'], P_right.m_cargo['this'], IntegerType( P_where ) )
        self.m_cargo['right'] = P_right

    def invert( self, P_invert ):
        return self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Invert( self.m_cargo['this'], IntegerType( P_invert ) )

    def box( self ):
        result = IceRayPy.type.math.interval.Scalar3D()
        self.m_cargo['dll'].IceRayC_Geometry__Base_GetBox( self.m_cargo['this'], AddressOf( result ) )
        return result

class Enclose:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Complex_Enclose0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Geometry_Complex_Enclose_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def hull( self, P_hull ):
        self.m_cargo['dll'].IceRayC_Geometry_Complex_Enclose_Hull( self.m_cargo['this'], P_hull.m_cargo['this'] )
        self.m_cargo['hull'] = P_hull
