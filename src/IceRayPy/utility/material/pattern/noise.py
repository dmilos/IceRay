#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

def Cells(
         P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.Cells( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface


def Crackle(
      P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.Crackle( P_dll )


    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface


def Perlin(
      P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.Perlin( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface


def Random(
      P_dll
     ,P_config
    ):

    I_pattern = IceRayPy.core.material.pattern.noise.Random( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface


def Value(
      P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.Value( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface

def Sobol(
      P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.Sobol( P_dll ) #!< Not yet implemented

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface


def VDC(
      P_dll
     ,P_config
    ):
    I_pattern = IceRayPy.core.material.pattern.noise.VDC( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
