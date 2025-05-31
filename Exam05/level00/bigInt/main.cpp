#include "bigint.hpp"
#include <iostream>

#include <stddef.h>
#include <limits.h>
#include <stdint.h>
int main()
{
    // bigint A(15);
    // A<<02;
    // std::cout << A.val << std::endl;
    
    std::cout << sizeof(size_t) << std::endl;
    std::cout << sizeof(long long) << std::endl;
    std::cout << LLONG_MAX << std::endl;
    std::cout << LONG_MAX << std::endl;
    std::cout << ULONG_MAX << std::endl;
    std::cout << ULLONG_MAX << std::endl;
    std::cout << SIZE_MAX << std::endl;

    // bigint B(100007);
    // bigint C;
    // std::cout << B.val<< std::endl;
    // std::cout << " + "<< std::endl;
    // std::cout << A.val<< std::endl;
    // std::cout << " || "<< std::endl;    

    // try {

    //     C = A+B;
    //     std::cout << C.val << std::endl;
    // }
    // catch(std::exception &e)
    // {   
    //     std::cout << e.what()<< std::endl;
    // }

}