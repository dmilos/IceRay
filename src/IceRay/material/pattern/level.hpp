#ifndef Dh_IceRay_material_pattern_level_hpp_
 #define Dh_IceRay_material_pattern_level_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_level

#include "./_pure.hpp"







 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_level
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {// Done
           public:
             explicit GC_level( T_coord const& P_direction = ::math::linear::vector::fill( T_coord{}, 1 ) )
              :M2_direction( P_direction )
              {
               M2_length = ::math::linear::vector::length( M2_direction );
               M2_length *= M2_length;
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               P_result = ::math::linear::vector::dot( M2_direction, P_coord )/M2_length ;
              }

           private:
             T_coord M2_direction;
             T_scalar M2_length;
          };

        }
      }
    }
  }

#endif
