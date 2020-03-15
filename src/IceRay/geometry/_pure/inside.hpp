#ifndef _DDMRM_Iceray_geometry__pure_inside_hpp_
 #define _DDMRM_Iceray_geometry__pure_inside_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside

#include "./_base.hpp"


#include "IceRay/type/math/coord.hpp"






 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_inside
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;

             typedef enum Ee_location
              {
               En_nowhere     = 0,
               En_in          = 1,
               En_out         = 2,
               En_symmetric   = 3, // = En_in + En_out
               En_surface     = 4,
               En_closure     = 5, // = En_surface + En_in
               En_complement  = 6, // = En_surface + En_out
               En_everywhere  = 7  // = En_in + En_out + En_surface
              } T_location;

           public:
                      GC_inside(){}
             virtual ~GC_inside(){}

           public:
             virtual T_location  Fv_inside   ( T_coord const& P_point/*, T_state &P_state*/ )const=0;

           public:
             static T_location Fs_invert( T_location const& P_where )
              {
               return T_location( 7 - P_where );
              }

             static T_location Fs_union( T_location const& P_left, T_location const& P_right )
              {
               return T_location( P_left | P_right );
              }

             static T_location Fs_intersect( T_location const& P_left, T_location const& P_right )
              {
               return T_location( P_left & P_right );
              }
          };

        }
      }
    }
  }

#endif
