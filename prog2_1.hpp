#include <string>
#include <vector>

using namespace std;

#ifndef __TOKENIZER_HPP__
#define __TOKENIZER_HPP__

    class Tokenizer{
        private:
            vector<string> tokens;//For storing the tokens
        public:
            Tokenizer();
            ~Tokenizer();
            void Tokenize(string s);
            vector<string> GetTokens();
    };
#endif
