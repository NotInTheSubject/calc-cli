#pragma once

#include <istream>
#include <string_view>

namespace calculator
{
    enum class Type
    {
        None,
        Scope,
        Number,
        Operation
    };

    enum class SpecificType
    {
        None,

        // Scopes
        OpenScope,
        CloseScope,

        // Number
        Number,

        // Operations
        Plus,
        Minus,
        Multiply,
        Divide,
        Exponentiation
    };

    class Unit
    {
    public:
        Type type;
        SpecificType specificType;
        std::string_view row;

        Unit(Type type, SpecificType specificType, std::string_view row)
            : type(type), specificType(specificType), row(row) {}
    };

    std::pair<Unit, std::string::iterator> parseUnit(std::string::iterator it, std::string::iterator endIt);
}
