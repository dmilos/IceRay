#ifndef Dh_DDMRM_Iceray_material_compute_transmission_reflect_schlick_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_reflect_schlick_HPP_

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
           namespace S_reflect
            {

               class GC_schlick
                : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
                {
                 public:
                   typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                   typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                   typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

                   typedef GS_DDMRM::S_IceRay::S_material::S_medium::GT_jurisdiction T_jurisdiction;

                   typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                   enum Ee_input
                    {
                      En_inCoord_Point  = 0
                     ,En_inCoord_Normal = 1
                     ,En_inRay_Inoming = 0
                     ,En_inScalar_IOR   = 0
                    };
                   enum Ee_output
                    {
                      En_outSize_RayCount=0
                     ,En_outSize_RayStart=1
                    };

                 public:
                   GC_schlick
                    (
                      T_size const& P_inCoord_Point     // = 0
                     ,T_size const& P_inCoord_Normal    // = 1
                     ,T_size const& P_ior               // = 0
                   //,T_size const& P_outSize_RayCount  // = 1
                     ,T_size const& P_outSize_RayStart  // = 2
                    )
                    {
                     F_input<T_coord>(  En_inCoord_Point,   P_inCoord_Point     );
                     F_input<T_coord>(  En_inCoord_Normal,  P_inCoord_Normal    );
                     F_input<T_scalar>( En_inScalar_IOR,    P_ior               );

                   //F_output<T_size>( En_outSize_RayCount, P_outSize_RayCount );
                     F_output<T_size>( En_outSize_RayStart, P_outSize_RayStart );
                    }

                 public:
                   bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                    {


                     auto const&  I_incoming = P_intersect.M_incoming;
                     auto const&  I_intersect = P_intersect.M_intersection;
                     T_coord  const& I_point    = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Point ) );
                     T_coord  const& I_normal   = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Normal) );
                     T_scalar const& I_IOR      = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_IOR  ) );


                     T_scalar I_air   ;
                     T_scalar I_watter;
                     {
                      auto const& I_jurisdiction = P_next.F_jurisdiction();
                      switch( I_jurisdiction.F_in( P_intersect.M_intersection.M_geometryID ) )
                       {
                        case( T_jurisdiction::En_unused ):
                        case( T_jurisdiction::En_close ):
                         {
                          I_air    = I_jurisdiction.F_data( I_jurisdiction.F_head() );
                          I_watter = I_IOR;
                         }break;
                        case( T_jurisdiction::En_open ):
                         {
                          I_air    = I_IOR;
                          I_watter = I_jurisdiction.F_data( I_jurisdiction.F_previous( I_jurisdiction.F_head() ) );
                         }break;
                       }
                     }

                     T_size I_begin = P_next.Fv_size();
                     P_next.Fv_push();
                     T_ray & I_reflected = P_next.Fv_top();

                     I_reflected.M_derivation  = T_ray::Ee_derivation::En_Reflected;
                     I_reflected.M_depth       = I_incoming.M_depth + 1;
                     I_reflected.M_parentUID   = I_incoming.M_UID;
                     I_reflected.M_geometryID  = I_intersect.M_geometryID;
                     I_reflected.M_state       = I_intersect.M_state;
                     I_reflected.M_ior         = I_incoming.M_ior;
                     I_reflected.M_coefficient = T_scalar(1);
                     I_reflected.M_hierarchy   = T_ray::Ee_hierarchy::En_solo;
                     I_reflected.M_origin      = I_point;
                     ::math::linear::vector::reflect( I_reflected.M_direction, I_incoming.M_direction, I_normal );
                     ::math::linear::vector::length( I_reflected.M_direction, T_scalar(1) );

                     GS_DDMRM::S_IceRay::S_material::S_transmission::GC_schlick I_schlick( I_air, I_watter );

                     T_scalar I_reflectance;
                     I_schlick.F_process( I_reflectance, I_incoming.M_direction, I_normal );

                     ::color::operation::scale( I_reflected.M_intesity, I_reflectance, I_incoming.M_intesity );


                   //M2_memoryRay->Fv_store(F_output<T_size>(P_outSize_RayCount),  1 );
                     M2_memorySize->Fv_store( F_output<T_size>(En_outSize_RayStart), P_next.Fv_size() - 1 );
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
                     M2_memorySize   = P_memory->F_get<T_size>();
                     M2_memoryCoord  = P_memory->F_get<T_coord>();
                     M2_memoryColor  = P_memory->F_get<T_color>();
                     M2_memoryScalar = P_memory->F_get<T_scalar>();
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
