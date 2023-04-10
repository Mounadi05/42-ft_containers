#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include "iterator/BidirectionalIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
#include <functional>

namespace ft {

    template <class Key, class T, class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
    class map 
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const Key, T> value_type;
            typedef Compare key_compare;
            typedef Allocator allocator_type;
            typedef size_t                                                  size_type;
            typedef ptrdiff_t                                               difference_type;
            typedef typename Allocator::reference reference;
            typedef typename Allocator::const_reference const_reference;
            typedef typename ft::bidirectional_iterator<pointer>            iterator;
            typedef typename ft::bidirectional_iterator<const_pointer>      const_iterator;
            typedef typename Allocator::pointer pointer;
            typedef typename Allocator::const_pointer const_pointer;
            typedef std::reverse_iterator<iterator> reverse_iterator;
            typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    };
}

#endif
