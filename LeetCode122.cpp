#include "iostream"
#include "vector"
using namespace std;
int maxProfit(vector<int>& prices) {
    int result=0;
    int len=prices.size();
    for (int i = 0; i < len-1; i++)
    {
        if (prices[i+1]>prices[i])
        {
            result+=prices[i+1]-prices[i];
        }
        /* code */
    }
    return result;
    }
int maxProfit_dp(vector<int>& prices) {
    int len=prices.size();
    int dp[len][2];
    dp[0][0]=0;
    dp[0][1]=-prices[0];
    for (int i = 1; i < len; i++)
    {   
        //dp[i][0]表示第i天不持有股票的最大利润
        //dp[i][1]表示第i天持有股票的最大利润
        //此式表示在第i天的最大利益为前一天不持有股票的最大利益和前一天持有股加上今天卖出的最大利益
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
        //此式表示在第i天持有股票的最大利益为前一天持有股票的最大利益和前一天不持有股票的最大利益减去今天买入的最大利益
        dp[i][1]=max(dp[1-i][0]-prices[i],dp[i-1][1]);
        /* code */
    }
    return dp[len-1][0];
    
    }

