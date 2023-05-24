#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <algorithm>   
#include <memory>
#include "../pair.hpp"
#include "../iterator/ReverseIterator.hpp"
#include "Node.hpp"
 
namespace ft
{
    template <class T, class compare = std::less<T>, class alloc = std::allocator<T> > 
    class RBT
    {
    public:
        typedef T value_type;
        typedef typename value_type::first_type key_type;

        typedef compare value_compare;
        typedef alloc allocator_type;
        typedef typename allocator_type::template rebind<ft::Node<value_type> >::other node_allocator;
        typedef typename node_allocator::pointer n_p;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef class ft::TreeIterator<T> iterator;
        typedef class ft::TreeIterator<T> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        n_p _tree;
        n_p _nil;
        size_type _size;
        allocator_type _alloc_value;
        node_allocator _alloc_node;
        value_compare _comp;
        void initNil()
        {
            _nil = _alloc_node.allocate(1);
            _nil->isBlack = true;
            _nil->isNil = true;
            _nil->parent = _nil;
            _nil->right = _nil;
            _nil->left = _nil;
        }

    public:
        RBT(const value_compare &comp = value_compare(), const allocator_type &alloca = allocator_type()) : _size(0), _alloc_value(alloca), _comp(comp)
        {
            initNil();
            _tree = _nil;
        }
        template <class InputIterator>
        RBT(InputIterator first, InputIterator last,
            const value_compare &comp = value_compare(), const allocator_type &alloca = allocator_type()) : _size(0), _alloc_value(alloca), _comp(comp)
        {
            initNil();
            _tree = _nil;
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }

        RBT(const RBT &other)
            : _size(other._size), _alloc_value(other._alloc_value), _alloc_node(other._alloc_node), _comp(other._comp)
        {
            initNil();
            if (other._tree == other._nil)
                _tree = _nil;
            else
            {
                _tree = copyTree(other._tree);
                _tree->parent = _nil;
            }
        }

        n_p copyTree(n_p node)
        {
            if (node == node->left)
                return _nil;

            n_p newNode = _alloc_node.allocate(1);
            newNode->data = _alloc_value.allocate(1);
            _alloc_value.construct(newNode->data, *(node->data));
            newNode->isBlack = node->isBlack;
            newNode->isNil = node->isNil;
            // newNode->left = newNode->right = newNode->parent = _nil;

            newNode->left = copyTree(node->left);
            newNode->right = copyTree(node->right);

            if (newNode->left != _nil)
                newNode->left->parent = newNode;
            if (newNode->right != _nil)
                newNode->right->parent = newNode;

            return newNode;
        }
        RBT &operator=(const RBT &other)
        {
            if (this != &other)
            {
                if (_tree != _nil)
                    destroy(_tree);
                _alloc_node.deallocate(_nil, 1);

                _size = other._size;
                _alloc_value = other._alloc_value;
                _alloc_node = other._alloc_node;
                _comp = other._comp;
                initNil();

                if (other._tree == other._nil)
                    _tree = _nil;
                else
                {
                    _tree = copyTree(other._tree);
                    _tree->parent = _nil;
                }
            }
            return *this;
        }
        ~RBT()
        {
            if (_size > 0)
                destroy(_tree);
            _alloc_node.deallocate(_nil, 1);
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                insert(*first);
                first++;
            }
        }
        iterator insert(const value_type &val)
        {
            if (find(val.first) == end())
            {
                n_p newNode = _alloc_node.allocate(1);
                newNode->data = _alloc_value.allocate(1);
               _alloc_value.construct(newNode->data, val);
                newNode->isBlack = false;
                if (_tree == _nil)
                {
                    newNode->left = newNode->right = newNode->parent = _nil;
                    _tree = newNode;
                    _tree->isBlack = true;
                }
                else
                {
                    newNode->left = newNode->right = _nil;
                    newNode->isNil = false;
                    n_p parent = _nil;
                    n_p current = _tree;
                    while (current != _nil)
                    {
                        parent = current;
                        if (_comp(newNode->data->first, current->data->first))
                            current = current->left;
                        else
                            current = current->right;
                    }
                    if (_comp(newNode->data->first, parent->data->first))
                        parent->left = newNode;
                    else
                        parent->right = newNode;

                    newNode->parent = parent;
                    balance(newNode);
                }
                _size++;
                return iterator(newNode);
            }
            return iterator(find(val.first));
        }
        size_type size() const
        {
            return _size;
        }
        iterator begin()
        {
            n_p node = _tree;
            while (node->left != _nil)
                node = node->left;
            return iterator(node);
        }

        const_iterator begin() const
        {
            n_p node = _tree;
            while (node->left != _nil)
                node = node->left;
            return const_iterator(node);
        }

        iterator end()
        {
            n_p node = _tree;
            while (node->right != _nil)
                node = node->right;
            _nil->parent = node;
            return iterator(_nil);
        }

        const_iterator end() const
        {
            n_p node = _tree;
            while (node->right != _nil)
                node = node->right;
            _nil->parent = node;
            return const_iterator(_nil);
        }
        iterator find(const key_type &k)
        {
            n_p root = _tree;
            while (root != _nil)
            {
                if (root->data->first == k)
                    return iterator(root);
                {
                    if (_comp(k,root->data->first))
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            return end();
        }
        const_iterator find(const key_type &k) const
        {
            n_p root = _tree;
            while (root != _nil)
            {
                if (root->data->first == k)
                    return const_iterator(root);
                {
                    if (_comp(k,root->data->first))
                        root = root->left;
                    else
                        root = root->right;
                }
            }
            return end();
        }
        void clear()
        {
            if (_size > 0)
                destroy(_tree);
            _tree = _nil;
            _size = 0;
        }


        allocator_type get_allocator() const
        {
            return  _alloc_value;
        }
        void erase(iterator position)
        {
            n_p node = position.getNode();
            n_p toDelete = node;

            if (node != _nil)
            {
                if (node->left == _nil)
                {
                    node = node->right;
                    transplant(toDelete, node);
                }
                else if (node->right == _nil)
                {
                    node = node->left;
                    transplant(toDelete, node);
                }
                else
                {
                    n_p tmp = findMin(node->right);

                    if (tmp->parent != node)
                    {
                        transplant(tmp, tmp->right);
                        tmp->right = node->right;
                        tmp->right->parent = tmp;
                    }

                    transplant(toDelete, tmp);
                    tmp->left = node->left;
                    tmp->left->parent = tmp;
                }

                _alloc_value.destroy(toDelete->data);
                _alloc_value.deallocate(toDelete->data, 1);
                _alloc_node.deallocate(toDelete, 1);

                _size--;
            }
        }
        iterator lower_bound(const key_type& k)
        {
            n_p node = _tree;
            n_p tmp = _nil;
            while (node != _nil)
            {
                if (!_comp(node->data->first, k))
                {
                    tmp = node;
                    node = node->left;
                }
                else
                    node = node->right;
            }
            if (tmp == _nil) return end();
            return iterator(tmp);
        }
        const_iterator lower_bound (const key_type& k) const
        {  
            n_p node = _tree;
            n_p tmp = _nil;
            while (node != _nil)
            {
                if (!_comp(node->data->first, k))
                {
                    tmp = node;
                    node = node->left;
                }
                else
                    node = node->right;
            }
            if (tmp == _nil) return end();
            return const_iterator(tmp);
        }
        iterator upper_bound(const key_type& k)
        {
            n_p root = _tree;
            n_p tmp = _nil;

            while (root != _nil)
            {
                if (_comp(k, root->data->first))
                {
                    tmp = root;
                    root = root->left;
                }
                else
                    root = root->right;
            }

            if (tmp != _nil)
                return iterator(tmp);
            return end();
        }

        const_iterator upper_bound(const key_type& k) const
        {
            n_p root = _tree;
            n_p tmp = _nil;

            while (root != _nil)
            {
                if (_comp(k, root->data->first))
                {
                    tmp = root;
                    root = root->left;
                }
                else
                    root = root->right;
            }
            if (tmp != _nil)
                return const_iterator(tmp);
            return end();
        }
        void swap (RBT& x)
        {
            std::swap(this->_tree,x._tree);
            std::swap(this->_nil,x._nil);
            std::swap(this->_alloc_node,x._alloc_node);
            std::swap(this->_alloc_value,x._alloc_value);
            std::swap(this->_comp,x._comp);
            std::swap(this->_size,x._size);
        }
        size_type max_size() const
        {
            return _alloc_node.max_size();
        }
    private:

       void transplant(n_p u, n_p v)
        {
            if (u->parent == _nil)
                _tree = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        n_p findMin(n_p node)
        {
            n_p tmp = node;
            while(tmp != _nil &&  tmp->left != _nil)
                tmp = tmp->left;
            return tmp; 
        }
        n_p findMax(n_p node)
        {
            n_p tmp = node;
            while(tmp != _nil &&  tmp->right != _nil)
                tmp = tmp->right;
            return tmp; 
        }
        void destroy(n_p tmp)
        {
            if (tmp == _nil)
                return;
            destroy(tmp->left);
            destroy(tmp->right);
            _alloc_value.destroy(tmp->data);
            _alloc_value.deallocate(tmp->data, 1);
            _alloc_node.deallocate(tmp, 1);
        }
        void balance(n_p node)
        {
            while (node->parent->isBlack == false)
            {
                if (node->parent == node->parent->parent->left)
                {
                    n_p uncle = node->parent->parent->right;
                    if (uncle->isBlack == false)
                    {
                        node->parent->isBlack = true;
                        uncle->isBlack = true;
                        node->parent->parent->isBlack = false;
                        node = node->parent->parent;
                    }
                    else
                    {
                        if (node == node->parent->right)
                        {
                            node = node->parent;
                            rotateLeft(node);
                        }
                        node->parent->isBlack = true;
                        node->parent->parent->isBlack = false;
                        rotateRight(node->parent->parent);
                    }
                }
                else
                {
                    n_p uncle = node->parent->parent->left;
                    if (uncle->isBlack == false)
                    {
                        node->parent->isBlack = true;
                        uncle->isBlack = true;
                        node->parent->parent->isBlack = false;
                        node = node->parent->parent;
                    }
                    else
                    {
                        if (node == node->parent->left)
                        {
                            node = node->parent;
                            rotateRight(node);
                        }
                        node->parent->isBlack = true;
                        node->parent->parent->isBlack = false;
                        rotateLeft(node->parent->parent);
                    }
                }

                if (node->parent == _nil) 
                    break;
            }
            _tree->isBlack = true;
        }
        void rotateLeft(n_p node)
        {
            n_p rightChild = node->right;
            node->right = rightChild->left;
            if (rightChild->left != _nil)
                rightChild->left->parent = node;
            rightChild->parent = node->parent;
            if (node->parent == _nil)
                _tree = rightChild;
            else if (node == node->parent->left)
                node->parent->left = rightChild;
            else
                node->parent->right = rightChild;
            rightChild->left = node;
            node->parent = rightChild;
        }
        void rotateRight(n_p node)
        {
            n_p leftChild = node->left;
            node->left = leftChild->right;
            if (leftChild->right != _nil)
                leftChild->right->parent = node;
            leftChild->parent = node->parent;
            if (node->parent == _nil)
                _tree = leftChild;
            else if (node == node->parent->right)
                node->parent->right = leftChild;
            else
                node->parent->left = leftChild;
            leftChild->right = node;
            node->parent = leftChild;
        }
    };

}

#endif
