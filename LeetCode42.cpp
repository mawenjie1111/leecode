#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int>& height) {
    int len=height.size();
    int left_max=height[0];
    int right_max=0;
    int right_max_index=0;
    int sum=0;
    for (int i = 1; i < len-1; i++)
    {
        if(right_max_index<=i)
        {
            right_max=height[i];
            for (int j = i+1; j < len; j++)
            {
    
                if(height[j]>right_max)
                {
                    right_max=height[j];
                    right_max_index=j;
                }
                /* code */
            }
        }
        if(height[i]<left_max&&height[i]<right_max&&i<right_max_index)
        {
            sum+=((left_max<=right_max)?left_max:right_max)-height[i];
        }
        left_max=(left_max>=height[i])?left_max:height[i];
        /* code */
    }
    return sum;
    }
int trap_dp(vector<int>& height) {
    int n=height.size();
    if(n==0){
        return 0;
    }
    vector<int> left(n);
    left[0]=height[0];
    vector<int> right(n);
    right[n-1]=height[n-1];
    for (int i = 1; i < n; ++i)
    {
        left[i]=max(left[i-1],height[i]);
        /* code */
    }
    for (int i = n-2; i >= 0; --i)
    {
        right[i]=max(right[i+1],height[i]);
        /* code */
    }
    int sum=0;
    for (int i=0;i<n;++i){
        sum += min(left[i],right[i])-height[i];
    }
    return sum;
}

int trap_doublepoint(vector<int>& height) {
    int ans=0;
    int left=0,right=height.size()-1;
    int leftmax=0;
    int rightmax=0;
    while (left<right)
    {
        leftmax=max(leftmax,height[left]);
        rightmax=max(rightmax,height[right]);
        if(height[right]<height[left]){
            ans+=rightmax-height[right];
            right--;
        }
        else{
            ans+=leftmax-height[left];
            left++;
        }
        /* code */
    }
    return ans;
    
}

int main(){
    vector<int> height={4,2,0,3,2,5};
    cout<<trap(height);
    return 0;
}