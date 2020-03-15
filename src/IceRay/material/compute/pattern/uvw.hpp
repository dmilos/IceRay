#ifndef Dh_DDMRM_Iceray_material_compute_pattern_UVW_HPP_
 #define Dh_DDMRM_Iceray_material_compute_pattern_UVW_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GC_UVW

 #include "../../pattern/_pure.hpp"

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_pattern
          {

             class GC_UVW // use UVW from object that we hit
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__pure   T_geometryPure;
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw     T_geometryUVW;

                 typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 enum Ee_input
                  {
                   En_inCoord_Point = 0
                  };

                 enum Ee_output
                  {
                   En_outCoord_result=0
                  };

               public:
                 explicit GC_UVW
                  (
                   ,T_size const& P_point      = 0
                   ,T_size const& P_result     = 0
                  )
                  {
                   F_input<T_coord>( En_inCoord_Point,     P_point );

                   F_output<T_coord>( En_outCoord_result, P_result );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_point      = M2_memoryCoord->Fv_load(   F_input<T_coord >( En_inCoord_Point ) );
                   T_geometry P_intersect.M_geometry;

                   M2_geometryUVW = nullptr; //!< TODO
                   T_coord I_result;

                   M2_geometryUVW->Fv_uvw( I_result, I_point, P_state );

                   M2_memoryCoord->Fv_store( F_output<T_coord>( En_outColor_result ), I_result );
                   return true;
                  }

               private:

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memoryCoord  = dynamic_cast<T2_memoryCoord* >( P_memory->F_get<T_coord>() );
                  }

               private:
                 T2_memoryCoord    *M2_memoryCoord;


             };

          }
        }
      }
    }
  }

#endif
