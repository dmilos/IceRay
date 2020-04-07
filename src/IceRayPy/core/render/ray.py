import ctypes

Integer = ctypes.c_int
Scalar = ctypes.c_double

class Direction:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Ray_Direction0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Release( self.m_cargo['this'] )

class Distance:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Ray_Distance0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Release( self.m_cargo['this'] )

    def geometry( self, P_geometry ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Distance_Geometry( self.m_cargo['this'], P_geometry.m_cargo['this'] )
        self.m_cargo['object'] = P_geometry

    def clip( self, P_clip ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Distance_Clip( self.m_cargo['this'], P_clip )

class Trace:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Ray_Trace0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Release( self.m_cargo['this'] )

    def object( self, P_object ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Trace_Object( self.m_cargo['this'], P_object.m_cargo['this'] )
        self.m_cargo['object'] = P_object

    def depth( self, P_depth ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Trace_Depth( self.m_cargo['this'], Integer(P_depth) )

    def trash( self, P_trash ):
        self.m_cargo['dll'].IceRayC_Render_Ray_Trace_Trash( self.m_cargo['this'], Scalar(P_trash) )
