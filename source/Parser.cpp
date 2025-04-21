#include <cstddef>
#include <string>
#include <utility>

#include "../include/Parser.hpp"

using std::move;
using std::string;

Parser::Parser() = default;

auto Parser::ParseArgument(string argument) -> string
{
    string arg = move(argument);
    string parsedArg;
    int next     = 0;

    for (char character : arg)
    {
        next++;

        if (character == '\\')
        {
            switch (arg.at(next))
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
            default:
                break;
            }
        }
        else if (arg.front() != '\\')
        {
            parsedArg += character;
        }
    }

    return parsedArg;
}
