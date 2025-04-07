#include <cstddef>
#include <string>
#include <utility>

#include "../include/Parser.hpp"

using std::string;
using std::move;

Parser::Parser()
{
}

auto Parser::ParseArgument(string argument) -> string
{
    /*
     * To implement parsing of escape sequences in command-line arguments, follow these steps:
     *
     * 4. **Handle multi-character escape sequences**:
     *    - For sequences like `\0num`, handle up to three digits after `\0` and convert them as an octal number.
     *    - Convert the octal value to a character using `static_cast<char>`.
     *
     * 5. **Store the converted result**:
     *    - Once you’ve parsed the escape sequence, add the corresponding character (e.g., `\n`, `\t`) to a result string or handle it as needed.
     *
     * 6. **Edge cases**:
     *    - Handle situations where the input might not be a valid escape sequence (e.g., `\x` or invalid octal values).
     *    - If the escape sequence is incomplete (like `\0` with no digits following it), decide how you want to handle it (either leave it as-is or treat it as a literal backslash).
     *
     * 7. **Return the parsed string**:
     *    - Once all escape sequences are handled, return the parsed string with actual characters replacing the escape sequences.
     *
     * Example of how the parser should behave:
     * - Input: `\\n`, Output: `\n` (newline)
     * - Input: `\\0a`, Output: `\n` (octal `0a` = newline)
     * - Input: `\\123`, Output: `'S'` (octal `123` = character 'S')
     */
    string arg = move(argument);
    string parsedArg;
    int iterator = 0;

    /*
     * 1. **Loop through the input string**:
     *    - Traverse each character of the input string (command-line argument) one by one.
     */
    for (char character : arg)
    {
        /*
         * 2. **Detect escape sequences**:
         *    - Whenever you encounter a backslash (`'\\'`), check the next character to determine if it's part of an escape sequence.
         *    - If the next character forms a valid escape sequence (e.g., `n`, `t`, `b`, `0` followed by digits), perform the corresponding action to convert it.
         */
        if (character == '\\')
        {
            /*
             * 3. **Handle escape sequences**:
             *    - **Standard escape sequences**:
             *      - `\a` → Alert (bell)
             *      - `\b` → Backspace
             *      - `\f` → Form feed
             *      - `\n` → Newline
             *      - `\r` → Carriage return
             *      - `\t` → Tab
             *      - `\v` → Vertical tab
             *      - `\\` → Backslash (it’s just a backslash)
             */
            switch (arg.at(iterator + 1))
            {
            case 'a':
                parsedArg += '\a';
                iterator++;
                break;
            case 'b':
                parsedArg += '\b';
                iterator++;
                break;
            case 'f':
                parsedArg += '\f';
                iterator++;
                break;
            case 'n':
                parsedArg += '\n';
                iterator++;
                break;
            case 'r':
                parsedArg += '\r';
                iterator++;
                break;
            case 't':
                parsedArg += '\t';
                iterator++;
                break;
            case 'v':
                parsedArg += '\v';
                iterator++;
                break;
            case '\\':
                parsedArg += '\\';
                iterator++;
                break;
                /*     *    - **Octal escape sequences** (`\0num`):
                 *      - If the sequence starts with `\0`, interpret the following digits as an octal value (up to 3 digits, from `000` to `377`).
                 *      - Convert the octal value into its corresponding byte (e.g., `\012` becomes `'\n'`, `\123` becomes `'S'`).
                 */
            default:
                iterator++;
                break;
            }
        }
        else
        {
            return arg;
        }
    }

    return parsedArg;
}