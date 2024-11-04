#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node* left;
    node* right;

    node(int value): val(value),left(NULL),right(NULL) {}
};

class binarytree
{
public:
    node* root;
    binarytree(): root(NULL){}

    void insertfunc(node* root, int value)
    {
        if(value < root->val)
        {
            if(!root->left)
            {
                root->left= new node(value);
            }
            else
            {
                insertfunc(root->left, value);
            }
        }
        else
        {
            if(!root->right)
            {
                root->right= new node(value);
            }
            else
            {
                insertfunc(root->right, value);
            }
        }
    }

    void insert(int value)
    {
        if(!root)
        {
            root = new node(value);
        }
        else
        {
            insertfunc(root, value);
        }
    }

    void preorder(node* newnode)
    {
        if(newnode!=NULL)
        {
            cout<<newnode->val<<endl;
            preorder(newnode->left);
            preorder(newnode->right);
        }
    }
    void inorder(node* newnode)
    {
        if(newnode!=NULL)
        {
            inorder(newnode->left);
            cout<<newnode->val<<endl;
            inorder(newnode->right);
        }
    }
    void postorder(node* newnode)
    {
        if(newnode!=NULL)
        {
            postorder(newnode->left);
            postorder(newnode->right);
            cout<<newnode->val<<endl;
        }
    }
};
int main()
{
    binarytree bt;
    int ch=0;
    int val=0;
    do
    {
        cout<<"insert value:"<<endl;
        cin>>val;
        bt.insert(val);
        cout<<"1. Continue, Else not"<<endl;
        cin>>ch;
    }while(ch==1);
    cout<<"traversals:"<<endl;
    cout<<"preorder:"<<endl;
    bt.preorder(bt.root);
    cout<<"inorder:"<<endl;
    bt.inorder(bt.root);
    cout<<"postorder:"<<endl;
    bt.postorder(bt.root);
    cout<<"end"<<endl;
}
