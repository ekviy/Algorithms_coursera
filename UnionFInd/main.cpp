#include <iostream>
#include <memory>
#include "UF.hh"

int main() {
    std::cout << "Inside MAIN" << std::endl;

    unsigned n = 10;
    std::unique_ptr<UF> uf(new UF(n));

    std::cout << "Default Vector!" << std::endl;
    uf->printVector();

    std::cout << "Reading from file . . ." << std::endl;
    uf->fillVectorFromFile("test1.txt");

    std::cout << "Vector udated from file!" << std::endl;
    uf->printVector();
}