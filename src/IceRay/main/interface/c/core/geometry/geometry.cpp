
#include "./geometry.h"
#include "../../type/coord.hpp"

#include "IceRay/geometry/geometry.hpp"

void IceRayC_Geometry_Release( IceRayC_GeometryHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto I_this = reinterpret_cast<Tf__base*> ( P_this );
  delete I_this;
 }

IceRayC_GeometryHandle IceRayC_GeometrySphere0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometrySphere1( IceRayC_TypeCoord3D P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{ c2cpp( P_center), P_radius } ;
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_GeometrySphere_Center( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( P_center) );
  return 1;
 }

int IceRayC_GeometrySphere_Radius( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;
  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__base*> ( P_this ) );
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_GeometryHandle IceRayC_GeometryBox0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometryBox1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{ c2cpp( P_lo ), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryTorus0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{};
  return reinterpret_cast<IceRayC_GeometryHandle>(dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryTorus1( IceRayC_TypeScalar P_minor )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{ P_minor };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

int IceRayC_GeometryTorus_Minor( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_minor )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto I_this = dynamic_cast< Tf_torus *>( reinterpret_cast<Tf__base*> ( P_this ) );
  I_this->F_minor( P_minor );
  return 1;
}

IceRayC_GeometryHandle IceRayC_GeometryTriangle0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryTriangle1( IceRayC_TypeCoord3D P_e0, IceRayC_TypeCoord3D P_ex, IceRayC_TypeCoord3D P_ey )
 { // TODO
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{ c2cpp( P_e0 ), c2cpp( P_ex ), c2cpp( P_ey ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometrySmoke0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometrySmoke1(  IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{ c2cpp( P_lo ), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryMotionBlur()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  // TODO typedef GS_DDMRM::S_IceRay::S_geometry::GC_TODO Tf_TODO;
  //auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_motion{};
  //return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
  return nullptr;
 }



IceRayC_GeometryHandle IceRayC_GeometryPlane0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new Tf_plane{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometryPlane1( IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_plane{ c2cpp( P_origin ), c2cpp( P_normal ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_GeometryPlane_Origin( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_pivot )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_pivot( c2cpp( P_pivot ) );
 }

int IceRayC_GeometryPlane_Normal( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_normal( c2cpp( P_normal ) );
 }



IceRayC_GeometryHandle IceRayC_GeometryHField()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;
  auto Ir_result = new Tf_hfield{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }


IceRayC_GeometryHandle IceRayC_GeometryDisc0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometryDisc1( IceRayC_TypeCoord3D P_center, IceRayC_TypeCoord3D P_normal, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{ c2cpp( P_center ), c2cpp( P_normal ), P_radius };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_GeometryDisc_Center(IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_center )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
  {
    return 0;
  }
  return I_this->F_center( c2cpp( P_center ) );
}

int IceRayC_GeometryDisc_Normal(IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_normal )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
  {
    return 0;
  }
  return I_this->F_normal( c2cpp( P_normal ) );
}

int IceRayC_GeometryDisc_Radius(IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_radius )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
  {
    return 0;
  }
  return I_this->F_radius( P_radius );
}

IceRayC_GeometryHandle IceRayC_GeometryCylinder0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cylinder Tf_cylinder;
  auto Ir_result = new Tf_cylinder{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometryCone0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cone Tf_cone;
  auto Ir_result = new Tf_cone{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_GeometryHandle IceRayC_GeometryParaboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_paraboloid Tf_paraboloid;
  auto Ir_result = new Tf_paraboloid{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryHyperboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryHyperboloid1(  IceRayC_TypeScalar P_core )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{ P_core };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

int IceRayC_GeometryHyperboloid_Core( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;

  auto I_this = dynamic_cast< Tf_hyperboloid *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_core( P_core );
 }

IceRayC_GeometryHandle IceRayC_GeometrySaddle0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_saddle Tf_saddle;
  auto Ir_result = new Tf_saddle{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}


IceRayC_GeometryHandle IceRayC_GeometryCSG()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  // TODO typedef GS_DDMRM::S_IceRay::S_geometry::GC_TODO Tf_TODO;
  //auto Ir_result = new Tf_CSG{};
  return nullptr;
 }


IceRayC_GeometryHandle IceRayC_GeometryAffine()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryTranslate0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryTranslate1( IceRayC_GeometryHandle P_child, IceRayC_TypeCoord3D P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ reinterpret_cast<Tf__base*> ( P_child ), c2cpp( P_move ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryVacuum0( )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{};
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_GeometryHandle IceRayC_GeometryVacuum1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{ c2cpp( P_lo), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_GeometryHandle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
