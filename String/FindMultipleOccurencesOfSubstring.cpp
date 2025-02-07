
//Find Multiple Occurrences of a Substring
#include <iostream>
using namespace std;
int main()
{
    string str="welcome to pramod to this to class";
    string substr="to";
    int pos=-1;
    while((pos=str.find(substr,pos+1))!=string::npos)
    {
        
        cout<<"position is = "<<pos<<endl;
        
    }
    return 0;
}


// output
// position is = 8
// position is = 18
// position is = 26
