#include <cctype>
#include <cstddef>
#include <string>

#include "Parser.hpp"

using std::stoi;
using std::string;

Parser::Parser() = default;

auto Parser::ParseOctal(const string& argument, size_t position) -> string
{
    int decimal        = 0; // Decimal value converted from octal
    int backslashIndex = 0; // Position of the \\ in the escape sequence
    string octalSeq;        // Extracted octal escape sequence
    string asciiChar;       // Resulting ASCII character from octal conversion

    // Loops through the whole argument to find where the octal escape sequence is and put it whole in a variable
    for (size_t i = position; i < argument.size(); i++)
    {
        if (argument.at(i) == '\\' || argument.at(i) == '0' || ::isdigit(argument.at(i)) != 0)
        {
            octalSeq += argument.at(i);
        }
    }

    // Checks if the escape sequence actually is octal. If not, returns it as is
    if ((octalSeq.at(2) - '0') > OCTAL || 3 < octalSeq.size() && (octalSeq.at(3) - '0') > OCTAL || 4 < octalSeq.size() && (octalSeq.at(4) - '0') > OCTAL)
    {
        return octalSeq;
    }

    // If the octal sequence length is at most 3 digits, convert it to ASCII; otherwise, return the sequence unchanged
    if (octalSeq.size() <= MAXSIZE)
    {
        octalSeq.erase(0, 2);
        decimal   = stoi(octalSeq, nullptr, OCTAL);
        asciiChar = static_cast<char>(decimal);
    }
    else if (octalSeq.size() > MAXSIZE)
    {
        return octalSeq;
    }

    return asciiChar;
}

auto Parser::ParseEscapeCharacter(const string& argument, size_t position) -> string
{
    string parsedEscape; // Result escape sequence after being parse

    switch (argument.at(position + 1))
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
        parsedEscape += ParseOctal(argument, position);
        break;
    default:
        parsedEscape += argument.at(position);
        parsedEscape += argument.at(position + 1);
        break;
    }

    return parsedEscape;
}

auto Parser::ParseArgument(const string& argument) -> string
{
    string parsedArg; // Parsed argument being constructed

    for (size_t i = 0; i < argument.size(); i++)
    {
        // If the current character is not \\, just adds it to the output string being constructed
        if (argument.at(i) != '\\')
        {
            parsedArg += argument.at(i);
            continue;
        }

        // If the current character is not \\ and is not the last character, parse it
        if (argument.at(i) != '\\' && argument.back() != '\\')
        {
            parsedArg += ParseEscapeCharacter(argument, i);

            // If the next character is 0, it is an octal sequence and we need to advance the position counter of the size of the sequence
            if (argument.at(i + 1) == '0')
            {
                size_t position = i + 2;

                while (position < argument.size() && ::isdigit(argument.at(position)) != 0)
                {
                    if (::isdigit(argument.at(position)) == 0)
                    {
                        break;
                    }

                    i++;
                    position++;
                }

                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            parsedArg += "\\";
        }
    }

    return parsedArg;
}
