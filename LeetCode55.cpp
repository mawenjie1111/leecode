#include "iostream"
#include "vector"
using namespace std;
bool canJump_dp(vector<int>& nums) {
    int len=nums.size();
    int dp[len];
    dp[0]=nums[0];
    int step=0;
    for (int  i = 1; i < len; i++)
    {
        if (dp[i-1]>=i)
        {
            dp[i]=max(dp[i-1],i+nums[i]);
        }
        else
        {
            return false;
        }
        /* code */
    return true;
    }
    }

bool canJump_Greed(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
 }