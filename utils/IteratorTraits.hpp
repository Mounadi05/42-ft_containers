#ifndef ITERATORTRAITS_HPP
#define ITERATORTRAITS_HPP

#include "Iterator.hpp"

namespace ft
{
    template <class iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T> 
    struct iterator_traits<T*> 
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };

    template<class T> 
    struct iterator_traits<const T*> 
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };
 }

#endif
