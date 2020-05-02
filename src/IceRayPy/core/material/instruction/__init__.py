print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.core.material.instruction.illumination
import IceRayPy.core.material.instruction.pattern
import IceRayPy.core.material.instruction.transmission
import IceRayPy.core.material.instruction.light
import IceRayPy.core.material.instruction.label
import IceRayPy.core.material.instruction.operation
import IceRayPy.core.material.instruction.constant

class NOP:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_NOP0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
