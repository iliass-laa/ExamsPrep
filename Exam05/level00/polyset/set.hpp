#pragma once

#include "searchable_bag.hpp"

class set
{
    searchable_bag &bag;
    public :
        set(searchable_bag &src):bag(src){};
        ~set();

        void insert(int);
        void insert(int * , int);
        bool has(int);
        void print();
        void clear();

        searchable_bag &get_bag();

        
};