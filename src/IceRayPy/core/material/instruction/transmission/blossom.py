print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

AddresOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

class Grid:
    def __init__(self, P_dll, P_normal, P_leader, P_side, P_angle, P_gauss, P_total, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Grid0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_side )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_total )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Hexagon:
    def __init__(self, P_dll, P_normal, P_leader, P_radius, P_angle, P_gauss, P_total, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Hexagon0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_radius )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_total )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Pinwheel:
    def __init__(self, P_dll, P_normal, P_leader, P_radius, P_angle, P_gauss, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Pinwheel0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_radius )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Random:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Random0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Sobol:
    def __init__( self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Sobol0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Triangle:
    def __init__(self, P_dll, P_normal, P_leader, P_radius, P_angle, P_gauss, P_total, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Triangle0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_radius )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_total )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class VDC:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_VDC0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
           ,SizeType( P_start )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
