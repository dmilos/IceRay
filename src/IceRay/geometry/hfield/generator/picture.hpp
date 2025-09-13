#ifndef _DDMM_IceRAY_geometry_hfield_generator_picture_H_
 #define _DDMM_IceRAY_geometry_hfield_generator_picture_H_

// GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_picture


#include "IceRay/type/basic/string.hpp"
#include "IceRay/type/basic/bool.hpp"
#include "IceRay/type/picture/memory.hpp"


#include "./_pure.hpp"
#include "./table.hpp"

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

           class GC_image
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T__pure;
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table T_table;

             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_bool     T_bool;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      T_picture;

             public:
                          GC_image( );
                explicit  GC_image( T_picture const& P_picture );

             public:
                T_bool F_picture( T_picture const& P_picture );
             public:
                T_bool Fv_size( T_size2D    const& P_size );
            };

          }
        }
      }
    }
  }

#endif