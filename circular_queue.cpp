#include <iostream>
using namespace std;
int n=100, cqueue[100], front =-1, rear=-1;
void add()
{
    int val=0;
    if((front==0 && rear==n-1)||(front==rear+1))
    {
        cout<<"kitchen busy"<<endl;
    }
    else

    {
        if(front==-1)
        {
            front++;
            rear++;
        }
        else
        {
            if(rear==n-1)
            {
                rear=0;
            }
            else
            {
                rear++;
            }
        }
        cout<<"billing token no:"<<endl;
        cin>>val;
        cqueue[rear]=val;
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
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            if(front==n-1)
            {
                front=0;
            }
            else
            {
                front++;
            }
        }
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
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<cqueue[i]<<endl;
            }
            cout<<"thats it"<<endl;
        }
        else
        {
            for(int i=front;i<=0;i++)
            {
                cout<<cqueue[i]<<endl;
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<cqueue[i]<<endl;
            }
            cout<<"thats it"<<endl;
        }
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