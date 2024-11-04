/*#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node (int n)
    {
        data = n;
        next = NULL;
    }
};
class q
{
public:
    node *rear=NULL;
    node *fr = NULL;
    void ins(int);
    void del();
    void display();
};

void q::ins(int val)
{
    node *newnode = new node(val);
    newnode->next = NULL;
    if (fr == NULL)
    {
        fr = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void q::del()
{
    node *temp = fr;
    temp = temp->next;
    fr = temp;
}

void q::display()
{
    node *temp = fr;
    while (temp != NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"NULL";
    }
}

int main()
{
    q Q;
    int ch, val;
    do
    {
        cout << "1: enqueue"<<endl;
        cout << "2: dequeue"<<endl;
        cout << "3: display queue"<<endl;
        cout << "4: exit"<<endl;
        cout << "enter choice: "<<endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "value to be inserted: "<<endl;
            cin >> val;
            Q.ins(val);
            break;
        }
        case 2:
        {
            Q.del();
            cout << "value dequeued"<<endl;
            break;
        }
        case 3:
        {
            Q.display();
            break;
        }
        }
    }
    while (ch != 4);
    
    return 0;
}*/

#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *next;
        node (int n)
        {
            data = n;
            next = NULL;
        }
};
class Stack
{
public:
    node *top = NULL;
    void push(int);
    void pop();
    void display();
};
void Stack::push(int val)
{
    node *newnode = new node(val);
    newnode->next = top;
    top = newnode;
}
void Stack::pop()
{
    node *temp = top;
    temp = temp->next;
    top = temp;
}
void Stack::display()
{
    node *temp = top;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    if (temp==NULL)
    {
        cout<<"NULL";
    }
}
int main()
{
    Stack s;
    int val, ch;
    do
    {
        cout << "1: push"<<endl;
        cout << "2: pop"<<endl;
        cout << "3: display stack"<<endl;
        cout << "4: exit"<<endl;
        cout << "enter choice: "<<endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "value to be pushed: "<<endl;
            cin >> val;
            s.push(val);
            break;
        }
        case 2:
        {
            s.pop();
            cout << "value popped"<<endl;
            break;
        }
        case 3:
        {
            s.display();
            break;
        }
        }
    }
    while (ch != 4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.display();
}
