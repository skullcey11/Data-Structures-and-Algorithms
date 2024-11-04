#include<iostream>
using namespace std;
int n = 100;
class Stack{
public:
    int top;
    int stacks[100];
    void push(int elem);
    void pop();
    void peek();
    void display();
    int isEmpty();
    int isFull();
    void sorting();
    Stack(){
        top = -1;
    }
};
int Stack :: isEmpty(){
    if (top<0){
        cout<<"\n Stack Underflow";
        return 0;
    }
}
int Stack :: isFull(){
    if (top>n-1){
        cout<<"\n Stack Overflow";
        return 0;
    }
}
void Stack :: push(int elem){
    isFull();
    top++;
    stacks[top] = elem;
}
void Stack :: pop(){
   isEmpty();
   top--;
}
void Stack :: peek(){
   isEmpty();
   cout<<"\n The top element is: "<<stacks[top];
}
void Stack :: display(){
   isEmpty();
   cout<<"\n The stack is: "<<endl;
   for (int i=0; i<=top; i++){
        cout<<stacks[i]<<" ";
   }
}
void Stack :: sorting(){
    isEmpty();
    for (int i = 1; i <= top; i++) {
        int key = stacks[i];
        int j = i - 1;
        while (j >= 0 && stacks[j] > key) {
            stacks[j + 1] = stacks[j];
            j = j - 1;
        }
        stacks[j + 1] = key;
    }
    cout << "\n Stack sorted successfully.";
}

int main(){
    int choice = 0;int element = 0;
    Stack stack1;
    do{
        cout<<"\n Stack Operations: ";
        cout<<"\n 1. Push";
        cout<<"\n 2. Pop";
        cout<<"\n 3. Peek";
        cout<<"\n 4. Display";
        cout<<"\n 5. Sorting";
        cout<<"\n 6. Exit";
        cout<<"\n Enter your choice";
        cin>>choice;
 switch (choice) {
            case 1:
                cout << "\n Enter the element to be entered: ";
                cin >> element;
                stack1.push(element);
                break;
            case 2:
                stack1.pop();
                break;
            case 3:
                stack1.peek();
                break;
            case 4:
                stack1.display();
                break;
            case 5:
                stack1.sorting();
                stack1.display();
                break;
            case 6:
                cout << "\n Exiting";
                break;
            default:
                cout << "\n Invalid option";
                break;
        }
 } while (choice != 6);
    return 0;
}
