import ctypes

SizeType = ctypes.c_uint

class Addition:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Addition0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Subtraction:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Color_Sutraction0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
