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

def print_ONf30(P_ONf30):
    print

def make_ONf30( P_emission, P_result ):
    ONf301 = IceRayCpp.MaterialIlluminationONf30()

    # TODO ONf301.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationONf30.Input.emission, P_emission )

    ONf301.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationONf30.Output.result,   P_result )
    ONf301.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationONf30.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return ONf301

print( '********************' )

ONf301 = make_ONf30(0,0)

print( '------------' )
print_ONf30( ONf301 )
print

