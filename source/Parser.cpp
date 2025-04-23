#include <cctype>
#include <cstddef>
#include <string>

#include "Parser.hpp"

#define OCTAL 8

using std::stoi;
using std::string;

Parser::Parser() : next(0) {};

auto Parser::ParseEscapeCharacter(const string& argument) const -> string
{
    string parsedEscape;

    switch (argument.at(next))
    {
    case 'a':
        parsedEscape += '\a';
        break;
    case 'b':
        parsedEscape += '\b';
        break;
    case 'f':
        parsedEscape += '\f';
        break;
    case 'n':
        parsedEscape += '\n';
        break;
    case 'r':
        parsedEscape += '\r';
        break;
    case 't':
        parsedEscape += '\t';
        break;
    case 'v':
        parsedEscape += '\v';
        break;
    case '\\':
        parsedEscape += '\\';
        break;
    case '0':
        parsedEscape += ParseOctal(argument);
        break;
    default:
        break;
    }

    return parsedEscape;
}

auto Parser::ParseArgument(const string& argument) -> string
{
    string parsedArg;
    next = 0;

    for (char character : argument)
    {
        next++;
        int previous = next - 2;

        if (character == '\\')
        {
            parsedArg += ParseEscapeCharacter(argument);
        }
        else if (argument.front() != '\\')
        {
            if (previous < 0 || argument.at(previous) != '\\')
            {
                parsedArg += character;
            }
        }
    }

    return parsedArg;
}

auto Parser::ParseOctal(const string& argument) -> string
{
    int backslashIndex = 0;
    string arg;
    string parsedOctal;
    int decimal = 0;

    for (int i = 0; i < argument.size(); i++)
    {
        if (argument.at(i) == '\\' && argument.at(i + 1) == '0')
        {
            backslashIndex = i;
            break;
        }
    }

    for (int i = backslashIndex; i < argument.size(); i++)
    {
        if (argument.at(i) == '\\' || argument.at(i) == '0' || ::isdigit(argument.at(i)) != 0)
        {
            arg += argument.at(i);
        }
    }

    if (arg.at(0) == '\\' && arg.at(1) == '0' && arg.size() <= 4)
    {
        arg.erase(0, 2);
        decimal     = stoi(arg, nullptr, OCTAL);
        parsedOctal = static_cast<char>(decimal);
    }
    else if (arg.at(0) == '\\' && arg.at(1) == '0' && arg.size() > 4)
    {
        return "\\0";
    }

    return parsedOctal;
}
