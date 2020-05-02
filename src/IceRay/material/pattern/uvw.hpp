#ifndef Dh_IceRay_material_pattern_uvw_hpp_
 #define Dh_IceRay_material_pattern_uvw_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_uvw

#include "./_pure.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/math/coord.hpp"
#include "IceRay/geometry/volumetric/vacuum.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_uvw // use UVW from other object. e.g. aply UVW sphere to cylinder
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base      T_geometry;
           private:
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw        T2_uvw;

           public:
             GC_uvw( T_geometry * P_geometry = nullptr )
              {
               M2_uvw = dynamic_cast<T2_uvw*>( P_geometry );
               if( nullptr == M2_uvw )
                {
                 M2_geometry = & Fs_vacuum();
                 M2_uvw = dynamic_cast<T2_uvw*>( & Fs_vacuum() );
                }
                M2_stateData.resize( M2_geometry->Fv_weight() );
                M2_stateInstance = T2_state( M2_stateData.data() );
                M2_uvw->Fv_reset( M2_stateInstance );
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               M2_uvw->Fv_uvw( P_result, P_coord, M2_stateInstance );
              }

           private:
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T2_state;

             mutable T2_state                  M2_stateInstance;
             mutable std::vector<std::uint8_t> M2_stateData;

             T2_uvw     *M2_uvw;
             T_geometry *M2_geometry;

          private:
           typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum T_vacuum;
           static T_vacuum & Fs_vacuum()
            {
             static T_vacuum Is_vacuum;
             return Is_vacuum;
            }

          };

        }
      }
    }
  }

#endif
