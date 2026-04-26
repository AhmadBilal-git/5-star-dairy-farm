#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = nullptr;
	}
};
class List {
	Node* head; Node* tail;
public:
	List() { head = tail = nullptr; };
	void display() {
		if (head == nullptr) {
			cout << "Empty List." << endl; return;
		}
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
	void front(int val) {
		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	void back(int val) {
		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
	void search(int target) {
		Node* temp = head; int pos = 1;
		if (head == nullptr) {
			cout << "Empty List" << endl;
			return;
		}
		while (temp != nullptr) {
			if (target == temp->data) {
				cout << "Target " << target << " fount at position " << pos << endl;
				return;
			}
			temp = temp->next; pos++;
		}
			cout << "Target not found" << endl;
	}
	void dfront() {
		if (head == nullptr) {
			cout << "Empty List" << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head == nullptr)tail = nullptr;
		delete temp;
		
	}
	void dend() {
		if (head == nullptr) { cout << "Empty list" << endl; return; }
		if (head == tail) {
			delete head;
			head = tail = nullptr; return;
		}
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = nullptr;
	}
	void dspecific(int target) {
		if (head == nullptr) {
			cout << "Empty list" << endl;
			return;
		}
		// delete from head
		while (head != nullptr && head->data == target) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		if (head == nullptr) {
			tail = nullptr;
			cout << "All matching nodes deleted." << endl;
			return;
		}
		Node* curr = head;
		Node* prev = nullptr;
		while (curr != nullptr) {
			if (curr->data == target) {
				Node* temp = curr;          
				prev->next = curr->next;
				curr = curr->next;
				delete temp;                
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
		// update tail
		tail = head;
		while (tail != nullptr && tail->next != nullptr) {
			tail = tail->next;
		}
		cout << "All occurrences of " << target << " deleted." << endl;
	}
	void reverse() {
		if (head == nullptr || head->next == nullptr) { cout << "Empty list." << endl; return; }
		tail = head;//old head now tail
		Node* prev = nullptr;
		Node* curr = head;
		Node* next = nullptr;
		while (curr != nullptr) {
			next = curr->next;
			curr->next = prev;//reverse link
			prev = curr;//moving previous
			curr = next;//moving current
		}
		head = prev;//new head
	}
	void delMN(int m, int n) {
		if (head == nullptr) { cout << "Empty list" << endl; return; }
		Node* curr = head;
		Node* prev = nullptr;

		while (curr != nullptr) {
			//skip M nodes
			for (int i = 0; i < m && curr != nullptr; i++) {
				prev=curr;
				curr = curr->next;
			}
			//if we reached at end
			if (curr == nullptr)return;
			//delete N nodes
			for (int i = 0; i < n && curr != nullptr; i++) {
				Node* temp = curr;
				curr = curr->next;
				delete temp;
			}
			//reconnect baki nodes
			if (prev != nullptr) {
				prev->next = curr;
			}
			if (head == nullptr) {
				head = curr;
			}
		}
		tail = curr;
		while (tail != nullptr && tail->next != nullptr) {
			tail = tail->next;
		}
		cout << endl;
	}
	
};
int main() { 
	List l;
	l.front(3); l.front(2); l.front(1);
	l.back(4); l.back(5); l.back(5); l.back(5); l.back(6); l.back(7); l.back(8); l.back(9);
	l.display();
	cout << "Reverse list: "; l.reverse();
	l.display();
	l.delMN(2, 3); l.display();
	l.dfront();
	l.dend();
	l.dspecific(5);
	l.dspecific(11);
	l.display();
	l.search(5); l.search(9);
	return 0;
}
