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
            Iterator getIterator() {return _iter}
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
            random_access_iterator operator+ (difference_type n) const{return random_access_iterator(_iter + n);}
            random_access_iterator& operator+=(difference_type n){
                _iter += n;
                return *this;
            }
            random_access_iterator operator- (difference_type n) const{return random_access_iterator(_iter  - n)}
            random_access_iterator& operator-=(difference_type n){
                _iter -= n;
                return *this;
            }
            reference operator[](difference_type n) const{return *(_iter+n);}
    };
    template <class Iterator> inline bool operator==(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return (lhs.getIterator() == rhs.getIterator())}
    
    template <class Iterator> inline bool operator>(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return (lhs.getIterator() > rhs.getIterator())}
   
    template <class Iterator> inline bool operator<(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return (rhs > lhs)}

    template <class Iterator> inline bool operator!=(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return !(lhs == rhs)}
    
    template <class Iterator> inline bool operator<=(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return !(rhs < lhs)}
    
    template <class Iterator> inline bool operator>=(const random_access_iterator<Iterator>& lhs,
    const random_access_iterator<Iterator>& rhs){return !(rhs > lhs)}

    template <class Iterator> typename random_access_iterator<Iterator>::difference_type operator-(
    const random_access_iterator<Iterator>& rhs,const random_access_iterator<Iterator>& lhs)
    {return (rhs._iter - lhs.iter)}

    template <class Iterator> random_access_iterator<Iterator> operator+(
    typename random_access_iterator<Iterator>::difference_type n,const random_access_iterator<Iterator>& iter)
    {return random_access_iterato<Iterator>(n+iter.getIterator())}
}

#endif