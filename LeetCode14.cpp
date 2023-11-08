#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int len=strs.size();
    int result_len=strs[0].length();
    string temp=strs[0];
    for (int i = 1; i < len; i++)
    {
        int temp_len=0;
        for (int j = 0; j < strs[0].length(); j++){
            if(strs[i][j]==temp[j]){
                temp_len++;
            }
            else{
                break;
            }
        }
        if(temp_len<=result_len){
            result_len=temp_len;
        }
    }
    return strs[0].substr(0,result_len);
    
    }