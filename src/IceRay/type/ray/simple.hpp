#ifndef Dh_DDMM_IceRay_type_ray_simple_HPP_
 #define Dh_DDMM_IceRay_type_ray_simple_HPP_
// GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple

 #include "../math/coord.hpp"
 #include "../color.hpp"

 #include "./line.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_ray
        {

         class GC_simple
          : public GS_DDMRM::S_IceRay::S_type::S_ray::GC_line
          {
           public:

             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar         T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar T_gray;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_line   T_line;

           public:
             GC_simple()
              :M_intesity( T_gray{1} )
              {
              }

             explicit GC_simple( T_line const& P_line )
               : T_line( P_line )
               , M_intesity( T_gray{1} )
              {
              }

             GC_simple const& operator=( T_line const& P_line )
              { 
               (T_line)*this = P_line;
               return *this;
              }

           public:
             T_color M_intesity;
          };

        }
      }
    }
  }

#endif

