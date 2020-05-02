import ctypes

import IceRayPy

Pointer = ctypes.POINTER
AddresOf = ctypes.addressof

class Cells:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_Cells0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Crackle:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_Crackle0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Perlin:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_Perlin0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Random:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_Random0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Value:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_Value0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class VDC:
    def __init__(self, P_dll, P_result, P_value : IceRayPy.type.math.coord.Scalar2D ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Noise_VDC0( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

