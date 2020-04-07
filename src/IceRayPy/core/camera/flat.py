import ctypes

Scalar = ctypes.c_double

class Perspective:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Perspective0()

    #def __init__(self, P_dll, P_aspect ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlat_Perspective1(P_aspect)
    #
    #def __init__(self, P_dll, P_width, P_height ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlat_Perspective2(P_width, P_height)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def width(self, P_width):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Perspective_Width(self.m_cargo['this'], Scalar( P_width ) )

    def height(self, P_height):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Perspective_Height(self.m_cargo['this'], Scalar( P_height ) )

    def aspect(self, P_aspect):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Perspective_Height(self.m_cargo['this'], Scalar( P_aspect ) )

class Orthogonal:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal0()

    #def __init__(self, P_dll, P_aspect ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal1(P_aspect)
    #
    #def __init__(self, P_dll, P_width, P_height ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal2(P_width, P_height)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def width(self, P_width):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal_Width(self.m_cargo['this'], Scalar( P_width ) )

    def height(self, P_height):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal_Height(self.m_cargo['this'], Scalar( P_height ) )

    def aspect(self, P_aspect):
        return self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal_Height(self.m_cargo['this'], Scalar( P_aspect ) )

