#include <cstddef>
#include <string>

#include "Parser.hpp"

#define OCTAL 8

using std::stoi;
using std::string;

Parser::Parser() : next(0) {};

auto Parser::ParseEscapeCharacter(const string& argument) const -> string
{
    string parsedArg;

    switch (argument.at(next))
    {
    case 'a':
        parsedArg += '\a';
        break;
    case 'b':
        parsedArg += '\b';
        break;
    case 'f':
        parsedArg += '\f';
        break;
    case 'n':
        parsedArg += '\n';
        break;
    case 'r':
        parsedArg += '\r';
        break;
    case 't':
        parsedArg += '\t';
        break;
    case 'v':
        parsedArg += '\v';
        break;
    case '\\':
        parsedArg += '\\';
        break;
    case '0':
        parsedArg += ParseOctal(argument);
    default:
        break;
    }

    return parsedArg;
}

auto Parser::ParseArgument(const string& argument) -> string
{
    string parsedArg;
    next = 0;

    for (char character : argument)
    {
        next++;

        if (character == '\\')
        {
            parsedArg = ParseEscapeCharacter(argument);
        }
        else if (argument.front() != '\\')
        {
            parsedArg += character;
        }
    }

    return parsedArg;
}

auto Parser::ParseOctal(const string& argument) -> string
{
    string arg = argument;
    string parsedArg;
    int decimal = 0;

    arg.erase(0, 2);

    decimal   = stoi(arg, nullptr, OCTAL);
    parsedArg = static_cast<char>(decimal);

    return parsedArg;
}
