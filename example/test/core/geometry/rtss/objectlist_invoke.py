import IceRayCpp
import IceRayPy



sphere = IceRayCpp.GeometrySimpleSphere( )
box1 = IceRayCpp.GeometrySimpleBox()
list1 = IceRayCpp.GeometryRTSSList()

geometry = IceRayCpp.GeometryRTSSGeometry( )
geometry.rtss( list1 )
geometry.push( sphere )
geometry.push( box1 )



