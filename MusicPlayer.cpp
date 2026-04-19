#include<iostream>
using namespace std;
class Node {
public:
	string Id, title, artist, duration;
	Node* next;
	Node* prev;
	Node(string id, string t, string art, string dur) {
		Id = id; title = t; artist = art; duration = dur;
		next = prev = nullptr;
	}
};
class SL {
	Node* head;//first song
	Node* tail;//last song
	Node* curr;//current song 
	int size; //for total songs
public:
	SL() {
		head = tail = curr = nullptr;
		size = 0;
	}
	void addSong(string id, string t, string art, string dur) {
		Node* newNode = new Node(id, t, art, dur);
		if (head == nullptr) {
			head = tail = curr = newNode;
			newNode->next = newNode->prev = newNode;//circular LL 
			size++;
			cout << "Added: [" << id << "] " << t << endl;
			return;
		}
		else {
			newNode->next = head;
			newNode->prev = tail;
			tail->next = newNode;
			head->prev = newNode;
			tail = newNode;
		}
		size++;
		cout << "Added: [" << id << "] " << t << endl;
	}
	void delSong(string did) {
		if (!head) {
			cout << "Playlist empty" << endl;
			return;
		}
		Node* temp = head;
		do {
			if (temp->Id == did) {
				if (size == 1) {
					delete temp;
					head = tail = curr = nullptr;
					size = 0;
					cout << "\nSong [" << did << "] deleted!" << endl;
					return;
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				if (temp == head) head = temp->next;
				if (temp == tail) tail = temp->prev;
				if (temp == curr) curr = temp->next;
				delete temp;
				size--;
				cout << "\nSong [" << did << "] deleted!" << endl;
				return;
			}
			temp = temp->next;
		} while (temp != head);
		cout << "\nSong not found" << endl;
	}
	void playNext() {
		if (!curr) {
			return;
		}
		curr = curr->next;
		cout << "Now Playing: [" << curr->Id << "] "
			<< curr->title << " - " << curr->artist
			<< " (" << curr->duration << ")" << endl;
		if (curr == head) cout << "(Loop at beginning!)" << endl;
	}
	void playBack() {
		if (!curr)return;
		curr = curr->prev;
		cout << "Now Playing: [" << curr->Id << "] "
			<< curr->title << " - " << curr->artist
			<< " (" << curr->duration<<")" << endl;
		if (curr == tail) cout << "(Loop at end!)" << endl;
	}
	void jumpTo(string jid) {
		if (!head) return;
		Node* temp = head;
		do {
			if (temp->Id == jid) {
				curr = temp;
				cout << "Jumped to: [" << jid << "] "
					<< temp->title << " - " << temp->artist << endl;
				return;
			}
			temp = temp->next;
		} while (temp != head);
		cout << "Song ID " << jid << " not found!" << endl;
	}
	void displayList() {
		if (head == nullptr) {
			cout << "No song exists" << endl;
			return;
		}
		cout << "\n=====Total " << size << " Songs=====" << endl;
		Node* temp = head;
		int i = 1;
		do {
			cout << i++ << ".[" << temp->Id << "] " << temp->title << " by " << temp->artist << " (" << temp->duration << ")";
			if (temp == curr) cout << "  << NOW PLAYING";
			cout << endl;
			temp = temp->next;
		} while (temp != head);
	}
};
int main() {
	SL sl;
	int choice;
	string Id, title, artist, duration;
	do {
		cout << "\n1. Test All Functions at once." << endl;
		cout << "2. Add New Song." << endl;
		cout << "3. See Full Playlist." << endl;
		cout << "4. Delete Song(by ID)." << endl;
		cout << "5. Play Next Song." << endl;
		cout << "6. Play Previous Song." << endl;
		cout << "7. Jump to Specific Song." << endl;
		cout << "8. Exit." << endl;
		cout << "Choose: ";
		cin >> choice;
		switch (choice) {
		case 1:
			sl.addSong("101", "Muni Badnam Hoi", "Ali Raza Sindhu", "200s");
			sl.addSong("102", "Bado Badi", "Chahat Fateh Ali Khan", "2000s");
			sl.addSong("103", "Bilo Dhumka laga", "Ahmad Bilal", "600s");
			sl.addSong("104", "Dududu duu", "Abdullah Raheem", "250s");
			sl.displayList();
			sl.delSong("105");
			sl.displayList();
			sl.delSong("104");
			sl.displayList();
			sl.playNext();
			sl.playBack();
			sl.jumpTo("103");
			break;
		case 2:
			cout << "Enter Title: "; cin >> title;
			cout << "Enter Song ID: "; cin >> Id;
			cout << "Enter Artist Name: "; cin >> artist;
			cout << "Enter Duration: "; cin >> duration;
			sl.addSong(Id, title, artist, duration);
			cout << "Song Added." << endl;
			break;
		case 3:
			sl.displayList();
			break;
		case 4:
			cout << "Enter Song ID: "; cin >> Id;
			sl.delSong(Id);
			cout << endl;
			break;
		case 5:
			sl.playNext();
			break;
		case 6:
			sl.playBack();
			cout << endl;
			break;
		case 7:
			cout << "Enter Song ID: "; cin >> Id;
			sl.jumpTo(Id);
			cout << endl;
			break;
		case 8:
			cout << "Program Ended.";
			break;
		default:
			cout << "Invalid input !";
			break;
		}

	} while (choice != 8);
	return 0;
}
