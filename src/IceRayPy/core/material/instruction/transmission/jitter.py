#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

AddressOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

class Sobol:
    def __init__(self, P_dll, P_normal, P_count, P_leader, P_angle ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_Sobol0(
            SizeType( P_normal )
          ,SizeType( P_count )
          ,SizeType( P_leader )
          ,SizeType( P_angle )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Random:
    def __init__(self, P_dll, P_normal, P_count, P_leader, P_angle ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_Random0(
            SizeType( P_normal )
           ,SizeType( P_count )
           ,SizeType( P_leader )
           ,SizeType( P_angle )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class VDC:
    def __init__(self, P_dll, P_normal, P_count, P_leader, P_angle ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_VDC0(
            SizeType( P_normal )
           ,SizeType( P_count )
           ,SizeType( P_leader )
           ,SizeType( P_angle )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
