#include "set.hpp"


set::~set()
{
    bag.clear();
}

void set::insert(int i)
{
    if (!bag.has(i))
        bag.insert(i);
}

void set::insert(int *arr, int i){
    if (!bag.has(i))
        bag.insert(arr, i);
}

bool set::has(int i){
    return(bag.has(i));
}

void set::clear()
{
    bag.clear();
}

void set::print(){
    bag.print();
}

searchable_bag &set::get_bag()
{
    return bag;
}
