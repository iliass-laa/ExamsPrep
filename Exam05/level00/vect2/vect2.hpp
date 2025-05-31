#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
    int v1, v2;
    public :
        vect2();
        vect2(int v1, int v2);
        vect2(vect2 const &vect);
        ~vect2();
        
        int operator[](int const index)const;
        int &operator[](int const index);
        
        vect2 &operator=(vect2 const &src);

        vect2 operator*(int scalar)const;
        vect2 operator+(vect2 const &op)const;
        vect2 operator-(vect2 const &op)const;
        vect2 &operator*=(int scalar);
        vect2 operator+=(vect2 const &op);
        vect2 operator-=(vect2 const &op);
        vect2 operator--();
        vect2 operator++();
        vect2 operator--(int);
        vect2 operator++(int);
        bool operator==(vect2 const &op)const;
        bool operator!=(vect2 const &op)const;
        vect2 operator-();
};



vect2 operator*(int x, vect2 const);

std::ostream &operator<<(std::ostream &obj,vect2 const &src);

#endif