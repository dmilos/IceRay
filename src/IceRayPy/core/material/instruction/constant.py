import ctypes

import IceRayPy

AddresOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar


class Size:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Size0( SizeType( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Scalar:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Scalar0( ScalarType( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Color:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Color0( AddresOf( P_value ), SizeType( P_result ) )


    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Coord2D:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar2D0( AddresOf( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Coord3D:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar3D0( AddresOf( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
