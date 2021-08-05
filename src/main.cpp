#include <iostream>
#include <iterator>
#include <vector>

using Value = double;
using input_iterator = std::istream_iterator<char>;

class Operation
{
public:
    virtual Value getValue() = 0;
};

// input_iterator clear_spaces

std::pair<Value, input_iterator> parseValue(input_iterator it, input_iterator endIt)
{
    // auto 
}

int main(int, char **)
{
    double d = .01;
    std::cout << "Hello, world!\n" << d << std::endl;
}
