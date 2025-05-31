#include "bigint.hpp"

bigint::bigint(){}

bigint::~bigint(){}


bigint::bigint(bigint const &src){
    *this = src; 
}

bigint::bigint(size_t lVal){
    int len = countLen(lVal);
    char s;
    int nbr;
    size_t factor;
    for(int i = 1; i < len ; len--)
    {
        factor = std::pow(10, len - 1);
        nbr =  (lVal / factor);
        lVal -= (nbr * factor);
        s = nbr + 48;
        val += s;
    }
    s = lVal + 48;
    val += s;
}

bigint &bigint::operator=(bigint const &src)
{
    this->val = src.val;
    return *this;
}

int bigint::countLen(size_t lVal)const
{   
    int res = 1;
    while (lVal >= 10)
    {
        lVal /= 10;
        res ++;
    }
    return res;
}   



bigint &bigint::operator+(bigint const &op)
{
    int opLen, valLen,  resLen;
    std::string res;
    int left, nbr;

    nbr = 0;
    left = 0;
    opLen = op.val.length();
    valLen = val.length();
    resLen = valLen + 1;
    if (valLen < opLen)
        resLen = opLen +1;
    res.resize(resLen);
    opLen--;
    valLen--;
    resLen--;
    while (opLen >= 0)
    {
        if (valLen >=0)
        {
            nbr = (val.at(valLen) - 48) + (op.val.at(opLen) - 48) + left;
            left = 0;
            if (nbr > 10)
            {
                left = nbr / 10;
                nbr  %= 10;
            }
            res.at(resLen) = nbr + 48;
        }
        else
        {
            nbr =(op.val.at(opLen) - 48) + left;
            left = 0;
            res.at(resLen) = nbr +48;
        }
        opLen--;
        valLen--;
        resLen --;
    }
    while (valLen >= 0)
    {
        nbr = (val.at(opLen) - 48) + left;
        left = 0;
        res.at(resLen) = nbr + 48;
        valLen --;
        resLen--;
    }
    if (left)
    {
        res.at(resLen) = left + 48;
        left = 0;
    }
    val = res;
    return *this;
}

// 1542 >> 3 = 1

bigint &bigint::operator>>(size_t op)
{
    if (op > val.length())
        return *this;
    val.resize(val.length() - op);
    return *this;
}


bigint &bigint::operator<<(size_t op)
{
    size_t oldS = val.length();
    val.resize(op + oldS);
    while (op + oldS > oldS)
    {
        val.at((op + oldS) - 1) = '0';
        op --;
    }
    return *this;
}


bool bigint::operator<(bigint const &op)const{
    if (val.length() < op.val.length())
        return true;
    if (val.length() > op.val.length())  
        return false;
    size_t i = 0;
    while (i < val.length())
    {
        if (val[i] > op.val[i])
            return false;
        i++;
    }
    return true;
}