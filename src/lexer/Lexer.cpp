#include "Lexer.h"
#include <cctype>
using namespace std;

//Calling constructor of Lexer class from Lexer.h
Lexer::Lexer(const string& src){
    source = src;
    pos = 0;
}

//Extracts character from cursor position
char Lexer::currentChar(){
    if(pos<source.size())
    return source[pos];
    return '\0';
}

//Moves cursor one character forward
void Lexer::advance(){
    pos++;
}

//Skips whitecase characters
void Lexer::skipWhitespace(){
    while(isspace(currentChar())){
        advance();
    }
}

//Extracts Identifier or keyword
Token Lexer::identifierOrKeyword(){
    string result;

    while(isalnum(currentChar()) || currentChar()=='_'){
        result += currentChar();
        advance();
    }

    if(result=="seed")
    return Token(TokenType::Seed,result);
    if(result=="bloom")
    return Token(TokenType::Bloom,result);
    else
    return Token(TokenType::Identifier,result);
}

//Extract Number
Token Lexer::number(){
    string result;
    while(isdigit(currentChar())){
        result += currentChar();
        advance();
    }

    return Token(TokenType::Number,result);
}

//Extract string literal
Token Lexer::stringLiteral(){
    string result;
    advance();

    //Edge-case: wond detect this string "Auro as invalid if at then end of the program
    while(currentChar()!='"' && currentChar()!='\0'){
        result += currentChar();
        advance();
    }

    advance();
    return Token(TokenType::String,result);
}

//Genrates Tokens
vector<Token> Lexer::tokenize(){
    vector<Token> tokens;
    
    while(currentChar()!='\0'){
        if(isspace(currentChar())){
            skipWhitespace();
        }
        else if(isalpha(currentChar()) || currentChar()=='_'){
            tokens.push_back(identifierOrKeyword());
        }
        else if(isdigit(currentChar())){
            tokens.push_back(number());
        }
        else if(currentChar()=='"'){
            tokens.push_back(stringLiteral());
        }
        else if(currentChar()=='='){
            tokens.push_back(Token(TokenType::Equal,"="));
            advance();
        }
        else
        {
            tokens.push_back(Token(TokenType::Unknown,string(1,currentChar())));
            advance();
        }
    }

    return tokens;
}

/*Edge cases & potential bugs (things to watch for)

isspace, isalpha, isdigit, isalnum require unsigned char

Standard cctype functions have undefined behavior if passed a negative char. Better use std::isspace(static_cast<unsigned char>(currentChar())).

This matters if your input could contain characters with high-bit set (non-ASCII).

stringLiteral() on unterminated string

If the source has a missing closing ", the loop runs until '\0', then advance() is called again (pos increments past end). It still returns a token, but you may want to detect and report an error (unterminated string).

number() only supports integers

No decimal point, no negative numbers, no hex. Decide whether you need floats or more numeric formats.

No comment handling

If your language has comments (e.g., // or #) you should detect and skip them in tokenize() (or in skipWhitespace variant).

No position info (line/column)

For good error messages, store line and column in Token (increment line when you see \n, reset column). Right now you can't tell where a token came from.

Unknown tokens are single-character only

For multi-char operators (if you later add == or +=) you'll need logic to read them as a unit.

Unicode / multi-byte

This lexer assumes 1 byte == 1 character (OK for ASCII). If you need UTF-8 support, you'll have to handle multi-byte codepoints.*/