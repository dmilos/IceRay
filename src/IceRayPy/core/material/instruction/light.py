import ctypes
import IceRayPy

SizeType = IceRayPy.type.basic.Size

class Generator: # generate light
    def __init__(self, P_dll, P_light, P_result ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_Generator0( P_light.m_cargo['this'], P_result )
        self.m_cargo['light'] = P_light

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class SpotCull: # Triage the spots against normal
    def __init__( self, P_dll, P_outSpotEnd, P_point, P_normal, P_spotBegin, P_spotEnd ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SpotCull0( P_outSpotEnd, P_point, P_normal, P_spotBegin, P_spotEnd )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class SpotConfine:
    def __init__(self, P_dll, P_geometry, P_outSpotEnd, P_spotBegin, P_spotEnd ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Spot_Confine0( P_geometry.m_cargo['this'], P_outSpotEnd, P_spotBegin, P_spotEnd )
        self.m_cargo['geometry'] = P_geometry

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class SpotObstruct:
    def __init__( self, P_dll, P_geometry, P_outSpotEnd, P_spotBegin, P_spotEnd ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Spot_Obstruct0( P_geometry.m_cargo['this'], P_outSpotEnd, P_spotBegin, P_spotEnd )
        self.m_cargo['geometry'] = P_geometry

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class SwarmA: # Make ONLY spots from memory light
    def __init__(self, P_dll, P_outSpot_End, P_inSpot_Begin, P_inLight_Light, P_inCoord_Point ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmA0( SizeType( P_outSpot_End ), SizeType(P_inSpot_Begin), SizeType(P_inLight_Light), SizeType(P_inCoord_Point) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class SwarmB: #Make spots from from memory light and Cull optionally
    def __init__(self, P_dll, P_TODO ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmB0( P_TODO )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class SwarmC:
    def __init__(self, P_dll, P_light, P_outSpot_Count, P_inSpot_Begin,                    P_inCoord_Point, P_inCoord_Normal ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmC0(
            P_light.m_cargo['this'],
            SizeType( P_outSpot_Count ), SizeType( P_inSpot_Begin ),
            SizeType( P_inCoord_Point ), SizeType( P_inCoord_Normal )
        )
        self.m_cargo['light'] = P_light

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

