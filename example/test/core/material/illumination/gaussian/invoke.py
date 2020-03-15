import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_gaussian(P_gaussian):
    print

def make_gaussian( P_emission, P_result ):
    gaussian1 = IceRayCpp.MaterialIlluminationGaussian()

    # TODO gaussian1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationGaussian.Input.emission, P_emission )

    gaussian1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationGaussian.Output.result,   P_result )
    gaussian1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationGaussian.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return gaussian1

print( '********************' )

gaussian1 = make_gaussian(0,0)

print( '------------' )
print_gaussian( gaussian1 )
print

