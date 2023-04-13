#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "iterator/MapIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
#include "pair.hpp"
#include "tools.hpp"
#include "RedBlackTree.hpp"

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
       
            //typedef typename Allocator::const_pointer                       const_pointer;
            //typedef typename ft::map_iterator<const_pointer>                const_iterator;
            //typedef std::reverse_iterator<iterator>                         reverse_iterator;
            //typedef std::reverse_iterator<const_iterator>                   const_reverse_iterator;
            private :
                size_type           _size;
                Allocator           _alloc;      
                key_compare         _comp;
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
           
            typedef    RBT<value_type,value_compare,Allocator>    rbt;
            typedef typename ft::map_iterator<value_type,value_compare>            iterator;
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc){}

            template <class InputIterator>
            map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc)
            {
                while(first != last)
                {
                    key_type _key = first->first;
                    mapped_type _value = first->second;
                    _tree.insert(_key, _value);
                    first++;
                }
            }
           
            size_type size() const
            {
                return _size;
            }
            iterator begin()
            {
                 return iterator(_tree._root);
             }
            private :
                rbt      _tree;
    };
}

#endif
