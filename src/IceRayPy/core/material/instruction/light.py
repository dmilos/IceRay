class Generator:
    def __init__(self, P_dll, P_light, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_Generator0( P_output, P_result )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def light(self, P_light ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_Generator_Light( self.m_cargo['this'], P_light.m_cargo['this'] )
        self.m_cargo['light'] = P_light


class SwarmA: # Make ONLY spots from memory light
    def __init__(self, P_dll, P_TODO ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmA0( P_TODO )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def light(self, P_light ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmA_Light( self.m_cargo['this'], P_light.m_cargo['this'] )
        self.m_cargo['light'] = P_light


class SwarmB: #Make spots from their own light and Cull
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmB0( P_TODO )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def light(self, P_light ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmB_Light( self.m_cargo['this'], P_light.m_cargo['this'] )
        self.m_cargo['light'] = P_light


class SwarmC:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmC0( P_TODO )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def light(self, P_light ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmC_Light( self.m_cargo['this'], P_light.m_cargo['this'] )
        self.m_cargo['light'] = P_light

