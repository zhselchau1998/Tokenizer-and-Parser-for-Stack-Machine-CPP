#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include "prog2_3.hpp"

using namespace std;

Parser :: Parser(){//No storage needed

}


Parser :: ~Parser(){//No storage declared

}


bool Parser :: Parse(vector<string> inputs){
    
    string stest = "";
    bool lengthTest=false;
    bool testTwo = false;
    int intTest = 0;

    for (int i=0; i<inputs.size(); i++){

        stest=inputs[i];
        
        //Vector Size Test
        if(lengthTest)
            return false;

        //1 Token Long Test
        if((stest.compare("pop")==0 || stest.compare("add")==0 || stest.compare("sub")==0 || stest.compare("mul")==0 || stest.compare("div")==0 || stest.compare("mod")==0 ||stest.compare("skip")==0) && i==0)
            lengthTest=true;

        //2 Token Long Test
        if(stest.compare("push")==0 || stest.compare("save")==0 || stest.compare("get")==0)
        if(i==0 && inputs.size()!=1)
            testTwo=true;

        //2 Token 2nd Test
        if(testTwo && i==1 && stringstream(stest) >> intTest)
            lengthTest=true;
    }    
    return lengthTest;
}