#ifndef _DDMRM_IceRay_render_ray_classic2_stack_data_hpp_
 #define _DDMRM_IceRay_render_ray_classic2_stack_data_hpp_

 #include "../../../../type/basic/size.hpp"
 #include "../../../../type/basic/integer.hpp"
 #include "../../../../geometry/_type/state.hpp"
 #include "../../../../type/ray/state.hpp"

 #include "./item.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {
         namespace S_classic2
          {
           namespace S_stack
            {

             class GC_data
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_int8   T_uint8;

                 typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_state           T_ray;
                 typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC_item T_item;

                 typedef std::vector<T_item>      T_stack;

                 GC_data()
                  {
                   M2_capacity = 0;
                   M2_end = 0;
                  }

               public:
                 T_size const& F_size()const
                  {
                   return M2_end;
                  }
               private:
                 T_size  M2_end;

               public:
                 T_size  const& F_capacity()const
                  {
                   return M2_capacity;
                  }
                 void           F_reserve( T_size  const&  P_capacity )
                  {
                   M2_capacity = P_capacity;
                   M2_container.resize( M2_capacity );
                  }

               private:
                 T_size  M2_capacity=0;

               public:
                 void          F_clear()
                  { 
                   this->M2_end=0;
                  }

                 T_item &      F_push( T_item const& P_item = T_item() )
                  {
                   if( this->M2_container.size() < this->M2_end )
                    {
                     this->M2_end = this->M2_end;
                    }
                   ++this->M2_end;
                   F_top() = P_item;
                   return F_top(); 
                  }
                 void          F_pop()
                  { 
                   if( 0 == this->M2_end ) return;
                   F_top() = T_item();
                   --this->M2_end;
                  }

                 T_item const& F_top()const
                  {
                   return this->M2_container[this->M2_end-1] ;
                  }
                 T_item      & F_top()
                  {
                   if( this->M2_container.size() < this->M2_end )
                    {
                     this->M2_end = this->M2_end;
                    }
                   return this->M2_container[this->M2_end-1] ;
                  }

                 T_item const& F_at( T_size const& P_index )const{ return this->M2_container[ P_index ]; }
                 T_item      & F_at( T_size const& P_index )     { return this->M2_container[ P_index ]; }

               private:
                 T_stack      & F2_container()      { return M2_container; }
                 T_stack const& F2_container()const { return M2_container; }
               private:
                 T_stack M2_container;
              };
            }
          }
        }
      }
    }
  }

#endif
