#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

auto main(int argc, char* argv[]) -> int
{
    size_t const size = argc;
    vector<char*> arguments(argv, argv + argc);

    if (argc < 1)
    {
        cout << "usage : echo <string you want to print>\n";
    }
    
    for (size_t i = 0; i < size; i++)
    {
        cout << arguments.at(i) << " ";
    }

    cout << "\n";

    return EXIT_SUCCESS;
}