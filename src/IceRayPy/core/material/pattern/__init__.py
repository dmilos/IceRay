#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import ctypes
import IceRayPy.core.material.pattern.constant
import IceRayPy.core.material.pattern.noise
import IceRayPy.core.material.pattern.side

AddressOf = ctypes.addressof

Color    = IceRayPy.type.color.RGB
ScalarType   = IceRayPy.type.basic.Scalar

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


class Gradient:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Gradient0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

    def set(self, P_point, P_value, P_type = None ):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Gradient_Set( self.m_cargo['this'], ScalarType( P_point ), AddressOf( P_value ) )

    def bottom( self, P_bottom ):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Gradient_Bottom( self.m_cargo['this'], AddressOf( P_bottom ) )
    
    def top( self, P_top ):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Gradient_Top( self.m_cargo['this'], AddressOf( P_top ) )

    def clear( self ):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Gradient_Clear( self.m_cargo['this'] )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
