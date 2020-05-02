import ctypes
import IceRayPy

Size2D = IceRayPy.type.math.coord.Size2D
AddresOf = ctypes.addressof

class Block:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Scanner_Block0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Release( self.m_cargo['this'] )

    def hot( self, P_point: Size2D ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Block_Hot( self.m_cargo['this'], AddresOf( P_point ) )

    def window( self, P_A: Size2D, P_B: Size2D ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Block_Window( self.m_cargo['this'], AddresOf( P_A ), AddresOf( P_B ) )

class Parallel:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Scanner_Parallel0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Release( self.m_cargo['this'] )
