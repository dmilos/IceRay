import ctypes

print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

SizeType = IceRayPy.type.basic.Size

AddresOf = ctypes.addressof






class Picture:
    def __init__(self, P_dll, P_filename = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Type_Picture0()
        if( None != P_filename ):
            self.load( P_filename )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Type_Picture_Release( self.m_cargo['this'] )


    def size( self, P_width, P_height ):
        self.m_cargo['dll'].IceRayC_Type_Picture_Size( self.m_cargo['this'], SizeType( P_width ), SizeType( P_height ) )


    def load( self, P_filename ):
        self.m_cargo['dll'].IceRayC_Type_Picture_Load( self.m_cargo['this'], P_filename.encode('utf-8') )

    def storePNM( self, P_filename ):
        self.m_cargo['dll'].IceRayC_Type_Picture_StorePNM( self.m_cargo['this'], P_filename.encode('utf-8') )


def Crop( P_dll, P_target, P_source, P_A, P_B ):
        P_dll.IceRayC_Type_Picture_Crop( P_target.m_cargo['this'], P_source.m_cargo['this'], AddresOf( P_A ), AddresOf( P_B ) )

def Default( P_dll, P_image ):
        P_dll.IceRayC_Type_Picture_Default( P_image.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
