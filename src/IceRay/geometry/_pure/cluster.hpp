#ifndef _DDMRM_Iceray_geometry__pure_cluster_hpp_
 #define _DDMRM_Iceray_geometry__pure_cluster_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster

#include <vector>

#include "./_base.hpp"

#include "IceRay/type/basic/scalar.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_cluster
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar      T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size        T_size;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base     T__base;


           //public:
           //  virtual T_size  Fv_balast( )const=0;

           public:
             typedef std::vector<T__base*> T_container;

             typedef struct C_fragment
              {
               explicit C_fragment( T_size const& P_depth = 0 )
                :M_depth(P_depth)
                {
                }

               T_size       M_index = Fs_invalid(); //!< index in enclosed object. Not ID.
               T_size       M_depth = 0;
               T__base *    M__base = nullptr;
               T_state      M_state; //!< Use nullptr for manager
              }T_fragment;

           public:
                      GC_cluster(){}
             virtual ~GC_cluster(){}

           public:
             // Total number of direct physical fragments
             virtual T_size const&      Fv_quantity()const=0;

             // First direct physical base
             virtual T__base*           Fv_base( T_size const& P_index )const=0;
           //virtual T_container const& Fv_container()const=0;

             // First direct state.
             virtual bool               Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const=0;

             ////  pack state of fragment in something usable
             // P_big must be allocated. This f-ion will use memcpy
             //virtual void        Fv_pack( T_state const& P_small, T_state & P_big )const
             // {
             //
             // }

           public:
             T_size const&  Fv_id( T_state const&P_state )
              {   // goes to the bottom!
               T_fragment I_fragment;

               if( false == this->Fv_fragment( I_fragment, P_state ) )
                {
                 return F_id();
                }

               return I_fragment.M__base->Fv_id( I_fragment.M_state );
              }
           public:
             static T_size const& Fs_invalid(){ static T_size Is_invalid( 0xA1b2c3d4 ); return Is_invalid; }

          };

        }
      }
    }
  }

#endif
