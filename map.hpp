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
            :_comp(comp),_tree(comp, alloc){}
            template <class InputIterator>  
            map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            : _comp(comp),_tree(first,last,_comp,alloc){}
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
            pair<iterator,bool> insert (const value_type& val)
            {
                if(_tree.find(val.first) == _tree.end())
                    return ft::pair<iterator,bool>(_tree.insert(val),true);
                return ft::pair<iterator,bool>(_tree.insert(val),false);
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
            size_type size() const
            {
                return _tree.size();
            }
            iterator find (const key_type& k)
            {
                return _tree.find(k);
            }
            const_iterator find (const key_type& k) const
            {
                return _tree.find(k);
            }
            bool empty() const
            {
                return (_tree.size() == 0);
            }

            void clear()
            {
                _tree.clear();
            }

            mapped_type& at (const key_type& k)
            {
                iterator it = _tree.find(k);          
                if (it == _tree.end())
                    throw std::out_of_range("map::at:  key not found");
                return it->second;
            }
            const mapped_type& at (const key_type& k) const
            {
                const_iterator it = _tree.find(k);          
                if (it == _tree.end())
                    throw std::out_of_range("map::at:  key not found");
                return it->second;
            }
            mapped_type& operator[] (const key_type& k)
            {
                iterator it = _tree.find(k);
                if (it == _tree.end())
                    it = _tree.insert(value_type(k,T()));
                return it->second;
            }
            size_type count (const key_type& k) const
            {
                return (_tree.find(k) != _tree.end());
            }

            key_compare key_comp() const
            {
                return _comp;
            }

            void print()
            {
                _tree.level_order();
            }

            private :
            key_compare _comp;
            rbt _tree;
        
    };

    template <class Key, class T, class Compare, class Alloc>  
    bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        if (lhs.size() == rhs.size())return ft::equal(lhs.begin(),lhs.end(),rhs.begin());    
        return false;;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return ft::lexicographical_compare (lhs.begin(), lhs.end(),rhs.begin(),rhs.end());
     }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>  
    bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    { 
        return !(lhs == rhs);
    }

    template <class Key, class T, class Compare, class Alloc>  
    bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return !( rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>  
    bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,const map<Key,T,Compare,Alloc>& rhs )
    {
        return !(lhs < rhs);
    }


}

#endif
