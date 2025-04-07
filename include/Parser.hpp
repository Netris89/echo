#include <string>

class Parser
{
private:
public:
    Parser();
    auto ParseArgument(char*) -> std::string;
};