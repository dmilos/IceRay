#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.core.material.instruction.illumination
import IceRayPy.core.material.instruction.pattern
import IceRayPy.core.material.instruction.transmission
import IceRayPy.core.material.instruction.light
import IceRayPy.core.material.instruction.label
import IceRayPy.core.material.instruction.operation
import IceRayPy.core.material.instruction.constant
import IceRayPy.core.material.instruction.convert
import IceRayPy.core.material.instruction.setup

SizeType   = IceRayPy.type.basic.Size
ScalarType = IceRayPy.type.basic.Scalar

class NOP:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_NOP0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Expression:
    def __init__(self, P_dll, P_output, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Expression0( SizeType( P_output ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

    def expression( self, P_expression ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Expression_Expression( self.m_cargo['this'], P_expression.encode('utf-8') )

    def string2index( self, P_index, P_name ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Expression_String2Index( self.m_cargo['this'], P_index, P_name.encode('utf-8') )

    def index2index( self, P_target, P_source ):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Operation_Expression_Index2Index( self.m_cargo['this'], P_target, P_source )

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
