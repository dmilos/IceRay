#ifndef Dh_IceRay_material_pattern_side_icosahedron_hpp_
 #define Dh_IceRay_material_pattern_side_icosahedron_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_icosahedron

#include "../_pure.hpp"
#include "./pyramid.hpp"

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

           class GC_icosahedron
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;

               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_pyramid T_pyramid;

             public:
               GC_icosahedron()
                {
                 auto gold = math::constants::GOLD;

                 std::array<T_coord, 12> I_vertex;
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 0],    +1, +gold,     0 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 1],    +1, -gold,     0 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 2],    -1, +gold,     0 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 3],    -1, -gold,     0 );

                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 4],     0,    +1, +gold );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 5],     0,    +1, -gold );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 6],     0,    -1, +gold );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 7],     0,    -1, -gold );

                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 8], +gold,     0,    +1 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[ 9], +gold,     0,    -1 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[10], -gold,     0,    +1 );
                 math::linear::vector::load<T_scalar, T_scalar>( I_vertex[11], -gold,     0,    -1 );

                 M2_pyramid[  0 ].F_construct( I_vertex[  0 ], I_vertex[ 11 ], I_vertex[  5 ] );
                 M2_pyramid[  1 ].F_construct( I_vertex[  0 ], I_vertex[  5 ], I_vertex[  1 ] );
                 M2_pyramid[  2 ].F_construct( I_vertex[  0 ], I_vertex[  1 ], I_vertex[  7 ] );
                 M2_pyramid[  3 ].F_construct( I_vertex[  0 ], I_vertex[  7 ], I_vertex[ 10 ] );
                 M2_pyramid[  4 ].F_construct( I_vertex[  0 ], I_vertex[ 10 ], I_vertex[ 11 ] );

                 M2_pyramid[  5 ].F_construct( I_vertex[  1 ], I_vertex[  5 ], I_vertex[  9 ] );
                 M2_pyramid[  6 ].F_construct( I_vertex[  5 ], I_vertex[ 11 ], I_vertex[  4 ] );
                 M2_pyramid[  7 ].F_construct( I_vertex[ 11 ], I_vertex[ 10 ], I_vertex[  2 ] );
                 M2_pyramid[  8 ].F_construct( I_vertex[ 10 ], I_vertex[  7 ], I_vertex[  6 ] );
                 M2_pyramid[  9 ].F_construct( I_vertex[  7 ], I_vertex[  1 ], I_vertex[  8 ] );

                 M2_pyramid[ 10 ].F_construct( I_vertex[  3 ], I_vertex[  9 ], I_vertex[  4 ] );
                 M2_pyramid[ 11 ].F_construct( I_vertex[  3 ], I_vertex[  4 ], I_vertex[  2 ] );
                 M2_pyramid[ 12 ].F_construct( I_vertex[  3 ], I_vertex[  2 ], I_vertex[  6 ] );
                 M2_pyramid[ 13 ].F_construct( I_vertex[  3 ], I_vertex[  6 ], I_vertex[  8 ] );
                 M2_pyramid[ 14 ].F_construct( I_vertex[  3 ], I_vertex[  8 ], I_vertex[  9 ] );

                 M2_pyramid[ 15 ].F_construct( I_vertex[  4 ], I_vertex[  9 ], I_vertex[  5 ] );
                 M2_pyramid[ 16 ].F_construct( I_vertex[  2 ], I_vertex[  4 ], I_vertex[ 11 ] );
                 M2_pyramid[ 17 ].F_construct( I_vertex[  6 ], I_vertex[  2 ], I_vertex[ 10 ] );
                 M2_pyramid[ 18 ].F_construct( I_vertex[  8 ], I_vertex[  6 ], I_vertex[  7 ] );
                 M2_pyramid[ 19 ].F_construct( I_vertex[  9 ], I_vertex[  8 ], I_vertex[  1 ] );
                }

               ~GC_icosahedron()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 for( P_result = 0; P_result < M2_pyramid.size(); ++P_result )
                  {
                   if( true == M2_pyramid[P_result].F_process( P_coord ) )
                    {
                     return;
                    }
                  }
                 P_result = 0;
                }
             public:
               std::array<T_pyramid, 20> M2_pyramid;
            };

           }
        }
      }
    }
  }

#endif
