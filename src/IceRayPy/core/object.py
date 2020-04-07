
import IceRayPy

class Object:
    def __init__( self, P_dll, P_geometry = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Object0()
        self.m_cargo['geometry'] = IceRayPy.core.geometry.Generic( self.m_cargo['dll'], self.m_cargo['this'] )
        self.m_cargo['medium'] ={};   
        self.m_cargo['pigment'] ={};   
        if( None != P_geometry ):
            self.geometry( P_geometry )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Object_Release( self.m_cargo['this'] )

    def geometry_set( self, P_geometry, P_own = None ):
        self.m_cargo['dll'].IceRayC_Object_GeometrySet( self.m_cargo['this'], P_geometry.m_cargo['this'] )
        self.m_cargo['geometry'] = P_geometry;

    def geometry_get( self ):
        return self.m_cargo['geometry']

    def pigment(self, P_pigment ):
        self.m_cargo['dll'].IceRayC_Object_Pigment( self.m_cargo['this'], P_pigment.m_cargo['this'] )
        self.m_cargo['pigment'] = P_pigment;

    def medium(self, P_medium):
        self.m_cargo['dll'].IceRayC_Object_Medium( self.m_cargo['this'], P_medium.m_cargo['this'] )
        self.m_cargo['medium'] = P_medium;

