import ctypes

import IceRayPy
import IceRayPy.type
import IceRayPy.type.basic

Scalar = IceRayPy.type.basic.Scalar

class Horizontal:
    def __init__(self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Cylinder_Horizontal0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def width(self, P_width ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Horizontal_Width(self.m_cargo['this'], Scalar( P_width ) )

    def theta(self, P_theta ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Horizontal_Theta(self.m_cargo['this'], Scalar( P_theta ) )

    def radius(self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Horizontal_Radius(self.m_cargo['this'], Scalar( P_radius ) )


class Vertical:
    def __init__(self, P_dll, P_config = None):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Cylinder_Vertical0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def phi(self, P_phi ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Vertical_Phi(self.m_cargo['this'], Scalar( P_phi ) )

    def height(self, P_height ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Vertical_Height(self.m_cargo['this'], Scalar( P_height ) )

    def radius(self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Camera_Cylinder_Vertical_Radius(self.m_cargo['this'], Scalar( P_radius ) )
