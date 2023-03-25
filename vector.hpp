#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator/RandomAccessIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>
#include <iterator>
#include "tools.hpp"
namespace ft{

    template<class T,class Allocator = std::allocator<T> > 
    class vector 
    {
        public:
            typedef typename Allocator::reference                           reference;
            typedef typename Allocator::const_reference                     const_reference;
            typedef T                                                       value_type;
            typedef Allocator                                               allocator_type;
            typedef size_t                                                  size_type;
            typedef ptrdiff_t                                               difference_type;
            typedef typename Allocator::pointer                             pointer;
            typedef typename Allocator::const_pointer                       const_pointer;
            typedef typename ft::random_access_iterator<pointer>            iterator;
            typedef typename ft::random_access_iterator<const_pointer>      const_iterator;
            typedef ft::reverse_iterator<pointer>                          reverse_iterator;
            typedef ft::reverse_iterator<const_pointer>                    const_reverse_iterator;
        protected :
            pointer             _data;
            size_type           _size;
            size_type           _capacity;
            allocator_type      _alloc;
        public :
            explicit vector(const allocator_type& alloc = allocator_type()):_data(NULL),_size(0),_capacity(0),_alloc(alloc){}
            explicit vector(size_type n, const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type()):_data(NULL),_size(0),_capacity(0),_alloc(alloc){assign(n, val);}
            
            template <class InputIterator> vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type(),typename std::enable_if<!std::is_integral<InputIterator>::value,InputIterator>::type* = 0)
            :_data(NULL),_size(0),_capacity(0),_alloc(alloc){assign(first, last);}

            ~vector()
            {
                clear();           
                if (_capacity > 0)_alloc.deallocate(_data,_capacity);
            }
            vector(const vector& other):_data(NULL),_size(0),_capacity(0),_alloc(other._alloc){
                 _capacity = _size = other._size;
                if (other._capacity > 0) _data =_alloc.allocate(_size);
                for(size_type i = 0; i < _size ;i++)_alloc.construct(&_data[i], other._data[i]);
            }
            vector& operator= (const vector& other){
             if(other._data != this->_data){
                    clear();
                    if(_capacity <= 0)
                    { 
                        _capacity = other._capacity;
                        _size = other._size;
                        _data = _alloc.allocate(_capacity);
                        for(size_type i = 0 ; i < _size; i++) _alloc.construct(&_data[i], other._data[i]);
                    }
                    else
                    {
                        if(_capacity < other._size)
                        {
                            _capacity = other._size;
                            _data = _alloc.allocate(_capacity);
                        }
                        _size = other._size;
                        for(size_type i = 0 ; i < _size; i++) _alloc.construct(&_data[i], other._data[i]);
                    }
                }
                return *this;
            }
            void assign(size_type n, const value_type& val)
            {
                clear();
                if (n > _capacity)
                {
                    if (_capacity > 0)_alloc.deallocate(_data,_capacity);
                    _capacity = n;
                    _data= _alloc.allocate(_capacity);
                }
                while(_size < n )_alloc.construct(&_data[_size++], val);
            }       
           
            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            { 
                clear();
                vector tmp;
                 while(first != last) tmp.push_back(*first++);
                size_t n = tmp.size();
                 if (n > _capacity)
                {
                     if (_capacity > 0)_alloc.deallocate(_data,_capacity);
                    _capacity = n;
                    _data= _alloc.allocate(_capacity);
                }
                size_t j = 0;
                for(size_type i = 0; i < n;i++)_alloc.construct(&_data[_size++], tmp[j++]);
            }
            void reserve(size_type n)
            {
               if (n >= max_size())throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                if (n > _capacity){
                    size_t size = _size;
                    pointer tmp = _alloc.allocate(n);                  
                    for(size_type i = 0; i < _size; i++)_alloc.construct(&tmp[i], _data[i]);
                    clear();
                    if (_capacity > 0) _alloc.deallocate(_data,_capacity);
                    _capacity = n;
                    _size = size;
                    _data = tmp;
                }
            }
            void push_back (const value_type& val)
            {
                if (_capacity == 0)
                {
                    _data = _alloc.allocate(1);
                    _alloc.construct(&_data[_size++],val);
                    _capacity = 1; 
                }
                else 
                {
                    if (_size < _capacity)_alloc.construct(&_data[_size++],val);
                    else {
                        reserve(_capacity * 2);
                        _alloc.construct(&_data[_size++],val);
                    }
                }
            }
            iterator erase (iterator position){return erase(position , position + 1);}
            iterator erase(iterator first, iterator last)
            {
                size_type it  = first - begin();
                size_type it1 =  last - first;
                for(;(it+it1) < _size; it++) _data[it] = _data[it+it1];
                for(; it1 > 0; it1--) _alloc.destroy(&_data[--_size]);
                return first;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if(n < _size) while(_size > n) _alloc.destroy(&_data[--_size]);
                else if (n >= max_size()) 
                {
                    clear();
                    if (_capacity > 0)_alloc.deallocate(_data,_capacity);
                    throw std::length_error("vector");
                }
                else while(_size < n) push_back(val);
            }
            iterator insert (iterator position, const value_type& val)
            {
                size_type pos = position - begin();
                insert (position, 1, val);
                return iterator(_data + pos);       
            }
            void insert(iterator position, size_type n, const value_type& val)
            {
                if (n > 0)
                {
                    size_t tmp_size = _size;
                    size_t start = position - begin();
                    if (n + _size > _capacity)reserve(ft::max(n + _capacity, _capacity * 2));
                    for(;_size > start; _size--)
                        if (_size + n - 1 < tmp_size)_data[_size + n - 1] = _data[_size - 1];
                        else _alloc.construct(&_data[_size + n - 1], _data[_size - 1]);
                    _size = n + tmp_size;
                    for(size_t i = n ;i > 0; i--) 
                       if (start < tmp_size) _data[start++]= val;
                       else _alloc.construct(&_data[start++],val);
                }
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                for (; first != last; ++first)
                {
                     position = insert(position, *first);
                    ++position;
                }
            }
            void swap(vector& x)
            {
                pointer             tmp_data = x._data;
                size_type           tmp_size = x._size;
                size_type           tmp_cap = x._capacity;
                allocator_type      tmp_alloc = x._alloc;
                x._data = this->_data;
                x._size = this->_size;
                x._capacity = this->_capacity;
                x._alloc = this->_alloc;
                this->_data = tmp_data;
                this->_size = tmp_size;
                this->_capacity = tmp_cap;
                this->_alloc = tmp_alloc;
            }
            size_type max_size() const{return (sizeof(T) == 1) ? _alloc.max_size()/2 : _alloc.max_size();}
            allocator_type get_allocator() const{return _alloc;}
            void pop_back(){_alloc.destroy(&_data[--_size]);}
            reference at(size_type n){return(n >= _size) ? throw std::out_of_range("vector") : _data[n];}
            const_reference at (size_type n) const{return(n >= _size) ? throw std::out_of_range("vector") : _data[n];}
            size_type capacity() const{ return _capacity;}
            size_type size() const{return _size;}
            bool empty() const{return (_size == 0);}
            reference operator[] (size_type n){return _data[n];}   
            const_reference operator[] (size_type n) const{return _data[n];}
            reference front(){return *_data;}
            const_reference front() const{return *_data;}
            reference back(){return _data[_size-1];}
            const_reference back() const{return _data[_size-1];}
            void clear() 
            {
                for(size_t i = 0 ; i < _size ; i++)
                {
                    _alloc.destroy(&_data[i]);
                }    
                _size = 0;            
            }
            iterator begin(){return iterator(_data);}
            const_iterator begin() const{return const_iterator(_data);}
            iterator end(){return iterator(_data + _size);}
            const_iterator end() const{return const_iterator(_data + _size);}
            reverse_iterator rend(){return reverse_iterator(_data);}
            const_reverse_iterator rend() const{return const_reverse_iterator(_data);}
            reverse_iterator rbegin(){return reverse_iterator(_data + _size);}
            const_reverse_iterator rbegin() const{return const_reverse_iterator(_data + _size);}
          
    };
    template <class T, class Alloc>  
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
            x.swap(y);
    }
    template <class T, class Allocator>
    bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){
        if (lhs.size() == rhs.size())return ft::equal(lhs.begin(),lhs.end(),rhs.begin());    
        return false;
    }
 
    template <class T, class Allocator>
    bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
        return ft::lexicographical_compare (lhs.begin(), lhs.end(),rhs.begin(),rhs.end());
    }
    template <class T, class Allocator>
    bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(lhs == rhs);}

    template <class T, class Allocator>
    bool operator> (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return (rhs < lhs);}
    
    template <class T, class Allocator>
    bool operator<= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(rhs < lhs);}

    template <class T, class Allocator>
    bool operator>= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(rhs > lhs);}
}
#endif