#ifndef _DDMM_IceRAY_geometry_rtss_uniform_H_
 #define _DDMM_IceRAY_geometry_rtss_uniform_H_
// GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform

#include <vector>

#include "./_pure.hpp"

#include "../flat/box.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_geometry
     {
      namespace S_RTSS
       {

        class GC_uniform
         : public GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D     T_size3D, T_position;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int3D      T_cell3D;
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;

          public:
             GC_uniform();
             GC_uniform( T_size3D const& P_dimension );
            ~GC_uniform( );

          public:
            void    Fv_reset( T_state &P_state )const;
            T_size  Fv_weight( )const;
             T_size const& Fv_id( T_state const&P_state )const;

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
            T_size    const& Fv_quantity( )const;
          private:
            mutable T_size       M2_cdwewewews;
          public:
            T__base*         Fv_base( T_size const& P_index )const;
            bool             Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const;

          public:
            bool F_cell( T_coord const & P_position, T_size3D & P_cell )const;
          public:
            T_size3D const& F_dimension()const;
            bool          F_dimension( T_size3D const& P_dimension );
            T_size3D  M2_dimension;
            T_coord M2_cubic;

          private:
            typedef std::vector< T_list >    T2_row;
            typedef std::vector< T2_row >    T2_area;
            typedef std::vector< T2_area >   T2_volume;

            T2_volume M2_volume;
          private:
            struct C2_geometry
             {
                      T__base        *M__base;
                      T_intersect    *M_intersect;
                      T_size          M_intersectSize;
              mutable std::uint16_t   M_check;
             };

            typedef  std::vector<C2_geometry> T2_collection;

         // public:
         //   T_collection    const& F_container()const{ return M2_collection; }
         //   void                  F_container( T_collection const& P_container ){ M2_collection = P_container; }
         // protected:
         //   T_collection        & F1_container(){ return M2_collection; }
          private:
            T2_collection M2_collection;
          private:
            T_size M2_compartment;

          private:
            mutable std::uint16_t M2_false;
            mutable std::uint16_t M2_true;
          private:
            struct C_intersect;
         };

      }
    }
  }
}

#endif
