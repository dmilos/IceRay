#ifndef _DDMRM_Iceray_geometry__pure__base_hpp_
 #define _DDMRM_Iceray_geometry__pure__base_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base


#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/interval.hpp"
#include "IceRay/type/ray/line.hpp"

#include "../_type/state.hpp"
#include "../_type/ray.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                         T_size;

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D         T_box, T_interval;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state            T_state;

                      GC__base();
                      GC__base( T_box const& P_box );
             virtual ~GC__base();

           public:
             virtual T_size  Fv_weight( )const=0;
             virtual void    Fv_reset( T_state &P_state )const=0;
           //virtual void    Fv_weight( T_size const& P_size, T_size const& P_count )const=0;

           public:
             T_box const& F_box()const
              {
               return M2_box;
              }
             virtual bool Fv_box( T_box const& P_box )
              {
               return false;
              }
           protected:
             void F1_box( T_box const& P_box )
              {
               M2_box = P_box;
               ::math::linear::vector::subtraction( M2_size, M2_box.hi(), M2_box.lo() );
              }
           private:

             T_box M2_box;

           public:
             T_coord const& F_size()const{ return M2_size; }
           protected:
             T_box      & F1_box(){ return M2_box; }
           private:
             T_coord M2_size;

           public:
             virtual T_size const& Fv_id( T_state const&P_state )const
              {
               return M2_ID; 
              }
             T_size const& F_id()const
              {
               return M2_ID; 
              }
           private:
             T_size M2_ID;
           private:
             static T_size M2s_counter;
          };

        }
      }
    }
  }

#endif
