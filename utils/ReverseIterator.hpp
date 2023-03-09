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
            explicit reverse_iterator(Iterator iter)_iter(iter){}
            Iterator getIterator() const{return _iter}
            reference operator*() const{return *_iter}
            pointer operator->() const{return &(operator*())}
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
            reverse_iterator operator- (difference_type n) const{return reverse_iterator(_iter + n)}
            reverse_iterator& operator-=(difference_type n){
                _iter += n;
                return *this;
            }
            reference operator[](difference_type n) const{return *(-n-1);}

    };
    template <class Iterator> inline bool operator==(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return (lhs.getIterator() == rhs.getIterator())}
    
    template <class Iterator> inline bool operator>(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return (lhs.getIterator() < rhs.getIterator())}
   
    template <class Iterator> inline bool operator<(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return (lhs.getIterator() > rhs.getIterator())}

    template <class Iterator> inline bool operator!=(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return !(lhs == rhs)}
    
    template <class Iterator> inline bool operator<=(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return (rhs > lhs)}
    
    template <class Iterator> inline bool operator>=(const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs){return (rhs < lhs)}

    template <class Iterator> typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator>& rhs,const reverse_iterator<Iterator>& lhs)
    {return (lhs._iter - rhs.iter)}

    template <class Iterator> reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& iter)
    {return reverse_iterator<Iterator>(iter.getIterator() - n)}
}
#endif