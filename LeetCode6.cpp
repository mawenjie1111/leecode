#include <iostream>
#include <vector>
#include <string>
using namespace std;
string convert(string s, int numRows) {
    if(numRows==1)
    {
        return s;

    }
    string re;
    bool change=true;
    int row=0;
    while(row<numRows)
    {
        int index=row;
        string temp="";
        change=true;
        while(index<s.size())
        {
            temp.append(1,s[index]);
            if(row==0)
            {
                index=index+(numRows-1-row)*2;
            }
            if(row==numRows-1)
            {
                index=index+row*2;
            }
            if(row!=0&&row!=numRows-1){
                if(change)
                {
                index=index+(numRows-1-row)*2;
                change=false;
          
                }
                else{
                index=index+row*2;
                change=true;
                }
            }
            if(index>=s.size())
            {
                break;
            }

        }
        row++;
        cout<<temp<<endl;
        re.append(temp);
        /* code */
    }
    return re;
}
string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        string res;
        for (const string &row : rows)
            res += row;
        return res;
}

int main()
{
    string s = "PAYPALISHIRING";
    cout << convert(s,3) << endl;
    return 0;
}
