#include "iostream"
#include "vector"
using namespace std;
int lengthOfLastWord(string s) {
    char *p= &s[0];
    char *last= &s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if(*p==' '&& *(p+1)!=' ')
        {
            last=p+1;
        }
        p++;
    }
    string ss(last);
    int len=0;
    for (int i = 0; i < ss.size(); i++)
    {
        if (ss[i]!=' ')
        {
            len++;
        }
        else
        {
            break;
        }
    }
    return len;
    }