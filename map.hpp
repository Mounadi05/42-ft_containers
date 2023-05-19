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
            public :
            class value_compare: public ft::binary_function<value_type,value_type,bool> 
            {
                friend class map;
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) {}
                public :
                    bool operator()(const value_type& x, const value_type& y) const 
                    {
                        return comp(x.first, y.first);
                    }
            };
            typedef typename ft::RBT<value_type,key_compare,Allocator>   rbt;
            typedef typename rbt::iterator                               iterator;
            typedef typename rbt::const_iterator                         const_iterator;
              explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _tree(comp, alloc)
        {
        }
            template <class InputIterator>  
            map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            {
                 _tree = rbt(first,last,comp,alloc);
                _tree.insert(first,last);
            }
            

            map(const map& other)
                : _tree(other._tree){}

            map& operator=(const map& other)
            {
                if (this != &other)
                    _tree = other._tree;
                return *this;
            }

            template <class InputIterator>  
            void insert (InputIterator first, InputIterator last)
            {
                _tree.insert(first,last);
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                return _tree.insert(val);
            }
            iterator begin()
            {
                return iterator(_tree.begin());
            }
            const_iterator begin() const
            {
                return const_iterator(_tree.begin());
            }
            iterator end()
            {
                return iterator(_tree.end());
            }
            const_iterator end() const
            {
                return const_iterator(_tree.end());
            }
            private :
                rbt _tree;
        
    };
}

#endif
