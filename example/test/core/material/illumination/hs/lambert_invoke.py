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

def print_HSLambert(P_HSLambert):
    print

def make_HSLambert( P_emission, P_result ):
    #MaterialIlluminationHSLambert( [Coord]point, [Coord]normal, [size]lightCount, [color]diffuse, [coord]groove, [color]result  )
    HSLambert1 = IceRayCpp.MaterialIlluminationHSLambert()

    # TODO HSLambert1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationHSLambert.Input.emission, P_emission )

    HSLambert1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationHSLambert.Output.result,   P_result )
    HSLambert1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationHSLambert.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return HSLambert1


print( '********************' )

HSLambert1 = make_HSLambert(0,0)

print( '------------' )
print_HSLambert( HSLambert1 )
print

