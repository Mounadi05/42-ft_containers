#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include "pair.hpp"
#include <memory>

namespace ft{

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class T> 
    const T& max (const T& a, const T& b) {return (a<b) ? b : a;}
    
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1) 
        {
            if (!(*first1 == *first2)) return false;
            ++first1; ++first2;
        }
        return true;
    }

    template <class It>
    size_t distance(It first, It last)
    {
            size_t result = 0;
            while (first != last) {
                ++first;
                ++result;
            }
            return result;
    }

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y) );
    }

    template <class Arg1, class Arg2, class Result>
    struct binary_function 
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };

    // template <class Type> struct rebind {
    //     typedef allocator<Type> other;
    // };


    template< class T > struct remove_const                { typedef T type; };
    template< class T > struct remove_const<const T>       { typedef T type; };
}
#endif