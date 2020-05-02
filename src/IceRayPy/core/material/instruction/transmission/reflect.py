print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

SizeType = ctypes.c_uint
ScalarType = ctypes.c_uint
AddresOf = ctypes.addressof

class One:
    def __init__(self, P_dll, P_point, P_normal, P_albedo ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Reflect_One0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_albedo )
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