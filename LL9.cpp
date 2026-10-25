//middle of the linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node* getMiddle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow= head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            fast= fast->next;
        }
        slow=slow->next;
    }
    return slow;

}
int main(){
    Node* node1= new Node(10);
    node1->next= new Node(20);
    node1->next->next= new Node(30);
    node1->next->next->next= new Node(40);
    Node* head= node1;
    Node* middle = getMiddle(head);
    if(middle != NULL){
        cout << "Middle element: " << middle->data << endl;
    }

    return 0;
}