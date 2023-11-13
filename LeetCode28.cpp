#include <iostream>
#include <vector>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
    int len = needle.size();
    int j = 0;
    int flag = -1;
    for (int i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
        }
        else
        {
            i = i - j;
            j = 0;
        }
        if (j == len)
        {
            flag = i + 1 - len;
            break;
        }
        /* code */
    }
    return flag;
}
int strStr_kmp(string haystack, string needle)
{
    int len=needle.size();
    vector<int> next(len,0);
    next[0]=-1;
    int i=0,j=-1;
    while (i<len-1)
    {
        if((j==-1)||(j!=-1&&needle[i]==needle[j]))
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
        /* code */
    }
    i=0,j=0;
    int len2=haystack.size();
    while (i<len2&&j<len)
    {
        if((j==-1)||(j!=-1&&haystack[i]==needle[j]))
        {
            i++;
            j++;
        }
        else{
            j=next[j];
        }
        /* code */
    }
    if(j==needle.size())
    {
        return i-j;
    }
    else{
        return -1;
    }
}
int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    cout << strStr_kmp(haystack, needle) << endl;
    return 0;
}