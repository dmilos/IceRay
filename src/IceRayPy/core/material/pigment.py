from ctypes import *
import IceRayPy

class Constant:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Constant0()

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Release( self.m_cargo['this'] )


class Surface:
    def __init__(self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface0()
        self.m_cargo['list'] = []
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Result(   self.m_cargo['this'], IceRayPy.core.material.instruction.label.color.dynamic.RESULT     )
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Lambda(   self.m_cargo['this'], IceRayPy.core.material.instruction.label.scalar.dynamic.LAMBDA    )
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Point(    self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT    )
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Normal(   self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL   )
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Origin(   self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.ORIGIN   )
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Incident( self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT )
       #self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Reflected(self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.REFLECTED)
       #self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Bump(     self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.BUMP     )
       #self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_UVW(      self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.UVW      )
       #self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Viewer(   self.m_cargo['this'], IceRayPy.core.material.instruction.label.coord3d.dynamic.VIEWER   )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Release( self.m_cargo['this'] )

    def append(self, P_instruction ): # P_instruction : IceRayPy.core.material.pigment.instruction
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Append( self.m_cargo['this'], P_instruction.m_cargo['this'] )
        self.m_cargo['list'].append( P_instruction )
