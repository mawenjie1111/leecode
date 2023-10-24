#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> quickSort(vector<int>& citations)
{
    int len=citations.size();
    if(len<=1)
    {
        return citations;
    }
    int pivot=citations[0];
    vector<int> left;
    vector<int> right;
    for(int i=1;i<len;i++)
    {
        if(citations[i]>=pivot)
        {
            left.push_back(citations[i]);
        }
        else
        {
            right.push_back(citations[i]);
        }
    }
    left=quickSort(left);
    right=quickSort(right);
    left.push_back(pivot);
    for(int i=0;i<right.size();i++)
    {
        left.push_back(right[i]);
    }
    return left;
}

int hIndex(vector<int>& citations) {
    citations=quickSort(citations);
    cout<<citations[0]<<endl;
    int len=citations.size();
    for (int i = 0; i < len; i++)
    {
        if (i+1==citations[i])
        {
            return i+1;
        }
        /* code */
    }
    return 1;
    }
int main(int argc, char const *argv[])
{
    vector<int> citations={3,0,6,1,5};
    hIndex(citations);
    return 0;
}
