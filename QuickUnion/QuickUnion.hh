
#ifndef QUICKUNION_HH
#define QUICKUNION_HH

#include <memory>
#include <vector>
#include <fstream>
#include <sstream>

namespace quick_union {

    class QuickUnion {
    private: 
        std::unique_ptr< std::vector<unsigned> > vec_;
        std::unique_ptr< std::vector<unsigned> > subtrees_size_;
        unsigned size_;
    public:
        QuickUnion(unsigned n);
        ~QuickUnion() {};

        void printVector() const;

        unsigned getRoot(unsigned i) const;

        bool connected(unsigned i, unsigned q) const;

        void union_two_elems(unsigned i, unsigned q);

        void fillVectorFromFile(std::string filename);
    };
}

#endif // QUICKUNION_HH