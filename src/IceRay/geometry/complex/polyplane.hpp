#ifndef _DDMM_IceRAY_geometry_complex_polyplane_H_
 #define _DDMM_IceRAY_geometry_complex_polyplane_H_


#include "../_pure/_base.hpp"
#include "../_pure/intersect.hpp"
#include "../_pure/normal.hpp"
#include "../_pure/inside.hpp"
#include "../_pure/distance.hpp"


 namespace S_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_complex
      {

       class GC_polyplane
        : public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        {
         public:
         /* TODO
           typedef struct PLANE
            {
             VECTOR3  point, normal;
             TEXTURE  texture;
            } PLANE;
           typedef enum PLANES__TYPE
            {
             PLANES__tAND,
             PLANES__tXOR
            }PLANES__TYPE;
         */

         public:
           GC_polyplane( );
          ~GC_polyplane( );

         public:
           void F_erase( T_size const& P_index );
           void F_append( T_coord const& P_origin, T_coord const& P_normal, T_type const& P_type = En_AND );

        protected:
       };

      }
    }
  }

#endif
