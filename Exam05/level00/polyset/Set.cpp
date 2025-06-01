#include <iostream>
#include <set>


int main()
{
    std::set<int, float> v;
    std::set<int, float> ::iterator it;

    int i = 78;
    int &ref = i;
    int &ref2 = ref;
    std::cout << ">>"<< ref2 << std::endl;
    v.insert(0);
    it = v.begin();
    std::cout << "v at 0 :" << it._M_node << std::endl;
}