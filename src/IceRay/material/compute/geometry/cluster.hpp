 #ifndef Dh_DDMRM_Iceray_material_compute_cluster_HPP_
 #define Dh_DDMRM_Iceray_material_compute_cluster_HPP_

 #include <tuple>
 #include <limits>

 #include "../../../type/basic/size.hpp"
 #include "../../../geometry/_pure/cluster.hpp"
 #include "../instruction.hpp"
 #include "../../_pure.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_geometry
          {

           class GC_cluster
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D       T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base      T_geometry;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster    T_cluster;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               enum Ee_output{ En_outColor_Result=0 };

             public:
               GC_cluster()
                {
                 F_output<T_color>( En_outColor_Result, 0 );

                 F_geometry( nullptr );
                }

               explicit GC_cluster( T_geometry * P_geometry )
                {
                 F_output<T_color>( En_outColor_Result, 0 );
                 F_geometry( P_geometry );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_color I_result = ::color::constant::black_t{};
                 if( nullptr != M2_cluster )
                  {
                   T_cluster::C_fragment I_fragment;
                   if( true == M2_cluster->Fv_fragment( I_fragment, P_state ) )
                    {
                     if( nullptr != M2_marbles[ I_fragment.M_index ] )
                      {
                       M2_marbles[ I_fragment.M_index ]->Fv_color( I_result, P_next, P_intersect, I_fragment.M_state );
                      }
                    }

                   M2_memoryColor->Fv_store(  F_output()[ T_memory::En_color    ][ En_outColor_Result ], I_result );
                  }

                 return true;
                }


             public:  // property geometry  geometry
               T_geometry    const* F_geometry()const{ return M2_geometry; }
               void                 F_geometry( T_geometry * P_geometry )
                {
                 M2_geometry = P_geometry;
                 M2_cluster = dynamic_cast<T_cluster*>( M2_geometry );
                 M2_marbles.clear();
                 if( nullptr != M2_cluster )
                  {
                   M2_marbles.resize( M2_cluster->Fv_quantity() );
                   for( T_size I_index = 0 ; I_index < M2_cluster->Fv_quantity(); ++I_index )
                    {
                     M2_marbles[ I_index ] = dynamic_cast< T_pigment* >( M2_cluster->Fv_base( I_index ) );
                    }
                  }
                }
             private:
               T_geometry *M2_geometry;
               typedef  std::vector<T_pigment *> T2_marbles;
               T_cluster  *M2_cluster;  //!< dumb_ptr;
               T2_marbles M2_marbles;

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color >  T2_memoryColor;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                  F1_memory() = P_memory;
                  M2_memoryColor  = dynamic_cast<T2_memoryColor * >( P_memory->F_get<T_color>( ) );
                }

             private:
               T2_memoryColor   *M2_memoryColor;
           };

          }
        }
      }
    }
  }

#endif
