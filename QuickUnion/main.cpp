#include <iostream>
#include <memory>
#include "QuickUnion.hh"



int main() {
    using namespace quick_union;

    std::cout << "Inside MAIN" << std::endl;

    unsigned n = 10;
    std::unique_ptr<QuickUnion> qu(new QuickUnion(n));
    
    std::cout << "Default Vector!" << std::endl;
    qu->printVector();

    std::cout << "Reading from file . . ." << std::endl;
    qu->fillVectorFromFile("../UnionFind/test1.txt");

    std::cout << "Vector udated from file!" << std::endl;
    qu->printVector();
}