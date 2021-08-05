#include "parsing.hpp"

using namespace calculator;

bool isNumber(char c) noexcept;
bool isOperator(char c) noexcept;
bool isScope(char c) noexcept;

std::pair<Unit, std::string::iterator> calculator::parseUnit(std::string::iterator it, std::string::iterator endIt)
{
    using namespace std::string_literals;

    while (it != endIt && *it != ' ')
        ++it;

    if (it == endIt)
        return {Unit(Type::None, SpecificType::None, ""s), it};

    auto c = *it;
    auto unit = Unit(Type::None, SpecificType::None, ""s);

    if (c == '*')
        unit = Unit(Type::Operation, SpecificType::Multiply, "*"s);
    
    return {unit, ++it};
}
