import ctypes

SizeType = ctypes.c_uint

class Ramp:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Ramp0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Saw:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Saw0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Wave:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Wave0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Sinkhole:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Sinkhole0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Relu:
    def __init__(self, P_dll,  P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Relu0( P_pattern.m_cargo['this'], SizeType( P_result ), SizeType( P_input ) )
        self.m_cargo['pattern'] = P_pattern

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
