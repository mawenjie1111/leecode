#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string reverseWords(string s)
{
    int len = s.size();
    string result="";
    for (int i = len;i >=0; i--)
    {
        if (s[i] == ' ')
        {
            s[i] = '\0';
            if(s[i+1]!='\0')
            {
                result+=&s[i+1];
                result+=" ";
            }
        }

        /* code */
    }
    if(s[0]!='\0')
    {
        result+=&s[0];
    }
    else{
        result.pop_back();
    }
    return result;
}
int main()
{
    string s = "  the sky is  blue  ";
    cout << reverseWords(s) << endl;
    return 0;
}
