#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int times=0;
        int len=nums.size();
        int pos=0;
        int before=0;
        int after=-1;
        int temp=nums[before];
        while(times<len&&len>1)
        {
            if(after==pos){
                pos++;
                before=pos;
                temp=nums[before];
            }
            else{
                after=(before+k)%len;
                swap(nums[after],temp);
                before=after;
                times++;         
                }
        }
    }
 void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

void rotate_bertter(vector<int>& nums, int k) {
        //reverse
        //
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums={-1,-100,3,99};
    rotate(nums,2);
    return 0;
}
