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
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_size2D;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D T_size3D;
             //typedef std::array<T_scalar, 3> T_block;

             public:
               GC__pure()
                :GC__pure(2,2)
               {
               }

               GC__pure( T_size const& P_x, T_size const& P_y )
                : GC__pure( T_size2D{ P_x, P_y } )
                {
                }
               explicit GC__pure( T_size2D const& P_size )
                {
                 M2_size[2] = 2;
                 Fv_size( P_size );
                }
              ~GC__pure(){ }

             public:
               virtual T_scalar Fv_value( T_size const& P_x, T_size const& P_y )const=0;
               virtual T_scalar Fv_value( T_size2D const& P_size )const=0;
             //virtual T_block  Fv_value( T_size const& P_x, T_size const& P_y )const=0;
             //virtual T_block  Fv_value( T_size2D const& P_size )const=0;

             public:
               T_size3D    const& F_size()const
                {
                 return M2_size;
                }

               virtual bool Fv_size( T_size2D    const& P_size )
                {
                 if( P_size[0] < 2 ) return false;
                 if( P_size[1] < 2 ) return false;
                 M2_size[0] = P_size[0];
                 M2_size[1] = P_size[1];
                 return true;
                }
             private:
               T_size3D      M2_size; //!< Number of fields. Like grid. 1x1 is vertical line, 2x2 is cube. 3x3 is four cubes, ...
            };

          }
        }
      }
    }
  }

#endif
