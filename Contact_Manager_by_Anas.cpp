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
	return 0;
}
