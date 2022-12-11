print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

AddresOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

class One:
    def __init__(self, P_dll, P_point, P_normal, P_albedo, P_index ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Reflect_One0(
           SizeType( P_point  )
          ,SizeType( P_normal )
          ,SizeType( P_albedo )
          ,SizeType( P_index  )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Schlick:
    def __init__(self, P_dll, P_point, P_normal, P_ior ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Reflect_Schlick0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_ior )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

print( '</' + __name__ + ' name=\'' +   __file__ + '>' )