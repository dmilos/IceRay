#ifndef Dh_DDMM_IceRay_camera_type_system_HPP_
 #define Dh_DDMM_IceRay_camera_type_system_HPP_
// GS_DDMRM::S_IceRay::S_camera::S_type::GT_system;


#include "../../type/math/coord.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_camera
      {
       namespace S_type
        {

         template < unsigned N_dimension, unsigned N_size >
          struct GC_system
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
           typedef typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< T_scalar, N_dimension >::T_typedef T_coord;

           typedef  std::array< T_coord, N_size > T_typedef;
          };

        }
      }
    }
  }

#endif

