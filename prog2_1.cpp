#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include "prog2_1.hpp"

using namespace std;

Tokenizer :: Tokenizer(){
    
}


Tokenizer :: ~Tokenizer(){
    if(!this->tokens.empty())
        this->tokens.clear();
}


void Tokenizer :: Tokenize(string input){
    stringstream stream(input); 
    
    int intTest;
    string stringTest;
    string stest;
    
    try{
        while(getline(stream, stest, ' ')){//Goes through whole string stream
            
            if(stest.find_first_not_of("0123456789") == string::npos){//int check
                //cout<<"you typed an int\n";
                this->tokens.push_back(stest);
                continue;
            }
            
            if(stest.compare("push")!=0 && stest.compare("pop")!=0 && stest.compare("add")!=0)
            if(stest.compare("sub")!=0 && stest.compare("mul")!=0 && stest.compare("div")!=0)
            if(stest.compare("mod")!=0 && stest.compare("skip")!=0 && stest.compare("get")!=0)
            if(stest.compare("save")!=0){
               throw "Unexpected token: ";
            }
            this->tokens.push_back(stest);
            
        }
    }catch(const char *e){
        //cerr << e << stest << endl;
        string et =e+stest+"\n";
        throw et;
    }
}


vector<string> Tokenizer :: GetTokens(){
    vector<string> tempVect(this->tokens);
    this->tokens.clear();

    return tempVect;
}

/*
int main(){
    
    string inputString;
    
    cout << "Input something: ";
    getline(cin, inputString);
    
    Tokenizer *myt = new Tokenizer();

    cout << inputString << endl;

    myt->Tokenize(inputString);
    vector<string> vect = myt->GetTokens();
    
    for(int i = 0; i < vect.size(); i++)
        cout << (string) vect[i] << "\n";

    cout << "Vector size: " << vect.size() << endl;
    
}*/





