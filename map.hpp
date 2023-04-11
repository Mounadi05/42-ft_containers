#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "iterator/MapIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
#include "pair.hpp"
#include "tools.hpp"

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
        private :
                struct Node
                {
                    Node *parent, *left, *right;
                    bool isBlack;
                    bool isLeftChild;
                    value_type value;
                    Node(Key k, T v) : parent(NULL), left(NULL), right(NULL),
                    isBlack(false), isLeftChild(false), value(k, v) {}
                };
                Node *              _root;
                size_type           _size;
                std::allocator<Node >      _alloc;
                key_compare         _comp;
        public :
            typedef Node*                                                   node_pointer;
            typedef typename Allocator::const_pointer                       const_pointer;
            typedef typename ft::map_iterator<Key, T, Node>                 iterator;
            //typedef typename ft::map_iterator<const_pointer>                const_iterator;
            typedef std::reverse_iterator<iterator>                         reverse_iterator;
            //typedef std::reverse_iterator<const_iterator>                   const_reverse_iterator;
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

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc){}

            template <class InputIterator>
            map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            :_comp(comp),_alloc(alloc)
            {
                while(first != last)
                {
                    key_type _key = first->first;
                    mapped_type _value = first->second;
                    Node * newNode; 
                    newNode = _alloc.allocate(1);
                    _alloc.construct(newNode,_key, _value);
                    newNode->isBlack = false; // new node is always colored red

                    Node *parent = NULL;
                    Node *current = _root;
                    while (current != nullptr)
                    {
                        parent = current;
                        if (_key < current->value.first)
                        {
                            current = current->left;
                            newNode->isLeftChild = true;
                        }
                        else
                        {
                            current = current->right;
                            newNode->isLeftChild = false;
                        }
                    }
                    newNode->parent = parent;
                    if (parent == NULL) // tree is empty, new node becomes root
                    {
                        _root = newNode;       
                        _root->isBlack = true; // colored root by black
                    }
                    else if (_key < parent->value.first) 
                        parent->left = newNode;
                    else 
                        parent->right = newNode;
                    _size++;
                    first++;
                }
            }
            mapped_type& operator[] (const key_type& k)
            {
                Node *root = _root; 
                while(root)
                {
                    if (root->value.first == k)
                        return root->value.second;              
                    {
                        if (k < root->value.first)
                            root = root->left;
                        else
                            root = root->right;
                    }
                }
                return root->value.second;
            }
            size_type size() const
            {
                return _size;
            }
            iterator begin()
            {
                return iterator(_root);
            }
            iterator end()
            {
                return iterator(_root + _size);
            }
            // const_iterator begin() const
            // {
            //     return iterator(_root);
            // }
            
    };
}

#endif
