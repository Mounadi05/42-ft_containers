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
            random_access_iterator(){}
            explicit random_access_iterator(Iterator iter):_iter(iter){}
            
            template <class U> 
            random_access_iterator(const random_access_iterator<U>& u):_iter(const_cast<Iterator>(u.getIterator())) {}
            
   
            random_access_iterator &operator=(const random_access_iterator  & rai){
                if (this->_iter != rai._iter){this->_iter = rai._iter;}
                return *this;
            }
             Iterator getIterator() const {return _iter;}
            reference operator*() const{return *_iter;}
            pointer operator->() const{return &(operator*());}
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
            random_access_iterator operator+ (difference_type n) const{return random_access_iterator(_iter + n);}
            random_access_iterator& operator+=(difference_type n){
                _iter += n;
                return *this;
            }
            random_access_iterator operator- (difference_type n) const{return random_access_iterator(_iter  - n);}
            random_access_iterator& operator-=(difference_type n){
                _iter -= n;
                return *this;
            }
            reference operator[](difference_type n) const{return *(_iter+n);}
    };
    template <class Iter1, class Iter2> 
    inline bool operator==(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (lhs.getIterator() == rhs.getIterator());}
    
    template <class Iter1, class Iter2> 
    inline bool operator>(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (lhs.getIterator() > rhs.getIterator());}
   
    template <class Iter1, class Iter2> 
    inline bool operator<(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (rhs > lhs);}

    template <class Iter1, class Iter2> 
    inline bool operator!=(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (lhs.getIterator() != rhs.getIterator());}
    
    template <class Iter1, class Iter2> 
    inline bool operator<=(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (lhs.getIterator() <= rhs.getIterator());}
    
    template <class Iter1, class Iter2> 
    inline bool operator>=(const random_access_iterator<Iter1>& lhs,
    const random_access_iterator<Iter2>& rhs){return (lhs.getIterator() >= rhs.getIterator());}

    template <class Iter1, class Iter2> 
    typename random_access_iterator<Iter1>::difference_type operator-(
    const random_access_iterator<Iter1>& rhs,const random_access_iterator<Iter2>& lhs)
    {return (rhs.getIterator() - lhs.getIterator());}

    template <class Iterator> random_access_iterator<Iterator> operator+(
    typename random_access_iterator<Iterator>::difference_type n,const random_access_iterator<Iterator>& iter)
    {return random_access_iterator<Iterator>(n+iter.getIterator());}
}

#endif