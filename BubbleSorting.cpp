#include <iostream>
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

    first.push_front("Ali", 012, "ali@mail.com");
    first.push_front("Abdullah", 345, "ali@mail.com");
    first.push_front("Ahmad", 678, "ali@mail.com");

    first.push_back("Anas", 901, "ali@mail.com");
    first.push_back("Obaid", 234, "ali@mail.com");

    first.display();

    first.search_by_name("Ali Hamza");

    first.sorting_list();
    cout << endl;
    first.display();

    first.deleteContact("Ali");
    cout << endl;
    first.display();
}