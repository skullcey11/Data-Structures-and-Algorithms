#include <iostream>
#include <string>
#include <string.h>
using namespace std;

char tempstk[100];
int top=-1;

void pushstk(char ch)
{
    top++;
    tempstk[top]=ch;
}
void peekstk(string exp)
{
    int c=0;
    for(int j=0;j<=top;j++)
    {
       if(tempstk[j]=='('||exp[j]=='{'||exp[j]=='[')
       {
           c++;
       }
    }
    if(c%2!=0)
    {
        cout<<"balanced"<<endl;
    }
    else
    {
        cout<<"not balanced"<<endl;
    }

}
void checker(string exp)
{
    for(int j=0;j<=exp.length();j++)
    {
        if(exp[j]=='('||exp[j]=='{'||exp[j]=='[')
        {
            pushstk(exp[j]);
        }
        else if(exp[j]==')'||exp[j]=='}'||exp[j]==']')
        {
            peekstk(exp);
        }
    }
}
int main()
{
    string input;
    cout<<"enter expression:"<<endl;
    cin>>input;
    checker(input);
    return 0;
}
