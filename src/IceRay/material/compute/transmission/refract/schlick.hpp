#ifndef Dh_DDMRM_Iceray_material_compute_transmission_refract_schlick_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_refract_schlick_HPP_

 #include <tuple>
 #include <limits>

 #include "../../instruction.hpp"
 #include "../../../transmission/schlick.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_transmission
          {
           namespace S_refract
            {

               class GC_schlick// Approximation with reflection
                : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
                {
                 public:
                   typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                   typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                   typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                   enum Ee_input
                    {
                      En_inCoord_Point  = 0
                     ,En_inCoord_Normal = 1
                     ,En_inRay_Incoming = 0
                     ,En_inScalar_IOR   = 0
                     ,En_inColor_Albedo = 0
                    };
                   enum Ee_output
                    {
                      En_outSize_RayCount=0
                     ,En_outRay_refracted=1
                    };

                 public:
                   GC_schlick
                    (
                      T_size const& P_inCoord_Point     = 0
                     ,T_size const& P_inCoord_Normal    = 1
                     ,T_size const& P_ior               = 0
                     ,T_size const& P_albedo            = 0
                   //,T_size const& P_outSize_rayCount = 0,
                   //,T_size const& P_outRay_refracted = 1
                    )
                    {
                     F_input<T_coord>(  En_inCoord_Point,       P_inCoord_Point     );
                     F_input<T_coord>(  En_inCoord_Normal,      P_inCoord_Normal    );
                     F_input<T_color>(  En_inColor_Albedo,      P_albedo );
                     F_input<T_scalar>( En_inScalar_IOR,        P_ior       );

                   //F_output<T_size>( En_outSize_RayCount,     P_outSize_RayCount );
                   //F_output( T_memory::En_ray,   En_outRay_refracted,     P_outRay_refracted );
                    }

                 public:
                   bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                    {


                     auto const&  I_incoming = P_intersect.M_incoming; //!< The ONE
                     auto const&  I_intersection = P_intersect.M_intersection;
                     T_coord  const& I_point    = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Point ) );
                     T_coord  const& I_normal   = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Normal) );
                     T_scalar const& I_IOR      = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_IOR  ) );
                     T_color  const& I_albedo   = M2_memoryColor->Fv_load( F_input<T_color>(  En_inColor_Albedo) );

                     T_color  I_intensity;
                     ::color::operation::multiply( I_intensity, I_albedo, I_incoming.M_intesity );

                     T_scalar I_air = 1.000277;
                     T_scalar I_watter = I_IOR;

                     if( 1.000277 != I_incoming.M_ior )
                      {
                       I_air = I_IOR;
                       I_watter = 1.000277;
                      }
                     GS_DDMRM::S_IceRay::S_material::S_transmission::GC_schlick I_schlick( I_air, I_watter );

                     T_scalar  I_reflectance    ;
                     I_schlick.F_process( I_reflectance, I_incoming.M_direction, I_normal );
                     T_scalar  I_transparency = T_scalar(1) - I_reflectance;


                     T_coord I_reflected; ::math::linear::vector::reflect( I_reflected, I_incoming.M_direction, I_normal );
                     T_coord I_refracted;
                     switch( ::math::linear::vector::refract( I_refracted, I_incoming.M_direction, I_normal, I_air, I_watter ) )
                      {
                       case( 0 ):
                       case( +1 ):
                        {
                         {
                          P_next.Fv_push( );
                          auto &I_ray = P_next.Fv_top();

                          I_ray.M_geometryID = P_intersect.M_intersection.M_geometryID;
                          I_ray.M_depth  = I_incoming.M_depth+1;
                          I_ray.M_origin = I_point;
                          I_ray.M_state = I_intersection.M_state;
                          I_ray.M_direction = I_refracted;
                          I_ray.M_type = T_ray::En_type1Refracted;
                          I_ray.M_ior  = I_watter;
                          I_ray.M_intesity = I_transparency * I_incoming.M_intesity;
                          I_ray.M_coefficient = I_transparency;
                         }
                         {
                          P_next.Fv_push( );
                          auto &I_ray = P_next.Fv_top();

                          I_ray.M_geometryID = P_intersect.M_intersection.M_geometryID;
                          I_ray.M_depth  = I_incoming.M_depth+1;
                          I_ray.M_origin = I_point;
                          I_ray.M_state = I_intersection.M_state;
                          I_ray.M_direction  = I_reflected;
                          I_ray.M_type = T_ray::En_type1Reflected;
                          I_ray.M_ior  = I_air;
                          I_ray.M_intesity = I_reflectance * I_incoming.M_intesity;
                          I_ray.M_coefficient = I_reflectance;
                         }
                        } break;

                       case( -1 ):
                        {
                         I_reflectance = I_reflectance + I_transparency;
                         P_next.Fv_push( );
                         auto &I_ray = P_next.Fv_top();

                         I_ray.M_geometryID = P_intersect.M_intersection.M_geometryID;
                         I_ray.M_depth  = I_incoming.M_depth+1;
                         I_ray.M_origin = I_point;
                         I_ray.M_state = I_intersection.M_state;
                         I_ray.M_direction  = I_reflected;
                         I_ray.M_type = T_ray::En_type1Reflected;
                         I_ray.M_ior  = I_air;
                         I_ray.M_intesity=  I_reflectance * I_incoming.M_intesity;
                         I_ray.M_coefficient = I_reflectance;
                        }break;
                      }
                     //M2_memoryRay->Fv_store( F_output()[ T_memory::En_size][ En_outRay_Rayrefracted ], I_refracted );
                     //M2_memorySize->Fv_store( F_output()[ T_memory::En_size][ En_outSize_RayCount ], 1 );

                     return true;
                    }

                 private:
                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;
                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color>   T2_memoryColor;
                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_ray>     T2_memoryRay;

                 public:
                   void    Fv_memory( T_memory * P_memory  )
                    {
                     F1_memory() = P_memory;
                     M2_memorySize   = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>(    ) );
                     M2_memoryCoord  = dynamic_cast<T2_memoryCoord* >( P_memory->F_get( T_memory::En_coord3D ) );
                     M2_memoryColor  = dynamic_cast<T2_memoryColor* >( P_memory->F_get<T_color>(   ) );
                     M2_memoryScalar = dynamic_cast<T2_memoryScalar* >( P_memory->F_get<T_scalar>(   ) );
                   //M2_memoryRay    = dynamic_cast<T2_memoryRay  * >( P_memory->F_get( T_memory::En_ray     ) );
                    }

                 private:
                   T2_memorySize     *M2_memorySize;
                   T2_memoryCoord    *M2_memoryCoord;
                   T2_memoryColor    *M2_memoryColor;
                   T2_memoryScalar   *M2_memoryScalar;
                 //T2_memoryRay      *M2_memoryRay;
                 //T_medium          *M2_medium;
                };

            }
          }
        }
      }
    }
  }

#endif
