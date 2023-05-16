#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include <memory>
#include "pair.hpp"
#include "../iterator/ReverseIterator.hpp"
template <class T, class comp, class alloc = std::allocator<T> >
class RBT {
public:
            typedef Val																		value_type;
			typedef Comp																	value_compare;
			typedef Alloc																	allocator_type;
			typedef typename allocator_type::template rebind<ft::node<value_type> >::other	node_allocator;
			typedef typename node_allocator::pointer										n_p;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef std::size_t																size_type;
			typedef std::ptrdiff_t															difference_type;
			typedef class ft::TreeIterator<Val>												iterator;
			typedef const class ft::TreeIterator<Val>										const_iterator;
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
};

#endif
