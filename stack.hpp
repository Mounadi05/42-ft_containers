#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
 namespace ft{
template <class T, class Container = ft::vector<T> >
class stack {
    protected:
            Container c;
    public:
        typedef typename Container::reference               reference;
        typedef typename Container::const_reference         const_reference;
        typedef typename Container::value_type              value_type;
        typedef typename Container::size_type               size_type;
        typedef Container                                   container_type;
        
        explicit stack(const Container& C = Container()):c(C){};
        stack& operator=(const stack& S){c = S.c; return *this;}
        bool empty() const { return c.empty(); }
        size_type size() const { return c.size(); }
        value_type& top() { return c.back(); }
        const value_type& top() const { return c.back(); }
        void push(const value_type& x) { c.push_back(x); }
        void pop() { c.pop_back();}

        friend bool operator==(const stack<T, Container>& x,const stack<T, Container>& y) {return (x.c == y.c);}
        friend bool operator< (const stack<T, Container>& x,const stack<T, Container>& y){return (x.c < y.c);}
        friend bool operator!=(const stack<T, Container>& x,const stack<T, Container>& y) {return (x.c != y.c);}
        friend bool operator> (const stack<T, Container>& x,const stack<T, Container>& y) {return (x.c > y.c);}
        friend bool operator>=(const stack<T, Container>& x,const stack<T, Container>& y) {return (x.c >= y.c);}
        friend bool operator<=(const stack<T, Container>& x,const stack<T, Container>& y) {return (x.c <= y.c);}
};

}
#endif