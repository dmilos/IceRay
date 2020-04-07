class Translate:
    def __init__(self, P_dll, P_output, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Translate0( P_output, P_input)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def transformation(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Translate_Transform( self.m_cargo['this'] )


class Projective:
    def __init__(self, P_dll, P_output, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Projective0(P_output, P_input)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def transformation(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Projective_Transform( self.m_cargo['this'] )


class Affine:
    def __init__(self, P_dll,P_output, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Affine0(P_output, P_input)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def transformation(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Transform_Affine_Transformation( self.m_cargo['this'] )

