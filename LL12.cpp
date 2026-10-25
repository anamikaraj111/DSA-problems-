//Detect a cycle in a linked list
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
bool cycleDetect(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    Node* node1= new Node(3);
    node1->next= new Node(2);
    node1->next->next= new Node(0);
    node1->next->next->next= new Node(-4);
    Node* head= node1;
    if(cycleDetect(head)){
        cout<<"Cycle is present"<< endl;

    }
    else{
        cout<<"Cycle is not present"<<endl;
    }

}