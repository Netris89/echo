#pragma Once;

#include <string>

class Parser
{
private:
    /**
     * @brief Parses a string representing an octal number and returns the corresponding ASCII character.
     *
     * This method takes a string that starts with a prefix (e.g., "0o" or similar), removes the prefix,
     * converts the remaining part from octal to decimal, and returns the corresponding ASCII character as a string.
     *
     * @param argument A string containing an octal number prefixed (e.g., "0o101").
     * @return A string containing the ASCII character corresponding to the octal value.
     *
     * @note The input string must be properly formatted; otherwise, this method may throw an exception.
     */
    auto static ParseOctal(std::string) -> std::string;

public:
    Parser();

    /**
     * @brief Parses a command-line argument string and interprets escape sequences.
     *
     * This function processes a string argument and converts any valid escape sequences
     * (e.g., `\\n`, `\\t`, `\\0xx`) into their corresponding character representations.
     * It supports both standard escape sequences (like newline, tab, etc.) and octal escape
     * sequences starting with `\\0` followed by up to three octal digits.
     *
     * @param argument The input argument string potentially containing escape sequences.
     * @return std::string The parsed string with escape sequences interpreted.
     *
     * @details
     * Supported escape sequences include:
     * - `\a` : Alert (bell)
     * - `\b` : Backspace
     * - `\f` : Form feed
     * - `\n` : Newline
     * - `\r` : Carriage return
     * - `\t` : Horizontal tab
     * - `\v` : Vertical tab
     * - `\\` : Literal backslash
     * - `\0nnn` : Octal escape sequence (e.g., `\\012` = newline)
     *
     * The function loops through the input string and detects backslashes (`\\`),
     * then determines the corresponding escape sequence. For octal escapes, it reads
     * up to three octal digits and converts the result to a character.
     *
     * Invalid or incomplete escape sequences are ignored or passed through as-is.
     *
     * @note
     * This implementation assumes the argument string is already formatted such that
     * double backslashes (`\\`) represent a literal backslash in the input.
     *
     * @see https://en.cppreference.com/w/cpp/language/escape for a list of standard escape sequences.
     */
    auto static ParseArgument(std::string) -> std::string;
};