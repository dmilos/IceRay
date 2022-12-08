import ctypes
import IceRayPy

SizeType = IceRayPy.type.basic.Size


def _Generic(
        P_dll
      , P_function
      , P_filename = None
      ):
    I_picture   = IceRayPy.type.graph.Picture( P_dll )
    if( None != P_filename ):
        I_picture.load( P_filename )
    else:
        I_picture.size( 256, 256 )
        IceRayPy.type.graph.Default( I_picture )
    I_image = IceRayPy.core.material.pattern.Image( P_dll, I_picture )
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    tmpCoord = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( P_function( P_dll, tmpCoord, point ) )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, tmpCoord ) )

    return I_surface


def Identity3D( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Identity3D, P_filename )

def Translate3D( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Translate3D, P_filename )

def Affine3D( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Affine3D, P_filename )

def Homography3D( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Homography3D, P_filename )


def Cartesian2Cylindric( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Cylindric, P_filename )

def Euclid2Max( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Euclid2Max, P_filename )

def Max2Euclid( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Max2Euclid, P_filename )



def Cartesian2Package( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Package, P_filename )

def Cartesian2Spherical( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Spherical, P_filename )

def Cartesian2Torus( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Torus, P_filename )

def Cartesian2Tablecloth( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Tablecloth, P_filename )

def Cartesian2WoodX( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2WoodX, P_filename )

def Cartesian2WoodY( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2WoodY, P_filename )

def Cartesian2WoodZ( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2WoodZ, P_filename )

def Cylindric2Cartesian( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cylindric2Cartesian, P_filename )

def Cylindric2Spherical( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cylindric2Spherical, P_filename )

def Spherical2Cartesian( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Spherical2Cartesian, P_filename )

def Spherical2Cylindric( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Spherical2Cylindric, P_filename )

def Cartesian2Fisheye( P_dll, P_config, P_filename = None ):
    return _Generic( P_dll, IceRayPy.core.material.instruction.operation.mapping.Cartesian2Fisheye, P_filename )
