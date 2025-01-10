#pragma once
#include <iostream>
#include "token.h"
using namespace std;

class Scanner
{
private:
    string input;

public:
    Scanner(const string &input) : input(input) {}

    Token scanToken()
    {
        while (isspace(input[0]))
        {
            input = input.substr(1);
        }
        
        if (input[0] == ',')
        {
            input = input.substr(1);
            return Token(COMMA, ",", 0);
        }
        else
        {
            string value = input.substr(0, 1);
            input = input.substr(1);
            return Token(UNDEFINED, value, 0);
        }
    }
};