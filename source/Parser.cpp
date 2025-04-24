#include <cctype>
#include <cstddef>
#include <string>

#include "Parser.hpp"

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
        // TODO(Ludo): implement case when it's not a valid escape sequence
        break;
    }

    return parsedEscape;
}

auto Parser::ParseArgument(const string& argument) -> string
{
    string parsedArg;
    next = 0;

    /* for (char character : argument)
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
            // FIXME : still prints last digits of an octal escape sequence
        }
    } */
    for (size_t i = 0; i < argument.size();)
    {
        next = i + 1;

        if (argument.at(i) != '\\')
        {
            parsedArg += argument.at(i);
            i++;
            next++;
        }

        if (argument.at(i) == '\\')
        {
            parsedArg += ParseEscapeCharacter(argument);

            if (argument.at(next) == '0')
            {
                i++;
                
                if (next + 1 <= argument.size() && (::isdigit(argument.at(next + 1)) != 0) && i <= argument.size())
                {
                    i++;
                }

                if (next + 2 <= argument.size() && (::isdigit(argument.at(next + 2)) != 0) && i <= argument.size())
                {
                    i++;
                }

                if (next + 3 <= argument.size() && (::isdigit(argument.at(next + 3)) != 0) && i <= argument.size())
                {
                    i++;
                }
            }
            else
            {
                i += 2;
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

    if (arg.at(0) == '\\' && arg.at(1) == '0' && arg.size() <= MAXSIZE)
    {
        arg.erase(0, 2);
        decimal     = stoi(arg, nullptr, OCTAL);
        parsedOctal = static_cast<char>(decimal);
    }
    else if (arg.at(0) == '\\' && arg.at(1) == '0' && arg.size() > MAXSIZE)
    {
        return arg;
    }

    return parsedOctal;
}
