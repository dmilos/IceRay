import ctypes

SizeType = ctypes.c_uint
ScalarType = ctypes.c_uint
AddresOf = ctypes.addressof

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
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord2D0( AddresOf( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Coord3D:
    def __init__(self, P_dll, P_value, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord3D0( AddresOf( P_value ), SizeType( P_result ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
