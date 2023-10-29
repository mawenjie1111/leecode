#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int romanToInt(string s) {

    unordered_map<char, int> roman;
    roman['I']=1;
    roman['V']=5;
    roman['X']=10;
    roman['L']=50;
    roman['C']=100;
    roman['D']=500;
    roman['M']=1000;
    int all=0;
    int len=s.size();
    for(int i=0;i<len-1;i++)
    {
        if (roman.at(s[i])>=roman.at(s[i+1]))
        {
            all=all+roman.at(s[i]);
        }
        else if (roman.at(s[i])<roman.at(s[i+1]))
        {
            all=all-roman.at(s[i]);
        }
      
    }
    all=all+roman.at(s[len-1]);
    return  all;
    }
int main(int argc, char const *argv[])
{
    string s="III";
    cout<<romanToInt(s)<<endl;
    return 0;
}
