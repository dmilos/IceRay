#ifndef Dh_DDMRM_system_allocator_chunk_simple_hpp_
 #define Dh_DDMRM_system_allocator_chunk_simple_hpp_
// GS_DDMRM::S_IceRay::S_geometry::S_state::GC_data

 namespace GS_DDMRM
  {
   namespace S_system
    {
     namespace S_allocator
      {
       namespace S_chunk
        {

         /*! \brief Dumb piece of memory.
            \note can not clone
            \note can not dealocate
         */
         class GC_simple
          {
           public:

            typedef void     T_void;
            typedef T_void * T_ptr;

            explicit GC_simple( T_ptr const & P_buffer = nullptr )
             : M2_buffer( P_buffer )
             {}

            ~GC_simple()
             {
             }

             T_ptr const& F_ptr( )const
              {
               return M2_buffer;
              }

             T_ptr const& F_ptr( )
              {
               return M2_buffer;
              }

             void F_ptr( T_ptr P_ptr )
              {
               M2_buffer = P_ptr;
              }

           private:
             T_ptr M2_buffer;
          };

        }
      }
    }
  }

#endif
