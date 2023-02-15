#ifndef Dh_DDMM_IceRay_type_color_HPP_
 #define Dh_DDMM_IceRay_type_color_HPP_

// GS_DDMRM::S_IceRay::S_type::S_color::GT_char
// GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
// GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_char
// GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar
// using namespace GS_DDMRM::S_graph::S_color::S_operator

#include "IceRay/type/nothing.hpp"

#include "color/color.hpp"

#include "./basic/scalar.hpp"
#include "./basic/size.hpp"
#include "./basic/integer.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_color
        {

         namespace S__internal
          {

           //typedef double GT_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar GT_scalar;

          }


         typedef  ::color::rgb<GS_DDMRM::S_IceRay::S_type::GT_uint8>    GT_char;
         typedef  ::color::rgb<GS_DDMRM::S_IceRay::S_type::S_color::S__internal::GT_scalar>   GT_scalar;

         namespace S_gray
          {

           typedef  ::color::gray<GS_DDMRM::S_IceRay::S_type::GT_uint8>   GT_char;
           typedef  ::color::gray<GS_DDMRM::S_IceRay::S_type::S_color::S__internal::GT_scalar>  GT_scalar;

          }

         namespace S_HSL
          {

           typedef  ::color::hsl<GS_DDMRM::S_IceRay::S_type::GT_uint8>   GT_char;
           typedef  ::color::hsl<GS_DDMRM::S_IceRay::S_type::S_color::S__internal::GT_scalar>  GT_scalar;

          }

        }
      }
    }
  }

#endif

