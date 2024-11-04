#include <iostream>
using namespace std;

class node 
{
public:
    int val;
    node* left;
    node* right;

    node(int value) : val(value), left(NULL), right(NULL) {}
};

class binarytree 
{
public:
    node* root;
    binarytree() : root(NULL) {}

    void insertfunc(node* root, int value) 
    {
        if (value < root->val) 
        {
            if (!root->left) 
            {
                root->left = new node(value);
            } else 
            {
                insertfunc(root->left, value);
            }
        } 
        else 
        {
            if (!root->right) 
            {
                root->right = new node(value);
            } 
            else 
            {
                insertfunc(root->right, value);
            }
        }
    }

    void insert(int value) 
    {
        if (!root) 
        {
            root = new node(value);
        } 
        else 
        {
            insertfunc(root, value);
        }
    }

    node* minValueNode(node* root) 
    {
        node* current = root;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    node* del(node* root, int k) 
    {
        if (root == nullptr)
        {
            return root;
        }  

        if (k < root->val) 
        {
            root->left = del(root->left, k);
        } 
        else if (k > root->val) 
        {
            root->right = del(root->right, k);
        } 
        else
        {
            
            if (root->left == nullptr)
            {
                node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) 
            {
                node* temp = root->left;
                delete root;
                return temp;
            }
            
            node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = del(root->right, temp->val);
        }
        return root;
    }

    void preorder(node* newnode) {
        if (newnode != NULL) {
            cout << newnode->val << endl;
            preorder(newnode->left);
            preorder(newnode->right);
        }
    }
    void inorder(node* newnode) {
        if (newnode != NULL) {
            inorder(newnode->left);
            cout << newnode->val << endl;
            inorder(newnode->right);
        }
    }
    void postorder(node* newnode) {
        if (newnode != NULL) {
            postorder(newnode->left);
            postorder(newnode->right);
            cout << newnode->val << endl;
        }
    }
};

int main() {
    binarytree bt;
    int ch = 0;
    int val = 0;
    do {
        cout << "Insert value:" << endl;
        cin >> val;
        bt.insert(val);
        cout << "1. Continue, Else not" << endl;
        cin >> ch;
    } while (ch == 1);

    cout << "To delete: " << endl;
    cin >> val;
    bt.del(bt.root, val);

    cout << "Traversals:" << endl;

    cout << "Preorder:" << endl;
    bt.preorder(bt.root);

    cout << "Inorder:" << endl;
    bt.inorder(bt.root);

    cout << "Postorder:" << endl;
    bt.postorder(bt.root);

    cout << "End" << endl;
}
