/*
 *  Copyright (c) 2025, Ludovic Hansen
 *  License: MIT
 *
 *  Description:
 *  This application implements a custom version of the `echo` command in C++.
 *  It handles various escape sequences, such as \a (alert), \b (backspace),
 *  \n (newline), \t (tab), etc. It prints the command-line arguments with the
 *  escape sequences interpreted correctly.
 *
 *  Usage: ./echo <string>
 *
 *  The following escape sequences are supported:
 *    \a      : Alert
 *    \b      : Backspace
 *    \n      : Newline
 *    \t      : Tab
 *    \r      : Carriage return
 *    \v      : Vertical tab
 *    \\      : Backslash
 *    \0num   : 8-bit octal value (num)
 *
 *  Note: More details on options and behavior can be found here:
 *  https://pubs.opengroup.org/onlinepubs/9699919799/utilities/echo.html
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

#include "../include/Parser.hpp"

using std::cerr;
using std::cout;
using std::string;
using std::vector;

auto main(int argc, char* argv[]) -> int
{
    vector<char*> arguments(argv, argv + argc); // Create a vector of arguments from command-line inputs
    Parser parser = *new Parser();

    // Check if no arguments are provided (argc <= 1 means no input string)
    if (argc <= 1)
    {
        cerr << "Usage: ./echo <string>\n";
        return EXIT_FAILURE;
    }

    // Output the strings (arguments) passed after the options
    for (int i = 1; i < argc; i++)
    {
        cout << parser.ParseArgument(arguments.at(i));
        
        if (i < argc - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";

    return EXIT_SUCCESS;
}
