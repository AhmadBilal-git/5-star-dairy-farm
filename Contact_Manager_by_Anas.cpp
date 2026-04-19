#include<iostream>
using namespace std;
class Node {
public:
	string name;
	string phone;
	string mail;
	Node* next;
	Node(string n, string p, string m) {
		name = n; phone = p; mail = m; next = nullptr;
	}
};

class list {
	Node* head;
	Node* tail;
public:
	list() {
		head = tail = nullptr;
	}
	void addFront(string n, string p, string m) {
		Node* newNode = new Node(n, p, m);
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	void addBack(string n, string p, string m) {
		Node* newNode = new Node(n, p, m);
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
	void search(string target) {
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->name == target) {
				cout << "----FOUND----" << endl;
				cout << "Name: " << temp->name << "\nPhone: " << temp->phone << "\nMail: " << temp->mail << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "No Result Found." << endl;
	}
	void Del(string target) {
		cout << "Deleting " << target << endl;
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		if (head->name == target) {
			Node* temp = head;
			head = head->next;
			if (head == nullptr)tail = nullptr;
			delete temp;
			cout << target << " deleted!" << endl;
			return;
		}
		Node* temp = head;
		Node* prev = nullptr;
		while (temp != nullptr) {
			if (temp->name == target) {
				prev->next = temp->next;
				if (temp == tail)tail = prev;
				delete temp;
				cout << target << " deleted!" << endl;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
		cout << target << " not found." << endl;
	}
	void sorting() {
		if (head == nullptr) {
			cout << "Empty List." << endl;
			return;
		}
		bool swapped;
		do {
			swapped = false;
			Node* temp = head;
			while (temp->next != nullptr) {
				if (temp->name > temp->next->name) {
					swap(temp->name, temp->next->name);
					swap(temp->phone, temp->next->phone);
					swap(temp->mail, temp->next->mail);
					swapped = true;
				}
				temp = temp->next;
			}
		} while (swapped);
	}
	void display() {
		if (head == nullptr) {
			cout << "List is Empty." << endl;
			return;
		}
		Node* temp = head;
		while (temp != nullptr) {
			cout << "Name: " << temp->name << "\nPhone: " << temp->phone << "\nMail: " << temp->mail << endl;
			temp = temp->next;
		}
	}
};

int main() {
	list l;
	string name;
	string phone;
	string mail;
	int input;
	do {
		cout << "\n1. Test All Functions at once." << endl;
		cout << "2. Push Contact from Front." << endl;
		cout << "3. Push Contact from Back." << endl;
		cout << "4. Display All Contacts." << endl;
		cout << "5. Arrange All Contacts(sorting)." << endl;
		cout << "6. Search Contact By name." << endl;
		cout << "7. Delete Contact By name." << endl;
		cout << "8. Exit." << endl;
		cout << "Choose: ";
		cin >> input;
		switch (input) {
		case 1:
			l.addFront("Anas", "456", "anas@gmail.com");
			l.addFront("Ahmed", "789", "ahmed@gmail.com");
			l.addBack("Ali", "123", "ali@gmail.com");
			cout << "====All Contacts====" << endl;
			l.display();
			cout << endl;
			cout << "====All Contacts After Sorting====" << endl;
			l.sorting();
			l.display();
			cout << "====Search for Anas====" << endl;
			l.search("Anas");
			cout << endl;
			cout << "====Search for Abdullah====" << endl;
			l.search("Abdullah");
			cout << endl;
			cout << "====Delete Anas====" << endl;
			l.Del("Anas");
			cout << endl;
			cout << "====Display after Delete====" << endl;
			l.display();
			break;
		case 2:
			cout << "Adding Contact via PUSH_FRONT." << endl;
			cout << "Enter Name: "; cin >> name;
			cout << "Enter Phone number: "; cin >> phone;
			cout << "Enter Email Address: "; cin >> mail;
			l.addFront(name, phone, mail);
			cout << "Contact Saved." << endl;
			break;
		case 3:
			cout << "Adding Contact via PUSH_BACK." << endl;
			cout << "Enter Name: "; cin >> name;
			cout << "Enter Phone number: "; cin >> phone;
			cout << "Enter Email Address: "; cin >> mail;
			l.addBack(name, phone, mail);
			cout << "Contact Saved." << endl;
			break;
		case 4:
			cout << "====All Contacts====" << endl;
			l.display();
			cout << endl;
			break;
		case 5:
			cout << "====All Contacts After Sorting====" << endl;
			l.sorting();
			l.display();
			break;
		case 6:
			cout << "Enter Name: "; cin >> name;
			cout << "Searching for "<<name<<"..." << endl;
			cin >> name;
			l.search(name);
			cout << endl;
			break;
		case 7:
			cout << "Enter Name: "; cin >> name;
			cout << "Searching for " << name << "..." << endl;
			l.Del(name);
			cout << endl;
			break;
		case 8:
			cout << "Program Ended.";
			break;
		default:
			cout << "Invalid input !";
			break;
		}

	} while (input != 8);
		return 0;
}
