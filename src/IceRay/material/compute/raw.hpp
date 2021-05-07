#ifndef _DDMRM_IceRay_material_compute_data_raw_HPP_
 #define _DDMRM_IceRay_material_compute_data_raw_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__pure
// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fake
// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<type>
// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed<type,size>
// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_flex<type>
// GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic<type>

 #include "../../type/basic/size.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_data
          {

           class GC__pure
            {
             public:
               typedef std::size_t T_size;

               virtual T_size const&  Fv_size()const=0;
               virtual bool           Fv_size( T_size const& P_size )=0;
               virtual void           Fv_reset()=0;
            };

           class GC_fake
            : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__pure
            {
             public:
               typedef std::size_t T_size;

               T_size const&  Fv_size()const{ return M2_size; }
               bool           Fv_size( T_size const& P_size ){ M2_size = P_size; return true; }
               void           Fv_reset(){ ; }
             private:
               T_size M2_size = 0;
            };

           template < typename N_type>
            class GC__base
             : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__pure
             {
              public:
                typedef N_type T_type;

                typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

                virtual void           Fv_store( T_size const& P_index,  T_type const& P_value )=0;
                virtual T_type const&  Fv_load(  T_size const& P_index )const=0;

               virtual T_size const&  Fv_size()const=0;
               virtual bool           Fv_size( T_size const& P_size )=0;
             };

           template < typename N_type, unsigned N_size >
            class GC_fixed
             : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<N_type>
             {
              public:
                typedef N_type T_type;

                typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

              public:
                GC_fixed()
                 {
                  Fv_reset();
                 }

              public:
                void            Fv_store( T_size const& P_index,  T_type const& P_value )
                 {
                  M2_data[P_index] = P_value;
                 }

                T_type const&   Fv_load( T_size const& P_index )const{ return M2_data[P_index]; }
                T_size const&   Fv_size()const{ static T_size Ir_size = N_size; return Ir_size; }
                bool            Fv_size( T_size const& P_size ){ return false; }

                void           Fv_reset(){ M2_data.fill( N_type() ); }

              private:
                std::array< N_type, N_size > M2_data;
             };

           template < typename N_type >
            class GC_flex
             : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<N_type>
             {
              public:
                typedef N_type T_type;

                typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

                void            Fv_store( T_size const& P_index,  T_type const& P_value )     { M2_data[P_index] = P_value; }
                T_type const&   Fv_load( T_size const& P_index )const{ return M2_data[P_index]; }

                T_size const&  Fv_size()const{ static T_size Ir_size = M2_data.size(); return Ir_size; }
                bool           Fv_size( T_size const& P_size ){ M2_data.resize( P_size ); return true; }
                void           Fv_reset(){ this->M2_data.fill( N_type() ); }

              private:
                std::vector< N_type > M2_data;
             };

           template < typename N_type >
            class GC_dynamic
             : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<N_type>
             {
              public:
                typedef N_type T_type;

                typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

                GC_dynamic( T_size const& P_size = 0 )
                 {
                  this->M2_data.resize( P_size );
                 }

                void            Fv_store( T_size const& P_index,  T_type const& P_value )
                 {
                  if( Fv_size() <= P_index  )
                   {
                    this->Fv_size( P_index +1 );
                   }
                  this->M2_data[P_index] = P_value;
                 }
                T_type const&   Fv_load( T_size const& P_index )const{ return this->M2_data[P_index]; }

                T_size const&  Fv_size()const{ static T_size Ir_size = this->M2_data.size(); return Ir_size; }
                bool           Fv_size( T_size const& P_size ){ this->M2_data.resize( P_size ); return true; }
                void           Fv_reset(){ std::fill(this-> M2_data.begin(), this->M2_data.end(), N_type() ); }

              private:
                std::vector< N_type > M2_data;
             };

           template < >
            class GC_dynamic<GS_DDMRM::S_IceRay::S_light::S_type::GC_spot>
             : public GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<GS_DDMRM::S_IceRay::S_light::S_type::GC_spot >
             , public GS_DDMRM::S_IceRay::S_light::S_type::GC_swarm
             {
              public:
                typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot  T_spot, T_type;
                typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_swarm T_swarm;

                typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

                GC_dynamic( T_size const& P_reserve )
                 {
                  this->F_reserve( P_reserve );
                 }

                void            Fv_store( T_size const& P_index,  T_type const& P_value )
                 {
                  if( Fv_size() <= P_index  )
                   {
                    this->Fv_size( P_index + 5 );
                   }
                  (*this)[P_index] = P_value;
                 }

                T_type const&   Fv_load( T_size const& P_index )const{ return (*this)[P_index]; }

                T_size const&  Fv_size()const{ static T_size Ir_size = (*this).F_size(); return Ir_size; }
                bool           Fv_size( T_size const& P_size ){ (*this).F_size( P_size ); return true; }
                void           Fv_reset(){ auto I_size = (*this).F_size();  (*this).F_size( 0 ); (*this).F_size( I_size ); }
             };


          }
        }
      }
    }
  }


#endif
