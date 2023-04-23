import ctypes

#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

SizeType = IceRayPy.type.basic.Size

AddressOf = ctypes.addressof


#import PIL
#from PIL import Image
#import io




class Picture:
    def __init__(self, P_dll, P_filename = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Type_Picture0()
        if( None != P_filename ):
            self.load( P_filename )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Type_Picture_Release( self.m_cargo['this'] )


    def set( self, P_location, P_color ):
        return self.m_cargo['dll'].IceRayC_Type_Picture_Set( self.m_cargo['this'], AddressOf( P_location ), AddressOf( P_color ) )

    def size( self, P_width=None, P_height=None ):
        if( ( None != P_width ) and ( None != P_height ) ):
            self.m_cargo['dll'].IceRayC_Type_Picture_Size( self.m_cargo['this'], SizeType( P_width ), SizeType( P_height ) );

        result = IceRayPy.type.math.coord.Size2D()
        self.m_cargo['dll'].IceRayC_Type_Picture_SizeGet( self.m_cargo['this'], AddressOf( result ) );
        return result

    def load( self, P_filename ):
        return self.m_cargo['dll'].IceRayC_Type_Picture_Load( self.m_cargo['this'], P_filename.encode('utf-8') )

    def storePNM( self, P_filename ):
        self.m_cargo['dll'].IceRayC_Type_Picture_StorePNM( self.m_cargo['this'], P_filename.encode('utf-8') )

    def storePNG( self, P_filename ):
        self.m_cargo['dll'].IceRayC_Type_Picture_StorePNG( self.m_cargo['this'], P_filename.encode('utf-8') )

    def storeJPEG( self, P_filename ):
        self.m_cargo['dll'].IceRayC_Type_Picture_StoreJPEG( self.m_cargo['this'], P_filename.encode('utf-8') )

    #def store( self, P_filename ):
    #    #s = self.size()
    #    #I_image = PIL.Image.frombytes( 'RGB', ( s[0], s[1] ), self.buffer(), 'raw', 'RGB', 0, 1 )
    #    #I_image.save( P_filename )
    #    pass

    def buffer( self ):
        pointer = self.m_cargo['dll'].IceRayC_Type_Picture_Buffer( self.m_cargo['this'] )
        return pointer
        #return ctypes.create_string_buffer( pointer, self.size()[0] * self.size()[1] )

    def crop( self, P_target, P_A, P_B ):
        self.m_cargo['dll'].IceRayC_Type_Picture_Crop( P_target.m_cargo['this'], self.m_cargo['this'], AddressOf( P_A ), AddressOf( P_B ) )

    def clear( self, P_color ):
        self.m_cargo['dll'].IceRayC_Type_Picture_Clear( self.m_cargo['this'], AddressOf( P_color ) )

    def average( self, P_average ):
        self.m_cargo['dll'].IceRayC_Type_Picture_Average( self.m_cargo['this'], AddressOf( P_average ) )

    def dispersion( self ):
        return self.m_cargo['dll'].IceRayC_Type_Picture_Dispersion( self.m_cargo['this'] )

def Crop( P_target, P_source, P_A, P_B ):
    P_source.m_cargo['dll'].IceRayC_Type_Picture_Crop( P_target.m_cargo['this'], P_source.m_cargo['this'], AddressOf( P_A ), AddressOf( P_B ) )

def Default( P_image ):
    P_image.m_cargo['dll'].IceRayC_Type_Picture_Default( P_image.m_cargo['this'] )

#def Print( P_image, P_position, P_string ):
     #s = self.size()
     #I_image = PIL.Image.frombytes( 'RGB', ( s[0], s[1] ), self.buffer(), 'raw', 'RGB', 0, 1 )
     #ImageDraw.Draw( I_image ).text(0,0), P_string )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
