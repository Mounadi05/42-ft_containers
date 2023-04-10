#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template<class Iterator>
    class bidirectional_iterator
    {
        private : 
            Iterator _iter;
        public :
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            bidirectional_iterator(){}
            explicit bidirectional_iteratorr(Iterator iter):_iter(iter){}
            
            template <class U> 
            bidirectional_iterator(const bidirectional_iterator<U>& u)
            :_iter(u.getIterator()) {}
            
            random_access_iterator &operator=(const bidirectional_iterator  & rai){
                if (this->_iter != rai._iter){this->_iter = rai._iter;}
                return *this;
            }
            Iterator getIterator() const {return _iter;}
            reference operator*() const{return *_iter;}
    };
}
#endif