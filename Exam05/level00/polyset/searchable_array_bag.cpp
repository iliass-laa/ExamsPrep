#include "searchable_array_bag.hpp"



searchable_array_bag::searchable_array_bag():array_bag(){}

searchable_array_bag::searchable_array_bag(searchable_array_bag const &src):array_bag(src){}

searchable_array_bag::~searchable_array_bag(){}



searchable_array_bag &searchable_array_bag::operator=(searchable_array_bag const &src){
    if (this != &src)
        array_bag::operator=(src);
    return *this;
}



bool  searchable_array_bag::has(int i)const
{
    int x = 0;
    
    while (x < this->size)
    {
        if (this->data[x] == i)
            return true;
        x++;
    }
    return false;
}