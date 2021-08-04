#include <iostream>
#include <vector>

using Value = double;

class Operation {
    public:
        virtual Value getValue() = 0;
};

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
