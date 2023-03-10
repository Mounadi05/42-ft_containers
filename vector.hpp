#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils/RandomAccessIterator.hpp"
#include "utils/ReverseIterator.hpp"
#include <stdexcept>   



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
            T *             _data;
            size_type       _size;
            size_type       _capacity;
            Allocator       _alloc;
        public :
            explicit vector(const allocator_type& alloc = allocator_type()):_data(NULL),_size(0),_capacity(0){}
            explicit vector(size_type n, const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type()):_size(0),_capacity(0),_data(NULL){
                assign(n, val);
            }
            
            template <class InputIterator> vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type()):_size(0),_capacity(0),_data(NULL){
                assign(first, last);
            }
            vector (const vector& other){
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(int i = 0 ; i < _size; i++) _data[i] = other._data[i];
            }
            vector& operator= (const vector& other){
                if(_capacity > 0) _alloc.deallocate(_data,_capacity);
                _capacity = other._capacity;
                _size = other._size;
                _data = _alloc.allocate(_capacity);
                for(int i = 0 ; i < _size; i++) _data[i] = other._data[i];
                return *this;
            }
            void assign(size_type n, const value_type& val)
            {
                if (n > _capacity)
                {
                    _capacity = n;
                    _data= _alloc.allocate(_capacity);
                }
                _size = n;
                for(int i = 0; i < n; i++)_data[i] = val;
            }

            template <class InputIterator>  
            void assign (InputIterator first, InputIterator last)
            {
                size_type size = last - first;
                if (size > _capacity)
                {
                    _capacity = size;
                    _data= _alloc.allocate(_capacity);
                }
                _size = size;
                for(int i = 0;first != last;i++)_data[i] = *(first++);
            }
            reference at(size_type n)
            {
                if(n >= _size) throw std::out_of_range("vector");
                return _data[n];
            }
            const_reference at (size_type n) const{
                if(n >= _size) throw std::out_of_range("vector");
                return _data[n];
            }
            size_type capacity() const
            {
                return _capacity;
            }
            size_type size() const
            {
                return _size;
            }
            bool empty() const
            {
                return (_size == 0);
            }
            reference operator[] (size_type n){
                if(n >= _size) throw std::out_of_range("vector");
                return _data[n];
            }   
            const_reference operator[] (size_type n) const{
                if(n >= _size) throw std::out_of_range("vector");
                return _data[n];
            }
            reference front(){
                return *_data;
            }
            const_reference front() const
            {
                return *_data;
            }
            reference back(){
                return _data[_size-1];
            }
            const_reference back() const{
                return _data[_size-1];
            }
       

            
    };
}
#endif