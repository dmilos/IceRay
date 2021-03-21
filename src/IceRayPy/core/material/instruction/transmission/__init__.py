print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.core.material.instruction.transmission.reflect
import IceRayPy.core.material.instruction.transmission.refract
import IceRayPy.core.material.instruction.transmission.blossom
import IceRayPy.core.material.instruction.transmission.jitter


class Jitter:
    def __init__(self, P_dll, P_normal, P_bump, P_count, P_start ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter0(
            SizeType( P_normal )
           ,SizeType( P_bump   )
           ,SizeType( P_count  )
           ,SizeType( P_start  )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Correct:
    def __init__(self, P_dll, P_cout, P_begin, P_angle ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct0(
            SizeType( P_cout  )
           ,SizeType( P_begin )
           ,SizeType( P_angle )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )



print( '</' + __name__ + ' name=\'' +   __file__ + '>' )