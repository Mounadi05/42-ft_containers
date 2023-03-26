#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include "IteratorTraits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        protected :
            Iterator _iter;
        public :
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
            reverse_iterator(){}
            explicit reverse_iterator(Iterator iter):_iter(iter){}
            template <class U> 
            reverse_iterator(const reverse_iterator<U>& u):_iter(u.base()){}
            
            reverse_iterator &operator=(const reverse_iterator & rai){
                if (this->_iter != rai.base())this->_iter = rai._iter;
                return *this;
            }
            Iterator base() const{return _iter;}
            reference operator*() const{
                Iterator tmp = _iter;    
                return *--tmp;
            }
            pointer operator->() const{return &(operator*());}
            reverse_iterator & operator++(){
                _iter--;
                return *this;
            }
            reverse_iterator operator++(int){
                reverse_iterator tmp = *this;
                _iter--;
                return tmp;
            }
            reverse_iterator & operator--(){
                _iter++;
                return *this;
            }
            reverse_iterator operator--(int){
                reverse_iterator tmp = *this;
                _iter++;
                return tmp;
            }
            reverse_iterator operator+ (difference_type n) const{return reverse_iterator(_iter - n);}
            reverse_iterator& operator+=(difference_type n){
                _iter -= n;
                return *this;
            }
            reverse_iterator operator- (difference_type n) const{return reverse_iterator(_iter + n);}
            reverse_iterator& operator-=(difference_type n){
                _iter += n;
                return *this;
            }
            reference operator[](difference_type n) const{return _iter[-n-1];}

    };
    template <class Iter1, class Iter2> 
    inline bool operator==(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return (lhs.base() == rhs.base());}
    
    template <class Iter1, class Iter2> 
    inline bool operator>(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return (lhs.base() < rhs.base());}
   
    template <class Iter1, class Iter2>  
    inline bool operator<(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return (lhs.base() > rhs.base());}

    template <class Iter1,class Iter2> 
    inline bool operator!=(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return !(lhs == rhs);}
    
    template <class Iter1,class Iter2> 
    inline bool operator<=(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return (lhs.base() >= rhs.base());}
    
    template <class Iter1,class Iter2> 
    inline bool operator>=(const reverse_iterator<Iter1>& lhs,
    const reverse_iterator<Iter2>& rhs){return (lhs.base() <= rhs.base());}

    template <class Iter1,class Iter2> 
    typename reverse_iterator<Iter1>::difference_type operator-(
    const reverse_iterator<Iter1>& rhs,const reverse_iterator<Iter2>& lhs)
    {return (lhs.base() - rhs.base());}

    template <class Iterator> reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& iter)
    {return reverse_iterator<Iterator>(iter.base() - n);}
}
#endif