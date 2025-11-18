#ifndef Dh_DDMRM_system_allocator_chunk_managed_hpp_
 #define Dh_DDMRM_system_allocator_chunk_managed_hpp_

// GS_DDMRM::S_system::S_allocator::S_chunk::GC_managed
// GS_DDMRM::S_system::S_allocator::S_chunk::to_string

#include <string>

#include "./simple.hpp"

#include "../fixed.hpp"

 namespace GS_DDMRM
  {
   namespace S_system
    {
     namespace S_allocator
      {
       namespace S_chunk
        {

         /*! \brief A piece of memory
             \note Will behaive like solid pointer.
         */
         class GC_managed
          : public GS_DDMRM::S_system::S_allocator::S_chunk::GC_simple
          {
           public:

             typedef void     T_void;
             typedef T_void * T_ptr;
             typedef GS_DDMRM::S_system::S_allocator::S_chunk::GC_simple   T_simple;
             typedef GS_DDMRM::S_system::S_allocator::S_fixed::GC_manager  T_allocator;

             explicit GC_managed( T_allocator *P_allocator = nullptr, T_ptr P_ptr = nullptr );

             GC_managed( GC_managed const& P_that );

            ~GC_managed();

             GC_managed &operator=( GC_managed const& P_other );

             using T_simple::F_ptr;

           public:
             void F_release( );
           public:
             T_allocator *F_allocator()const{ return M2_allocator; }
             T_allocator *F_allocator(){ return M2_allocator; }
             bool         F_allocator(T_allocator * P_allocator ){ M2_allocator = P_allocator; return true; }

           private:
             mutable T_allocator *M2_allocator;
          };

        }
      }
    }
  }

#endif
