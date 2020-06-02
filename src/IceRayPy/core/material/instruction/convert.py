print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

import IceRayPy

SizeType   = IceRayPy.type.basic.Size
ScalarType   = IceRayPy.type.basic.Scalar

class _General:
    def __init__(self, P_native, P_dll, P_result, P_input ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = P_native( SizeType( P_result ), SizeType( P_input ) )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

def Bool2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Bool0, P_dll, P_result, P_input )

def Bool2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Integer0 , P_dll, P_result, P_input )

def Bool2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Size0 , P_dll, P_result, P_input )

def Bool2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Scalar0 , P_dll, P_result, P_input )

def Bool2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Color0 , P_dll, P_result, P_input )

def Bool2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Coord2D0 , P_dll, P_result, P_input )

def Bool2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Coord3D0 , P_dll, P_result, P_input )


def Integer2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Bool0, P_dll, P_result, P_input )

def Integer2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Integer0 , P_dll, P_result, P_input )

def Integer2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Size0 , P_dll, P_result, P_input )

def Integer2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Scalar0 , P_dll, P_result, P_input )

def Integer2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Color0 , P_dll, P_result, P_input )

def Integer2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Coord2D0 , P_dll, P_result, P_input )

def Integer2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Coord3D0 , P_dll, P_result, P_input )


def Size2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Bool0, P_dll, P_result, P_input )

def Size2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Integer0 , P_dll, P_result, P_input )

def Size2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Size0 , P_dll, P_result, P_input )

def Size2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Scalar0 , P_dll, P_result, P_input )

def Size2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Color0, P_dll, P_result, P_input )

def Size2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Coord2D0 , P_dll, P_result, P_input )

def Size2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Coord3D0 , P_dll, P_result, P_input )


def Scalar2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Bool0, P_dll, P_result, P_input )

def Scalar2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Integer0, P_dll, P_result, P_input )

def Scalar2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Size0, P_dll, P_result, P_input )

def Scalar2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Color0, P_dll, P_result, P_input )

def Scalar2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Coord2D0 , P_dll, P_result, P_input )

def Scalar2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Coord3D0 , P_dll, P_result, P_input )


def ColorD2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Bool0 , P_dll, P_result, P_input )

def ColorD2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Integer0 , P_dll, P_result, P_input )

def ColorD2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Size0 , P_dll, P_result, P_input )

def ColorD2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Scalar0 , P_dll, P_result, P_input )

def ColorD2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Color0 , P_dll, P_result, P_input )

def ColorD2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Coord2D0 , P_dll, P_result, P_input )

def ColorD2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_ColorD2Coord3D0 , P_dll, P_result, P_input )


def Coord2D2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Bool0, P_dll, P_result, P_input )

def Coord2D2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Integer0 , P_dll, P_result, P_input )

def Coord2D2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Size0 , P_dll, P_result, P_input )

def Coord2D2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Scalar0 , P_dll, P_result, P_input )

def Coord2D2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Color0 , P_dll, P_result, P_input )

def Coord2D2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Coord2D0 , P_dll, P_result, P_input )

def Coord2D2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Coord3D0 , P_dll, P_result, P_input )


def Coord3D2Bool( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Bool0, P_dll, P_result, P_input )

def Coord3D2Integer( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Integer0 , P_dll, P_result, P_input )

def Coord3D2Size( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Size0 , P_dll, P_result, P_input )

def Coord3D2Scalar( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Scalar0 , P_dll, P_result, P_input )

def Coord3D2Color( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Color0 , P_dll, P_result, P_input )

def Coord3D2Coord2D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Coord2D0 , P_dll, P_result, P_input )

def Coord2D2Coord3D( P_dll, P_result, P_input ):
    return _General( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Coord3D0 , P_dll, P_result, P_input )


print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )