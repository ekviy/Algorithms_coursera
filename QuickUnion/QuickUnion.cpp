#include "QuickUnion.hh"
#include <memory>
#include <iostream>

namespace quick_union {

    QuickUnion::QuickUnion(unsigned n) :
        vec_(std::make_unique<std::vector<unsigned>>()),
        subtrees_size_(std::make_unique<std::vector<unsigned>>(10, 0)),
        size_(n)
    {
        for (unsigned i = 0; i < n; i++) {
            vec_->push_back(i);
        }
    }

    void QuickUnion::printVector() const {
        for (unsigned i = 0; i < size_; i++) {
            std::cout << i << " : " << vec_->at(i) << std::endl;
        }
    }

    unsigned QuickUnion::getRoot(unsigned i) const {
        while (i != vec_->at(i)) {
            vec_->at(i) = vec_->at(vec_->at(i));
            i = vec_->at(i);
        }

        return i;
    }

    bool QuickUnion::connected(unsigned p, unsigned q) const {
        return getRoot(p) == getRoot(q);
    }

    void QuickUnion::union_two_elems(unsigned p, unsigned q) {
        unsigned i = getRoot(p);
        unsigned j = getRoot(q);

        // improvement to join smaller subtree to larger one
        if (i == j) return;
        if (subtrees_size_->at(i) < subtrees_size_->at(j)) {
            vec_->at(i) = j;
            subtrees_size_->at(j) += subtrees_size_->at(i);
        }
        else {
            vec_->at(j) = i;
            subtrees_size_->at(i) += subtrees_size_->at(j);
        }
    }

    void QuickUnion::fillVectorFromFile(std::string filename) {
        std::ifstream file(filename);
        
        std::string line;
        std::getline(file, line);
        size_ = std::stoul(line);

        unsigned p, q;
        while(std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> p >> q) {
                union_two_elems(p, q);
            }
            else {
                std::cerr << "Line does not have view \"n1 n2\"";
            }
        }
        file.close();
    }
}