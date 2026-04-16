#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = nullptr;
        }
};

class list{
    public:
        node* head = nullptr;

        void pushFront(int val){
            node* newNode = new node(val);
            if(head == nullptr){
                head = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
        }

        void findMiddle(){
          node* temp = head;
          int count = 0;
          while(temp != nullptr){
            temp = temp->next;
            count++;
          }
          temp = head;
          
          if(count%2 == 0){
            for(int i = 0; i < count/2-1; i++){
            temp = temp->next;}
            cout<<temp->data<<"-"<<temp->next->data;
          }else{
            for(int j = 0; j < count/2; j++){
                temp = temp->next;
            }
            cout<<temp->data<<endl;
          }
      

          

        }
        void display(){
            node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<"<=>";
                temp = temp->next;
            }
        }
};

int main(){
    list list1;
    list1.pushFront(4);
    list1.pushFront(3);
    list1.pushFront(2);
    list1.pushFront(1);

    list1.display();

    list1.findMiddle();

    return 0;
}