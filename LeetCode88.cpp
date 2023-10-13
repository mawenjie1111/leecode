#include <iostream>
#include <vector> // Added this line to include the vector header file
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0; // i for nums1, j for nums2
    int m2 = m;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        { // if nums1[i]<nums2[j], q just move on
            i++;
        }
        else
        { // if nums1[i]>=nums2[j], insert nums2[j] into nums1
            nums1.insert(nums1.begin() + i, nums2[j]);
            i++;
            j++;
            m++; // length of nums1 increase by 1
            nums1.pop_back();//delete the last element of nums1
        }
    }
    // **************too slow!******************
    // nums1.erase(nums1.begin()+m,nums1.end());//delete the elements after m in nums1
    // nums1.insert(nums1.end(),nums2.begin()+j,nums2.end());//insert the elements after j in nums2 into nums1
    // *****************************************
    while (j < n)
    {
        nums1[i] = nums2[j];
        i++;
        j++;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
