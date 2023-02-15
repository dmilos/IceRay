#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

AddressOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar


class Fresnel:
    def __init__(self, P_dll, P_point, P_normal, P_ior, P_albedo, P_total, P_leader ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Fresnel0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_ior )
          ,SizeType( P_albedo )
          ,SizeType( P_total )
          ,SizeType( P_leader )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Multi:
    def __init__(self, P_dll, P_point, P_normal, P_ior, P_albedo ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Multi0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_ior )
          ,SizeType( P_albedo )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Schlick:
    def __init__(self, P_dll, P_point, P_normal, P_ior, P_albedo, P_total, P_leader ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Schlick0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_ior )
          ,SizeType( P_albedo )
          ,SizeType( P_total )
          ,SizeType( P_leader )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class Snell:
    def __init__(self, P_dll, P_point, P_normal, P_ior, P_albedo, P_transparency, P_leader ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Snell0(
           SizeType( P_point )
          ,SizeType( P_normal )
          ,SizeType( P_ior )
          ,SizeType( P_albedo )
          ,SizeType( P_transparency )
          ,SizeType( P_leader )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
