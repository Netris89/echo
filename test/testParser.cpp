#include <gtest/gtest.h>
#include <string>

#include "parser.hpp"

using std::string;

TEST(ParserTests, TestSimpleArguments)
{
    string testedString = Parser::ParseArgument("NoEscapeSequencesHere");
    EXPECT_EQ(testedString, "NoEscapeSequencesHere");
    EXPECT_EQ(testedString.size(), 21);
}

TEST(ParserTests, TestAlert)
{
    EXPECT_EQ(Parser::ParseArgument("Alert\aSound"), "Alert\aSound");
}

TEST(ParserTests, TestBackspace)
{
    EXPECT_EQ(Parser::ParseArgument("Back\bSpace"), "Back\bSpace");
}

TEST(ParserTests, TestSuppressNewLine)
{
    EXPECT_EQ(Parser::ParseArgument("Suppress\\cNewline"), "Suppress");
}

TEST(ParserTests, TestFormFeed)
{
    EXPECT_EQ(Parser::ParseArgument("Form\fFeed"), "Form\fFeed");
}

TEST(ParserTests, TestNewLine)
{
    EXPECT_EQ(Parser::ParseArgument("New\nLine"), "New\nLine");
}

TEST(ParserTests, TestTab)
{
    EXPECT_EQ(Parser::ParseArgument("Tab\tSpace"), "Tab\tSpace");
}

TEST(ParserTests, TestBackslash)
{
    EXPECT_EQ(Parser::ParseArgument("Back\\slash"), "Back\\slash");
    EXPECT_EQ(Parser::ParseArgument("EndWith\\"), "EndWith\\");
    EXPECT_EQ(Parser::ParseArgument("\\StartWith"), "\\StartWith");
}

TEST(ParserTests, TestInvalidEscapeSequences)
{
    EXPECT_EQ(Parser::ParseArgument("Invalid\\xEscape"), "Invalid\\xEscape");
}

TEST(ParserTests, TestEmptyString)
{
    EXPECT_EQ(Parser::ParseArgument(""), "");
}

TEST(ParserTests, TestOctal)
{
    EXPECT_EQ(Parser::ParseArgument("\\041"), "!");
    EXPECT_EQ(Parser::ParseArgument("\\012"), "\n");
    EXPECT_EQ(Parser::ParseArgument("\\078"), "\078");
    EXPECT_EQ(Parser::ParseArgument("\\0x"), "\\0x");
}
