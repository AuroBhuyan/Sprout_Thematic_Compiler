#include <iostream>
#include "lexer/Lexer.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    cout<<"Inside main:\n";
    ifstream file("../../examples/program1.sprout");
    if(!file.is_open()){
        cerr<<"Error: File was not opened\n";
        return 1;
    }

    stringstream buffer;
    buffer<<file.rdbuf();
    string code = buffer.str();

    Lexer lexer(code);
    auto tokens = lexer.tokenize();

    for(auto &t:tokens){
        t.print();
    }

    return 0;
}
