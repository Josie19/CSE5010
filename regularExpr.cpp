/*
    created: jose magallanes
    purpose:converting 3 state DFA into regular expression
    version:1 -->only determining if string is accepted
    version:2 -->will read in values and construct an FA to convert and return regular exxpression
    date: October 21, 2020
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
/*-----------------------------------------------------version 1------------------------------------------------------------------*/
int main(){
    string filename = "file.txt";
    fstream read;
    read.open(filename.c_str(),ios::in);//file handle

    string re1 = "(a+b)";
    string re2 = "(a+b)*";
    string re3 = re1+re2;

    string possible_string;//read line 1
    read >> possible_string;
    read.close();
    
    if(possible_string == re1 | possible_string == re2 | possible_string == re3){
        cout << "string accepted!" << endl;
    }
    else
    {
        cout << "string not accepted!" << endl;
    }
    
    return 0;
}


/*------------------------------------------------------version 2------------------------------------------------------------------

//prototypes
string convertG(map<string,string>);//might end up using 2d vector to store edge values to an index corresponding to a specific node
//driver function
int main(){
    map<string,string> dfa
    int states;
   string filename = "file.txt"; 
   fstream read;
   read.open(filename.c_str(), ios::in);
   read >> states;
   for(int i(0), string node, expr; i < states; i++){
       read >> node >> expr;
       convertG(dfa);
   }
   string regular = convertG();
   //trim the stream
   //then convert to k to int using stoi()
   //invoke convertG()
   convertG(string fa, int num_nodes);
   return 0; 
}
//implementation
string convertG(map<string,string>dfa){
    string regexp;

    return regexp;
}
*/