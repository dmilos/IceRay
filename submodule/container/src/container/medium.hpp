#ifndef _MEDIUM_H_
 #define _MEDIUM_H_

// GS_DDMRM::S_container::GC_medium< N_data, N_allocator=std::allocator<N_data> >

 #include <vector>
 #include <memory>

 namespace GS_DDMRM
  {
   namespace S_container
    {

      template< typename N_data, typename N_allocator=std::allocator<N_data> >
       class GC_medium
        {
         public:
           typedef N_data T_data;
           typedef typename std::allocator<T_data>::size_type   T_size;
           typedef std::allocator<T_data>              T_allocator;


         public:
           enum Ee_COMMAND
            {
             En_cNOTHING, En_cPOP, En_cPUSH
            };

         public:
           GC_medium( T_size P_data = 1, T_size P_stack = 1 );
          ~GC_medium( );


         public:
          int     F_push( T_size const& P_index, T_data const& P_data );
          void    F_pop(  );

          T_data      & F_prev_info( void );
          T_data const& F_prev_info( void )const;

          T_size  F_prev_index( );

          T_data      & F_top_info( void );
          T_data const& F_top_info( void )const;
          T_size  F_top_index( void );

          int     F_in( T_size i )const;

          bool    F_empty( )const;

          void    F_view( );
          void    F_reset( );


          void    F_capacity_stack( T_size );
          void    F_capacity_list( T_size );

          void    F_print(  );

         private:
          //T_size s_stack;    C_stack  *stack;

          struct C_list;
          struct C_stack;
          typedef std::vector<C_stack, T_allocator> T1_stack_container;
          typedef std::vector<C_list, T_allocator>  T1_list_container;


          struct C_list
            {
             C_list(){ flag = false; }
             C_list( C_list const& P_original )
              :flag  ( P_original.flag )
              ,M_data( P_original.M_data )
              ,prev( P_original.prev)
              ,next( P_original.next)
              {  }

             bool flag;
             T_data M_data;
             T_size prev, next;
            };

          struct C_stack
           {  // sve ono sto je pokvario prev, next, flag data
            C_stack(){}
            C_stack
             (
              T_size P_who,
              C_list const& P_mem,
              T_size P_tail
             )
             :mem(P_mem)
             ,who(P_who)
             ,M_tail( P_tail )
              {
              }

            C_list    mem; // actualy what
            T_size  who, M_tail;
           };


          T1_stack_container      M1_stack;
          T1_list_container       M1_list;

          T_size                  M1_lhead, M1_ltail;  //head n' tail of the list;

        };

      template< typename N_data, typename N_allocator >
       GC_medium<N_data,N_allocator>::GC_medium( T_size P_data, T_size P_stack)
        {
         if( P_data == 0 )  return;

         M1_stack.reserve( P_stack );
         M1_list.resize( P_data );
        }

      template< typename N_data, typename N_allocator >
      GC_medium<N_data,N_allocator>::~GC_medium( )
        {
        }

      template< typename N_data, typename N_allocator >
       int GC_medium<N_data,N_allocator>::F_push( T_size const& P_id, T_data const& P_data )
        {
         if( M1_list.size() <= P_id )
          {
           M1_list.resize( P_id + 1 );
          }

         auto p_i = this->M1_list.begin() + P_id;

         if( true == M1_stack.empty() )
          {
           // sad je P_id glava
           M1_ltail = P_id;
           M1_lhead = P_id;

           // pamti
           M1_stack.push_back( C_stack( P_id, *p_i, M1_ltail ) );

           //popuni
           p_i->next = P_id;
           p_i->prev = P_id;
           p_i->flag = true;
           p_i->M_data = P_data;

           return true;
          }

         if( true == p_i->flag )
          { /* izbacivanje */
             /*ide na stek */
              M1_stack.push_back( C_stack( P_id, *p_i, M1_ltail ) );

              // primopredaja duznosti
              if( M1_ltail == P_id )
                M1_ltail= M1_list[ M1_ltail ].next;


             /* da prebodem */
              M1_list[ p_i->prev ].next = p_i->next;
              M1_list[ p_i->next ].prev = p_i->prev;
             /* dokusurivanje */
              p_i -> flag = false;

             M1_lhead = M1_list[ M1_ltail ].prev;
          }
         else
          { /* Ubacivanje */
             /* inicijalizacija */
              p_i->prev   = M1_lhead;
              p_i->next   = M1_ltail;
              p_i->M_data = P_data;

              M1_list[ M1_lhead ].next = P_id;
              M1_list[ M1_ltail ].prev = P_id;

             /* na stek */
              M1_stack.push_back( C_stack( P_id, *p_i, M1_ltail ) );

             /* da zalijemo */
             p_i->flag = true;
             M1_lhead = P_id;
          }

          return true;
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_pop(  )
        {
         T_size who;

         if( true == M1_stack.empty() ) return;

         who    = M1_stack.back().who;

         if(  M1_stack.back().mem.flag )
          {   /* vracanje */
           M1_list[ who ]           = M1_stack.back().mem;
           M1_list[ M1_list[ who ].next].prev = who;
           M1_list[ M1_list[ who ].prev].next = who;
          }
         else
          {
           /* izbacivanje da ga vise nema */
           M1_list[ who ]. flag = false;

           M1_list[ M1_list[ who ].next ].prev = M1_list[ who ].prev;
           M1_list[ M1_list[ who ].prev].next = M1_list[ who ].next;

          }

          M1_ltail = M1_stack.back().M_tail;
          M1_lhead = M1_list[ M1_ltail ].prev;


          M1_stack.pop_back();

        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_data& GC_medium<N_data,N_allocator>::F_prev_info( void )
        {
         return M1_list[M1_list[ M1_lhead ].prev].M_data;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_data const& GC_medium<N_data,N_allocator>::F_prev_info( void )const
        {
         return M1_list[M1_list[ M1_lhead ].prev].M_data;
        }


      template< typename N_data, typename N_allocator >
      typename GC_medium<N_data,N_allocator>::T_data& GC_medium<N_data,N_allocator>::F_top_info()
        {
         return M1_list[ M1_lhead ].M_data;
        }

      template< typename N_data, typename N_allocator >
      typename GC_medium<N_data,N_allocator>::T_data const& GC_medium<N_data,N_allocator>::F_top_info( )const
        {
         return M1_list[ M1_lhead ].M_data;
        }

      template< typename N_data, typename N_allocator >
      typename GC_medium<N_data,N_allocator>::T_size GC_medium<N_data,N_allocator>::F_prev_index()
        {
         return M1_list[ M1_lhead ].prev;
        }

      template< typename N_data, typename N_allocator >
       typename GC_medium<N_data,N_allocator>::T_size GC_medium<N_data,N_allocator>::F_top_index()
        {
         return M1_lhead;
        }

      template< typename N_data, typename N_allocator >
       int   GC_medium<N_data,N_allocator>::F_in( T_size P_id )const
        {
         return M1_list[ P_id ].flag;
        }

      template< typename N_data, typename N_allocator >
       bool GC_medium<N_data,N_allocator>::F_empty( )const
        {
         return M1_stack.empty();
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_view(  )
        {
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_reset(  )
        {
         M1_stack.clear();
         fill( M1_list.begin(), M1_list.end(), C_list() );
        }

      template< typename N_data, typename N_allocator >
       void GC_medium<N_data,N_allocator>::F_print( )
        {
         T_size ll = M1_ltail;
         int c=0;

         do{

            // printf( " %2i",ll );

            ll = M1_list[ ll ].next;

             c++;//if( 20 < c ) break;
           } while( ll != M1_ltail );

        }

       /*
       void medium_main(void)
        {
         int i , a;

         GC_medium med(10,10);

         for( i=1;i < 60;i++ )
          {
           a = rand()%6+1;

           if( 30 < i ) { a=0;}

           if( a != 0 )
            med.F_push( a, 1.6f );
           else
            med.F_pop(  );


           printf( " %2i",a );
           med.F_print(  );

           cout <<'\n';
          }

         getch();
        }
       */

    }
  }

#endif
