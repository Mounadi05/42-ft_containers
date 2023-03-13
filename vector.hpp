#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils/RandomAccessIterator.hpp"
#include "utils/ReverseIterator.hpp"
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
            typedef ft::reverse_iterator<iterator>                          reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
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
            const allocator_type& alloc = allocator_type(),typename std::enable_if<!std::is_integral<InputIterator>::value,InputIterator>::type* = 0):_data(NULL),_size(0),_capacity(0),_alloc(alloc){assign(first, last);}

            ~vector()
            {
                clear();
                if (_capacity > 0)_alloc.deallocate(_data,_capacity);
            }
            vector (const vector& other){
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0 ; i < _size; i++) _alloc.construct(&_data[i], other._data[i]);
            }
            vector& operator= (const vector& other){
                if(_capacity > 0)
                { 
                    clear();
                    _alloc.deallocate(this->_data,this->_capacity);
                }
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0 ; i < _size; i++) _alloc.construct(&_data[i], other._data[i]);
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
                _size = n;
                for(size_type i = 0; i < n; i++)_alloc.construct(&_data[i], val);
            }
           
            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {   
                clear();
                vector tmp;
                while(first != last)
                    tmp.push_back(*first++);
                if (tmp.size() > _capacity)
                {
                    if (_capacity > 0)_alloc.deallocate(_data,_capacity);
                    _capacity = tmp.size();
                    _data= _alloc.allocate(_capacity);
                }
                for( size_type i = 0; i < tmp.size();i++)_alloc.construct(&_data[_size++], tmp.at(i));
            }
            void reserve (size_type n)
            {
                if (n > _capacity)
                {
                    size_type size = _size;
                    pointer tmp = _alloc.allocate(size);
                    for(size_type i = 0; i < _size; i++)_alloc.construct(&tmp[i], _data[i]);
                    clear();
                    _alloc.deallocate(_data,_capacity);
                    _data = _alloc.allocate(n);
                    _capacity = n;
                    _size = size;
                    for(size_type i = 0; i < _size; i++)_alloc.construct(&_data[i], tmp[i]);
                    while(size > 0)_alloc.destroy(&tmp[--size]);
                    _alloc.deallocate(tmp,_size);
                }
            }
            void push_back (const value_type& val)
            {
               // std::cerr << ">>>> push_back" << std::endl;
                if (!_capacity)
                {
                    _data = _alloc.allocate(++_capacity);
                    _alloc.construct(&_data[_size++],val);
                }
                else 
                {
                    if (_size < _capacity)_alloc.construct(&_data[_size++],val);
                    else {
                        reserve(_capacity * 2);
                        _alloc.construct(&_data[_size++],val);
                    }
                }
               // std::cerr << "<<<<< push_back" << std::endl;
            }
            size_type max_size() const{return _alloc.max_size();}
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
            void clear(){while(_size > 0)_alloc.destroy(&_data[--_size]);}
            iterator begin(){return iterator(_data);}
            const_iterator begin() const{return const_iterator(_data);}
            iterator end(){return iterator(_data + _size);}
            const_iterator end() const{return const_iterator(_data + _size);}
            reverse_iterator rend(){return reverse_iterator(_data);}
            const_reverse_iterator rend() const{return const_reverse_iterator(_data);}
            reverse_iterator rbegin(){return reverse_iterator(_data + _size);}
            const_reverse_iterator rbegin() const{return const_reverse_iterator(_data + _size);}
            // template <class It>
            // size_type distance(It first, It last)
            // {
            //     size_type result = 0;
            //     while (first != last) {
            //         ++first;
            //         ++result;
            //     }
            //     return result;
            // }
    friend bool operator== (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){
        if (!(lhs._alloc == rhs._alloc && lhs._size == rhs._size && lhs._capacity == rhs._capacity))return false;
        for(size_t i = 0; i < lhs._size ; i++)if (lhs._data[i] != rhs._data[i]) return false;            
        return true;
    }
    friend bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
        return lexicographical_compare (lhs.begin(), lhs.end(),rhs.begin(),rhs.end());
    }
    friend bool operator!= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(lhs == rhs);}
    friend bool operator> (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return (rhs < lhs);}
    friend bool operator<= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(rhs < lhs);}
    friend bool operator>= (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs){ return !(rhs > lhs);}

    };
   
}
#endif