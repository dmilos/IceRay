#ifndef Dh_IceRay_material_pattern_side_pyramid_hpp_
 #define Dh_IceRay_material_pattern_side_pyramid_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_pyramid

#include "../_pure.hpp"

#include <iostream>
#include <iomanip>




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {
         namespace S_side
          {

           class GC_pyramid
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine T_affine;



               GC_pyramid( )
                {

                }

               ~GC_pyramid()
                {
                }

             public:
               void F_construct( T_coord const&a, T_coord const&b, T_coord const&c )
                {
                 T_affine I_2world;
                 static T_coord Is_zero{0,0,0};
                 ::math::linear::affine::system( I_2world, Is_zero, a, b, c );
                 ::math::linear::affine::invert( M2_2local, I_2world );
                }

             public:
               bool  F_process( T_coord const& P_coord )const
                { // NOTE: open pyramid with bas of triangle
                 T_coord I_local;
                 ::math::linear::affine::transform( I_local, M2_2local, P_coord );

                 if( I_local[0] < 0 ) return false;
                 if( I_local[1] < 0 ) return false;
                 if( I_local[2] < 0 ) return false;
                 return true;
                }
             public:
               T_affine M2_2local;
            };

           }
        }
      }
    }
  }

#endif
