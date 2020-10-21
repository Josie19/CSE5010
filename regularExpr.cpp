/*
    created: jose magallanes
    purpose:converting 3 state DFA into regular expression
    version:1 -->only determining if string is accepted
    version:2 -->will read in values and construct an FA to convert and return regular exxpression
    date: October 21, 2020
*/

#include<iostream>
#include<sstream>
#include<string>

using namespace std;
/*-----------------------------------------------------version 1------------------------------------------------------------------*/
int main(){
    string filename = "file.txt"
    fstream read;
    read.open(filename.c_str());

    string re1 = "";
    string re2 = "";
    string re3 = re1+re2;

    string possible_string;
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
string convertG(string, int);//might end up using 2d vector to store edge values to an index corresponding to a specific node
//driver function
int main(){
   string filename = "file.txt"; 
   fstream read;
   read.open(filename.c_str());
   for(int i = 0; i < 1; i++){
       read >> dfa >> k;
   }
   //trim the stream
   //then convert to k to int using stoi()
   //invoke convertG()
   convertG(string fa, int num_nodes);
   return 0; 
}
//implementation
string convertG(string dfa, int k){
    string regexp;

    return regexp;
}
*/