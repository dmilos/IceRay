import ctypes

import IceRayPy

SizeType   = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

class _General:
    def __init__(self, P_native, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].P_native( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

def Bool2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Bool0, P_dll, P_result, P_input )

def Bool2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Integer0 , P_dll, P_result, P_input )

def Bool2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Size0 , P_dll, P_result, P_input )

def Bool2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Scalar0 , P_dll, P_result, P_input )

def Bool2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Color0 , P_dll, P_result, P_input )

def Bool2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Coord2D0 , P_dll, P_result, P_input )

def Bool2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Bool2Coord3D0 , P_dll, P_result, P_input )


def Integer2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Bool0, P_dll, P_result, P_input )

def Integer2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Integer0 , P_dll, P_result, P_input )

def Integer2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Size0 , P_dll, P_result, P_input )

def Integer2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Scalar0 , P_dll, P_result, P_input )

def Integer2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Color0 , P_dll, P_result, P_input )

def Integer2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Coord2D0 , P_dll, P_result, P_input )

def Integer2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Integer2Coord3D0 , P_dll, P_result, P_input )


def Size2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Bool0, P_dll, P_result, P_input )

def Size2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Integer0 , P_dll, P_result, P_input )

def Size2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Size0 , P_dll, P_result, P_input )

def Size2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Scalar0 , P_dll, P_result, P_input )

def Size2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Color0, P_dll, P_result, P_input )

def Size2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Coord2D0 , P_dll, P_result, P_input )

def Size2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Size2Coord3D0 , P_dll, P_result, P_input )


def ColorD2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Bool0 , P_dll, P_result, P_input )

def ColorD2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Integer0 , P_dll, P_result, P_input )

def ColorD2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Size0 , P_dll, P_result, P_input )

def ColorD2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Scalar0 , P_dll, P_result, P_input )

def ColorD2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Color0 , P_dll, P_result, P_input )

def ColorD2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Coord2D0 , P_dll, P_result, P_input )

def ColorD2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_ColorD2Coord3D0 , P_dll, P_result, P_input )


def Coord2D2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Bool0, P_dll, P_result, P_input )

def Coord2D2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Integer0 , P_dll, P_result, P_input )

def Coord2D2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Size0 , P_dll, P_result, P_input )

def Coord2D2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Scalar0 , P_dll, P_result, P_input )

def Coord2D2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Color0 , P_dll, P_result, P_input )

def Coord2D2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Coord2D0 , P_dll, P_result, P_input )

def Coord2D2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Coord3D0 , P_dll, P_result, P_input )


def Coord3D2Bool( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Bool0, P_dll, P_result, P_input )

def Coord3D2Integer( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Integer0 , P_dll, P_result, P_input )

def Coord3D2Size( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Size0 , P_dll, P_result, P_input )

def Coord3D2Scalar( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Scalar0 , P_dll, P_result, P_input )

def Coord3D2Color( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Color0 , P_dll, P_result, P_input )

def Coord3D2Coord2D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord3D2Coord2D0 , P_dll, P_result, P_input )

def Coord2D2Coord3D( self, P_dll, P_result, P_input ):
    return _General( self, IceRayC_Material_Pigment_Surface_Instruction_Operation_Convert_Coord2D2Coord3D0 , P_dll, P_result, P_input )


