//find nth node from the end of  the linked list
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
int getKthFromLast(Node* head , int k){
    int count=0;
    Node* curr=head;
    while(curr!=NULL){
        count++;
        curr= curr->next;
    }
    if(k > count){
        return -1;
    }
    curr= head;
    for(int i=0;i<count-k;i++){
        curr= curr->next;
        return curr->data;
    }
}
int main(){
    Node* node1= new Node(1);
    node1->next= new Node(2);
    node1->next->next= new Node(3);
    node1->next->next->next= new Node(4);
    Node* head= node1;
     cout<< getKthFromLast(head, 2)<<endl;

}