
#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template<class Key, class T, class Node>
    class map_iterator
    {
    private:
        Node* _node; 
        typedef map_iterator<Key, T, Node> self_type;

    public:
        typedef typename ft::iterator_traits<Node*>::difference_type difference_type;
        typedef typename ft::iterator_traits<Node*>::value_type value_type;
        typedef typename ft::iterator_traits<Node*>::pointer pointer;
        typedef typename ft::iterator_traits<Node*>::reference reference;
        typedef typename ft::iterator_traits<Node*>::iterator_category iterator_category;

        map_iterator() : _node(nullptr) {}
        explicit map_iterator(Node* node) : _node(node) {}

        template <class Key_, class T_, class Node_>
        map_iterator(const map_iterator<_Key, _T, _Node>& other)
        : _node(other.getNode()) {}

        self_type& operator=(const map_iterator& other)
        {
            if (this->_node != other._node)
                this->_node = other._node;
            return *this;
        }

        Node* getNode() const { return _node; }

        reference operator*() const { return _node->data; }
        pointer operator->() const { return &(_node->data); }

        self_type& operator++()
        {
            if (_node)
            {
                if (_node->right)
                {
                    _node = _node->right;
                    while (_node->left)
                        _node = _node->left;
                }
                else
                {
                    Node* parent = _node->parent;
                    while (parent && _node == parent->right)
                    {
                        _node = parent;
                        parent = parent->parent;
                    }
                    _node = parent;
                }
            }
            return *this;
        }

        self_type operator++(int)
        {
            self_type temp(*this);
            operator++();
            return temp;
        }

        self_type& operator--()
        {
            if (_node)
            {
                if (_node->left)
                {
                    _node = _node->left;
                    while (_node->right)
                        _node = _node->right;
                }
                else
                {
                    Node* parent = _node->parent;
                    while (parent && _node == parent->left)
                    {
                        _node = parent;
                        parent = parent->parent;
                    }
                    _node = parent;
                }
            }
            return *this;
        }

        self_type operator--(int)
        {
            self_type temp(*this);
            operator--();
            return temp;
        }

        friend bool operator==(const self_type& lhs, const self_type& rhs)
        {
            return lhs._node == rhs._node;
        }

        friend bool operator!=(const self_type& lhs, const self_type& rhs)
        {
            return !(lhs == rhs);
        }
    };
}

#endif

