#include "iostream"
#include "vector"
using namespace std;
  
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //greed
    int len=gas.size();
    int all=0;
    int start=-1;
    int temp=0;
    for (int i = 0; i < len; i++)
    {
        all=all+gas[i]-cost[i];
        if(all<=temp)
        {
            temp=all;
            start=i;
        }
    }
    if (all<0)
    {
        return -1;
    }
    return (start+1)%len;
        /* code */
}
    