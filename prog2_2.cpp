#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "prog2_1.hpp"

using namespace std;

int main(int argc, char *argv[]){

    cout << "Assignment #2-2, Zach Selchau, zhselchau1998@yahoo.com" << endl;
    
    string filename(argv[1]);
    ifstream infile(filename);

    string line = "";
    Tokenizer *tokenizer = new Tokenizer();
    int lineNum = 0;
    vector<string> inputs;
    string output = "";

    while(getline(infile, line)){
        lineNum++;//For cerr
        try{
            tokenizer->Tokenize(line);
        }catch(const string e){//Catch the error that was rethrown by prog2_1
            cerr << "Error on line " << lineNum << ": " << e;
            return 0;
        }    
        inputs = tokenizer->GetTokens();
        
        for(int i=0; i<inputs.size(); i++){//Not failed so add to the output
            output = output + inputs[i];
            if(i+1!=inputs.size())
                output = output + ",";
        }
        output = output + "\n";
    }
    
    cout << output;
}






