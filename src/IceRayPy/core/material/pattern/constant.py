class Size:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Size( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Scalar( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Color:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Color( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar2D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Scalar2D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar3D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Scalar3D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar4D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Scalar4D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )


class Size2D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Size2D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Scalar3D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Size3D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )

class Size4D:
    def __init__(self, P_dll, P_result, P_value ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Contant_Coord_Size4D( P_output, AddresOf( P_value ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Release( self.m_cargo['this'] )
