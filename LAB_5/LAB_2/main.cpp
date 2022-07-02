#include <iostream>
#include "tree.hpp"

int main()
{
    Tree<int> tree;
    tree.insert(5);
    
    tree.Print();
    return 0;
}
