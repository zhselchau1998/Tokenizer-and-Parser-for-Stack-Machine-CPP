#include <vector>
#include <string>

using namespace std;

#ifndef __PARSER_HPP__
#define __PARSER_HPP__

    class Parser{//No storage needed
        private:
            
        public:
            Parser();
            ~Parser();
            bool Parse(vector <string> s);
    };
#endif
