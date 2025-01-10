#pragma once
#include <iostream>
#include "token.h"
using namespace std;

class Scanner
{
private:
    string input;
    int line = 1;

public:
    Scanner(const string &input) : input(input) {}

    Token scanToken()
    {
        if (input.empty())
        {
            return Token(END, "", line);
        }

        if (input[0] == '\n')
        {
            line++;
            input = input.substr(1);
        }

        while (isspace(input[0]))
        {
            input = input.substr(1);
            if (input.empty())
            {
                return Token(END, "", line);
            }
        }
        
        if (input[0] == ',')
        {
            return scanComma();
        }
        else if (input.substr(0, 2) == ":-")
        {
            return scanColonDash();
        }
        else if (input[0] == '.')
        {
            return scanPeriod();
        }
        else if (input.substr(0, 2) == ": ")
        {
            return scanColon();
        }
        else if (input[0] == '\'')
        {
            return scanQuote();
        }
        else if (input[0] == '\"')
        {
            return scanQuote2();
        }
        else if (input[0] == '?')
        {
            return scanQMark();
        }
        else if (input[0] == '(')
        {
            return scanLeftParen();
        }
        else if (input[0] == ')')
        {
            return scanRightParen();
        }
        else if (input.substr(0, 2) == "#|")
        {
            return scanComment2();
        }
        else if (input[0] == '#')
        {
            return scanComment();
        }
        else if (input[0] == '*')
        {
            return scanMultiply();
        }
        else if (input[0] == '+')
        {
            return scanAdd();
        }
        else if (input.substr(0, 7) == "Schemes")
        {
            return scanSchemes();
        }
        else if (input.substr(0, 5) == "Facts")
        {
            return scanFacts();
        }
        else if (input.substr(0, 5) == "Rules")
        {
            return scanRules();
        }
        else if (input.substr(0, 7) == "Queries")
        {
            return scanQueries();
        }
        else if (isalnum(input[0]))
        {
            return scanID();
        }
        else
        {
            return Token(UNDEFINED, input.substr(0, 1), line);
        }
    }

    Token scanComma()
    {
        input = input.substr(1);
        return Token(COMMA, ",", line);
    }

    Token scanColon()
    {
        input = input.substr(1);
        return Token(COLON, ":", line);
    }

    Token scanColonDash()
    {
        input = input.substr(2);
        return Token(COLON_DASH, ":-", line);
    }

    Token scanPeriod()
    {
        input = input.substr(1);
        return Token(PERIOD, ".", line);
    }

    Token scanQMark()
    {
        input = input.substr(1);
        return Token(Q_MARK, "?", line);
    }

    Token scanLeftParen()
    {
        input = input.substr(1);
        return Token(LEFT_PAREN, "(", line);
    }

    Token scanRightParen()
    {
        input = input.substr(1);
        return Token(RIGHT_PAREN, ")", line);
    }

    Token scanSchemes()
    {
        input = input.substr(7);
        return Token(SCHEMES, "Schemes", line);
    }

    Token scanFacts()
    {
        input = input.substr(5);
        return Token(FACTS, "Facts", line);
    }

    Token scanRules()
    {
        input = input.substr(5);
        return Token(RULES, "Rules", line);
    }

    Token scanQueries()
    {
        input = input.substr(7);
        return Token(QUERIES, "Queries", line);
    }

    Token scanQuote()
    {
        input = input.substr(1);
        string value = "";
        while (input[0] != '\'')
        {
            value += input[0];
            input = input.substr(1);
            if (input.empty())
            {
                value = "'" + value;
                return Token(UNDEFINED, value, line);
            }
        }
        input = input.substr(1);
        return Token(STRING, value, line);
    }

    Token scanQuote2()
    {
        input = input.substr(1);
        string value = "";
        while (input[0] != '\"')
        {
            value += input[0];
            input = input.substr(1);
            if (input.empty())
            {
                value = "\"" + value;
                return Token(UNDEFINED, value, line);
            }
        }
        input = input.substr(1);
        return Token(STRING, value, line);
    }

    Token scanComment()
    {
        input = input.substr(1);
        string value = "";
        while (input[0] != '\n')
        {
            value += input[0];
            input = input.substr(1);
            if (input.empty())
            {
                value = "#" + value;
                return Token(UNDEFINED, value, line);
            }
        }
        return Token(COMMENT, value, line);
    }

    Token scanID()
    {
        string value = "";
        while (isalnum(input[0]))
        {
            value += input[0];
            input = input.substr(1);
        }
        return Token(ID, value, line);
    }

    Token scanMultiply()
    {
        input = input.substr(1);
        return Token(MULTIPLY, "*", line);
    }

    Token scanAdd()
    {
        input = input.substr(1);
        return Token(ADD, "+", line);
    }

    Token scanComment2()
    {
        input = input.substr(2);
        string value = "";
        while (input.substr(0, 2) != "|#")
        {
            value += input[0];
            input = input.substr(1);
            if (input.empty())
            {
                value = "#|" + value;
                return Token(UNDEFINED, value, line);
            }
        }
        input = input.substr(2);
        return Token(COMMENT, value, line);
    }
};