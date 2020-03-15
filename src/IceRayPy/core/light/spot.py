
import IceRayCpp

def print_spot(P_spot):
    print_coord( P_spot.center() )
    print_color( P_spot._0() )
    print_color( P_spot._1() )
    print_color( P_spot._2() )


class Spot:
    m_spot = IceRayCpp.LightTypeSpot();
    def get_native(self):
        return self.m_spot

    def set_center():
        pass

    def set_0():
        pass

    def set_1():
        pass

    def set_2():
        pass