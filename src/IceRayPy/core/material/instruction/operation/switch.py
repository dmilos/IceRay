import ctypes

SizeType = ctypes.c_uint

class Size:
    def __init__(self, P_dll, P_result, P_input, P_candidate ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Size0( SizeType( P_result ), SizeType( P_input ), SizeType( P_candidate ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Scalar:
    def __init__(self, P_dll, P_result, P_input, P_candidate ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Scalar0( SizeType( P_result ), SizeType( P_input ), SizeType( P_candidate ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Color:
    def __init__(self, P_dll, P_result, P_input, P_candidate ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Color0( SizeType( P_result ), SizeType( P_input ), SizeType( P_candidate ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Coord2D:
    def __init__(self, P_dll, P_result, P_input, P_candidate ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord2D0( SizeType( P_result ), SizeType( P_input ), SizeType( P_candidate ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Coord3D:
    def __init__(self, P_dll, P_result, P_input, P_candidate ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord3D0( SizeType( P_result ), SizeType( P_input ), SizeType( P_candidate ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
