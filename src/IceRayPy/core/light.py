class Spot:
    def __init__( self ):
         pass # TODO

    def __del__( self ):
         pass # TODO

class Area:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Area0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def origin( self, P_origin ):
        pass # TODO

    def X( self, P_origin ):
        pass # TODO

    def Y( self, P_origin ):
        pass # TODO

class Blocked:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Blocked0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Chandelier:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Chandelier0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Circle:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Circle0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Clipped:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Clipped0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


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

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Line:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Line0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Point:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Point0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Reflector:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Reflector0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Sphere:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Sphere0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Spline:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Spline0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )


class Sun:
    def __init__( self, P_dll ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Light_Sun0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )



