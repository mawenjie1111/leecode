#include "iostream"
#include "vector"
using namespace std;
int candy(vector<int>& ratings) {;
    int len=ratings.size();
    vector<int> left(len,1);
    vector<int> right(len,1);
    for (int i = 1; i < len; i++)
    {
        if (ratings[i]>ratings[i-1])
        {
            left[i]=left[i-1]+1;
        }
    }
    for (int i = len-2; i >=0; i--)
    {
        if (ratings[i]>ratings[i+1])
        {
            right[i]=right[i+1]+1;
        }
    }
    int all=0;
    for (int i = 0; i < len; i++)
    {
        all+=max(left[i],right[i]);
    }
    return all;
}
int main(int argc, char const *argv[])
{
    vector<int> ratings={1,2,2};
    cout<<candy(ratings)<<endl;
    return 0;
}
