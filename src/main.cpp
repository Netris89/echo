#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

using std::cerr;
using std::cout;
using std::string;
using std::vector;

auto main(int argc, char* argv[]) -> int
{
    vector<char*> arguments(argv, argv + argc); // Create a vector of arguments from command-line inputs
    int opt           = 0;                      // Variable to store the option returned by getopt
    bool newLine      = true;                   // Flag to determine if a newline should be printed at the end

    // Check if no arguments are provided (argc <= 1 means no input string)
    if (argc <= 1)
    {
        cerr << "Usage: ./echo [-n] <string>\n";
        return EXIT_FAILURE;
    }

    // Process the command-line options (e.g., "-n" flag) *
    // Loop through options using getopt
    while ((opt = getopt(argc, argv, "n")) != -1)
    {
        // If the -n flag is found, disable printing a newline at the end,
        // if the flag is not -n, prints an error
        switch (opt)
        {
        case 'n':
            newLine = false;
            break;
        case '?':
            cerr << "Valid option is -n\n";
            return EXIT_FAILURE;
        }
    }

    // Output the strings (arguments) passed after the options
    // optind points to the first non-option argument
    for (int i = optind; i < argc; i++)
    {
        cout << arguments.at(i);

        if (i < argc - 1)
        {
            cout << " ";
        }
    }

    // Print a newline if the -n flag was not used
    if (newLine)
    {
        cout << "\n";
    }

    return EXIT_SUCCESS;
}
