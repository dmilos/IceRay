#ifndef Dh_DDMRM_Iceray_geometry_state_data_hpp_
 #define Dh_DDMRM_Iceray_geometry_state_data_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state

#include <cstddef>
#include <cstdint>

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/integer.hpp"
#include "memory/allocator/chunk/managed.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__type
        {

         class GC_state
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size  T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_uint8 T_uint8;

             typedef GS_DDMRM::S_system::S_allocator::S_chunk::GC_managed T_managed;
             typedef T_managed::T_ptr       T_ptr;
             typedef T_managed::T_allocator T_allocator;

           public:
             explicit GC_state()
              : M2_managed( nullptr, nullptr )
              {
              }

             GC_state( T_ptr const& P_ptr )
              : M2_managed( nullptr, P_ptr )
              {
              }

             explicit GC_state( T_managed const& P_managed )
              : M2_managed( P_managed )
              {
              }

             GC_state( GC_state const& P_that )
              {
               *this = P_that;
              }
             ~GC_state()
               {
                F_clear();
               }

           public:
             GC_state & operator =( GC_state const& P_that )
              {
               this->M2_managed = P_that.M2_managed;
               return *this;
              }

          public:
            void F_clear()
             {
              this->M2_managed.F_release();
             }
          public:
            T_ptr F_ptr()
              {
               return this->M2_managed.F_ptr();
              }

             T_ptr F_ptr()const
              {
               return this->M2_managed.F_ptr();
              }

           public:
             void F_root()
              {
               if( nullptr == this->M2_managed.F_ptr() ) return;
               if( nullptr == this->M2_managed.F_allocator() ) return;
               this->M2_managed.F_ptr( this->M2_managed.F_allocator()-> F_head( M2_managed ) );
              }

           public:
             template< typename N_content >
              N_content & F_content()
               {
                return *reinterpret_cast<N_content*>( this->M2_managed.F_ptr() );
               }

             template< typename N_content >
              N_content const& F_content()const
               {
                return *reinterpret_cast<N_content const*>( this->M2_managed.F_ptr() );
               }

             template< typename N_content, typename N_appendix >
              N_appendix & F_appendix()
               {
                return * reinterpret_cast<N_appendix*>( reinterpret_cast<N_content*>( this->M2_managed.F_ptr() ) + 1 );
               }

             template< typename N_content, typename N_appendix >
              N_appendix const& F_appendix()const
               {
                return * reinterpret_cast<N_appendix const*>( reinterpret_cast<N_content const*>( this->M2_managed.F_ptr() ) + 1 );
               }

             template< typename N_content >
              bool F_tail( GC_state & P_tail )const
               {
                return this->F_tail( P_tail, sizeof( N_content ) );
               }

             template< typename N_content >
              bool F_tail( GC_state & P_tail )
               {
                return this->F_tail( P_tail, sizeof( N_content ) );
               }

             bool F_tail( GC_state & P_tail, T_size const& P_size )
              {
               if( nullptr == this->M2_managed.F_allocator() )
                {
                 P_tail.M2_managed.F_allocator( nullptr );
                 P_tail.M2_managed.F_ptr( (void*) ( reinterpret_cast<T_uint8*>(  this->M2_managed.F_ptr() ) + P_size ) );
                 return true;
                }

               if( false == this->M2_managed.F_allocator()->F_share( P_tail.M2_managed, this->M2_managed ) )
                {
                 return false;
                }
               P_tail.M2_managed.F_ptr( (void*) ( (T_uint8*)P_tail.M2_managed.F_ptr() + P_size ) );
               return true;
              }

             bool F_tail( GC_state & P_tail, T_size const& P_size )const
              {
               if( nullptr == this->M2_managed.F_allocator() )
                {
                 P_tail.M2_managed.F_allocator( nullptr );
                 P_tail.M2_managed.F_ptr( (void*) ( reinterpret_cast<T_uint8*>( this->F_ptr() ) + P_size ) );
                 return true;
                }

               if( false == this->M2_managed.F_allocator()->F_share( P_tail.M2_managed, this->M2_managed ) )
                {
                 return false;
                }
               P_tail.M2_managed.F_ptr( (void*) ( (T_uint8*)P_tail.F_ptr() + P_size ) );
               return true;
              }

           public:
             T_managed const& F_chunk()const
              {
               return M2_managed;
              }
             T_managed & F_chunk()
              {
               return M2_managed;
              }
           public:
             T_managed M2_managed;
          };

        }
      }
    }
  }

#endif
