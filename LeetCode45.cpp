#include "iostream"
#include "vector"
using namespace std;
int jump(vector<int> &nums)
{
    int len = nums.size();
    int dp[len];
    dp[0] = 0;
    int step = 0;
    int step2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (i - step <= nums[step])
        {
            dp[i] = dp[step] + 1;
        }
        else
        {
            step = step2;
            dp[i] = dp[step] + 1;
        }
        if (i + nums[i] > step2 + nums[step2])
        {
            step2 = i;
        }
    }
    return dp[len - 1];
}
int jump_greed(vector<int> &nums)
{
    int maxPos = 0, n = nums.size(), end = 0, step = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (maxPos >= i)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end)
            {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    jump(nums);
    return 0;
}
