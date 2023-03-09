#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        protected :
            Iterator iter;
        public :
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
    };
}
#endif