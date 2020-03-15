#ifndef _DDMM_IceRAY_geometry_rtss_list_H_
 #define _DDMM_IceRAY_geometry_rtss_list_H_
// GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list

#include <vector>

#include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_RTSS
        {

         class GC_list
          : public GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;

           public:
              GC_list( );
             ~GC_list( );

           public:
             void    Fv_reset( T_state &P_state )const;
             T_size  Fv_weight( )const;

           public:
             bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const;

           public:
             T_size Fv_push( T__base * P_object );
             void   Fv_erase( T__base  * P_object );
             void   Fv_clear();
             void   Fv_optimize();

             T_list      const& Fv_owners( T_coord const& P_point )const;
             void               Fv_prepare( T_coord const& P_point, T_state & P_state )const;

           public:
             T_size  const&  Fv_quantity( )const;
           private:
             mutable T_size  M2_size;
           public:
             T__base*        Fv_base( T_size const& P_index )const;
             bool            Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;
             T_size const&   Fv_id( T_state const&P_state )const;
           private:

             struct C2_geometry
              {
               T__base      *M__base;
               T_intersect  *M_intersect;
               T_size        M_intersectSize;
              };

             typedef  std::vector<C2_geometry> T2_collection;

          // public:
          //   T_collection    const& F_container()const{ return M2_collection; }
          //   void                  F_container( T_collection const& P_container ){ M2_collection = P_container; }
          // protected:
          //   T_collection        & F1_container(){ return M2_collection; }
           private:
             T2_collection M2_collection;
             T_list        M2_index;
           private:
             T_size M2_compartment;

           private:
             struct C_intersect;
         };

       }
     }
   }
 }
#endif
