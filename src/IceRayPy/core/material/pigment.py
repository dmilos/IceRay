class Default:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Default0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Release( self.m_cargo['this'] )

class Surface:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Release( self.m_cargo['this'] )

    def append(self, P_instruction ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Append( self.m_cargo['this'], P_instruction )
