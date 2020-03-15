
import IceRayCpp

def print_disc( P_area ):
    print( P_area.sample() )
    print_light_spot( area1.spot() )
    print_coord( area1.x() )
    print_coord( area1.y() )
    print( area1.sample() )


class Disc:
    m_area = IceRayCpp.LightDisc();
    def get_native(self):
        return self.m_spot
