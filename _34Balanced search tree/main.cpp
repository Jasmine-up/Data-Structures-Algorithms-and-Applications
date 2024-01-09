#include <iostream>
#include "AVLTree.h"
#include <map>

int main() {
//    AVLTreeTest();
    std::map<std::string, size_t> people {{ "Fred", 45}, {"Joan", 33},{"Jill", 22}};
    std::string name{"Joan"};
    if(people.erase(name))
        std::cout << name << " was removed." << std::endl;
    else
        std::cout << name << " was not found" << std::endl;
    return 0;
}
