#ifndef REVERSE_ITERATOR_H
# define REVERSE_ITERATOR_H

// # include "iterator.hpp"

namespace ft
{

template <typename Iter>
class reverse_iterator
{
    private:
        Iter _base_iter;
        Iter _rev_iter;

    public:
        reverse_iterator(Iter iter) :
        _base_iter(iter),
        _rev_iter(iter - 1)
        {};

        ~reverse_iterator(void);

    Iter base(void) const
    {
        return (this->_base_iter);
    }

    Iter operator* (void) const
    {
        return *(this->_rev_iter);
    };

    reverse_iterator operator+ (int val) const
    {
        reverse_iterator r(this->_base_iter - val);
        return r;
    };

    void operator++ (void)
    {
        this->_base_iter--;
        this->_rev_iter--;
    };

    void operator++ (int)
    {
        this->_base_iter--;
        this->_rev_iter--;
    };

    void operator+= (int val)
    {
        this->_base_iter -= val;
        this->_rev_iter -= val;
    };

    reverse_iterator operator- (int val) const
    {
        reverse_iterator r(this->_base_iter + val);
        return r;
    };

    void operator-- (void)
    {
        this->_base_iter++;
        this->_rev_iter++;
    };
    
    void operator-- (int)
    {
        this->_base_iter++;
        this->_rev_iter++;
    };

    void operator-= (int val)
    {
        this->_base_iterator += val;
        this->_rev_iter += val;
    };

    Iter *operator-> (void) const
    {
        return &(*this->_rev_iter);
    };

    Iter operator[] (int index)
    {
        return (this->_rev_iter - index);
    }

};

template <class Iterator>
bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    if (lhs->_rev_iterator == rhs->_rev_iterator)
        return true;
    return false;
};

template <class Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return !(lhs == rhs);
};

template <class Iterator>
bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return (lhs->_rev_iter > rhs->_rev_iter);
};

template <class Iterator>
bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return (lhs->_rev_iter >= rhs->_rev_iter);
};

template <class Iterator>
bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return (lhs->_rev_iter < rhs->_rev_iter);
};

template <class Iterator>
bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
    return (lhs->_rev_iter <= rhs->_rev_iter);
};

}

#endif