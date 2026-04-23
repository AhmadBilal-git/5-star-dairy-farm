#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string name;
    int phone_no;
    string email;
    Node *next;

    Node(string name, int phone, string email)
    {
        this->name = name;
        this->phone_no = phone;
        this->email = email;
        next = nullptr;
    }
};

class Linklist
{
private:
    Node *head;

public:
    Linklist()
    {
        head = nullptr;
    }

    // End pe node enter krna
    void push_back(string name, int val, string addr)
    {
        Node *new_node = new Node(name, val, addr);

        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        
    }

    // Start pe node add krna
    void push_front(string name, int val, string addr)
    {
        Node *new_node = new Node(name, val, addr);

        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }

    // Node k naam se search krna
    void search_by_name(string name)
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            if (temp->name == name)
            {
                cout << "Person Name is : " << temp->name << " Email : " << temp->email << " Phone Number : " << temp->phone_no << endl;
                count++;
            }
            temp = temp->next;
        }

        if(count> 1){
            cout<<name <<" match with "<<count<<" nodes "<<endl;
        }else if(count == 0){
            cout<<"No match found with the name : "<<name <<endl;
        }
    }

    // Delete a contact by name
    void deleteContact(string name)
    {

        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            if (head->name == name)
            {
                delete head;
                head = nullptr;
                return;
            }
        }

        if (head->name == name)
        {
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->next->name == name)
            {
                Node *del = temp->next;
                temp->next = del->next;
                delete del;
                return;
            }
            temp = temp->next;
        }

        // Agr last wala node ha tu
        temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp->next != nullptr && temp->next->name == name)
        {
            Node *del = temp->next;
            temp->next = nullptr;
            delete del;
            return;
        }
        cout << "Name not found" << endl;
    }

    void sorting_list()
    {
        Node *temp = head;
        Node *prev = nullptr;
        Node *ahead = nullptr;

        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        // Bubble sort
        for (int i = 0; i < count - 1; i++)
        {
            temp = head;
            prev = nullptr;
            for (int j = 0; j < count - 1 - i && temp != nullptr && temp->next != nullptr; j++)
            {
                ahead = temp->next;
                if (temp->name > ahead->name)
                {
                    if (prev == nullptr)
                    {
                        head = ahead;
                    }
                    else
                    {
                        prev->next = ahead;
                    }
                    temp->next = ahead->next;
                    ahead->next = temp;
                    prev = ahead;
                    temp = temp->next;
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
    }

    // Node ko display krne k lya
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "Name : " << temp->name << " "
                                               "Email : "
                 << temp->email << " "
                                   "Phone Number : "
                 << temp->phone_no << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Linklist first;
    string name,email;
    int phone;
    int choice;
    do{
        cout<<"\n     Contact Management System   \n";
        cout<<"1 : Add Contact at end  \n";
        cout<<"2 : Add Contact at start \n";
        cout<<"3 : Search Contact by name \n";
        cout<<"4 : Delete Contact by name \n";
        cout<<"5 : Sort the Contacts Alphabetically \n";
        cout<<"6 : Display the Contacts \n";
        cout<<"0 : Enter 0 to exit \n";
        cout<<"Enter the Number to perform Operation : ";
        cin>>choice;
        cin.ignore();
        
        switch (choice)
        {
        case 1:
            cout<<"Enter the Contact Details :" <<endl;
            cout<<"Name : ";
            getline(cin,name);
            cout<<"Email : ";
            getline(cin,email);
            cout<<"Phone Number : ";
            cin>>phone;
            first.push_back(name,phone,email);
            cout<<"Contact Added Successfylly \n";
            break;
        case 2:
            cout<<"Enter the Contact Details :" <<endl;
            cout<<"Name : ";
            getline(cin,name);
            cout<<"Email : ";
            getline(cin,email);
            cout<<"Phone Number : ";
            cin>>phone;
            first.push_front(name,phone,email);
            cout<<"Contact Added Successfully \n";
            break;
        case 3:
            cout<<"Enter the Contact Name to Search " <<endl;
            cout<<"Name : ";
            getline(cin,name);
            first.search_by_name(name);
            break;
        case 4:
            cout<<"Enter the Contact Name to Delete :" <<endl;
            cout<<"Name : ";
            getline(cin,name);
            first.deleteContact(name);
            cout<<"Contact Deleted Successfully \n";
            break;
        case 5:
            first.sorting_list();
            cout<<"Contacts Sorted Successfully \n";
            first.display();
            break;
        case 6:
            first.display();
            break;
        case 0:
           cout<<"Closing...\n";
           return 0;
        default:
            cout<<"Invalid Input \n";
            break;
        }
    }
    while(choice != 0);
}