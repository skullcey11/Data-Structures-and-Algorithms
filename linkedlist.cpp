/*#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
};
class LinkedList{
private:
    Node *head;
public:
    LinkedList() : head(NULL) {}
    void insert_start(int data);
    void insert_end(int data);
    void insert_middle(int data, int pos);
    void del_start();
    void del_end();
    void del_middle(int pos);
    int siz();
    void display();
};
void LinkedList :: insert_start(int data){
    Node *new_node = new Node;
    new_node->data = data;
    if (head == NULL){
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}
void LinkedList :: insert_middle(int data, int pos){
    Node *new_node = new Node;
    new_node->data = data;
    if (pos == 0){
        new_node->next = head;
        head = new_node;
        return;
    }
    Node *temp = head;
    for (int i=1; i<pos-1; i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void LinkedList :: insert_end(int data){
    Node *new_node = new Node;
    Node *temp = head;
    new_node->data = data;
    if (head == NULL){
        head = new_node;
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    new_node->next = NULL;
    temp->next = new_node;
}
void LinkedList :: del_start(){
    Node *temp = head;
    temp = head->next;
}
void LinkedList :: del_end(){
    Node *temp = head;
    int len = siz();
    for(int i=1; i<len-1; i++){
        temp = temp->next;
    }
    temp->next = NULL;
}
void LinkedList :: del_middle(int pos){
    Node *temp = head;
    for(int i=1; i<pos-1; i++){
        temp = temp->next;
    }
    Node *toDel = temp->next;
    temp->next = toDel->next;
    delete toDel;
}
int LinkedList :: siz(){
    Node *temp = head;
    int len = 0;
    while (temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void LinkedList :: display(){
    cout<<"\n The linked list is: ";
    Node *temp = new Node();
    temp = head;
    while (temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main(){
    LinkedList L1;
    L1.insert_start(30);
    L1.insert_start(20);
    L1.insert_start(10);
    L1.insert_end(40);
    L1.insert_end(50);
    L1.insert_end(60);
    L1.insert_middle(70, 7);
    L1.display();
    L1.del_start();
    L1.del_end();
    L1.del_middle(3);
    L1.display();
    return 0;
}*/

#include<iostream>
using namespace std;
class Node{
    public:
    string song;
    Node *next;
    Node(){
        song = "";
        next = NULL;
    }
};
class LinkedList{
private:
    Node *head;
public:
    LinkedList() : head(NULL) {}
    void insert_end(string song);
    void del_song(string song);
    void display();
};

void LinkedList :: insert_end(string song){
    Node *new_node = new Node;
    Node *temp = head;
    new_node->song = song;
    if (head == NULL){
        head = new_node;
        return;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    new_node->next = NULL;
    temp->next = new_node;
}

void LinkedList :: del_song(string song){
    if (head == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }
    if (head->song == song) {
        Node *toDel = head;
        head = head->next;
        delete toDel;
        return;
    }
    int counter = 0;
    Node *temp = head;
    while (temp->next != NULL){
        if (temp->next->song == song){
            counter++;
            Node *toDel = temp->next;
            temp->next = toDel->next;
            cout<<"\n Deleted";
            delete toDel;
            return;
        }
        temp = temp->next;
    }
    if (counter == 0){
        cout<<"\n Song not found";
    }
}

void LinkedList :: display(){
    cout<<"\n The playlist is: ";
    Node *temp = new Node();
    temp = head;
    while (temp != NULL){
        cout<<temp->song<<"-->";
        temp = temp->next;
    }
    cout<<"End";
}
int main(){
    LinkedList playlist;
    int choice=0;
    string new_song, del_song;
    do{
        cout<<"\n 1. Add a song to the playlist.";
        cout<<"\n 2. Remove a song from the playlist.";
        cout<<"\n 3. View the playlist";
        cout<<"\n 4. Exit"<<endl<<" ";
        cin>>choice;
        cin.ignore();
        switch(choice){
        case 1:
            cout<<"\n Enter the song name you want to add: ";
            getline(cin, new_song);
            playlist.insert_end(new_song);
            break;
        case 2:
            cout<<"\n Enter the song name you want to remove: ";
            getline(cin, del_song);
            playlist.del_song(del_song);
            break;
        case 3:
            playlist.display();
            break;
        case 4:
            cout<<"\n Exitting";
            return 0;
            break;
        default:
            cout<<"\n Error";
            break;
        }

    }
    while (choice != 4);
    return 0;
}

