import ctypes

AddresOf = ctypes.addressof


import IceRayPy

Color    = IceRayPy.type.color.RGB
ScalarType   = IceRayPy.type.basic.Scalar

class Transparent:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Transparent0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )


class Solid:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Solid0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )



g_value = 0.0

class Constant:
    def __init__(self, P_dll, P_value = None, P_deplete = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Constant0()
        self.value(   IceRayPy.type.color.RGB( 1.0, 1.0, 1.0 ) )
        global g_value
        self.deplete( IceRayPy.type.color.RGB( g_value, g_value, g_value ) )
        g_value = g_value + 1/360.0

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )

    def value( self, P_value : Color ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Constant_Value( self.m_cargo['this'], AddresOf( P_value ) )

    def deplete( self, P_deplete : Color ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Constant_Deplete( self.m_cargo['this'], AddresOf( P_deplete ) )

import colorsys
g_hue = 0;

class Linear:
    def __init__(self, P_dll, P_value = None, P_c0 = None, P_c1 = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Linear0()
        global g_hue
        rgb = colorsys.hsv_to_rgb(g_hue/360.0,1,1)
        g_hue = g_hue + 1
        self.value( IceRayPy.type.color.RGB( rgb[0], rgb[0], rgb[0] ) )
        self.A( 0 )
        self.B( 1 )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )

    def value( self, P_value : Color ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Linear_Value( self.m_cargo['this'], AddresOf( P_value ) )

    def A(self, P_A  ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Linear_A( self.m_cargo['this'], ScalarType( P_A ) )

    def B(self, P_B ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Linear_B( self.m_cargo['this'], ScalarType( P_B ) )


class Quadratic:
    def __init__(self, P_dll, P_value = None, P_c0 = None, P_c1 = None, P_c2 = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Quadratic0()
        self.value( IceRayPy.type.color.RGB(1,2,3) )
        self.A( 1 )
        self.B( 2 )
        self.C( 2 )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )

    def value( self, P_value : Color ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Quadratic_Value( self.m_cargo['this'], AddresOf( P_value ) )

    def A(self, P_A ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Quadratic_A( self.m_cargo['this'], ScalarType( P_A ) )

    def B(self, P_B ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Quadratic_B( self.m_cargo['this'], ScalarType( P_B ) )

    def C(self, P_C ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Quadratic_C( self.m_cargo['this'], ScalarType( P_C ) )

class Exponential:
    def __init__( self, P_dll, P_half = None, P_value = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Medium_Exponential0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Medium_Release( self.m_cargo['this'] )

    def value( self, P_value : Color ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Exponential_Value( self.m_cargo['this'], AddresOf( P_value ) )

    def half(self, P_half ):
        self.m_cargo['dll'].IceRayC_Material_Medium_Exponential_Half( self.m_cargo['this'], ScalarType( P_half ) )

