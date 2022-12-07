print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

AddresOf = ctypes.addressof

SizeType   = IceRayPy.type.basic.Size
ScalarType = IceRayPy.type.basic.Scalar

class Cone:
    def __init__(self, P_dll, P_normal, P_bump, P_angleIn, P_angleOut ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Cone0(
            SizeType( P_normal  )
           ,SizeType( P_bump )
           ,SizeType( P_angleIn )
           ,SizeType( P_angleOut )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Direction:
    def __init__(self, P_dll, P_normal, P_leader, P_count, P_angle ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Direction0(
            SizeType( P_normal  )
           ,SizeType( P_leader )
           ,SizeType( P_count )
           ,SizeType( P_angle )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
