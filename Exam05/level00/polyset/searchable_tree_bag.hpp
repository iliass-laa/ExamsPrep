#pragma once
#include "tree_bag.hpp"

class searchable_tree_bag : public tree_bag , public searchable_bag
{
    public :
        searchable_tree_bag();
        searchable_tree_bag(searchable_tree_bag const &src);
        ~searchable_tree_bag();

        searchable_tree_bag &operator=(searchable_tree_bag const &src);


        bool has(int)const;

};