#include <iostream>
using namespace std;

// Двозв'язний список - це ДСД, в якому об'єкти складаються із елементів,
// що містять певну інформацію і два вказівники:
// один на попередній елемент, інший - на наступний елемент.

int get_random_number(int min, int max) {
	return rand() % (max - min + 1) + min;
}



int menu() {

	cout << "\n\n0 - Exit\n";
	cout << "1 - Add Head\n";
	cout << "2 - Add Tail\n";
	cout << "3 - Delete Head\n";
	cout << "4 - Delete Tail\n";
	cout << "5 - Clear\n";
	cout << "6 - Add pos\n";

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}



struct element {
	int data = 0;
	element* next = nullptr;
	element* prev = nullptr;
};

class list {
	element* head, * tail;
	int size;

public:
	list() {
		head = tail = nullptr;
		size = 0;
	}

	
	void add_head(int value) {

		element* new_element = new element;
		new_element->data = value;

		if (size == 0) {
			head = tail = new_element;
		}
		else {
			new_element->next = head;
			head->prev = new_element;
			head = new_element;
			new_element = nullptr;
		}

		size++;

	}


	void add_tail(int value) {
		element* new_element = new element;
		new_element->data = value;

		if (size == 0) {
			head = tail = new_element;
		}
		else {
			tail->next = new_element;
			new_element->prev = tail;
			tail = new_element;
			new_element = nullptr;
		}

		size++;
	}



	void set(int size) {
		for (int i = 0; i < size; i++)
			add_head(get_random_number(-50, 50));
	}




	void print() const {

		element* tmp = head;

		while (tmp) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}

	}



};




int main() {
	srand(time(0));


	int number, pos;

	list l;
	l.set(10);


	do {
		system("cls");
		l.print();

		int choice = menu();
		if (!choice) break;

		switch (choice)
		{
		case 1:
			cout << "Enter number: ";
			cin >> number;
			l.add_head(number);
			break;
		case 2:
			cout << "Enter number: ";
			cin >> number;
			l.add_tail(number);
			break;
		/*case 3:
			l.delete_head();
			break;*/
	/*	case 4:
			l.delete_tail();
			break;*/
		/*case 5:
			l.clear();
			break;*/
	/*	case 6:
			cout << "Enter pos: ";
			cin >> pos;
			cout << "Enter number: ";
			cin >> number;
			l.add_pos(pos, number);
			break;*/
		default:
			cout << "Incorrect input";
			break;
		}
	} while (true);



	

	return 0;
}