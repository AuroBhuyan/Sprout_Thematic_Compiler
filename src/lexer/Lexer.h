#pragma once
#include "Token.h"
#include <vector>
using namespace std;

class Lexer{
    private:
        string source;
        size_t pos;

        char currentChar();
        void advance();
        void skipWhitespace();
        Token identifierOrKeyword();
        Token number();
        Token stringLiteral();

    public:
        Lexer(const string& src);
        vector<Token> tokenize();
};