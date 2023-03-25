#ifndef TOOLS_HPP
#define TOOLS_HPP
#include <iostream>
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
}
#endif