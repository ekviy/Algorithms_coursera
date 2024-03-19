#ifndef UF_HH
#define UF_HH

#include <vector>
#include <iostream>
#include <cstdlib> // for rand
#include <fstream>
#include <sstream>

class UF {
private:
    std::unique_ptr<std::vector<unsigned>> vec_;
    unsigned size_;

    void generateRandomVector(unsigned n) {
        for (unsigned i = 0; i < n; i++) {
            unsigned random = static_cast<unsigned>(rand());
            vec_->push_back(random);
        }
    }
public:
    UF(unsigned n): vec_(std::make_unique<std::vector<unsigned>>()), size_(n) {
        // generateRandomVector(n);
        for (unsigned i = 0; i < size_; i++) {
            vec_->push_back(i);
        }
    }

    bool connected(unsigned int p, unsigned int q) {
        return vec_->at(p) == vec_->at(q);
    }

    void printVector() const {
        int i = 0;
        for (const auto& elem : *vec_) {
            std::cout << i << " : " << elem << std::endl;
            i++;
        }
    }

    void union_two_elem(const unsigned int p, const unsigned int q) {
        unsigned pid = vec_->at(p);
        unsigned qid = vec_->at(q);
        for (unsigned i = 0; i < size_; i++) {
            if (vec_->at(i) == pid) {
                vec_->at(i) = qid;
            }
        }
    }

    void fillVectorFromFile(std::string filename) {
        std::ifstream file(filename);
        
        std::string line;
        std::getline(file, line);
        size_ = std::stoul(line);

        unsigned p, q;
        while(std::getline(file, line)) {
            std::istringstream iss(line);
            if (iss >> p >> q) {
                union_two_elem(p, q);
            }
            else {
                std::cerr << "Line does not have view \"n1 n2\"";
            }
        }
        file.close();
    }

    ~UF() {};
};

#endif // UF_HH