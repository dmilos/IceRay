print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy


def Grid(
     P_dll
    ,P_light     = None
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ,P_leader = 0
    ,P_count = 5
    ,P_angle = 0.5
    ,P_gauss = 0.5
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface


def Hexagon(
     P_dll
    ,P_light     = None
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ,P_leader = 0
    ,P_count = 1
    ,P_angle = 0.5
    ,P_gauss = 0.5
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Hexagon( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface


def Random(
     P_dll
    ,P_light     = None
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ,P_leader = 0
    ,P_count = 1
    ,P_angle = 0.5
    ,P_gauss = 0.5
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Random( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface


def VDC(
     P_dll
    ,P_light     = None
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ,P_leader = 0
    ,P_count = 1
    ,P_angle = 0.5
    ,P_gauss = 0.5
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.VDC( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )