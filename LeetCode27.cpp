#include "iostream"
#include "vector"
using namespace std;

int removeElement(vector<int>& nums, int val) {
    for (int index=0; index < nums.size(); index++)
    {
        if (nums[index] == val)
        {
            nums.erase(nums.begin()+index);
            index--;
        }
        /* code */
    }
    return nums.size();
    }
int removeElement_better(vector<int>& nums, int val) {
    //double poniters
    //right pointer is the length of the new array
    //change the order of elements
    // O(n) time O(1) space
    int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] == val) {
                //if nums[left] == val, swap nums[left] and nums[right]
                // evne nums[right] == val, it will be removed in the next loop
                nums[left] = nums[right];
                right--;
            } else {
                left++;

            }
        }
        return left;
}