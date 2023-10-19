#include "iostream"
#include "vector"
using namespace std;
int maxProfit(vector<int>& prices) {
    int min=1e9,max=0;
    for (int i = 0; i < prices.size(); i++)
    {
      max=prices[i]-min>max?prices[i]-min:max;
      min=prices[i]<min?prices[i]:min;
    }
    return max;
    }