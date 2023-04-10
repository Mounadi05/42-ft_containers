#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

template <class T1, class T2>
struct pair 
{
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair();
    pair(const T1& x, const T2& y):first(x),second(y){}
    template<class U, class V> 
    pair(const pair<U, V> &p):first(p.first),second(p.second){}
    template<class U, class V> 
    pair & operator=(const pair<U, V> &p)
    {
        if(this->first != p.first && this->second != p.second)
        {
            this->fisrt = p.first;
            this->second = p.second;
        }
        return *this;
    }
};
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first == rhs.first && lhs.second == rhs.second; 
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs == rhs); 
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return lhs.first < rhs.first || (rhs.first == lhs.first && lhs.second < rhs.second); 
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(rhs < lhs); 
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs <r hs); 
    }

}

#endif