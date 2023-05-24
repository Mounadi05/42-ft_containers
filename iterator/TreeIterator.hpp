#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

#include "../RBT/Node.hpp"
#include "../utility.hpp"

namespace ft
{
    template <class Val>
    class TreeIterator
    {
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename ft::iterator_traits<Val *>::value_type value_type;
        typedef typename ft::iterator_traits<Val *>::reference reference;
        typedef typename ft::iterator_traits<Val *>::pointer pointer;
        typedef const typename ft::iterator_traits<Val *>::reference const_reference;
        typedef const typename ft::iterator_traits<Val *>::pointer const_pointer;
        typedef typename ft::iterator_traits<Val *>::difference_type difference_type;
        typedef std::size_t size_type;
        typedef Node<Val> *node_pointer;

    protected:
        node_pointer root;

    public:
        TreeIterator() {}
        TreeIterator(node_pointer ptr) : root(ptr) {}
        TreeIterator(const TreeIterator<Val> &other) { *this = other; }
        TreeIterator &operator=(const TreeIterator<Val> &other)
        {
            if (this != &other)
                root = other.root;
            return *this;
        }
        node_pointer getNode()
        {
            return root;
        }
        ~TreeIterator() {}
        reference operator*() { return *root->data; }
        pointer operator->() { return &operator*(); }
        const_reference operator*() const { return *(root->data); }
        const_pointer operator->() const { return &operator*(); }
        node_pointer getPointer() const { return root; }
        TreeIterator &operator++()
        {
            if (root->isNil)
                root = root->parent;
            else if (!root->right->isNil)
            {
                root = root->right;
                while (!root->left->isNil)
                    root = root->left;
            }
            else
            {
                node_pointer tmp = root->parent;
                while (!tmp->isNil && root == tmp->right)
                {
                    root = tmp;
                    tmp = tmp->parent;
                }
                root = tmp;
            }
            return *this;
        }

        TreeIterator operator++(int)
        {
            TreeIterator<value_type> tmp(*this);
            ++(*this);
            return tmp;
        }
        TreeIterator &operator--()
        {
            if (root->isNil)
            {
                root = root->parent;
            }
            else if (!root->isNil && !root->left->isNil)
            {
                root = root->left;
                while (!root->right->isNil)
                    root = root->right;
            }
            else
            {
                node_pointer tmp = root->parent;
                while (!tmp->isNil && root == tmp->left)
                {
                    root = tmp;
                    tmp = tmp->parent;
                }
                root = tmp;
            }
            return *this;
        }

        TreeIterator operator--(int)
        {
            TreeIterator<value_type> tmp(*this);
            --(*this);
            return tmp;
        }
        template <class T>
        bool operator==(const TreeIterator<T> &other) const { return root == other.root; }
        template <class T>
        bool operator!=(const TreeIterator<T> &other) const { return root != other.root; }
    };
}

#endif
