#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template<class Iterator>
    class random_access_iterator  
    {
        private : 
            Iterator _iter;
        public :
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            Iterator getIterator() {return _iter}
            random_access_iterator():{}
            random_access_iterator(Iterator iter):_iter(iter){}
            reference operator*() const{return *_iter}
            pointer operator->() const{return &(operator*())}
            random_access_iterator & operator++(){
                _iter++;
                return *this;
            }
            random_access_iterator operator++(int){
                random_access_iterator tmp = *this;
                _iter++;
                return tmp;
            }
            random_access_iterator & operator--(){
                _iter--;
                return *this;
            }
            random_access_iterator operator--(int){
                random_access_iterator tmp = *this;
                _iter--;
                return tmp;
            }
            random_access_iterator operator+ (difference_type n) const{
                random_access_iterator tmp = *this;
                tmp._iter += n;
                return *this;

            }
            random_access_iterator& operator+=(difference_type n){
                _iter += n;
                return *this;
            }
            random_access_iterator operator- (difference_type n) const{
                random_access_iterator tmp = *this;
                tmp._iter -= n;
                return *this;
            }
            random_access_iterator& operator-=(difference_type n){
                _iter -= n;
                return *this;
            }
            reference operator[](difference_type n) const;

    };

}

#endif