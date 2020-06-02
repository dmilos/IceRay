import ctypes

import IceRayPy

Coord3D     = IceRayPy.type.math.coord.Scalar3D

Scalar = IceRayPy.type.basic.Scalar
AddresOf = ctypes.addressof

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
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal0()

    #def __init__( self, P_dll, P_aspect ):
    #    self.m_cargo = {}
    #    self.m_cargo['dll'] = P_dll
    #    self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal1(P_aspect)
    #
    #def __init__( self, P_dll, P_width, P_height ):
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



class Super:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_Flat_Orthogonal0()

    def eye(self, P_eye : Coord3D ):
        self.m_cargo['dll'].IceRayC_Camera_Flat_Super_Eye(self.m_cargo['this'], AddresOf( P_eye ) )

    def ocular(self, P_ocular : Coord3D):
        self.m_cargo['dll'].IceRayC_Camera_Flat_Super_Ocular(self.m_cargo['this'], AddresOf( P_ocular ) )

    def view(self, P_view : Coord3D):
        self.m_cargo['dll'].IceRayC_Camera_Flat_Super_View(self.m_cargo['this'], AddresOf( P_view ) )

    def objective(self, P_objective : Coord3D):
        self.m_cargo['dll'].IceRayC_Camera_Flat_Super_Objective(self.m_cargo['this'], AddresOf( P_objective ) )

    def focus(self, P_focus : Coord3D):
        self.m_cargo['dll'].IceRayC_Camera_Flat_Super_Focus(self.m_cargo['this'], AddresOf( P_focus ) )
