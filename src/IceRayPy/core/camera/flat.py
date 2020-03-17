class Perspective:

    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatPerspective0()

    #def __init__(self, P_dll, P_aspect ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatPerspective1(P_aspect)
    #
    #def __init__(self, P_dll, P_width, P_height ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatPerspective2(P_width, P_height)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def width(self, P_width):
        return self.m_cargo['dll'].IceRayC_CameraFlatPerspective_Width(self.m_cargo['this'], P_width )

    def height(self, P_height):
        return self.m_cargo['dll'].IceRayC_CameraFlatPerspective_Height(self.m_cargo['this'], P_height )

    def aspect(self, P_aspect):
        return self.m_cargo['dll'].IceRayC_CameraFlatPerspective_Height(self.m_cargo['this'], P_aspect )

class Orthogonal:
    
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal0()

    #def __init__(self, P_dll, P_aspect ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal1(P_aspect)
    #
    #def __init__(self, P_dll, P_width, P_height ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal2(P_width, P_height)

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def width(self, P_width):
        return self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal_Width(self.m_cargo['this'], P_width )

    def height(self, P_height):
        return self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal_Height(self.m_cargo['this'], P_height )

    def aspect(self, P_aspect):
        return self.m_cargo['dll'].IceRayC_CameraFlatOrthogonal_Height(self.m_cargo['this'], P_aspect )

