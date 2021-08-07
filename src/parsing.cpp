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
        return {Unit(Type::None, SpecificType::None, nullptr), it};

    auto unit = Unit(Type::None, SpecificType::None, nullptr);

    if (*it == '*')
        return {Unit(Type::Operation, SpecificType::Multiply, std::string_view(&*it, 1)), ++it};

    if (*it == '/')
        return {Unit(Type::Operation, SpecificType::Divide, std::string_view(&*it, 1)), ++it};

    if (*it == '+')
        return {Unit(Type::Operation, SpecificType::Plus, std::string_view(&*it, 1)), ++it};

    if (*it == '-')
        return {Unit(Type::Operation, SpecificType::Minus, std::string_view(&*it, 1)), ++it};

    if (*it == '(')
        return {Unit(Type::Scope, SpecificType::OpenScope, std::string_view(&*it, 1)), ++it};

    if (*it == ')')
        return {Unit(Type::Scope, SpecificType::CloseScope, std::string_view(&*it, 1)), ++it};

    auto from = it;
    for (unsigned dotsCount = 0; (*it >= '0' && *it <= '9') || (*it == '.' && ++dotsCount);)
        ++it;

    // MAKES RETRNS STATEMANTS

    return {unit, ++it};
}
