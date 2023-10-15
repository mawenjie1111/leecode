#include "iostream"
#include "vector"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0)
    {
        return 0;
    }
    int left = 0, right = 1;
    while (right < nums.size())
    {
        if (nums[left] == nums[right])
        {
            right++;
        }
        else
        {
            left++;
            nums[left] = nums[right];
            right++;
        }
    }
    return left + 1;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
