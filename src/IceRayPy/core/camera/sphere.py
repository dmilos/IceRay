import ctypes

import IceRayPy

Scalar = IceRayPy.type.basic.Scalar

class Fisheye:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Sphere_Fisheye0()
    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def radius(self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Fisheye_Radius(self.m_cargo['this'], Scalar( P_radius ) )

    def phi(self, P_phi ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Fisheye_Phi(self.m_cargo['this'], Scalar( P_phi ) )

    def theta(self, P_theta ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Fisheye_Theta(self.m_cargo['this'], Scalar( P_theta ) )

class Horizontal:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Sphere_Horizontal0()
    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def radius(self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Horizontal_Radius(self.m_cargo['this'], Scalar( P_radius ) )

    def phi(self, P_phi ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Horizontal_Phi(self.m_cargo['this'], Scalar( P_phi ) )

    def theta(self, P_theta ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Horizontal_Theta(self.m_cargo['this'], Scalar( P_theta ) )


class Vertical:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Sphere_Vertical0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def radius(self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Vertical_Radius(self.m_cargo['this'], Scalar( P_radius ) )

    def phi(self, P_phi ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Vertical_Phi(self.m_cargo['this'], Scalar( P_phi ) )

    def theta(self, P_theta ):
        return self.m_cargo['dll'].IceRayC_Camera_Sphere_Vertical_Theta(self.m_cargo['this'], Scalar( P_theta ) )
