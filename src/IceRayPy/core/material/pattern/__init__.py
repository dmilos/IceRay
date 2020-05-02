print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy.core.material.pattern.constant
import IceRayPy.core.material.pattern.noise
import IceRayPy.core.material.pattern.side

class Image:
    def __init__(self, P_dll, P_picture = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Image0()
        if( None != P_picture ):
            self.picture( P_picture )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

    def picture( self, P_picture ):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Image_Picture( self.m_cargo['this'], P_picture.m_cargo['this'] )
        self.m_cargo['picture'] = P_picture


class Brick:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Brick0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Checker:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Checker0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Hexagon:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Hexagon0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Wave:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Wave0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Onion:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Onion0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Level:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Level0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
