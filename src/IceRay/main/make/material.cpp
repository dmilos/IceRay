#include "IceRay/type/basic/size.hpp"
#include "IceRay/material/pattern/constant.hpp"
#include "IceRay/material/compute/surface.hpp"
#include "IceRay/material/compute/pattern/constant.hpp"
#include "IceRay/material/compute/light/swarm1.hpp"
#include "IceRay/material/compute/illumination/ward_real.hpp"
#include "IceRay/material/compute/illumination/ward_isotropic.hpp"
#include "IceRay/material/compute/illumination/ward_approx.hpp"
#include "IceRay/material/compute/illumination/phong.hpp"
#include "IceRay/material/compute/illumination/on_p44.hpp"
#include "IceRay/material/compute/illumination/lambert.hpp"
#include "IceRay/material/compute/illumination/hs_phong.hpp"
#include "IceRay/material/compute/illumination/hs_lambert.hpp"
#include "IceRay/material/compute/illumination/gaussian.hpp"
#include "IceRay/material/compute/illumination/blinn.hpp"
#include "IceRay/material/compute/illumination/beckmann.hpp"
#include "IceRay/material/compute/illumination/ambient.hpp"
#include "IceRay/material/compute/geometry/normal.hpp"
#include "IceRay/material/compute/geometry/cluster.hpp"

//#include "IceRay/material/compute/intersect.hpp"


typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar        GTs_coord;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar        GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::GT_size                   GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                 GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface GTs_surface;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure                 GTs_light;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base     GTs_geometry;


void make_pigment_illumination_ambient
 (
   GTs_surface        *P_surface
  ,GTs_size     const& P_emission
  ,GTs_size     const& P_color 
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_ambient Tf_ambient;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_ambient *I_ambient= nullptr;

  I_ambient = new Tf_ambient(  );

  I_ambient->F_input(  Tf_memory::En_color,   Tf_ambient::En_inColor_Emission,   P_emission );

  I_ambient->F_output( Tf_memory::En_color ,  Tf_ambient::En_outColor_result,    P_color );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_ambient );
 }



void make_pigment_illumination_beckmann
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Roughness
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_beckmann Tf_beckmann;

  Tf_beckmann *I_beckmann = new Tf_beckmann(  );

  I_beckmann->F_input(  Tf_memory::En_coord,   Tf_beckmann::En_inCoord_Point,      0 );
  I_beckmann->F_input(  Tf_memory::En_coord,   Tf_beckmann::En_inCoord_Normal,     1 );
  I_beckmann->F_input(  Tf_memory::En_size,    Tf_beckmann::En_inSize_LightCount,  0 );

  I_beckmann->F_input(  Tf_memory::En_color,   Tf_beckmann::En_inColor_Specular,    P_inColor_Specular  );
  I_beckmann->F_input(  Tf_memory::En_color,   Tf_beckmann::En_inColor_Roughness,   P_inColor_Roughness  );
  I_beckmann->F_output( Tf_memory::En_color ,  Tf_beckmann::En_outColor_result,     P_outColor_result    );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_beckmann );
 }

void make_pigment_illumination_blinn
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Shininess
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_blinn Tf_blinn;

  Tf_blinn *I_blinn = new Tf_blinn(  );

  I_blinn->F_input(      Tf_memory::En_coord,   Tf_blinn::En_inCoord_Point,      0 );
  I_blinn->F_input(      Tf_memory::En_coord,   Tf_blinn::En_inCoord_Normal,     1 );
  I_blinn->F_input(      Tf_memory::En_size,    Tf_blinn::En_inSize_LightCount,  0 );

  I_blinn->F_input(  Tf_memory::En_color,   Tf_blinn::En_inColor_Specular,    P_inColor_Specular  );
  I_blinn->F_input(  Tf_memory::En_color,   Tf_blinn::En_inColor_Shininess,   P_inColor_Shininess );
  I_blinn->F_output( Tf_memory::En_color ,  Tf_blinn::En_outColor_result,     P_outColor_result   );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_blinn );
 }


void make_pigment_illumination_gaussian
 (
  GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Smoothness
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_gaussian Tf_gaussian;

  Tf_gaussian *I_gaussian = new Tf_gaussian(  );

  I_gaussian->F_input(   Tf_memory::En_coord,   Tf_gaussian::En_inCoord_Point,     0 );
  I_gaussian->F_input(   Tf_memory::En_coord,   Tf_gaussian::En_inCoord_Normal,    1 );
  I_gaussian->F_input(   Tf_memory::En_size,    Tf_gaussian::En_inSize_LightCount, 0 );

  I_gaussian->F_input(  Tf_memory::En_color,   Tf_gaussian::En_inColor_Specular,    P_inColor_Specular  );
  I_gaussian->F_input(  Tf_memory::En_color,   Tf_gaussian::En_inColor_Smoothness,  P_inColor_Smoothness );
  I_gaussian->F_output( Tf_memory::En_color ,  Tf_gaussian::En_outColor_result,     P_outColor_result   );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_gaussian );
 }


void make_pigment_illumination_HeidrichSeidel_lambert
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Diffuse
  ,GTs_size const& P_inCoord_Groove
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_Lambert Tf_HeidrichSeidelLambert;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_HeidrichSeidelLambert *I_HeidrichSeidel= new Tf_HeidrichSeidelLambert();

  I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelLambert::En_inCoord_Point,      0 );
  I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelLambert::En_inCoord_Normal,     1 );
  I_HeidrichSeidel->F_input(  Tf_memory::En_size,    Tf_HeidrichSeidelLambert::En_inSize_LightCount,  0 );

  I_HeidrichSeidel->F_input(  Tf_memory::En_color,   Tf_HeidrichSeidelLambert::En_inColor_Diffuse,    P_inColor_Diffuse  );
  I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelLambert::En_inCoord_Groove,     P_inCoord_Groove   );
  I_HeidrichSeidel->F_output( Tf_memory::En_color ,  Tf_HeidrichSeidelLambert::En_outColor_result,    P_outColor_result  );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_HeidrichSeidel );
 }


void make_pigment_illumination_HeidrichSeidel_phong
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inCoord_Groove
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Shininess
  ,GTs_size const& P_outColor_result
 )
 {
   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_Phong Tf_HeidrichSeidelPhong;
   typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
   Tf_HeidrichSeidelPhong *I_HeidrichSeidel= new Tf_HeidrichSeidelPhong();

   I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelPhong::En_inCoord_Point,      0 );
   I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelPhong::En_inCoord_Normal,     1 );
   I_HeidrichSeidel->F_input(  Tf_memory::En_size,    Tf_HeidrichSeidelPhong::En_inSize_LightCount,  0 );

   I_HeidrichSeidel->F_input(  Tf_memory::En_coord,   Tf_HeidrichSeidelPhong::En_inCoord_Groove,     P_inCoord_Groove    );
   I_HeidrichSeidel->F_input(  Tf_memory::En_color,   Tf_HeidrichSeidelPhong::En_inColor_Specular,   P_inColor_Specular  );
   I_HeidrichSeidel->F_input(  Tf_memory::En_color,   Tf_HeidrichSeidelPhong::En_inColor_Shininess,  P_inColor_Shininess );
   I_HeidrichSeidel->F_output( Tf_memory::En_color ,  Tf_HeidrichSeidelPhong::En_outColor_result,    P_outColor_result   );

   P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_HeidrichSeidel );
 }


//void make_pigment_illumination_HeidrichSeidel_normal( ... );


void make_pigment_illumination_lambert
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Diffuse
  ,GTs_size const& P_outColor_result
)
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_lambert Tf_lambert;

  Tf_lambert *I_lambert = new Tf_lambert(  );

  I_lambert->F_input(  Tf_memory::En_coord,   Tf_lambert::En_inCoord_Point,      0 );
  I_lambert->F_input(  Tf_memory::En_coord,   Tf_lambert::En_inCoord_Normal,     1 );
  I_lambert->F_input(  Tf_memory::En_size,    Tf_lambert::En_inSize_LightCount,  0 );

  I_lambert->F_input(  Tf_memory::En_color,   Tf_lambert::En_inColor_Diffuse,    P_inColor_Diffuse );

  I_lambert->F_output( Tf_memory::En_color ,  Tf_lambert::En_outColor_result,    P_outColor_result );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_lambert );
 }



// WARNING OBSOLETE !!!
void make_pigment_illumination_light( GTs_surface *P_surface, GTs_geometry *P_geometry,  GTs_light * P_light,  GTs_size const& P_point, GTs_size const& P_count )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarm1 Tf_light;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory          Tf_memory;
  Tf_light *I_light = new Tf_light();

  I_light->F_light( P_light );
  //I_light->F_geometry( dynamic_cast< Tf_light::T_geometry * > ( P_geometry ) );
  I_light->F_input(  Tf_memory::En_coord, Tf_light::En_inCoord_Point, P_point );
  I_light->F_output( Tf_memory::En_size,  Tf_light::En_outSize_SpotCount, P_count );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_light );
 }


void make_pigment_illumination_on_p44
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_A
  ,GTs_size const& P_inColor_B
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_p44  Tf_on44;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_on44 *I_on44= new Tf_on44();

  I_on44->F_input(  Tf_memory::En_coord,  Tf_on44::En_inCoord_Point,      0 );
  I_on44->F_input(  Tf_memory::En_coord,  Tf_on44::En_inCoord_Normal,     1 );
  I_on44->F_input(  Tf_memory::En_size,   Tf_on44::En_inSize_LightCount,  0 );

  I_on44->F_input(  Tf_memory::En_color,  Tf_on44::En_inColor_A,        P_inColor_A        );
  I_on44->F_input(  Tf_memory::En_color,  Tf_on44::En_inColor_B,        P_inColor_B        );
  I_on44->F_output( Tf_memory::En_color , Tf_on44::En_outColor_result,  P_outColor_result  );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_on44 );
 }


GTs_color compute_on_p44_A( GTs_color const& P_sigma )
 {
  GTs_color Ir_A;
  Ir_A.set( 0, 1 - 0.5 * P_sigma[0] * P_sigma[0]/( P_sigma[0] * P_sigma[0]  + 0.33 ) /* + 0.17 * P_ro * P_sigma[0]* P_sigma[0]/( P_sigma[0] * P_sigma[0]  + 0.13 )*/ );
  Ir_A.set( 1, 1 - 0.5 * P_sigma[1] * P_sigma[1]/( P_sigma[1] * P_sigma[1]  + 0.33 ) /* + 0.17 * P_ro * P_sigma[1]* P_sigma[1]/( P_sigma[1] * P_sigma[1]  + 0.13 )*/ );
  Ir_A.set( 2, 1 - 0.5 * P_sigma[2] * P_sigma[2]/( P_sigma[2] * P_sigma[2]  + 0.33 ) /* + 0.17 * P_ro * P_sigma[2]* P_sigma[2]/( P_sigma[2] * P_sigma[2]  + 0.13 )*/ );
  return Ir_A;
 }

GTs_color compute_on_p44_B( GTs_color const& P_sigma )
 {
  GTs_color Ir_B;
  Ir_B.set( 0, 0.45 * P_sigma[0] * P_sigma[0]/( P_sigma[0] * P_sigma[0]  + 0.09 ) );
  Ir_B.set( 1, 0.45 * P_sigma[1] * P_sigma[1]/( P_sigma[1] * P_sigma[1]  + 0.09 ) );
  Ir_B.set( 2, 0.45 * P_sigma[2] * P_sigma[2]/( P_sigma[2] * P_sigma[2]  + 0.09 ) );
  return Ir_B;
 }


void make_pigment_illumination_phong
 (
   GTs_surface *P_surface
  ,GTs_size const& P_outColor_result
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Shininess
  ,GTs_size const& P_inSize_LightCount
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_phong Tf_phong;

  Tf_phong *I_phong = new Tf_phong(  );

  I_phong->F_input(  Tf_memory::En_color,   Tf_phong::En_inColor_Specular,    P_inColor_Specular  );
  I_phong->F_input(  Tf_memory::En_color,   Tf_phong::En_inColor_Shininess,   P_inColor_Shininess );
  I_phong->F_input(  Tf_memory::En_size,    Tf_phong::En_inSize_SpotCount,   P_inSize_LightCount );

  I_phong->F_output( Tf_memory::En_color ,  Tf_phong::En_outColor_result,     P_outColor_result   );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_phong );
 }


void make_pigment_illumination_ward_approx
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_AlphaX
  ,GTs_size const& P_inColor_AlphaY
  ,GTs_size const& P_inCoord_Direction
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_approx Tf_ward;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_ward *I_ward = nullptr;

  I_ward = new Tf_ward();

  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Point,       0 );
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Normal,      1 );
  I_ward->F_input(  Tf_memory::En_size,    Tf_ward::En_inSize_LightCount,   0 );
  
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_Specular,    P_inColor_Specular   );
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_AlphaX,      P_inColor_AlphaX     );
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_AlphaY,      P_inColor_AlphaY     );
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Direction,   P_inCoord_Direction  );
  I_ward->F_output( Tf_memory::En_color ,  Tf_ward::En_outColor_result,     P_outColor_result    );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_ward );
 }

void make_pigment_illumination_ward_real
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_AlphaX
  ,GTs_size const& P_inColor_AlphaY
  ,GTs_size const& P_inCoord_Direction
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_real Tf_ward;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_ward *I_ward = nullptr;

  I_ward = new Tf_ward();

  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Point,       0 );
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Normal,      1 );
  I_ward->F_input(  Tf_memory::En_size,    Tf_ward::En_inSize_LightCount,   0 ) ;
  
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_Specular,    P_inColor_Specular  );
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_AlphaX,      P_inColor_AlphaX    );
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_AlphaY,      P_inColor_AlphaY    );
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Direction,   P_inCoord_Direction );
  I_ward->F_output( Tf_memory::En_color ,  Tf_ward::En_outColor_result,     P_outColor_result   );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_ward );

 }

void make_pigment_illumination_ward_isotropic
 (
   GTs_surface *P_surface
  ,GTs_size const& P_inColor_Specular
  ,GTs_size const& P_inColor_Alpha
  ,GTs_size const& P_outColor_result
 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_isotropic Tf_ward;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;
  Tf_ward *I_ward = nullptr;

  I_ward = new Tf_ward();
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Point,       0 );
  I_ward->F_input(  Tf_memory::En_coord,   Tf_ward::En_inCoord_Normal,      1 );
  I_ward->F_input(  Tf_memory::En_size,    Tf_ward::En_inSize_LightCount,   0 );
  
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_Specular,    P_inColor_Specular   );
  I_ward->F_input(  Tf_memory::En_color,   Tf_ward::En_inColor_Alpha,       P_inColor_Alpha      );
  I_ward->F_output( Tf_memory::En_color ,  Tf_ward::En_outColor_result,     P_outColor_result    );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_ward );
 }






void make_pigment_normal( GTs_surface *P_surface, GTs_geometry * P_geometry, GTs_size const& P_point, GTs_size const& P_normal )
{
   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GC_normal Tf_normal;
   typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

   Tf_normal  *I_normal = new Tf_normal( );

 // TODO I_normal->F_input(  Tf_memory::En_geometryNormal, Tf_normal::En_inGeometryNormal_This,  P_geometry );
 // STATE
   I_normal->F_input(  Tf_memory::En_coord3D,        Tf_normal::En_inCoord_Point,  P_point );
   I_normal->F_output( Tf_memory::En_coord3D,        Tf_normal::En_outCoord_Normal, P_normal );

   P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_normal );
}










void make_pigment_pattern_size_const( GTs_surface *P_surface, GTs_size const& P_size, GTs_size const& P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GT_constSize   Tf_size;

  Tf_size *I_size = new Tf_size( P_size, P_result );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_size );
 }

void make_pigment_pattern_scalar_const( GTs_surface *P_surface, GTs_scalar const& P_scalar, GTs_size const& P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GT_constScalar   Tf_scalar;

  Tf_scalar *I_scalar = new Tf_scalar( P_scalar, P_result );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_scalar );
 }

void make_pigment_pattern_color_const( GTs_surface *P_surface, GTs_color const& P_color, GTs_size const& P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GT_constColor   Tf_color;

  Tf_color *I_color = new Tf_color( P_color, P_result );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_color );
 }

void make_pigment_pattern_coord_const( GTs_surface *P_surface, GTs_coord const& P_coord, GTs_size const& P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            Tf_memory;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GT_constCoord3D   Tf_coord;

  Tf_coord *I_coord = new Tf_coord( P_coord, P_result );

  P_surface->F_pocessor().F_instruction( P_surface->F_pocessor().F_program().F_papllet().size(), I_coord );
 }

