#ifndef _DDMM_IceRAY_geometry_hfield_generator__pure_H_
 #define _DDMM_IceRAY_geometry_hfield_generator__pure_H_

// GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure


#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {
         namespace S_generator
          {

           class GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_coord;

             public:
               GC__pure()
                :GC__pure(1,1)
               {
               }

               explicit GC__pure( T_coord const& P_size )
                :M2_size( P_size )
                {
                 ;
                }

               GC__pure( T_size const& P_x, T_size const& P_y )
                {
                 M2_size[0] = P_x;
                 M2_size[1] = P_y;
                }
              ~GC__pure(){ }

             public:
               //virtual std::array<T_scalar, 9> Fv_block( T_size const& P_y, T_size const& P_x )const=0;
             public:
               virtual T_scalar Fv_value( T_size const& P_y, T_size const& P_x )const=0;
               virtual T_scalar Fv_value( T_coord const& P_size )const=0;

             public:
               T_coord    const& F_size()const
                {
                 return M2_size;
                }
             protected:
               T_coord        & F1_size(){ return M2_size; }
             private:
               T_coord      M2_size; //!< Number of fields. Like grid. 1x1 is vertical line, 2x2 is cube. 3x3 is four cubes, ...
             public:
            };

          }
        }
      }
    }
  }

#endif
