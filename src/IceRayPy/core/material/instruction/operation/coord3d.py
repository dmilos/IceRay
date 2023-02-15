import ctypes

import IceRayPy

import IceRayPy

AddressOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

Coord3DType        = IceRayPy.type.math.coord.Scalar3D
Affine3DType       = IceRayPy.type.math.affine.Scalar3D
Homography3DType   = IceRayPy.type.math.matrix.Scalar4D



class Addition:
    def __init__(self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Addition0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Cross:
    def __init__(self, P_dll, P_result,  P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Cross0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Load:
    def __init__(self, P_dll, P_result, P_X, P_Y, P_Z ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Load0( SizeType( P_result ), SizeType( P_X ), SizeType( P_Y ), SizeType( P_Z ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Multiply:
    def __init__(self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Multiply0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Scale:
    def __init__(self, P_dll, P_result, P_scalar, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Scale0( SizeType( P_result ), SizeType( P_scalar ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Subtraction:
    def __init__(self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Subtraction0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Unit:
    def __init__(self, P_dll, P_result, P_left ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Unit0( SizeType( P_result ), SizeType( P_left ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Dot:
    def __init__(self, P_dll, P_result, P_left, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Dot0( SizeType( P_result ), SizeType( P_left ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Length:
    def __init__(self, P_dll, P_result, P_right ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Length0( SizeType( P_result ), SizeType( P_right ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

