import ctypes
import IceRayPy
import IceRayPy.core

Pointer  = ctypes.POINTER
AddresOf = ctypes.addressof

VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Size3D = IceRayPy.type.math.coord.Size3D

#Geometry = IceRayPy.core.geometry.Generic

class Object:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object0()
        self.m_cargo['child']=[]

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def push( self, P_child ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Push( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'].append( P_child )

    def clear( self ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Clear( self.m_cargo['this'] )

    def rtss( self, P_rtss ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Rtss( self.m_cargo['this'], P_rtss.m_cargo['this'] )
        self.m_cargo['rtss'] = P_rtss

    def optimize( self ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Optimize( self.m_cargo['this']  )


class List:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_List0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Release( self.m_cargo['this'] )

class Uniform:
    def __init__( self, P_dll, P_size = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_Uniform0()

        if None != P_size:
            self.dimension( P_size )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Release( self.m_cargo['this'] )

    def dimension( self, P_size : Size3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_RTSS_Uniform_Dimension( self.m_cargo['this'], AddresOf( P_size ) )
