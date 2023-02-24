#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

#import sys
#import time
#import math
import os
import platform
import pathlib
#import inspect
#import types
import ctypes
import time

SizeType = ctypes.c_size_t

class Info:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
    def __del__(self):
        pass

    def to_string(self):
        result ={}

        key   = ctypes.create_string_buffer( 32 )
        next  = ctypes.create_string_buffer( 32 )
        value = ctypes.create_string_buffer( 32 )
        tmp  = ctypes.create_string_buffer( 32 )
        r = self.m_cargo['dll'].IceRayC_System_First( ctypes.c_size_t(32), key )
        print( "--------------", flush = True )
        while( 0 != r ):
            self.m_cargo['dll'].IceRayC_System_Value( ctypes.c_size_t(32), key, ctypes.c_size_t(32), value )
            print( repr(key.value.decode()) +":"+ repr(value.value.decode()) )
            result[ repr(key.value.decode()) ] = repr(value.value.decode())
            r = self.m_cargo['dll'].IceRayC_System_Next( ctypes.c_size_t(32), key, ctypes.c_size_t(32), next )
            tmp = key
            key = next
            next = tmp
        print( "--------------", flush = True )

def SearchCDLL( P_path = None, P_preferDebug = False ):

    result = ''
    result_debug = ''
    result_release = ''

    if( None != P_path ):
        if( True == os.path.exists( P_path ) ):
            result = P_path

    if( 'Windows' == platform.system() ):
        path_current = str( pathlib.Path(__file__).parent.absolute() )
        path_retreat = "../../.."
        path_root  = path_current + "/" + path_retreat

        list_all={
              "build/cmake/_makeVS/cdll/Debug/IceRayDLL-1.0.0.0.dll"          : { 'exists': False, 'config': 'debug',  'arch' : '32' }
            , "build/cmake/_makeVS/cdll/Release/IceRayDLL-1.0.0.0.dll"        : { 'exists': False, 'config': 'release','arch' : '32' }
            , "bin\IceRayCDLL-x86-Release/IceRayCDLL-1.0.0.0-dynamic.dll"     : { 'exists': False, 'config': 'release','arch' : '32' }
            , "bin\IceRayCDLL-x86-Debug/IceRayCDLL-1.0.0.0-dynamic.dll"       : { 'exists': False, 'config': 'debug',  'arch' : '32' }
            #, "bin\IceRayCDLL-x86_64-Release/IceRayCDLL-1.0.0.0-dynamic.dll"  : { 'exists': False, 'config': 'release','arch' : '64' }
            #, "bin\IceRayCDLL-x86_64-Debug/IceRayCDLL-1.0.0.0-dynamic.dll"    : { 'exists': False, 'config': 'debug',  'arch' : '64' }
        }

        for item in list_all:
            list_all[item]['absolute'] = path_root + '/' + item
            if( True == os.path.exists( list_all[item]['absolute'] ) ):
                list_all[item]['exists'] = True;
                if( 'debug' == list_all[item]['config'] ):
                    result_debug = list_all[item]['absolute']
                if( 'release' == list_all[item]['config'] ):
                    result_release = list_all[item]['absolute']
            print( "DLL test: "+ str( os.path.exists( list_all[item]['absolute']  ) )  + "\'"+ " -> "+ list_all[item]['absolute'], flush = True  )

    if( 'Linux' == platform.system() ):

        bin_root  = os.getcwd()+ "/../.."         #!< cmake Ubuntu
        bin_dir   = "build/cmake/_makeGcc/cdll"   #!< cmake Ubuntu
        bin_dll   = "libIceRayDLL-1.0.0.0.so"     #!< cmake Ubuntu
        bin_test = bin_root +'/'+ bin_dir +'/'+ bin_dll
        print( "DLL exists: "+ str( os.path.exists( bin_test ) )  + "\'"+ " -> "+ bin_test, flush = True  )
        if( True == os.path.exists( bin_test ) ):
            result = bin_test

    if( ( 0 != len(result_debug ) ) and ( 0 == len( result_release ) ) ):
        result = result_debug

    if( ( 0 == len(result_debug ) ) and ( 0 != len( result_release ) ) ):
        result = result_release

    if( True == P_preferDebug ):
        if( 0 != len(result_debug)  ):
            result = result_debug
    else:
        if( 0 != len(result_release)  ):
            result = result_release


    print( "DLL final-debug: "+ result_debug, flush = True  )
    print( "DLL final-release: "+ result_release, flush = True  )
    print( "DLL final: "+ result, flush = True  )

    return result

def _MakeFunction( P_function, P_return, P_argument ):
    P_function.restype = P_return
    P_function.argtypes = P_argument
    return

def _MapFunction_Camera_Cylinder( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal0             , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal1             , ctypes.c_void_p    , [ctypes.c_double  , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal2             , ctypes.c_void_p    , [ctypes.c_double  , ctypes.c_double  , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal_Radius       , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double   ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal_Theta        , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double   ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Horizontal_Width        , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double   ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical0               , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical1               , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical2               , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double, ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical_Height         , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical_Phi            , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Cylinder_Vertical_Radius         , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    return

def _MapFunction_Camera_DOF( P_dll ): #TODO
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone0                        , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone1                        , ctypes.c_void_p    , [ctypes.c_size_t,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone2                        , ctypes.c_void_p    , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone3                        , ctypes.c_void_p    , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_double, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone_Aperture                , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone_Child                   , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone_Gauss                   , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cone_Sample                  , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder0                    , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder1                    , ctypes.c_void_p    , [ctypes.c_size_t, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder2                    , ctypes.c_void_p    , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder3                    , ctypes.c_void_p    , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_double, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder_Aperture            , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder_Child               , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder_Gauss               , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Cylinder_Sample              , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus0                       , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus1                       , ctypes.c_void_p    , [ ctypes.c_size_t, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus2                       , ctypes.c_void_p    , [ ctypes.c_void_p,  ctypes.c_size_t, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus_Aperture               , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus_Child                  , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus_Focus                  , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus_Gauss                  , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Camera_DOF_Focus_Sample                 , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_size_t ] )
    return

def _MapFunction_Camera_Flat( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Orthogonal0                 , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Orthogonal_Aspect           , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Orthogonal_Height           , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Orthogonal_Width            , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective0                , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective1                , ctypes.c_void_p    , [ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective2                , ctypes.c_void_p    , [ctypes.c_double, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective_Aspect          , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective_Height          , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Perspective_Width           , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super0                      , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super_Eye                   , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super_Focus                 , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super_Objective             , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super_Ocular                , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Flat_Super_View                  , ctypes.c_int       , [ctypes.c_void_p, ctypes.c_void_p] )
    return

def _MapFunction_Camera_Sphere( P_dll ): #done
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye0                  , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye1                  , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye2                  , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double, ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye_Phi               , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye_Radius            , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Fisheye_Theta             , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Horizontal0               , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Horizontal1               , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Horizontal_Phi            , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Horizontal_Radius         , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Horizontal_Theta          , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical0                 , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical1                 , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical2                 , ctypes.c_void_p    , [ctypes.c_double , ctypes.c_double , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical_Phi              , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical_Radius           , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    _MakeFunction( P_dll.IceRayC_Camera_Sphere_Vertical_Theta            , ctypes.c_int       , [ctypes.c_void_p , ctypes.c_double  ] )
    return

def _MapFunction_Camera_Transform( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine0                , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine1                , ctypes.c_void_p    , [ ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine2                , ctypes.c_void_p    , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine_2Local_Get      , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine_2Local_Set      , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine_2World_Get      , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine_2World_Set      , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Affine_Child           , ctypes.c_int       , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Invert0                , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Invert1                , ctypes.c_void_p    , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Invert_Child           , ctypes.c_int       , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Pin0                   , ctypes.c_void_p    , [] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Pin1                   , ctypes.c_void_p    , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Pin_Child              , ctypes.c_int       , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Camera_Transform_Pin_Origin             , ctypes.c_int       , [ctypes.c_void_p,ctypes.c_void_p] )
    return

def _MapFunction_Camera( P_dll ): #done
    _MakeFunction( P_dll.IceRayC_Camera_Release, ctypes.c_int, [ctypes.c_void_p] )
    _MapFunction_Camera_Cylinder( P_dll )
    _MapFunction_Camera_DOF( P_dll )
    _MapFunction_Camera_Flat( P_dll )
    _MapFunction_Camera_Sphere( P_dll )
    _MapFunction_Camera_Transform( P_dll )
    return


def _MapFunction_Light_Area( P_dll ): #done
    _MakeFunction(P_dll.IceRayC_Light_Area0                             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Area_Origin                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Area_Sample                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction(P_dll.IceRayC_Light_Area_Spot                         ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Area_X                            ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Area_Y                            ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )

def _MapFunction_Light_Chandelier( P_dll ): #done
    _MakeFunction(P_dll.IceRayC_Light_Chandelier0                       ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Chandelier_Push                   ,      ctypes.c_int,    [ctypes.c_void_p] )

def _MapFunction_Light_Circle( P_dll ): #done
    _MakeFunction(P_dll.IceRayC_Light_Circle0                           ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Circle_Center                     ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Circle_Sample                     ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Circle_Spot                       ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Circle_X                          ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Circle_Y                          ,      ctypes.c_int,    [ctypes.c_void_p] )

def _MapFunction_Light_Confine( P_dll ): #done
    _MakeFunction(P_dll.IceRayC_Light_Confine0                          ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Confine_Child                     ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Confine_Shell                     ,      ctypes.c_int,    [ctypes.c_void_p] )

def _MapFunction_Light_Dark( P_dll ): #DONE
    _MakeFunction(P_dll.IceRayC_Light_Dark0                             ,      ctypes.c_void_p, [] )

def _MapFunction_Light_Disc( P_dll ): #done
    _MakeFunction(P_dll.IceRayC_Light_Disc0                             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Disc_Center                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Disc_Sample                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction(P_dll.IceRayC_Light_Disc_Spot                         ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Disc_X                            ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction(P_dll.IceRayC_Light_Disc_Y                            ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )

def _MapFunction_Light_Line( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Line0                             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Line_End                          ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Line_Sample                       ,      ctypes.c_int,    [ctypes.c_size_t] )
    _MakeFunction(P_dll.IceRayC_Light_Line_Spot                         ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Line_Start                        ,      ctypes.c_int,    [ctypes.c_void_p] )
    pass

def _MapFunction_Light_Obstruct( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Obstruct0                         ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Obstruct1                         ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Obstruct2                         ,      ctypes.c_void_p, [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Obstruct_Barrier                  ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Obstruct_Child                    ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )
    pass

def _MapFunction_Light_Point( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Point0                            ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Point1                            ,      ctypes.c_void_p, [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Point_Center                      ,      ctypes.c_int,    [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Point_Spot                        ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )
    pass

def _MapFunction_Light_Reflector( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Reflector0                        ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Reflector_Center                  ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Reflector_Direction               ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Reflector_Inner                   ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction(P_dll.IceRayC_Light_Reflector_Outter                  ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction(P_dll.IceRayC_Light_Reflector_Spot                    ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p] )
    pass

def _MapFunction_Light_Sphere( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Sphere0                           ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere1                           ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere2                           ,      ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere3                           ,      ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_double,ctypes.c_size_t] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere_Radius                     ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere_Sample                     ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_size_t] )
    _MakeFunction(P_dll.IceRayC_Light_Sphere_Spot                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p] )
    pass

def _MapFunction_Light_Spline( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Spline0                           ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Spline_CP                         ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Spline_Sample                     ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_size_t] )
    _MakeFunction(P_dll.IceRayC_Light_Spline_Spot                       ,      ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p] )
    pass

def _MapFunction_Light_Sun( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_SunG0                             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_SunG1                             ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_SunG_Child                        ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_SunS0                             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_SunS1                             ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_SunS_Center                       ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_SunS_Spot                         ,      ctypes.c_int,    [ctypes.c_void_p,ctypes.c_void_p] )

def _MapFunction_Light_Transform( P_dll ):#DONE
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine0                 ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine1                 ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine2                 ,      ctypes.c_void_p, [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine_2Local_Get       ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine_2Local_Set       ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine_2World_Get       ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine_2World_Set       ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Affine_Child            ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography0             ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography_2Local_Get   ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography_2Local_Set   ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography_2World_Get   ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography_2World_Set   ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Homography_Child        ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Identity0               ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Identity1               ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Identity_Child          ,      ctypes.c_int,    [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate0              ,      ctypes.c_void_p, [] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate1              ,      ctypes.c_void_p, [ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate2              ,      ctypes.c_void_p, [ctypes.c_void_p , ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate_2Local_Get    ,      ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate_2Local_Set    ,      ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate_2World_Get    ,      ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate_2World_Set    ,      ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction(P_dll.IceRayC_Light_Transform_Translate_Child         ,      ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p ] )


def _MapFunction_Light( P_dll ): #!< DONE
    _MakeFunction(P_dll.IceRayC_Light_Release                           ,      ctypes.c_int,    [ctypes.c_void_p] )

    _MapFunction_Light_Area( P_dll )
    _MapFunction_Light_Chandelier( P_dll )
    _MapFunction_Light_Circle( P_dll )
    _MapFunction_Light_Confine( P_dll )
    _MapFunction_Light_Dark( P_dll )
    _MapFunction_Light_Disc( P_dll )
    _MapFunction_Light_Line( P_dll )
    _MapFunction_Light_Obstruct( P_dll )
    _MapFunction_Light_Point( P_dll )
    _MapFunction_Light_Reflector( P_dll )
    _MapFunction_Light_Sphere( P_dll )
    _MapFunction_Light_Sun( P_dll )
    _MapFunction_Light_Transform( P_dll )
    _MapFunction_Light_Transform( P_dll )
    return

def _MapFunction_Geometry_Blobby( P_dll ): #TODO

    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Affine0                      , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Affine1                      , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Affine_2World_Get            , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Affine_Child                 , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Release              , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Sphere0                      , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Sphere1                      , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_double,ctypes.c_double] ) 
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Sphere_Center                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Sphere_Influence             , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Sphere_Radius                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Translate0                   , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Translate1                   , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] ) 
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Translate_Child              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_Translate_Move               , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UCylinderZ0                  , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UCylinderZ1                  , ctypes.c_void_p  , [ctypes.c_double] ) 
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UCylinderZ_Core              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_USphere0                     , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_USphere1                     , ctypes.c_void_p  , [ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_USphere_Core                 , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UWaterZ0                     , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UWaterZ1                     , ctypes.c_void_p  , [ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_Element_UWaterZ_Level                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_System0                      , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_System_Push                  , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Blobby_System_RTSS                  , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )

def _MapFunction_Geometry_HField( P_dll ): #done

    _MakeFunction( P_dll.IceRayC_Geometry_HField_System0                      , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_System_Lo                    , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_System_Hi                    , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_System_Object                , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_System_Generator             , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )

    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Release            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Image0             , ctypes.c_void_p  , [] )
   #_MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Image1             , ctypes.c_void_p  , [ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Image_Picture      , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )

    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Expression0        , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Expression1        , ctypes.c_void_p  , [ ctypes.c_char_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Expression_Pattern , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_char_p ] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Generator_Expression_Box     , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_void_p ] )

    _MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Release               , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Flat0                 , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Triangle0             , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Quad0                 , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Geometry0             , ctypes.c_void_p  , [] )
   #_MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Geometry1             , ctypes.c_void_p  , [ctypes.c_void_p] )
   #_MakeFunction( P_dll.IceRayC_Geometry_HField_Object_Geometry_Geometry     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )


def _MapFunction_Geometry_Complex( P_dll ): #done

    _MapFunction_Geometry_HField( P_dll )

    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Enclose0          , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Enclose1          , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Enclose_Child     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Enclose_Hull      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect0        , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect1        , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect_Left0   , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect_Left1   , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_int] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect_Right0  , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Complex_Intersect_Right1  , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_int] )



def _MapFunction_Geometry_RTSS( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_List0                          , ctypes.c_void_p  , [] )

    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object0                        , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object1                        , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object_Clear                   , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object_Optimize                , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object_Push                    , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Object_Rtss                    , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Release                        , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Uniform0                       , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Uniform1                       , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_RTSS_Uniform_Dimension              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )

def _MapFunction_Geometry_Transform( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine0                   , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine1                   , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine_2Local_Get         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine_2Local_Set         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine_2World_Get         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine_2World_Set         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Affine_Child              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography0               , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography1               , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography_2Local_Get     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography_2Local_Set     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography_2World_Get     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography_2World_Set     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Homography_Child          , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Identity0                 , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Identity1                 , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Identity_Child            , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_MotionBlur0               , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_MotionBlur1               , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_MotionBlur2               , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_MotionBlur_Child          , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_MotionBlur_Direction      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate0                , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate1                , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate2                , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate_2Local_Get      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate_2Local_Set      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate_2World_Get      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate_2World_Set      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Transform_Translate_Child           , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )

def _MapFunction_Geometry_Volumetric( P_dll ): #DONE
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist0                    , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist1                    , ctypes.c_void_p  , [ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist2                    , ctypes.c_void_p  , [ctypes.c_double,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist3                    , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist4                    , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist5                    , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_double,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist_Density             , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist_Hull                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Mist_Precision           , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Smoke0                   , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Smoke2                   , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Smoke_Hull               , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Vacuum0                  , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Vacuum1                  , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Vacuum_Box               , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Vacuum_Hi                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Volumetric_Vacuum_Lo                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )


def _MapFunction_Geometry( P_dll ): #TODO

    _MakeFunction( P_dll.IceRayC_Geometry_Release                             , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry__Base_GetBox                        , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )

    _MapFunction_Geometry_Blobby( P_dll )
    _MapFunction_Geometry_Complex( P_dll )
    _MapFunction_Geometry_RTSS(P_dll)
    _MapFunction_Geometry_Transform( P_dll )
    _MapFunction_Geometry_Volumetric(P_dll)

    _MakeFunction( P_dll.IceRayC_Geometry_Box0                                , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Box1                                , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Box_Hi                              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Box_Lo                              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Cone0                               , ctypes.c_void_p  , [] )

    _MakeFunction( P_dll.IceRayC_Geometry_Cylinder0                   , ctypes.c_void_p  , [] )
    #_MakeFunction( P_dll.IceRayC_Geometry_Cylinder1                   , ctypes.c_void_p  , [ ctypes.c_double ] )
    #_MakeFunction( P_dll.IceRayC_Geometry_Cylinder2                   , ctypes.c_void_p  , [ ctypes.c_double, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Geometry_Cylinder_Radius             , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Geometry_Cylinder_Height             , ctypes.c_int     , [ ctypes.c_void_p, ctypes.c_double ] )

    _MakeFunction( P_dll.IceRayC_Geometry_CylinderU0                          , ctypes.c_void_p  , [] )

    _MakeFunction( P_dll.IceRayC_Geometry_Disc0                               , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Disc1                               , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Disc_Center                         , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Disc_Normal                         , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Disc_Radius                         , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid0                          , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid1                          , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid2                          , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid_Center                    , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid_RadiusS                   , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid_RadiusV                   , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Ellipsoid_System                    , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Hyperboloid0                        , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Hyperboloid1                        , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Hyperboloid_Core                    , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Paraboloid0                         , ctypes.c_void_p  , [] )

    _MakeFunction( P_dll.IceRayC_Geometry_Plane0                              , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Plane1                              , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Plane_Normal                        , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Plane_Origin                        , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Quadric0                            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Saddle0                             , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_USphere0                            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Sphere0                             , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Sphere1                             , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Sphere_Center                       , ctypes.c_int     , [ ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Geometry_Sphere_Radius                       , ctypes.c_int     , [ ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Geometry_Torus0                              , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Torus1                              , ctypes.c_void_p  , [] )#!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Torus_Minor                         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )

    _MakeFunction( P_dll.IceRayC_Geometry_Triangle0                           , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Triangle1                           , ctypes.c_void_p  , [] ) #!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_Triangle_Origin                     , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Triangle_eX                         , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_Triangle_eY                         , ctypes.c_int     , [] )

    _MakeFunction( P_dll.IceRayC_Geometry_UDisc0                              , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_UDisc1                              , ctypes.c_void_p  , [] ) #!<mTODO
    _MakeFunction( P_dll.IceRayC_Geometry_UDisc_Radius                        , ctypes.c_int     , [] )
    _MakeFunction( P_dll.IceRayC_Geometry_TriangleU0                          , ctypes.c_void_p  , [] )


def _MapFunction_Object(P_dll): #DONE
    _MakeFunction( P_dll.IceRayC_Object_Release        , ctypes.c_int    , [ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Object0               , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Object1               , ctypes.c_void_p , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Object_Cast2Geometry  , ctypes.c_void_p , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Object_Geometry_Get   , ctypes.c_void_p , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Object_Geometry_Set   , ctypes.c_int    , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Object_Medium         , ctypes.c_int    , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Object_Pigment        , ctypes.c_int    , [ctypes.c_void_p,ctypes.c_void_p] )
    return

def _MapFunction_Render(P_dll): #!< TODO
    _MakeFunction( P_dll.IceRayC_Render_Engine0                   , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Release            , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Pierce             , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Pixel              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Ray                , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Scanner            , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Sheaf              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Start              , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Progress           , ctypes.c_double  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Engine_Stop               , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Pierce_Projector0         , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Pierce_Projector_Camera   , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Pierce_Projector_Sheaf    , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Pierce_Release            , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Pierce_UV0                , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_PixelBasic0               , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Pixel_Constant0           , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Pixel_Release             , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Pixel_UV0                 , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Direction0            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Distance0             , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Distance1             , ctypes.c_void_p  , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Distance_Clip         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Distance_Geometry     , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Release               , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace0                , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace_Depth           , ctypes.c_int     , [ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace_IOR             , ctypes.c_int     , [ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace_Next            , ctypes.c_int     , [ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace_Object          , ctypes.c_int     , [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Render_Ray_Trace_Trash           , ctypes.c_int     , [ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Render_Scanner_Block0            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Scanner_Block_Hot         , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Scanner_Block_Window      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Scanner_Parallel0         , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Scanner_Release           , ctypes.c_int     , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Render_Sheaf_ALL0                , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Sheaf_First0              , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Sheaf_Random0             , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Render_Sheaf_Release             , ctypes.c_int     , [ctypes.c_void_p] )

def _MapFunction_Type_Math_Affine3D(P_dll): #!< done
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_Compose              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_ID                   , ctypes.c_int, [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_LookAt               , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_Move                 , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_RotateA              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_RotateD              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p,ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_RotateX              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_RotateY              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_RotateZ              , ctypes.c_int, [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_ScaleS               , ctypes.c_int, [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_ScaleV               , ctypes.c_int, [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_Zero                 , ctypes.c_int, [ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_System               , ctypes.c_int, [ ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Affine3D_SystemZ              , ctypes.c_int, [ ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )

def _MapFunction_Type_Math_Coord1D(P_dll): #!< TODO
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Addition              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Distance              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Fill                  , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Length                , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Load                  , ctypes.c_int, [ctypes.c_void_p, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Scale                 , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord1D_Subtraction           , ctypes.c_int, [] )

def _MapFunction_Type_Math_Coord2D(P_dll): #!< TODO
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Addition              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Distance              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Fill                  , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Length                , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Load                  , ctypes.c_int, [ctypes.c_void_p, ctypes.c_double, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Scale                 , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord2D_Subtraction           , ctypes.c_int, [] )

def _MapFunction_Type_Math_Coord3D(P_dll): #!< done
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Addition              , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Cross                 , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_DominantIndex         , ctypes.c_int,    [ ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Distance              , ctypes.c_double, [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Fill                  , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Length                , ctypes.c_double, [ ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Load                  , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_double, ctypes.c_double, ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Scale                 , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_double, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord3D_Subtraction           , ctypes.c_int,    [ ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )

def _MapFunction_Type_Math_Coord4D(P_dll): #!< TODO
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Addition              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Distance              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Fill                  , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Length                , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Load                  , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Scale                 , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Coord4D_Subtraction           , ctypes.c_int, [] )

def _MapFunction_Type_Math(P_dll): #!< TODO
    _MapFunction_Type_Math_Affine3D( P_dll )
    _MapFunction_Type_Math_Coord1D(P_dll)
    _MapFunction_Type_Math_Coord2D(P_dll)
    _MapFunction_Type_Math_Coord3D(P_dll)

    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Construct1D        , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Construct2D        , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Construct3D        , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Transform1D        , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Transform2D        , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Homography_Transform3D        , ctypes.c_int, [] )

    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix1D_Multiply             , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix2D_Multiply             , ctypes.c_int, [] )

    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_ID                   , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_Multiply             , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_RotateA              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_RotateX              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_RotateY              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_RotateZ              , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_ScaleS               , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_ScaleV               , ctypes.c_int, [] )
    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix3D_Zero                 , ctypes.c_int, [] )

    _MakeFunction( P_dll.IceRayC_Type_Math_Matrix4D_Multiply             , ctypes.c_int, [] )

def _MapFunction_Type_Picture(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Type_Picture_Release    , ctypes.c_int    , [ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Type_Picture0           , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Type_Picture1           , ctypes.c_void_p , [ctypes.c_char_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Bits       , ctypes.c_int    , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Crop       , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Crop0      , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Default    , ctypes.c_int    , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Load       , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_char_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_Size       , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_SizeGet    , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_SizeSet    , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_StorePNM   , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_char_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_StorePNG   , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_char_p] )
    _MakeFunction( P_dll.IceRayC_Type_Picture_StoreJPEG  , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_char_p] )
    return

def _MapFunction_Type(P_dll): #!< DONE
    _MapFunction_Type_Math(P_dll)
    _MapFunction_Type_Picture(P_dll)
    _MakeFunction( P_dll.IceRayC_Type_Color_HSL2RGB , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Type_Color_RGB2HSL , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p] )
    return

def _MapFunction_Material_Medium(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Medium_Release           , ctypes.c_int     , [ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Material_Medium_Constant0         , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Constant1         , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Constant_Deplete  , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Constant_Value    , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Exponential0      , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Exponential1      , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Exponential_Half  , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Exponential_Value , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Linear0           , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Linear1           , ctypes.c_void_p  , [ctypes.c_void_p,ctypes.c_double, ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Linear_A          , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Linear_B          , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Linear_Value      , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic0        , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic1        , ctypes.c_void_p  , [ ctypes.c_void_p,ctypes.c_double,ctypes.c_double,ctypes.c_double ] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic_A       , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic_B       , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic_C       , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_double] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Quadratic_Value   , ctypes.c_int     , [ctypes.c_void_p,ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Solid0            , ctypes.c_void_p  , [] )
    _MakeFunction( P_dll.IceRayC_Material_Medium_Transparent0      , ctypes.c_void_p  , [] )
    return

def _MapFunction_Material_Pattern(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Brick0                          , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Checker0                        , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Hexagon0                        , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Image0                          , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Image1                          , ctypes.c_void_p , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Image_Picture                   , ctypes.c_int    , [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Level0                          , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Cells0                    , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Crackle0                  , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Gold0                     , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Perlin0                   , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Random0                   , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Value0                    , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Noise_Vdc0                      , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Onion0                          , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Release                         , ctypes.c_int    , [ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Side_Cube0                      , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Side_Dodecahedron0              , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Side_Icosahedron0               , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Side_Octahedron0                , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Side_Tetrahedron0               , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Wave0                           , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Gradient0                       , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Gradient_Set                    , ctypes.c_int ,    [ctypes.c_void_p, ctypes.c_double, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Gradient_Bottom                 , ctypes.c_int ,    [ctypes.c_void_p, ctypes.c_void_p] )
    _MakeFunction( P_dll.IceRayC_Material_Pattern_Gradient_Top                    , ctypes.c_int ,    [ctypes.c_void_p, ctypes.c_void_p] )

    return

def _MapFunction_Material_Pigment_Surface(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface0         , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Append   , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Lambda   , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Normal   , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Point    , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Result   , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Incident , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Origin   , ctypes.c_int    , [ ctypes.c_void_p, ctypes.c_size_t ] )
    return

def _MapFunction_Material_Pigment_Surface_Instruction_Constant(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Color0          , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar2D0 , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar3D0 , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar4D0 , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size2D0   , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size3D0   , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size4D0   , ctypes.c_void_p , [ ctypes.c_void_p, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Scalar0         , ctypes.c_void_p , [ ctypes.c_double, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Constant_Size0           , ctypes.c_void_p , [ ctypes.c_size_t, ctypes.c_size_t ] )
    return

def _MapFunction_Material_Pigment_Surface_Instruction_Type(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Integer_Addition0,    ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Integer_Divide0,      ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Integer_Multiply0,    ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Integer_Subtraction0, ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Size_Addition0,       ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Size_Divide0,         ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Size_Multiply0,       ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Size_Subtraction0,    ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Scalar_Addition0,     ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Scalar_Divide0,       ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Scalar_Multiply0,     ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Scalar_Subtraction0,  ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Addition0   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Load0       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Multiply0   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Scale0      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Subtraction0, ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_Unit0       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Addition0   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Cross0      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Load0       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Multiply0   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Scale0      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Subtraction0, ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord3D_Unit0       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )


def _MapFunction_Material_Pigment_Surface_Instruction_Convert(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Bool0                         , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Color0                        , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Coord2D0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Coord3D0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Integer0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Scalar0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Bool2Size0                         , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Bool0                        , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Color0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Coord2D0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Coord3D0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Integer0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Scalar0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Color2Size0                        , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Bool0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Color0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Coord2D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Coord3D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Integer0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Scalar0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord2D2Size0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Bool0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Color0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Coord2D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Coord3D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Integer0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Scalar0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Coord3D2Size0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Bool0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Color0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Coord2D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Coord3D0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Integer0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Scalar0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Integer2Size0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Bool0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Color0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Coord2D0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Coord3D0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Integer0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Scalar0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Scalar2Size0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Bool0                         , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Color0                        , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Coord2D0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Coord3D0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Integer0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Scalar0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Convert_Size2Size0                         , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t] )
    return

def _MapFunction_Material_Pigment_Surface_Instruction_Illumination(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ALP0                          , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Ambient0                      , ctypes.c_void_p , [ SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_AsDiffuse0                    , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_AsSpecular0                   , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0                     , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Blinn0                        , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Gaussian0                     , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_HsLambert0                    , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_HsNormal0                     , ctypes.c_void_p , [ SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_HsPhong0                      , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Lambert0                      , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ON_Fujii_Proposed             , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ON_Fujii_Qualitative          , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ON_Ouwerkerk                  , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ON_f29                        , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_ON_f30                        , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_Phong0                        , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_WardApprox0                   , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_WardIsotropic0                , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Illumination_WardReal0                     , ctypes.c_void_p , [ SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType, SizeType] )

def _MapFunction_Material_Pigment_Surface_Instruction_Light(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Light_Generator0                           , ctypes.c_void_p , [ctypes.c_void_p,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmA0                              , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmB0                              , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmC0                              , ctypes.c_void_p , [ctypes.c_void_p,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Operation_Mapping(P_dll): #!< TODO
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Affine3D0                , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Affine3D1                , ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_size_t ,ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Affine3D_Structure       , ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Cylindric0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Fisheye0       , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Package0       , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Spherical0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Tablecloth0    , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2Torus0         , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodX0         , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodY0         , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cartesian2WoodZ0         , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cylindric2Cartesian0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Cylindric2Spherical0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Euclid2Max0              , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Homography3D0            , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Homography3D1            , ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Homography3D_Structure   , ctypes.c_int,    [ctypes.c_void_p, ctypes.c_void_p ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Identity3D0              , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Max2Euclid0              , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Spherical2Cartesian0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Spherical2Cylindric0     , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D0             , ctypes.c_void_p, [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D1             , ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_Translate3D_Move         , ctypes.c_void_p, [ctypes.c_void_p, ctypes.c_void_p ] )

def _MapFunction_Material_Pigment_Surface_Instruction_Operation(P_dll): #!< done
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Ramp0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Relu0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Saw0                       , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Sinkhole0                  , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Wave0                      , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t ] )

    _MapFunction_Material_Pigment_Surface_Instruction_Operation_Mapping(P_dll)

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Color0                    , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord2D0                  , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord3D0                  , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Scalar0                   , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Size0                     , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Pattern(P_dll): #done
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Color0                             , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Scalar2D0                    , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Scalar3D0                    , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Size2D0                      , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Size3D0                      , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Scalar0                            , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Pattern_Size0                              , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t ] )

def _MapFunction_Material_Pigment_Surface_Instruction_Spot(P_dll): #done
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Spot_Confine0                              , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Spot_Cull0                                 , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Spot_Obstruct0                             , ctypes.c_void_p , [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Spot_UWV0                                  , ctypes.c_void_p , [ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Correct(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Cone0     , ctypes.c_void_p , [ ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Trim0     , ctypes.c_void_p , [ ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Claim0    , ctypes.c_void_p , [ ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Correct_Leader0   , ctypes.c_void_p , [ ctypes.c_size_t, ctypes.c_size_t, ctypes.c_size_t ] )

def _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Blossom(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Grid0     , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Hexagon0  , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Pinwheel0 , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Random0   , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Sobol0    , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_Triangle0 , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Blossom_VDC0      , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Reflect(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Reflect_One0      , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Reflect_Schlick0  , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Refract(P_dll):
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Fresnel0  , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Schlick0  , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Refract_Snell0    , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Jitter(P_dll): #!< check
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_Sobol0     , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_Random0    , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Transmission_Jitter_VDC0       , ctypes.c_void_p , [ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t,ctypes.c_size_t] )

def _MapFunction_Material_Pigment_Surface_Instruction(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_Release , ctypes.c_int   , [ctypes.c_void_p] )

    _MakeFunction( P_dll.IceRayC_Material_Pigment_Surface_Instruction_NOP0    , ctypes.c_void_p, [] )

    _MapFunction_Material_Pigment_Surface_Instruction_Constant(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Convert(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Illumination(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Light(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Operation(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Pattern(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Spot(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Correct(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Blossom(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Jitter(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Reflect(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Transmission_Refract(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction_Type(P_dll)

    return

def _MapFunction_Material_Pigment(P_dll): #!< DONE
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Constant0      , ctypes.c_void_p , [] )
    _MakeFunction( P_dll.IceRayC_Material_Pigment_Release        , ctypes.c_int    , [ ctypes.c_void_p ] )

    _MapFunction_Material_Pigment_Surface(P_dll)
    _MapFunction_Material_Pigment_Surface_Instruction(P_dll)

def _MapFunction_Material(P_dll): #!< DONE
    _MapFunction_Material_Medium(P_dll)
    _MapFunction_Material_Pattern(P_dll)
    _MapFunction_Material_Pigment(P_dll)

def _MapSystem(P_dll):
    _MakeFunction( P_dll.IceRayC_System_First, ctypes.c_int    , [ ctypes.c_size_t, ctypes.c_char_p ] )
    _MakeFunction( P_dll.IceRayC_System_Value, ctypes.c_int    , [ ctypes.c_size_t, ctypes.c_char_p, ctypes.c_size_t, ctypes.c_char_p ] )
    _MakeFunction( P_dll.IceRayC_System_Next,  ctypes.c_int     , [ ctypes.c_size_t, ctypes.c_char_p, ctypes.c_size_t, ctypes.c_char_p ] )


def LoadCDLL( P_path ):

    dll = ctypes.cdll.LoadLibrary( P_path )

    _MapFunction_Light( dll )
    _MapFunction_Geometry( dll )
    _MapFunction_Camera( dll )
    _MapFunction_Object( dll )
    _MapFunction_Render( dll )
    _MapFunction_Type( dll )
    _MapFunction_Material( dll )
    _MapSystem( dll )

    #_MakeFunction( P_dll.IceRayC_WhatEver                                     , ctypes.c_void_p , [] )

    dll.IceRayC_Utility_Random_Table_Next #!< TODO
    info = Info( dll );
    info.to_string()
    return dll

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
