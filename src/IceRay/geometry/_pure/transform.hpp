#ifndef _DDMRM_Iceray_geometry__pure_transform_hpp_
 #define _DDMRM_Iceray_geometry__pure_transform_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_transform

#include "./_base.hpp"


#include "IceRay/type/math/matrix.hpp"
#include "IceRay/type/math/affine.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_transform
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine    T_affine;
             typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_matrix    T_matrix;

           public:
                      GC_transform();
             virtual ~GC_transform();

           public:
             // return is live as long P_state is live. One depth only. Use fragment to reach leaf.
             virtual T_affine const&  Fv_2world( T_state const& P_state )const
              {
               return Fs_identity();
              }

             // return is live as long P_state is live. One depth only. Use fragment to reach leaf.
             virtual T_affine const&  Fv_2local( T_state const& P_state )const
              {
               return Fs_identity();
              }

           public:
             static T_affine const& Fs_identity ()
              {
               static T_affine Irs_identity  = ::math::linear::affine::id( T_affine{} );
               return  Irs_identity;
              }
          };

        }
      }
    }
  }

#endif
