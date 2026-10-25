//reverse a linked list by k groups
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
Node* reverseKnodes(Node* head, int k){
    if(head==NULL || k<=1){
        return head;
    }
    Node* curr= head;
    Node* prev= NULL;
    Node* next= NULL;
    int count=0;
    while(curr !=NULL && count<k ){
        next= curr->next;
        curr->next=prev;
        prev=curr;
        curr= next;
        count++;
    }
    //recursive call
    if(next!=NULL){
        head->next= reverseKnodes(next, k);
    }
    return prev;
    
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;

    }
}
int main(){
    Node* node1= new Node(1);
    node1->next= new Node (2);
    node1->next->next= new Node(3);
    node1->next->next->next= new Node(4);
    Node* head= node1;
    head = reverseKnodes(head, 2);
    print(head);
    cout << endl;

}