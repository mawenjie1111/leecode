#include "iostream"
#include "vector"
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    bool skip = true;
    //sign thr repeat element  firstly  appear
    int len = nums.size();
    if (nums.size() == 0)
    {
        return 0;
    }
    int left = 0, right = 1;
    int mid = left + 1;
    //mid always point to Nth repeating element
    while (right < len)
    {
        if (nums[left] == nums[right])
        {
            if (skip)
            {
                skip = false;
                nums[mid] = nums[right];
                //[ 1,   1,   1,  1,  2,  2,  3]             [ 1,   1,   2,  1,  2,  2,  3]            [ 1,   1,   2,  2,  2,  2,  3]            [ 1,   1,   2,  2,  3,  2,  3] 
                //  ^    ^                                               ^   ^       ^                                     ^   ^   ^ 
                //  |    |                           ---->               |   |       |         ---->                       |   |   |      ---->
                //  l   m,r                                              l   m       r                                     l   m   r 
                right++;    
                continue;
            }
            right++;
        }
        else
        {
            if (skip)
            {
                left++;
            }
            else
            {
                left += 2;
            }
            mid = left + 1;
            // left += 2;
            nums[left] = nums[right];
            right++;
            skip = true;
        }
    }
    if (skip)
    {
        return left + 1;
    }
    else
    {
        return left + 2;
    }
}
int removeDuplicates_better(vector<int> &nums)
{
     int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
}