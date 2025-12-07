#pragma once
#include <string>
#include <iostream>
using namespace std;

enum class TokenType
{
    Seed,
    Bloom,
    Identifier,
    Number,
    String,
    Equal,
    Unknown
};

struct Token
{
    TokenType type;
    string value;

    Token(TokenType typ, const string &val)
    {
        type = typ;
        value = val;
    }

    void print() const
    {
        cout << "Token(";
        switch (type)
        {
        case TokenType::Seed:
            cout << "Seed";
            break;
        case TokenType::Bloom:
            cout << "Bloom";
            break;
        case TokenType::Identifier:
            cout << "Identifier";
            break;
        case TokenType::Number:
            cout << "Number";
            break;
        case TokenType::String:
            cout << "String";
            break;
        case TokenType::Equal:
            cout << "Equal";
            break;
        default:
            cout << "Unknown";
            break;
        }
        cout << ", \"" << value << "\")\n";
    }
};