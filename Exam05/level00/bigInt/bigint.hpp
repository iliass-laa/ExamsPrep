#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <cmath>
#include <iostream>
class bigint
{
    public :
        std::string val;
        bigint();
        bigint(size_t nbr);
        bigint(bigint const &src);
        ~bigint();

        bigint &operator=(bigint const &src);
        int countLen(size_t lVal)const;
    
        bigint &operator+(bigint const &op);
        bigint &operator>>(size_t op);
        bigint &operator<<(size_t op);
        bool operator>(bigint const &op)const;
        bool operator<(bigint const &op)const;
        bool operator==(bigint const &op)const;
        bool operator!=(bigint const &op)const;
        bool operator<=(bigint const &op)const;
        bool operator>=(bigint const &op)const;


};  


#endif