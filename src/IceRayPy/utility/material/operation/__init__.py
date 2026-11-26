#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.utility.material.operation.mapping




def NOP(
    P_dll
    ,P_config = None
   ):

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.NOP( P_dll ) )

    return I_surface

def Expression(
    P_dll
    ,P_config = None
    ,P_expression = None
   ):

    scalar_memory = IceRayPy.core.material.instruction.label.scalar.dynamic._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    e = IceRayPy.core.material.instruction.Expression( P_dll, scalar_memory, scalar_memory );
    I_surface.append( e )
    e.string2index( 0, "x")
    e.string2index( 1, "y")
    e.string2index( 2, "z")

    e.index2index(0,0)
    e.index2index(1,1)
    e.index2index(2,2)
    e.expression("x+y+z")


    bool_memory = IceRayPy.core.material.instruction.label.scalar.dynamic._BEGIN
    scalar_memory = IceRayPy.core.material.instruction.label.scalar.dynamic._BEGIN
    integer_memory = IceRayPy.core.material.instruction.label.integer.dynamic._BEGIN
    color_memory = IceRayPy.core.material.instruction.label.color.dynamic._BEGIN
    coord2d_memory = IceRayPy.core.material.instruction.label.coord2d.dynamic._BEGIN
    coord3d_memory = IceRayPy.core.material.instruction.label.coord3d.dynamic._BEGIN

    I_surface.append( IceRayPy.core.material.instruction.operation.fill.Bool(     P_dll, bool_memory,     True, 3 ) )
   #I_surface.append( IceRayPy.core.material.instruction.operation.fill.Integer(  P_dll, integer_memory,  13,   3 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.fill.Scalar(   P_dll, scalar_memory,   22,   3 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.fill.Color(    P_dll, color_memory,    IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 ),  3 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.fill.Coord2D(  P_dll, coord2d_memory,  IceRayPy.type.math.coord.Scalar2D( 0, 0 ),    2 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.fill.Coord3D(  P_dll, coord3d_memory,  IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ), 1 ) )

    return I_surface

def Coord3D2Color(
    P_dll
    ,P_config = None
    ,P_function = None
    ,P_filename = None
   ):

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    normal = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.convert.Coord3D2Color( P_dll, result, normal ) )

    return I_surface

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
