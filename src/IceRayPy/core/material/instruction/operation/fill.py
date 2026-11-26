import ctypes

import IceRayPy

import IceRayPy

AddressOf = ctypes.addressof

BoolType     = IceRayPy.type.basic.Bool
IntegerType  = IceRayPy.type.basic.Integer
SizeType     = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar
ColorType    = IceRayPy.type.color.RGB
Coord2DType  = IceRayPy.type.math.coord.Scalar2D
Coord3DType  = IceRayPy.type.math.coord.Scalar3D


class Bool:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Bool0( SizeType( P_result ), BoolType( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Integer:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Integer0( SizeType( P_result ), IntegerType( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Scalar:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Scalar0( SizeType( P_result ), ScalarType( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Color:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Color0( SizeType( P_result ), AddressOf( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Coord2D:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Coord2D0( SizeType( P_result ), AddressOf( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Coord3D:
    def __init__(self, P_dll, P_result, P_value, P_size):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Fill_Coord3D0( SizeType( P_result ), AddressOf( P_value ), SizeType( P_size ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
