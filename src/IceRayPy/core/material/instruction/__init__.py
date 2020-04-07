

class Ambient:
    def __init__(self, P_dll, P_value = None):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Ambient0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def value(self):
        pass #TODO

class NOP:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_NOP0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )
