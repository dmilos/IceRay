print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

SizeType = ctypes.c_uint
ScalarType = ctypes.c_uint
AddresOf = ctypes.addressof

class Grid:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Grid0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Hexagon:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Hexagon0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Random:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Random0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class VDC:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle, P_gauss ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Vdc0(
            SizeType( P_normal )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
           ,SizeType( P_gauss )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
