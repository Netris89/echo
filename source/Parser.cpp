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
    int previous = 0;

    for (char character : arg)
    {
        next++;
        previous = next - 2;

        if (character == '\\')
        {
            switch (arg.at(next))
            {
            case 'a':
                parsedArg += '\a';
                // next++;
                break;
            case 'b':
                parsedArg += '\b';
                // next++;
                break;
            case 'f':
                parsedArg += '\f';
                // next++;
                break;
            case 'n':
                parsedArg += '\n';
                // next++;
                break;
            case 'r':
                parsedArg += '\r';
                // next++;
                break;
            case 't':
                parsedArg += '\t';
                // next++;
                break;
            case 'v':
                parsedArg += '\v';
                // next++;
                break;
            case '\\':
                parsedArg += '\\';
                // next++;
                break;
            default:
                // next++;
                break;
            }
        }
        else if (arg.at(previous) != '\\')
        {
            parsedArg += character;
        }
    }

    return parsedArg;
}
