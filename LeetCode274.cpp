#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(),greater<int>());
    if(citations[0]==0)
    {
        return 0;
    }
    int len=citations.size();
    int result=len;
    for (int i = 0; i < len; i++)
    {
        if (i+1>citations[i])
        {
            result=i;
            break;
        }
        /* code */
    }
    return result;
    }

