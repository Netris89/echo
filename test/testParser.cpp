#include "../include/Parser.hpp"
#include <gtest/gtest.h>

TEST(ParserTests, TestEscapeSequences)
{
    EXPECT_EQ(Parser::ParseArgument("Hello\\nWorld"), "Hello\nWorld");
    EXPECT_EQ(Parser::ParseArgument("Tab\\tSpace"), "Tab\tSpace");
    EXPECT_EQ(Parser::ParseArgument("Back\\bSpace"), "Back\bSpace");

    EXPECT_EQ(Parser::ParseArgument("Alert\\aSound"), "Alert\aSound");

    EXPECT_EQ(Parser::ParseArgument("Line\\012Break"), "Line\nBreak");

    EXPECT_EQ(Parser::ParseArgument("Backslash\\\\"), "Backslash\\");
}

TEST(ParserTests, TestInvalidEscapeSequences)
{
    EXPECT_EQ(Parser::ParseArgument("Invalid\\xEscape"), "Invalid\\xEscape");

    EXPECT_EQ(Parser::ParseArgument("EndWith\\"), "EndWith\\");
}

TEST(ParserTests, TestSimpleArguments)
{
    EXPECT_EQ(Parser::ParseArgument("HelloWorld"), "HelloWorld");
    EXPECT_EQ(Parser::ParseArgument("NoEscapeSequencesHere"), "NoEscapeSequencesHere");
}
