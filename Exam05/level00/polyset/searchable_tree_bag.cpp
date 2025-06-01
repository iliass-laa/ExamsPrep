#include "searchable_tree_bag.hpp"



searchable_tree_bag::searchable_tree_bag():tree_bag(){}

searchable_tree_bag::searchable_tree_bag(searchable_tree_bag const &src):tree_bag(src){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag &searchable_tree_bag::operator=(searchable_tree_bag const &src){
    if (&src != this)
        tree_bag::operator=(src);
	return *this;
}


bool searchable_tree_bag::has(int val)const{
    
    node *tmp = this->tree;
    while (tmp)
    {
        if (tmp->value == val)
            return true;
        if (tmp->value < val)
            tmp = tmp->r;
        else
            tmp = tmp->l;
    }
    return false;
}