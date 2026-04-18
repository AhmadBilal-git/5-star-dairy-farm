#include <iostream>
using namespace std;

class Node
{
public:
string name;
    int phone_no;
    string email;
    Node *next;

    Node(string name,int phone, string email)
    {
        this->name = name;
        this->phone_no = phone;
        this->email = email;
        next = nullptr;
    }
};


class Linklist{
    private : 
    Node * head;
    public:
    Linklist(){
        head = nullptr;
    }

    //End pe node enter krna 
    void push_back(string name, int val, string addr){
        Node * new_node = new Node(name,val,addr);

        if(head == nullptr){
            head = new_node;
            return;
        }
        else
        {
            Node * temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    //Start pe node add krna
    void push_front(string name, int val,string addr){
        Node * new_node = new Node(name,val,addr);

        if(head == nullptr){
            head = new_node;
            return;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }

    //Node k naam se search krna
    void search_by_name(string name){
        Node * temp = head;
        while(temp != nullptr){
            if(temp->name == name){
                cout<<"Person Name is : "<<temp->name << " Email : "<<temp->email<<" Phone Number : "<<temp->phone_no<<endl;
                return;
            }
            temp = temp->next;
        }

        //Agr node na hu tu
        cout<<"Bache name sahii enter kr(Record not found)"<<endl;
    }
    
    //Node ko display krne k lya
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<"Name : "<<temp->name<<" "
                "Email : "<<temp->email<<" "
                "Phone Number : "<<temp->phone_no<<endl;
            temp = temp->next;
        }
    }

};
int main()
{
    Linklist first;

    first.push_front("Ali",012,"ali@mail.com");
    first.push_front("Abdullah",345,"ali@mail.com");
    first.push_front("Ahmad",678,"ali@mail.com");

    first.push_back("Anas",901,"ali@mail.com");
    first.push_back("Obaid",234,"ali@mail.com");

    first.display();

    first.search_by_name("Ali Hamza");

    first.display();
    
}