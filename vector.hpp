#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils/RandomAccessIterator.hpp"
#include "utils/ReverseIterator.hpp"
#include <stdexcept>   
#include <type_traits>



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
            const allocator_type& alloc = allocator_type(),typename std::enable_if<std::is_integral<typename std::iterator_traits<InputIterator>::value_type>::value>::type* = 0):_data(NULL),_size(0),_capacity(0),_alloc(alloc){assign(first, last);}

            ~vector()
            {
                clear();
                _alloc.deallocate(_data,_capacity);
            }
            vector (const vector& other){
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0 ; i < _size; i++) _data[i] = other._data[i];
            }
            vector& operator= (const vector& other){
                if(_capacity > 0)
                { 
                    for(size_t i = 0 ; i < _size;i++)_alloc.destroy(&_data[i]);
                    _alloc.deallocate(_data,_capacity);
                }
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(size_type i = 0 ; i < _size; i++) _data[i] = other._data[i];
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
            void assign (InputIterator first, InputIterator last, typename std::enable_if<std::is_integral<typename std::iterator_traits<InputIterator>::value_type>::value>::type = 0)
            {
                size_type size = last - first;
                if (size > _capacity)
                {
                    _capacity = size;
                    _data= _alloc.allocate(_capacity);
                }
                _size = size;
                for(size_type i = 0;first != last;i++)_data[i] = *(first++);
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
            

    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last)
    // {
    //     clear();
    //     reserve(std::distance(first, last));
    //     for (iterator it = begin(); first != last; ++first, ++it)
    //         _alloc.construct(it, *first);
    //     _size = std::distance(first, last);
    // }
    };
}
#endif