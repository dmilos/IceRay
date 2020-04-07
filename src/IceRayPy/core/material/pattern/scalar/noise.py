class VDC:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_VDC0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_Release( self.m_cargo['this'] )

class Random:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_Random0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_Release( self.m_cargo['this'] )

class Gold:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_Gold0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Scalar_Release( self.m_cargo['this'] )

