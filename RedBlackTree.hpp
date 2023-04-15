#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include <memory>
#include "pair.hpp"

template <class T, class comp, class alloc = std::allocator<T> >
class RBT {
public:
    typedef T value_type;
    typedef alloc allocator_type;
    alloc _alloc;
    struct Node 
    {
        Node* parent;
        Node* left;
        Node* right;
        T* data;
        bool isBlack;
        bool isLeftChild;
        template<class K, class V>
        Node(const ft::pair<K, V>& p, RBT en = RBT()) : parent(NULL), left(NULL), right(NULL),
            isBlack(false), isLeftChild(false)
        {
            data = en._alloc.allocate(1);
            en._alloc.construct(data,ft::pair<K,V>(p.first,p.second));
        }
        template<class K, class V>
        Node(K k, V v,RBT en = RBT()) :parent(NULL), left(NULL), right(NULL),
                    isBlack(false), isLeftChild(false) 
        {
            data = en._alloc.allocate(1); 
            en._alloc.construct(data,ft::pair<K,V>(k,v));
        }
        // Node *get_Nill()
        // {
        //     std::cout << "****** > " << std::endl;
        //     std::cout << hold->Nill->parent->data->first << std::endl;
        //     std::cout << "****** < " << std::endl;
        //     return hold->Nill;
        // }
       
    };
    std::allocator<Node >   node_alloc;
    Node *Nill;
    
    RBT() : _root(NULL), _size(0) 
    {            
        Nill = node_alloc.allocate(1);    
    }
    RBT(const RBT& other)
    {
        Nill = node_alloc.allocate(1);
        _root = copyNode(other._root);
        _size = other._size;
    }
    RBT& operator=(const RBT& other)
    {
        if (this == &other)
            return *this; 
        this->~RBT();
        
        if (other._root != NULL)
        {
            Nill = node_alloc.allocate(1);
            _root = copyNode(other._root);
            _size = other._size;
        }
        return *this;    
    }
  
    ~RBT() 
    {
        if (_root != NULL)
            destroy(_root);
    }
    template<class K, class V>
    Node* insert(K _key ,V _value,comp _comp) 
    {
        if(search(_key) == NULL)
        {
            Node * newNode; 
            newNode =  node_alloc.allocate(1);
            node_alloc.construct(newNode, _key, _value);
            newNode->isBlack = false; // new node is always colored red

            Node *parent = NULL;
            Node *current = _root;
            while (current != NULL)
            {
                parent = current;
                if (comp(_comp)(_key, current->data->first))
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
            else if (comp(_comp)(_key, parent->data->first))
                parent->left = newNode;
            else
                parent->right = newNode;
            _size++;
            balance(_root);
        }
         return (search(_key));
    }

    Node * FindMin()
    {
        Node *tmp = _root;
        if (tmp == NULL)
            return tmp;
        while(tmp->left)
             tmp = tmp->left;
        return tmp;    
    }

    Node * FindMax()
    {
        Node *tmp = _root;
        if (tmp == NULL)
            return tmp;
        while(tmp->right)
            tmp = tmp->right;
        Nill->parent = tmp;
        return (tmp->right);
    }
    template<class K>
    Node * search (const K& key) const
    {
        Node *root = _root; 
        while(root)
        {
            if (root->data->first== key)
                return root;              
            {
                if (key < root->data->first)
                    root = root->left;
                else
                    root = root->right;
            }
        }
        return root;
    }
    Node* _root;
    size_t _size;
    private :
            void balance(Node* newNode)
            {
                Node* parent = newNode->parent;
                Node* grandparent = NULL;
                Node* uncle = NULL;

                while (parent != NULL && !parent->isBlack && newNode != _root && newNode->parent->parent != NULL && !newNode->parent->parent->isBlack)
                {
                    grandparent = newNode->parent->parent;
                    if (newNode->parent == grandparent->left)
                    {
                        uncle = grandparent->right;

                        if (uncle != NULL && !uncle->isBlack)
                        {
                            // Case 1: Uncle is red
                            newNode->parent->isBlack = true;
                            uncle->isBlack = true;
                            grandparent->isBlack = false;
                            newNode = grandparent;
                        }
                        else
                        {
                            // Case 2: Uncle is black
                            if (newNode == newNode->parent->right)
                            {
                                newNode = newNode->parent;
                                rotateLeft(newNode);
                            }

                            // Case 3: Uncle is black
                            newNode->parent->isBlack = true;
                            grandparent->isBlack = false;
                            rotateRight(grandparent);
                        }
                    }
                    else
                    {
                        uncle = grandparent->left;

                        if (uncle != NULL && !uncle->isBlack)
                        {
                            // Case 1: Uncle is red
                            newNode->parent->isBlack = true;
                            uncle->isBlack = true;
                            grandparent->isBlack = false;
                            newNode = grandparent;
                        }
                        else
                        {
                            // Case 2: Uncle is black
                            if (newNode == newNode->parent->left)
                            {
                                newNode = newNode->parent;
                                rotateRight(newNode);
                            }

                            // Case 3: Uncle is black
                            newNode->parent->isBlack = true;
                            grandparent->isBlack = false;
                            rotateLeft(grandparent);
                        }
                    }

                    parent = newNode->parent;
                }

                // Make sure the root is always black
                _root->isBlack = true;
            }

            void rotateLeft(Node* node)
            {
                Node* child = node->right;
                node->right = child->left;

                if (child->left != NULL)
                    child->left->parent = node;

                child->parent = node->parent;

                if (node->parent == NULL)
                    _root = child;
                else if (node == node->parent->left)
                    node->parent->left = child;
                else
                    node->parent->right = child;

                child->left = node;
                node->parent = child;
            }

            void rotateRight(Node* node)
            {
                Node* child = node->left;
                node->left = child->right;

                if (child->right != NULL)
                    child->right->parent = node;

                child->parent = node->parent;

                if (node->parent == NULL)
                    _root = child;
                else if (node == node->parent->left)
                    node->parent->left = child;
                else
                    node->parent->right = child;

                child->right = node;
                node->parent = child;
            }
        
            void destroy(Node* node) 
            {
                if (node == NULL)
                    return;
                destroy(node->left);  
                destroy(node->right);  
                _alloc.destroy(node->data);  
                _alloc.deallocate(node->data, 1);  
                node_alloc.deallocate(node, 1);
            }
            Node* copyNode(const Node* otherNode)
            {
                if (otherNode == NULL)
                    return NULL;
                Node * newNode; 
                newNode =  node_alloc.allocate(1);
                node_alloc.construct(newNode,otherNode->data->first, otherNode->data->second);
                newNode->isBlack = otherNode->isBlack;
                newNode->isLeftChild = otherNode->isLeftChild;
                newNode->parent = NULL;
                newNode->left = copyNode(otherNode->left);
                if (newNode->left != NULL)
                    newNode->left->parent = newNode;
                newNode->right = copyNode(otherNode->right);
                if (newNode->right != NULL)
                    newNode->right->parent = newNode;

                return newNode;
            }
};

#endif
