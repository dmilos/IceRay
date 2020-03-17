#ifndef Dh_DDMRM_Iceray_material_transmission__pure_HPP_
 #define Dh_DDMRM_Iceray_material_transmission__pure_HPP_

 // GS_DDMRM::S_IceRay::S_material::S_transmission::GC__pure

 #include "IceRay/type/basic/size.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_transmission
        {

         class GC__pure //! Probably no need
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
             typedef GS_DDMRM::S_IceRay::S_material::GT_beam            T_beam;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state  T_state;
             typedef GS_DDMRM::S_IceRay::S_material::GC_intersect       T_intersect, T_incident;

                      GC__pure(){}
             virtual ~GC__pure(){}

           public:
             virtual T_size const& Fv_max( )const=0; //!< maximum number of next rays
             virtual bool Fv_color( T_beam &P_next, T_incident const& P_incident, T_state const& P_state )const=0; //!< calculate next rays
          };

        }
      }
    }
  }

#endif