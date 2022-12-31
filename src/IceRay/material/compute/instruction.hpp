#ifndef Dh_DDMRM_Iceray_material_compute__pure_HPP_
 #define Dh_DDMRM_Iceray_material_compute__pure_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction

 #include "../../type/basic/size.hpp"
 #include "../../type/color.hpp"
 #include "../../type/ray/state.hpp"
 #include "../beam.hpp"

 #include "../../material/pigment/_pure.hpp"

 #include "./memory.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {

         class GC_instruction
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace        T_ray;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state    T_state;

             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  T_pigment;

             typedef GS_DDMRM::S_IceRay::S_material::GT_beam T_beam;

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory               T_memory;


             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::T_component T_component;

             typedef std::vector<T_size>      T_operand;
             typedef std::vector<T_operand>   T_signature;

           public:
                      GC_instruction():M2_memory(nullptr){}
             virtual ~GC_instruction(){}

           public:
             virtual bool     Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const=0;

           public:
             T_size   F_size( T_component const& P_component )const
              {
               T_size Ir_max = 0;
               if( P_component < (T_component)M2_input.size()  )
                {
                 for( auto const& I_index : M2_input[ static_cast<T_size>(P_component) ] )
                  {
                   Ir_max = std::max<T_size>( Ir_max, I_index );
                  }
                }
               if( P_component < (T_component)M2_output.size() )
                {
                 for( auto const& I_index : M2_output[ static_cast<T_size>(P_component) ] )
                  {
                   Ir_max = std::max<T_size>( Ir_max, I_index );
                  }
                }
               return Ir_max;
              }

           public:
             template < typename N_type >
              T_size const& F_input( T_size const& P_position )const
               {
                static const T_component I_component = (T_component) T_memory::C_type2component< N_type >::En_component;
                return F_input( I_component, P_position );
               }

             T_size const& F_input( T_component const& P_component, T_size const& P_position )const
              {
               return F_input()[static_cast<T_size>(P_component)][P_position];
              }

           public:
             template< typename N_type>
              void F_input( T_size const& P_position, T_size const& P_index )
               {
                static const T_component I_component = (T_component) T_memory::C_type2component< N_type >::En_component;
                F_input( I_component, P_position, P_index );
               }

             void F_input(  T_component const& P_component, T_size const& P_position, T_size const& P_index )
              {
               M2_input.resize( std::max<T_size>( M2_input.size(), static_cast<T_size>(P_component) + 1 ) );
               M2_input[static_cast<T_size>(P_component)].resize( std::max<T_size>( M2_input[static_cast<T_size>(P_component)].size(), P_position + 1 ) );
               M2_input[static_cast<T_size>(P_component)][P_position] = P_index;
               if( nullptr != F1_memory() )
                {
                 F1_memory()->F_size( P_component, std::max<T_size>( P_index, F1_memory()->F_size(P_component) ) );
                }
              }

           public:
             T_signature const& F_input()const
              {
               return M2_input;
              }
           protected:
             T_signature & F1_input()
              {
               return M2_input;
              }
           private:
             T_signature M2_input;

           public:
             template < typename N_type >
              T_size const& F_output( T_size const& P_position )const
               {
                static const T_component I_component = (T_component) T_memory::C_type2component< N_type >::En_component;
                return F_output( I_component, P_position );
               }

             T_size const& F_output(  T_component const& P_component, T_size const& P_position )const
              {
               return M2_output[static_cast<T_size>(P_component)][P_position];
              }

             template< typename N_type>
              void F_output( T_size const& P_position, T_size const& P_index )
               {
                static const T_component I_component = (T_component) T_memory::C_type2component< N_type>::En_component;
                F_output( I_component, P_position, P_index );
               }

             void F_output( T_component const& P_component, T_size const& P_position, T_size const& P_index )
              {
               M2_output.resize( std::max<T_size>( M2_output.size(), static_cast<T_size>(P_component) + 1 ) );
               M2_output[static_cast<T_size>(P_component)].resize( std::max<T_size>( M2_output[static_cast<T_size>(P_component)].size(), P_position + 1 ) );
               M2_output[static_cast<T_size>(P_component)][P_position] = P_index;
               if( nullptr != F1_memory() )
                {
                 F1_memory()->F_size( P_component, std::max<T_size>( P_index, F1_memory()->F_size(P_component) ) );
                }
              }

           public:
             T_signature const& F_output()const
              {
               return M2_output;
              }
           protected:
             T_signature & F1_output(){ return M2_output; }
           private:
             T_signature M2_output;

           public:
             virtual void    Fv_memory( T_memory * P_memory )
              {
               M2_memory = P_memory; 
              }
           protected:
             T_memory * & F1_memory()
              {
               return M2_memory; 
              }
           private:
             T_memory *M2_memory;
          };

        }
      }
    }
  }

#endif
