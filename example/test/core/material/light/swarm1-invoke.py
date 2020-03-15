


import IceRayCpp
import IceRayPy

swarm1_0 = IceRayCpp.MaterialLightSwarm1()
swarm1_1 = IceRayCpp.MaterialLightSwarm1(0)
#swarm1_2 = IceRayCpp.MaterialLightSwarm1(0,0)


swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.point,   0 )
swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.normal,  0 )
swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.start,   0 )
swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.light,   0 )
#swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.limit,  -1 )

swarm1_0.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Output.count,  0 )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')



print( '********************' )

print( '------------' )

#print( IceRayPy.core.material.light.swarm1.__dict__ )

swarm1 = IceRayPy.core.material.light.swarm1.Swarm1()

swarm1.set_input( 'point', 0  );
swarm1.set_input( 'normal', 1  );
swarm1.set_input( 'start', 1  );
swarm1.set_input( 'light', 1  );

swarm1.set_output( 'count', 0  );


swarm1 = IceRayPy.core.material.light.swarm1.Print( swarm1 )






