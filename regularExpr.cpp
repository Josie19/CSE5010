/*
    created: jose magallanes
    purpose:converting 3 state DFA into regular expression
    version:1 -->only determining if string is accepted
    version:2 -->will read in values and construct an FA to convert and return regular exxpression
    versio:3 -->will use p,q,k to return a regular expression; k > 0 will use recursion to return the regular expression
    date: October 21, 2020
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;
/*-----------------------------------------------------version 1------------------------------------------------------------------
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
*/

/*------------------------------------------------------version 2------------------------------------------------------------------

//prototypes
string convertG(map<string,int> dfa);//might end up using 2d vector to store edge values to an index corresponding to a specific node
//driver function
int main(){
   map<string,int> dfa;
   int states;
   string filename = "file2.txt"; 
   fstream read;
   read.open(filename.c_str(), ios::in);
   read >> states;
   for(int i(0),node; i < states; i++){ 
       string expr;
       read >> expr >> node;//1 (a+b)*
       dfa.insert({expr,node});//hoping string,string pairs work
   }
   read.close();
   cout << convertG(dfa) << endl;
   return 0;
}
//implementation
string convertG(map<string,int> dfa){
    map<string,int>::iterator iter;
    string regexp = "";
    string afile = "answer.txt";
    fstream write;
    write.open(afile.c_str(), ios::out);
    
    //construct the map
    map<string,int> gnfa(dfa.begin(), dfa.end());//copy nodees and edges from dfa to fa
    int length = gnfa.size();
    //two cases that convertG() will handle
    if(length == 2){
        for(iter = gnfa.begin(); iter != gnfa.end(); iter++){//for debugging purposes
            string tempexp = iter->first;
            write << tempexp << endl;
            regexp += iter->first;
            //erase pair
            //comment out starting here
            //are their types able to be compared?
            if(iter == gnfa.end()-1){
                string tempexp = iter->first;
                write << tempexp << endl;
                regexp += iter->first;  
            }
            else
            {
                string tempexp = iter->first;
                write << tempexp << endl;
                regexp += iter->first;
                //erase pair
            }
            //ending here
        }//should have a 2 state gnfa as well as the final regular expression
    }
    else if(length > 2){
        //insert s and a to form length+2 gnfa
        //gnfa.insert({"s",0});
        //gnfa.insert({"a",4});
        for(iter = gnfa.begin(); iter != gnfa.end(); iter++){
            string tempexp = iter->first;
            write << tempexp;
            regexp += iter->first;
            //erase pair
        }
    }
    else{
        cout << "Single state FA does not need to be converted to get RE\n";
        for(iter = gnfa.begin(); iter != gnfa.end(); ++iter){
            string tempexp = iter->first;
            cout << "RE: " << iter->first;
            write << tempexp << endl;
        }
    }
    write.close();

    return regexp;
}
*/
/*------------------------------------------------------version 3------------------------------------------------------------------*/
string convert(int,int,int);

int main(){
    //1 <= k <=3
    //1 <= p,q <=3
    //cout << convert(2,2,1) << endl;
    cout << "(" + convert(3,1,0) + "(" + convert(1,2,1) + ")" + "(" + convert(2,3,0) + ")" + "U" + convert(2,3,0) + ")*";
}
//intermediaries: k
//start node: p
//next node: q
string convert(int p, int q, int k){
    string regexp;
    if(k==0){//with no intermediaries
        if(p==1){
            if(q==1){
                return "e";
            }
            if(q==2){
                return "a+b";
            }
            if(q==3){
                return "";
            }
        }
        if(p==2){
            if(q==1){
                return "";
            }
            if(q==2){
                return "a+e";
            }
            if(q==3){
                return "b";
            }
        }
        if(p==3){
            if(q==1){
                return "a";
            }
            if(q==2){
                return "b";
            }
            if(q==3){
                return "e";
            }
        }
    }
    else{//with intermediaries
        return regexp = "(" + convert(p,q,k-1) + ")" + "U" + "(" + convert(p,k,k-1) + ")" + "(" + convert(k,k,k-1) + "*" + ")" + "(" + convert(k,q,k-1) + ")";
    }
    return regexp;
}

//((a(a∪b))∗∪(a(a∪b)∗∪b) ∪ b)∗
