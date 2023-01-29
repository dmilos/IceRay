print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

Pointer = ctypes.POINTER
AddressOf = ctypes.addressof

class Size:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Size0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Scalar0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Color:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Color0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar2D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Scalar2D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar3D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Scalar3D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar4D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Scalar4D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Size2D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Size2D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar3D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Size3D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Size4D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Constant_Coord_Size4D0( P_output, AddressOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
