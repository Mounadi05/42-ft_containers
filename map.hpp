#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "iterator/MapIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
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
       
            typedef typename Allocator::const_pointer                       const_pointer;
             //typedef std::reverse_iterator<iterator>                         reverse_iterator;
            //typedef std::reverse_iterator<const_iterator>                   const_reverse_iterator;
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
           
            typedef    RBT<value_type,key_compare,Allocator>   rbt;
            typedef typename ft::map_iterator<value_type,key_compare,Allocator>            iterator;
            typedef typename ft::map_iterator<value_type,key_compare,Allocator>                 const_iterator;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc){}

            template <class InputIterator>
            map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc)
            {
                 insert (first,last);
            }
            template <class InputIterator>  
            void insert (InputIterator first, InputIterator last)
            {
                while(first != last)
                {
                    key_type _key = first->first;
                    mapped_type _value = first->second;
                    _tree.insert(_key, _value,_comp);
                    first++;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                key_type _key = val.first;
                mapped_type _value = val.second;
                iterator tmp=  _tree.insert(_key, _value,_comp);
                return tmp;

            }
            pair<iterator,bool> insert (const value_type& val)
            {       
                key_type _key = val.first;
                mapped_type _value = val.second;
                iterator tmp_it = _tree.search(_key);
                if (tmp_it != NULL)
                    return (ft::pair<iterator,bool>(tmp_it,false));
                tmp_it = _tree.insert(_key, _value,_comp);
                return pair<iterator,bool>(tmp_it,true);
            }
            
            
        //    mapped_type& operator[] (const key_type& k)
        //    {

        //    }
            mapped_type& at (const key_type& k)
            {
                typename rbt::Node *tmp = _tree.search(k);
                if (tmp == NULL)
                   throw std::out_of_range("map::at:  key not found");
                return tmp->data->second;
            }
            const mapped_type& at (const key_type& k) const
            {
                typename rbt::Node *tmp = _tree.search(k);
                if (tmp == NULL)
                   throw std::out_of_range("map::at:  key not found");
                return tmp->data->second;
            }
            void clear()
            {
                _tree.~RBT();
            }
            size_type size() const
            {
                return _tree._size;
            }
            iterator begin()
            {
            
                return iterator(_tree.FindMin());
            }
            iterator end()
            {
                return iterator(_tree.FindMax());
            }
            private :
                rbt      _tree;
    };
}

#endif
