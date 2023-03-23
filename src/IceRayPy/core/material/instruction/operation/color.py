import ctypes

import IceRayPy

SizeType = IceRayPy.type.basic.Size

class Addition:
    def __init__( self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Addition0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Load:
    def __init__(self, P_dll,  P_result, P_r, P_g, P_b ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Load0( SizeType( P_result ), SizeType( P_r ), SizeType( P_g ), SizeType( P_b ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Multiply:
    def __init__( self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Multiply0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Scale:
    def __init__(self, P_dll,  P_result, P_scalar, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Scale0( SizeType( P_result ), SizeType( P_scalar ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Subtraction:
    def __init__( self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Sutraction0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

