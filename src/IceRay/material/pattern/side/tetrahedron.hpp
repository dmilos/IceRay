#ifndef Dh_IceRay_material_pattern_side_tetrahedron_hpp_
 #define Dh_IceRay_material_pattern_side_tetrahedron_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_side_tetrahedron

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

           class GC_tetrahedron
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;

               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_pyramid T_pyramid;


               GC_tetrahedron()
                {
                 std::array<T_coord, 4> I_vertex;
                 math::linear::vector::load<T_scalar,T_scalar>( I_vertex[0], 0,0,1 );
                 math::linear::vector::load<T_scalar,T_scalar>( I_vertex[1],          0.0,  2*sqrt(2)/3.0, -1.0/3.0 );
                 math::linear::vector::load<T_scalar,T_scalar>( I_vertex[2], -sqrt(6)/3.0, -sqrt(2.0)/3.0, -1.0/3.0 );
                 math::linear::vector::load<T_scalar,T_scalar>( I_vertex[3], +sqrt(6)/3.0, -sqrt(2.0)/3.0, -1.0/3.0 );

                 M2_pyramid[0].F_construct( I_vertex[0], I_vertex[1], I_vertex[2] );
                 M2_pyramid[1].F_construct( I_vertex[0], I_vertex[1], I_vertex[2] );
                 M2_pyramid[2].F_construct( I_vertex[1], I_vertex[2], I_vertex[3] );
                 M2_pyramid[3].F_construct( I_vertex[1], I_vertex[2], I_vertex[3] );
                }

               ~GC_tetrahedron()
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
               std::array<T_pyramid, 4> M2_pyramid;
            };

           }
        }
      }
    }
  }

#endif
