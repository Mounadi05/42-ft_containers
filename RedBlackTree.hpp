#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include <memory>

template <class T, class comp, class alloc = std::allocator<T> >
class RBT {
public:
    typedef T value_type;
    typedef alloc allocator_type;
    alloc _alloc;
     struct Node 
    {
        Node* parent;
        Node* right;
        Node* left;
        T* data;
        bool isBlack;
        bool isLeftChild;
        Node(){}
        template<class K, class V>
        Node(K k, V v,RBT en = RBT()) : parent(NULL), left(NULL), right(NULL),
                    isBlack(false), isLeftChild(false) 
        {
            data = en._alloc.allocate(1); 
            en._alloc.construct(data, k, v);
        }
    };
    std::allocator<Node >   node_alloc;
    RBT() : _root(nullptr), _size(0) {}
    template<class K, class V>
    void insert(K _key ,V _value) 
    {
        Node * newNode; 
        newNode =  node_alloc.allocate(1);
        node_alloc.construct(newNode, _key, _value);
        newNode->isBlack = false; // new node is always colored red

        Node *parent = NULL;
        Node *current = _root;
        while (current != nullptr)
        {
            parent = current;
            if (comp()(_key, current->data->first))
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
        else if (comp()(_key, parent->data->first)) 
            parent->left = newNode;
        else 
            parent->right = newNode;
        _size++;
        
    }
    Node* _root;
    size_t _size;
    
};

#endif
