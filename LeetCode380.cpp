#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
using namespace std;
class RandomizedSet {
public:

    RandomizedSet() {
        //initialize the random seed
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(indices.count(val))
        {
            return false;
        }
        int index=nums.size();
        nums.push_back(val);
        indices[val]=index;
        return true;
        
    }
    bool remove(int val) {
        if(!indices.count(val))
        {
            return false;
        }
        int index=indices[val];
        int last=nums.back();
        nums[index]=last;
        indices[last]=index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int index=rand()%nums.size();
        return nums[index];
    }
private:
    //save the nums
    vector<int> nums;
    //save the index of nums
    unordered_map<int, int> indices;
};