
import IceRayCpp


class Point:
    m_area = IceRayCpp.LightPoint();
    def get_native(self):
        return self.m_spot
