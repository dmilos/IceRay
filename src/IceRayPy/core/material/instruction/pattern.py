import ctypes

import IceRayPy

Pointer = ctypes.POINTER
AddresOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size

class Size:
    def __init__(self, P_dll, P_pattern, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Pattern_Size0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Scalar:
    def __init__(self, P_dll, P_pattern, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Pattern_Scalar0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Color:
    def __init__(self, P_dll, P_pattern, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Pattern_Color0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Size3D:
    def __init__(self, P_dll, P_pattern, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Size3D0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Coord3D:
    def __init__(self, P_dll, P_pattern, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Scalar3D( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

