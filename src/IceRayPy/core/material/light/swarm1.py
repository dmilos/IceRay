import IceRayCpp

#print( __name__ )

class Swarm1:
    m_swarm1 = None

    def __init__(self, P_light = 1, P_count = 0 ):
        self.m_swarm1 = IceRayCpp.MaterialLightSwarm1( P_light, P_count )

    def get_instruction( self ):
        return self.m_swarm1

    def set_input(self, P_type, P_index):
        if( 'point' == P_type ):
            self.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.point,   P_index )
        if( 'normal' == P_type ):
            self.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.normal,  P_index )
        if( 'start' == P_type ):            
            self.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.start,   P_index )
        if( 'light' == P_type ):            
            self.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.light,   P_index )
        #if( 'limit' == P_type ):            
            #swarm1_0.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.limit,  P_index )

    def set_output(self, P_type, P_index):
        if( 'count' == P_type ):            
            self.m_swarm1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Output.count, P_index )

            
def Print( P_swarm1 ):
    #print( P_swarm1.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.point  ) )
    #print( P_swarm1.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.normal ) )
    #print( P_swarm1.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.start  ) )
    #print( P_swarm1.m_swarm1.input( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightSwarm1.Input.light  ) )
    pass
    
