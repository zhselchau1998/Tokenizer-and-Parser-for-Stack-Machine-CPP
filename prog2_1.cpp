#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include "prog2_1.hpp"

using namespace std;

Tokenizer :: Tokenizer(){//No memory needs to be allocated on the heap
    
}


Tokenizer :: ~Tokenizer(){//This is unnecesary, but I like to be thurough
    if(!this->tokens.empty())
        this->tokens.clear();
}


void Tokenizer :: Tokenize(string input){
    stringstream stream(input); //Puts the imput into a string stream for tokenization checks
    
    int intTest;
    string stringTest;
    string stest;
    
    try{
        while(getline(stream, stest, ' ')){//Goes through whole string stream
            
            if(stest.find_first_not_of("0123456789") == string::npos){//int check
                this->tokens.push_back(stest);
                continue;
            }
            
            if(stest.compare("push")!=0 && stest.compare("pop")!=0 && stest.compare("add")!=0)
            if(stest.compare("sub")!=0 && stest.compare("mul")!=0 && stest.compare("div")!=0)
            if(stest.compare("mod")!=0 && stest.compare("skip")!=0 && stest.compare("get")!=0)
            if(stest.compare("save")!=0){//Check for correct tokens
               throw "Unexpected token: ";
            }
            this->tokens.push_back(stest);
            
        }
    }catch(const char *e){//Just rethrow the error, No output necessary
        string et =e+stest+"\n";
        throw et;
    }
}


vector<string> Tokenizer :: GetTokens(){
    vector<string> tempVect(this->tokens);//Queue behaviour
    this->tokens.clear();

    return tempVect;
}