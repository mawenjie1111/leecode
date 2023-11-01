#include "iostream"
#include "vector"
using namespace std;
int main(int argc, char const *argv[])
{
    string s="hello world";
    char *p= &s[0];
    char *last= &s[0];
    char **q;
    for (int i = 0; i < s.size(); i++)
    {
        if(*p==' ')
        {
            p[i]='\0';
            //*q=&last[i+1];
            last=p;
            cout<<*(last+1)<<endl;
        }
        p++;
        /* code */
    }
    cout<<&last<<endl;
    return 0;
}
