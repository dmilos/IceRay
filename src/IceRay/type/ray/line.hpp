#ifndef Dh_DDMM_IceRay_type_ray_line_HPP_
 #define Dh_DDMM_IceRay_type_ray_line_HPP_
// GS_DDMRM::S_IceRay::S_type::S_ray::GC_line

 #include "../basic/scalar.hpp"
 #include "../math/coord.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_ray
        {

         class GC_line
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

           public:
             GC_line()
              :M_origin( {0} )
              ,M_direction( {1} )
              {
              }

           public:
             T_coord M_origin;
             T_coord M_direction;
          };

        }
      }
    }
  }

#endif

