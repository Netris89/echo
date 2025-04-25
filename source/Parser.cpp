#include <cctype>
#include <cstddef>
#include <string>

#include "Parser.hpp"

using std::stoi;
using std::string;

Parser::Parser() = default;

auto Parser::ParseEscapeCharacter(const string& argument, size_t counter) -> string
{
    string parsedEscape;

    switch (argument.at(counter + 1))
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
        parsedEscape += ParseOctal(argument, counter);
        break;
    default:
        parsedEscape += argument.at(counter);
        parsedEscape += argument.at(counter + 1);
        break;
    }

    return parsedEscape;
}

auto Parser::ParseArgument(const string& argument) -> string
{
    string parsedArg;

    for (size_t i = 0; i < argument.size(); i++)
    {
        if (argument.at(i) != '\\')
        {
            parsedArg += argument.at(i);
        }
        else
        {
            parsedArg += ParseEscapeCharacter(argument, i);

            if (argument.at(i + 1) == '0')
            {
                for (size_t j = i + 2; j < argument.size() && ::isdigit(argument.at(j)) != 0; j++)
                {
                    if (::isdigit(argument.at(j)) == 0)
                    {
                        break;
                    }

                    i++;
                }

                i++;
            }
            else
            {
                i++;
            }
        }
    }

    return parsedArg;
}

auto Parser::ParseOctal(const string& argument, size_t counter) -> string
{
    int decimal        = 0;
    int backslashIndex = 0;
    string arg;
    string parsedOctal;

    for (size_t i = counter; i < argument.size(); i++)
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
