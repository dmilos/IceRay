#ifndef Dh_DDMRM_Iceray_medium_$[![name]!]_HPP_
 #define Dh_DDMRM_Iceray_medium_$[![name]!]_HPP_

 #include "../medium.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_$[![name]!]
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:

             explicit GC_$[![name]!](){ ; }
             virtual ~GC_$[![name]!](){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end )const
              {
               return $[![TODO]!]
              }

          };

        }
      }
    }
  }

#endif
