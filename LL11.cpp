//detect if a LL is Circular LL
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
bool isCircular(Node* head){
    if(head==NULL){
        return true;
    }
    if(head->next==NULL){
        return true;
    }
    Node* temp= head->next;
    while(temp!=NULL && temp!=head){
        temp= temp->next;
    }
    if(temp==NULL){
        return false;
    }
    if(temp==head){
        return true;
    }
}
int main(){
    Node* node1= new Node(10);
    node1->next= new Node(20);
    node1->next->next= new Node(30);
    Node* head= node1;
    if(isCircular){
        cout<<"This is circular linked list"<<endl;
    }
    if(!isCircular){
        cout<<"This is not a circular linked list"<<endl;
    }

}