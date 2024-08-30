#include <iostream>
using namespace std;
int n=100, queue[100], front =-1, rear=-1;
void add()
{
    int val=0;
    if(rear==n-1)
    {
        cout<<"kitchen busy"<<endl;
    }
    else
    {
        if(front==-1)
        {
            front++;
        }
        cout<<"billing token no:"<<endl;
        cin>>val;
        rear++;
        queue[rear]=val;
    }
}
void remove()
{
    if(front==-1)
    {
        cout<<"kitchen empty"<<endl;
    }
    else
    {
        cout<<"removing order no:"<<queue[front]<<endl;
        front++;
    }
}
void display()
{
    if(front==-1)
    {
        cout<<"no orders"<<endl;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<endl;
        }
        cout<<"thats it"<<endl;
    }
}
int  main()
{
    cout<<"canteen billing token:"<<endl;
    int ch=1;
    cout<<"orders for today:"<<endl;
    cin>>n;
    while(ch==1||ch==2||ch==3)
    {
        cout<<"1) add an order, 2) done with an order, 3) display remaining orders"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: add();
            break;
            case 2: remove();
            break;
            case 3: display();
            break;
        }
        cout<<"select an option"<<endl;
    }
    return 0;
}