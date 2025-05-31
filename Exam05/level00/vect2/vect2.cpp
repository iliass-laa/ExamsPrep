#include "vect2.hpp"


vect2::vect2():v1(0), v2(0){}

vect2::vect2(int V1, int V2):v1(V1), v2(V2){}

vect2::vect2(vect2 const &src)
{
    *this = src;
}

vect2::~vect2()
{}

vect2 &vect2::operator=(vect2 const &src)
{
    v1 = src.v1;
    v2 = src.v2;
    return *this;
}

int &vect2::operator[](int const index){
    if (index == 0)
        return v1;
    return v2;
}

int vect2::operator[](int const index)const{
    if (index == 0)
        return v1;
    if (index == 1)
        return v2;
    return 0;
}
vect2 vect2::operator+(vect2 const &op)const
{
    return (vect2(v1+ op[0], v2 + op[1]));   
}

vect2 vect2::operator-(vect2 const &op)const
{
    return (vect2(v1- op[0], v2 - op[1]));   
}

vect2 vect2::operator*(int scalar)const{
    return (vect2(v1*scalar,v2*scalar ));
}

std::ostream &operator<<(std::ostream &obj,vect2 const &src)
{
    obj<<"{"<<src[0] << ", "<< src[1]<< "}" << std::endl;
    return obj;
}

vect2 operator*(int x, vect2 const v)
{
    return (v * x);
}

vect2 vect2::operator+=(vect2 const &op)
{
    v1 += op[0];
    v2 += op[1];
    return *this;
}

vect2 vect2::operator-=(vect2 const &op)
{
    v1 -= op[0];
    v2 -= op[1];
    return *this;
}

vect2 &vect2::operator*=(int scalar)
{
    v1 *= scalar;
    v2 *=  scalar;
    return *this;
}


vect2 vect2::operator--()
{
    v1--;
    v2--;
    return (*this);
}

vect2 vect2::operator++()
{
    v1++;
    v2++;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    v1++;
    v2++;
    return (*this);
}

vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    v1--;
    v2--;
    return (*this);
}

bool vect2::operator==(vect2 const &op)const
{
    return (v1 == op[0] && v2 == op[1]);
}

bool vect2::operator!=(vect2 const &op)const
{
    return (v1 != op[0] && v2 != op[1]);
}


vect2 vect2::operator-()
{
    v1 *= -1;
    v2 *= -1;
    return (*this);
}