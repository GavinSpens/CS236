#pragma once
#include <iostream>
#include <sstream>
using namespace std;

enum TokenType
{
    COMMA,
    COLON,
    COLON_DASH,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    MULTIPLY,
    ADD,
    END,
    UNDEFINED
};

class Token
{
private:
    TokenType type;
    string value;
    int line;

public:
    Token(TokenType type, string value, int line) : type(type), value(value), line(line) {}

    TokenType getType() const
    {
        return type;
    }

    string toString() const
    {
        stringstream out;
        out << "(" << typeName(type) << "," << "\"" << value << "\"" << "," << line << ")";
        return out.str();
    }

    string typeName(TokenType type) const
    {
        switch (type)
        {
        case COMMA:
            return "COMMA";
        case COLON:
            return "COLON";
        case COLON_DASH:
            return "COLON_DASH";
        case PERIOD:
            return "PERIOD";
        case Q_MARK:
            return "Q_MARK";
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case SCHEMES:
            return "SCHEMES";
        case FACTS:
            return "FACTS";
        case RULES:
            return "RULES";
        case QUERIES:
            return "QUERIES";
        case ID:
            return "ID";
        case STRING:
            return "STRING";
        case COMMENT:
            return "COMMENT";
        case MULTIPLY:
            return "MULTIPLY";
        case ADD:
            return "ADD";
        case END:
            return "END";
        default:
            return "UNDEFINED";
        }
    }
};