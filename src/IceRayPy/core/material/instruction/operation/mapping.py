import ctypes

import IceRayPy

import IceRayPy

AddressOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

Coord3DType        = IceRayPy.type.math.coord.Scalar3D
Affine3DType       = IceRayPy.type.math.affine.Scalar3D
Homography3DType   = IceRayPy.type.math.matrix.Scalar4D


class Identity3D:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Identity3D0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Translate3D:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def move(self, P_move : Coord3DType ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D_Move( self.m_cargo['this'], AddressOf( P_move ) )


class Affine3D:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Affine3D0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def structure(self, P_structure : Affine3DType ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D_Structure( self.m_cargo['this'], AddressOf( P_structure ) )


class Homography3D:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Homography3D0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def structure(self, P_structure : Homography3DType ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Homography3D_Structure( self.m_cargo['this'], AddressOf( P_structure ) )


class Cartesian2Cylindric:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Cylindric0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2Package:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Package0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2Spherical:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Spherical0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2Torus:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Torus0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2Tablecloth:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Tablecloth0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2WoodX:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodX0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2WoodY:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodY0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2WoodZ:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodZ0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cylindric2Cartesian:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cylindric2Cartesian0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cylindric2Spherical:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cylindric2Spherical0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Spherical2Cartesian:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Spherical2Cartesian0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Spherical2Cylindric:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Spherical2Cylindric0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Euclid2Max:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Euclid2Max0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Max2Euclid:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Max2Euclid0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Cartesian2Fisheye:
    def __init__(self, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Fisheye0( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )



