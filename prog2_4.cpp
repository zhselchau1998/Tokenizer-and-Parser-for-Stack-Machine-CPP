#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "prog2_1.hpp"
#include "prog2_3.hpp"

using namespace std;

int main(int argc, char *argv[]){

    cout << "Assignment #2-4, Zach Selchau, zhselchau1998@yahoo.com" << endl;
    
    string filename(argv[1]);
    ifstream infile(filename);

    string line = "";
    Tokenizer *tokenizer = new Tokenizer();
    Parser *parser = new Parser();
    int lineNum = 0;
    vector<string> inputs;
    string output = "";

    while(getline(infile, line)){
        lineNum++;
        try{
            tokenizer->Tokenize(line);
        }catch(const string e){
            cerr << "Error on line " << lineNum << ": " << e;
            return 0;
        }    
        inputs = tokenizer->GetTokens();
        
        if(!parser->Parse(inputs)){
            output="";
            for(int i=0; i<inputs.size(); i++){
                output = output + inputs[i];
                if(i+1!=inputs.size())
                    output = output + " ";
            }
            cout << "Parse error line " << lineNum << ": " << output << endl;
            return 0;
        }

        for(int i=0; i<inputs.size(); i++){
            output = output + inputs[i];
            if(i+1!=inputs.size())
                output = output + ",";
        }
        output = output + "\n";
    }
    cout << output;
}






