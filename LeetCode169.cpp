#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hashtable; 
    int len=nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        hashtable[nums[i]]++;
        if (hashtable[nums[i]] >len / 2)
        {
            return nums[i];
        }
    }
    return 0;
    }

int majorityElement_better(vector<int>& nums) {
    //Boyer-Moore Voting Algorithm
    //time complexity:O(n)
    //space complexity:O(1)
    int count=0;
    int candidate=0;
    int len=nums.size();
    for(int i=0;i<len;i++){
        if(count==0){
            candidate=nums[i];
        }
        if(nums[i]==candidate){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
    }


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
