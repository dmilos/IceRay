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

def print_phong(P_phong):
    print

def make_phong( P_emission, P_result ):
    phong1 = IceRayCpp.MaterialIlluminationPhong()

    # TODO phong1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationPhong.Input.emission, P_emission )

    phong1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationPhong.Output.result,   P_result )
    phong1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationPhong.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return phong1

print( '********************' )

phong1 = make_phong(0,0)

print( '------------' )
print_phong( phong1 )
print

