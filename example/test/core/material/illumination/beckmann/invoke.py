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

def print_beckmann(P_beckmann):
    print( P_beckmann )


def make_beckmann( P_emission, P_result ):
    beckmann1 = IceRayCpp.MaterialIlluminationBeckmann()

    # TODO beckmann1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationBeckmann.Input.emission, P_emission )

    beckmann1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationBeckmann.Output.result,   P_result )
    beckmann1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationBeckmann.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return beckmann1

print( '********************' )

print( '------------' )

beckmann1 = make_beckmann( 0, 0 )

print_beckmann( beckmann1 )

