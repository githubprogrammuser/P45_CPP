#include <iostream>
using namespace std;

// ������� ��������� �����(���) - �� ��������� �����,
// ��'���� ��� ���� ���������� �� �� �����������.

// ������(Vector)
// ������(������'�����, �����'�����)
// ����
// �����(������, ʳ������, ����� � �����������, ���)
// ������(������� ������)


// ������'����� ������ - �� ���, � ����� ��'���� ����������� �� ��������,
// �� ������ ����� ���������� � �������� �� ����� �������.

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
			tail = new_element;
			new_element = nullptr;
		}

		size++;
	}


	void delete_head() {
		if (size == 0) return;

		element* tmp = head;
		head = head->next;
		delete tmp;
		tmp = nullptr;

		size--;

	}

	void delete_tail() {
		if (size == 0) return;

		if (size == 1) {
			delete_head();
			return;
		}

		element* tmp = head;

		while (tmp->next != tail)
			tmp = tmp->next;

		delete tail;
		tail = tmp;
		tmp->next = nullptr;
		tmp = nullptr;

		size--;
	}


	void add_pos(int pos, int value) {
		
		if (size == 0) add_head(value);
		else if (pos == size) add_tail(value);
		else {
			element* new_element = new element;
			new_element->data = value;

			element* tmp = head;

			int i = 0;
			while (i++ < pos - 1)
				tmp = tmp->next;

			new_element->next = tmp->next;

			tmp->next = new_element;

			size++;
		}
	}


	void clear() {
		while(head)
			delete_head();
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

	~list() {
		clear();
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
		case 3:
			l.delete_head();
			break;
		case 4:
			l.delete_tail();
			break;
		case 5:
			l.clear();
			break;
		case 6:
			cout << "Enter pos: ";
			cin >> pos;
			cout << "Enter number: ";
			cin >> number;
			l.add_pos(pos, number);
			break;
		default:
			cout << "Incorrect input";
			break;
		}
	} while (true);




	return 0;
}