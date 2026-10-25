//remove duplicates from sorted linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        this->next = NULL;
    }
};

Node* deleteDuplicates(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void freeList(Node* head){
    Node* curr = head;
    while(curr != NULL){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

int main(){
    Node* node1 = new Node(10);
    node1->next = new Node(10);
    node1->next->next = new Node(20);

    Node* head = node1;
    head = deleteDuplicates(head);
    print(head);
    freeList(head);
    return 0;
}