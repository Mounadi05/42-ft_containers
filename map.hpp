#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "iterator/TreeIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
#include "tools.hpp"
#include "RBT/RedBlackTree.hpp"

namespace ft {

    template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map 
    {
        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef ft::pair<const Key, T>                                  value_type;
            typedef Compare                                                 key_compare;
            typedef Allocator                                               allocator_type;
            typedef size_t                                                  size_type;
            typedef ptrdiff_t                                               difference_type;
            typedef typename Allocator::reference                           reference;
            typedef typename Allocator::const_reference                     const_reference;
            typedef typename Allocator::pointer                             pointer;
       
            typedef typename Allocator::const_pointer                       const_pointer;
              private :
                size_type           _size;
                key_compare         _comp;
                Allocator           _alloc;     
            public :
            class value_compare: public ft::binary_function<value_type,value_type,bool> 
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}
                public:
                    bool operator()(const value_type& x, const value_type& y) const 
                    {
                        return comp(x.first, y.first);
                    }
            };
           
            typedef    ft::RBT<value_type,key_compare,Allocator>   rbt;
            typedef typename ft::RBT<value_type,key_compare,Allocator>::iterator           iterator;
            typedef typename ft::RBT<value_type,key_compare,Allocator>::const_iterator                  const_iterator;
            
            iterator insert (iterator position, const value_type& val)
            {
                _tree.insert(val);
                return position;
            }
            private :
                rbt _tree;
        
    };
}

#endif
