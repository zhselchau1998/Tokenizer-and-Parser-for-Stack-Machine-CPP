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
    vector<vector<string>> inputs;
    string output = "";

    while(getline(infile, line)){

        lineNum++;
        try{
            tokenizer->Tokenize(line);
        }catch(const string e){
            cerr << "Error on line " << lineNum << ": " << e;
            return 0;
        }    
        inputs.push_back(tokenizer->GetTokens());

        for(int i=0; i<inputs[lineNum-1].size(); i++){
            output = output + inputs[lineNum-1][i];
            if(i+1!=inputs[lineNum-1].size())
                output = output + ",";
        }
        output = output + "\n";
    }

    for(int i=0; i<inputs.size(); i++)
        if(!parser->Parse(inputs[i])){
            output="";
            for(int j=0; j<inputs[i].size(); j++){
                output = output + inputs[i][j];
                if(j+1!=inputs[i].size())
                    output = output + " ";
            }
            cout << "Parse error on line " << lineNum << ": " << output << endl;
            return 0;
        }

    cout << output;
}






