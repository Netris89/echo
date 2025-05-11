#include <gtest/gtest.h>

#include "parser.hpp"

TEST(ParserTests, TestSimpleArguments)
{
    EXPECT_EQ(Parser::ParseArgument("HelloWorld"), "HelloWorld");
    EXPECT_EQ(Parser::ParseArgument("NoEscapeSequencesHere"), "NoEscapeSequencesHere");
}

TEST(ParserTests, TestNewLine)
{
    EXPECT_EQ(Parser::ParseArgument("Hello\nWorld"), "Hello\nWorld");
}

TEST(ParserTests, TestTab)
{
    EXPECT_EQ(Parser::ParseArgument("Tab\tSpace"), "Tab\tSpace");
}

TEST(ParserTests, TestBackspace)
{
    EXPECT_EQ(Parser::ParseArgument("Back\bSpace"), "Back\bSpace");
}

TEST(ParserTests, TestAlert)
{
    EXPECT_EQ(Parser::ParseArgument("Alert\aSound"), "Alert\aSound");
}

TEST(ParserTests, TestLineBreak)
{
    EXPECT_EQ(Parser::ParseArgument("Line\012Break"), "Line\nBreak");
}

TEST(ParserTests, TestBackslash)
{
    EXPECT_EQ(Parser::ParseArgument("Backslash\\\\"), "Backslash\\\\");
}

TEST(ParserTests, TestInvalidEscapeSequences)
{
    EXPECT_EQ(Parser::ParseArgument("Invalid\\xEscape"), "Invalid\\xEscape");
    EXPECT_EQ(Parser::ParseArgument("EndWith\\"), "EndWith\\");
    EXPECT_EQ(Parser::ParseArgument("\\StartWith"), "\\StartWith");
}

TEST(ParserTests, TestEmptyString)
{
    EXPECT_EQ(Parser::ParseArgument(""), "");
}

TEST(ParserTests, TestOctal)
{
    EXPECT_EQ(Parser::ParseArgument("\041"), "!");
}
