#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include <memory>
#include "../pair.hpp"
#include "../iterator/ReverseIterator.hpp"
#include "Node.hpp"
namespace ft{
template <class T, class comp = std::less<T>, class alloc = std::allocator<T> >
class RBT {
	public:
            typedef T																		value_type;
			typedef comp																	value_compare;
			typedef alloc																	allocator_type;
			typedef typename allocator_type::template rebind<ft::Node<value_type> >::other	node_allocator;
			typedef typename node_allocator::pointer										n_p;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef std::size_t																size_type;
			typedef std::ptrdiff_t															difference_type;
			typedef class ft::TreeIterator<T>												iterator;
			typedef const class ft::TreeIterator<T>										    const_iterator;
			typedef ft::reverse_iterator<iterator>											reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
			typedef typename ft::Node<value_type>											Node;
	private :
		Node * _tree;
		size_type _size;
		alloc _alloc;
	public : 
	
     void insert(const value_type& value) {
            Node * node; 
        if (_tree->isNil) {
            _tree->parent = node;  
            _tree->parent->isBlack = true;  
        } else {
            Node * current = _tree->parent;
            Node * parent = NULL;

            while (!current->isNil) {
                parent = current;

                if (value_compare()(node->data, current->data))
                    current = current->left;
                else
                    current = current->right;
            }
            node->parent = parent;

            if (value_compare()(node->data, parent->data))
                parent->left = node;
            else
                parent->right = node;

            node->isBlack = false; 
         }

        _size++;
    }

};
}

#endif
