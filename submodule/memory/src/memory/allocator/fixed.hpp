#ifndef Dh_DDMRM_system_allocator_fixed_manager_hpp_
 #define Dh_DDMRM_system_allocator_fixed_manager_hpp_

#include <cstdint>
#include <vector>


 namespace GS_DDMRM
  {
   namespace S_system
    {
     namespace S_allocator
      {

       namespace S_chunk
        {
         class GC_managed;
        }

       namespace S_fixed
        {

         class GC_manager
          {
           public:
            typedef std::size_t    T_size;
            typedef std::uint32_t  T_index;

            typedef GS_DDMRM::S_system::S_allocator::S_chunk::GC_managed T_data, T_chunk;
            typedef void  T_void;
            typedef T_void* T_ptr;

            explicit GC_manager( T_size const& P_weight = 0 );
                    ~GC_manager();

           public:
             void F_reserve( T_size const & P_data );
             bool F_share( T_chunk & P_data, T_chunk const& P_model ); //!< Increase Instance counter
             bool F_new( T_chunk & P_data );                           //!< Make truly new instance
             bool F_new( T_chunk & P_data, T_chunk const& P_model );   //!< Make truly new instance
             bool F_release( T_chunk & P_data );
             bool F_check( T_chunk const& P_data )const;
             bool F_clear();

            public:
              T_size    const& F_weight()const{ return M2_weight; }
              bool             F_weight( T_size const& P_weight );
            protected:
              T_size        & F1_weight(){ return M2_weight; }
            private:
              T_size M2_weight;

            public:
             T_size    const& F_gross()const{ return M2_gross; }
            private:
              T_size M2_gross;

            private:
              typedef std::uint8_t T2_uint8;
              typedef std::vector< T2_uint8 >  T2_container;
              T2_container M2_container;

            public:
              T_ptr  F_head(   T_chunk const& P_data )const;

            public:
              T_size F_acquired()const
               {
                return M2_acquired;
               }
              T_size F_available()const{ return M2_available; }
            private:
              typedef std::vector< T_size >  T2_available;
              T2_available M2_vacant;
              T_size M2_acquired, M2_available, M2_top;
              static T_index Fs_invalid(){ return T_size(-1); }
            private:
              struct C2_hat;
              typedef C2_hat T2_hat;
            private:
              T_size F2_gross()const;
            private:
              T2_hat      &  F2_hat(    T_chunk const& P_data )const;
              T2_hat      &  F2_hat(    T_chunk      & P_data )const;
              T_size         F2_offset( T_chunk const& P_data )const;
          };

        }
      }
    }
  }

#endif
