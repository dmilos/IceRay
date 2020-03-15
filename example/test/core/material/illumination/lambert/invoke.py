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

def print_lambert(P_lambert):
    print
    
def make_lambert( P_emission, P_result ):
    lambert1 = IceRayCpp.MaterialIlluminationLambert()

    # TODO lambert1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Input.emission, P_emission )

    lambert1.output( P_result, IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.result )
    lambert1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationLambert.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return lambert1

print( '********************' )

lambert1 = make_lambert(0,0)

print( '------------' )
print_lambert( lambert1 )
print

