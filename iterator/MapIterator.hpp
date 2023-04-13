#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "IteratorTraits.hpp"
#include "../RedBlackTree.hpp"

namespace ft
{
    template <class T,class compare,class alloc = std::allocator<T> >
    class map_iterator
    {
    public:
        typedef T                               value_type;
        typedef ptrdiff_t                       difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename  RBT<T,compare>::Node* node_pointer;

        map_iterator(node_pointer node = nullptr) : _node(node) {}

        reference operator*() const { return *_node->data; }

        pointer operator->() const { return _node->data; }

        map_iterator& operator++()
        {
            if (_node->right)
            {
                _node = _node->right;
                while (_node->left)
                    _node = _node->left;
            }
            else 
            {
                node_pointer prev = _node;
                _node = _node->parent;
                while (_node && _node->right == prev)
                {
                    prev = _node;
                    _node = _node->parent;
                }
            }
            return *this;
        }

        map_iterator operator++(int)
        {
            map_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        map_iterator& operator--()
        {
            if (_node->isBlack && _node->right && _node->right->right)
            {
                _node = _node->right;
                while (_node->left)
                    _node = _node->left;
            }
            else
            {
                node_pointer prev = _node;
                _node = _node->parent;
                while (_node && _node->left == prev)
                {
                    prev = _node;
                    _node = _node->parent;
                }
            }
            return *this;
        }

        map_iterator operator--(int)
        {
            map_iterator tmp(*this);
            --(*this);
            return tmp;
        }

        bool operator==(const map_iterator& other) const { return _node == other._node; }

        bool operator!=(const map_iterator& other) const { return _node != other._node; }
    private:
         node_pointer   _node;
    }; 
}

#endif