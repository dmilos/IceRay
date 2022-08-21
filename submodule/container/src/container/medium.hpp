#ifndef _MEDIUM_H_
 #define _MEDIUM_H_

// GS_DDMRM::S_container::GC_medium< N_data, N_allocator=std::allocator<N_data> >

 #include <vector>
 #include <memory>
 #include <iostream>
 #include <iomanip>

 namespace GS_DDMRM
  {
   namespace S_container
    {

     /*
        1. different brackets of
        2. second insert means close
        3. allow overlap    ( { ) }
        4. simple undo
    */

      template< typename N_data, typename N_allocator=std::allocator<N_data> >
       class GC_medium
        {
         public:
           typedef N_data T_data;
           typedef typename std::allocator<T_data>::size_type   T_size;
           typedef std::allocator<T_data>              T_allocator;

           enum  Ee_state { En_unused = -1, En_open = 0, En_close = 1 };

         public:
           GC_medium( T_size P_data = 1, T_size P_stack = 1 );
          ~GC_medium( );

         public:
           void    F_clear( );
           int     F_push( T_size const& P_index, T_data const& P_data );
           void    F_pop(  );

           T_size const & F_previous( T_size const& P_index )const;
           T_data const&  F_data( T_size const& P_index )const;
           T_data&        F_data( T_size const& P_index );
           T_size const&  F_head( void )const;

           Ee_state const&   F_in( T_size const& P_index )const;

           bool    F_empty( )const;

           void    F_capacity_stack( T_size const& );
           void    F_capacity_list( T_size const& );

           void    F_print(  );

         private:
           static T_size const& Fs_infinity(){ static T_size Irs_infinity = -1; return Irs_infinity; }
           static T_size const& Fs_abyss()   { static T_size Irs_abyss    = 0xeeeeeeee; return Irs_abyss;    }
           static T_size const& Fs_invalid() { static T_size Irs_invalid  = 0x666999; return Irs_invalid;  }
           //T_size const& F_alpha() { static T_size Irs_invalid  = 0x666999; return Irs_invalid;  }
           //T_size const& F_omega() { static T_size Irs_invalid  = 0x666999; return Irs_invalid;  }

         private:
           struct C_list
             {
              Ee_state M_state = En_unused;
              T_data M_data;
              T_size prev = Fs_invalid();
              T_size next = Fs_invalid();
             };
           typedef std::vector<C_list, T_allocator>  T2_list;

           struct C_record
            {
             C_list entry;
             T_size M_index;
             T_size M_tail, M_head;
             T_size prev_next = Fs_invalid();
             T_size next_prev = Fs_invalid();
             T_size head_next = Fs_invalid();
            };
           typedef std::vector<C_record, T_allocator> T2_undo;

           T2_undo       M2_undo;  // undo stack
           T2_list       M1_list;   // actual
           T_size        M2_head, M1_tail;  //head n' tail of the list;
         };

      template< typename N_data, typename N_allocator >
       GC_medium<N_data,N_allocator>::GC_medium( T_size P_data, T_size P_stack )
        {
         if( P_data == 0 )  return;
         M1_tail = Fs_abyss();
         M2_head = Fs_infinity();
         M2_undo.reserve( P_stack );
         M1_list.resize( P_data );
        }

      template< typename N_data, typename N_allocator >
      GC_medium<N_data,N_allocator>::~GC_medium( )
        {
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_clear()
        {
         M1_tail = Fs_abyss();
         M2_head = Fs_infinity();
         M2_undo.clear();
         fill( M1_list.begin(), M1_list.end(), C_list() );
        }

      template< typename N_data, typename N_allocator >
       int GC_medium<N_data,N_allocator>::F_push( T_size const& P_id, T_data const& P_data )
        {
         if( M1_list.size() <= P_id )
          {
           M1_list.resize( P_id + 1 );
          }

         auto & entry = this->M1_list[ P_id ];
         M2_undo.emplace_back();
         auto & record  = M2_undo.back();
         record.entry = entry;
         record.M_index = P_id;
         record.M_tail = M1_tail;
         record.M_head = M2_head;

         switch( entry.M_state )
          {
           case( En_open ):
            {
             entry.M_state = En_close;
             entry.M_data = P_data;

             if( Fs_abyss()    !=  entry.prev )
              {
               record.prev_next = M1_list[ entry.prev ].next;
               M1_list[ entry.prev ].next = entry.next;
              }
             else
              {
               M1_tail = entry.next; if( Fs_infinity() == M1_tail ) M1_tail = Fs_abyss();
              }

             if( Fs_infinity() != entry.next )
              {
               record.next_prev = M1_list[ entry.next ].prev;
               M1_list[ entry.next ].prev = entry.prev;
              }
             else
              {
               M2_head = entry.prev; if( Fs_abyss() == M2_head ) M2_head = Fs_infinity();
              }
            } break;

           case( En_unused ):
           case( En_close ):
            {
             entry.M_state  = En_open;
             entry.next     = Fs_infinity();
             entry.M_data   = P_data;

             if( Fs_infinity() != M2_head )
              {
               record.head_next = M1_list[ M2_head ].next;
               M1_list[ M2_head ].next = P_id;
               entry.prev   = M2_head;
              }
             else
              {
               entry.prev   = Fs_abyss();
               M1_tail = P_id;
              }

             M2_head = P_id;
           } break;
          }
         return true;
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_pop()
        {
         if( true == M2_undo.empty() )
          {
           return;
          }
         auto const& record = M2_undo.back();
         auto const& entry = record.entry;
         auto const& I_index = record.M_index;
         M1_list[ I_index ] = entry;
         M1_tail = record.M_tail;
         M2_head = record.M_head;

         if( Fs_invalid() != record.prev_next) M1_list[ entry.prev ].next = record.prev_next;
         if( Fs_invalid() != record.next_prev) M1_list[ entry.next ].prev = record.next_prev;
         if( Fs_invalid() != record.head_next) M1_list[ M2_head    ].next = record.head_next;

         M2_undo.pop_back( );
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_size const& GC_medium<N_data,N_allocator>::F_previous( T_size const& P_index )const
        {
         return M1_list[ P_index ].prev;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_data const& GC_medium<N_data,N_allocator>::F_data( T_size const& P_index )const
        {
         return M1_list[ P_index ].M_data;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_data  & GC_medium<N_data,N_allocator>::F_data( T_size const& P_index )
        {
         return M1_list[ P_index ].M_data;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_size const& GC_medium<N_data,N_allocator>::F_head()const
        {
         return M2_head;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::Ee_state const&  GC_medium<N_data,N_allocator>::F_in( T_size const& P_id )const
        {
         static Ee_state Irs_state = En_unused;
         if( P_id < M1_list.size() ) 
          {
           return M1_list[ P_id ].M_state;
          }
         return Irs_state;
        }

      template< typename N_data, typename N_allocator >
       bool GC_medium<N_data,N_allocator>::F_empty( )const
        {
         return M2_undo.empty();
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_print( )
        {

         T_size ll = M1_tail;
         if( Fs_abyss() == ll )
          {
           std::cout << "{";
           std::cout << "};";
           std::cout << std::endl;
           return;
          }

         if( Fs_infinity() == ll )
          {
           std::cout << "{";
           std::cout << "};";
           std::cout << std::endl;
           return;
          }

        std::cout << "{";
         std::cout << std::endl;

         std::cout << "  Tail: " << M1_tail; std::cout << std::endl;
         std::cout << "  Head: " << M2_head; std::cout << std::endl;

         std::cout << "  List: ";
            std::cout << std::endl;
         std::cout << "    { ";

         int c=0;
         do
          {
           std::cout << std::endl;
           std::cout << "      " << "{ ";
           std::cout << "      " << "i: " << ll << "; ";
           std::cout << "      " << "s: " << M1_list[ ll ].M_state << "; ";

           std::cout << "      " << "p: ";
           if( Fs_abyss() == M1_list[ ll ].prev ) std::cout << "abyss"; else std::cout << std::setw(5) << M1_list[ ll ].prev ;
           std::cout << "; ";

           std::cout << "      " << "n: ";
           if( Fs_infinity() == M1_list[ ll ].next ) std::cout << "infinity"; else std::cout << std::setw(8) << M1_list[ ll ].next ;
           std::cout << "; ";

           std::cout << "      " << "d: " << M1_list[ ll ].M_data << "; ";
           std::cout << "      " << " }";

           ll = M1_list[ ll ].next;
           if( Fs_infinity() == ll )
            {
             break;
            }
           c++;//if( 20 < c ) break;
           } while( ll != M1_tail  );
          std::cout << std::endl;
         std::cout << "    } ";

        if( false )
          {
           std::cout << std::endl;
            std::cout << "  Stack: ";
            std::cout << std::endl;
           std::cout << "    { ";
            std::cout << std::endl;

           for( auto const& I_item : M2_undo )
            {
             std::cout << std::endl;
             std::cout << "      " << "{ ";
             //std::cout << "      " << "f: " << I_item.mem.M_state << "; ";

            std::cout << "      " << "p: ";
            //if( Fs_abyss() == I_item.mem.prev ) std::cout << "abyss"; else std::cout << std::setw(5) << I_item.mem.prev ;
            std::cout << "; ";

            std::cout << "      " << "n: ";
            //if( Fs_infinity() == I_item.mem.next ) std::cout << "infinity"; else std::cout << std::setw(8) << I_item.mem.next ;
            std::cout << "; ";
             //std::cout << "      " << "d: " << I_item.mem.M_data << "; ";
             std::cout << "      " << " }";
            }
            std::cout << std::endl;
           std::cout << "    } ";
          }
         std::cout << std::endl;
         std::cout << "}; ";
           std::cout << std::endl;
        }

    }
  }

#endif
