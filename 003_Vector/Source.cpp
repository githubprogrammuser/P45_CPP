#include <iostream>
using namespace std;

void line(int count) {
	cout << "\n";
	for (int i = 0; i < count; i++)
		cout << "-";
	cout << "\n";
}


class vector {
	int* data;
	int size;
public:
	vector() {
		data = nullptr;
		size = 0;
	}

	vector(int size) { // 10
		// this->data = new int[size];
		for (int i = 0; i < size; i++)
			add_element_end(rand() % 101 - 50);
	}

	vector(const vector& other) {
		this->data = new int[other.size];
		this->size = other.size;

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
			// *(this->data + i) = *(other.data + i);
		}
	}



	void print() {
		line(100);
		for (int i = 0; i < size; i++)
			cout << *(data + i) << " ";
		line(100);
	}

	void add_element_end(int number) {
		int* p = new int[size + 1];

		for (int i = 0; i < size; i++)
			*(p + i) = *(data + i);

		p[size] = number;
		delete[] data;
		data = p;
		size++;
		p = nullptr;
	}

	void add_element_start(int number) {
		int* p = new int[size + 1];

		for (int i = 1; i < size + 1; i++)
			*(p + i) = *(data + i - 1);

		p[0] = number;

		delete[] data;
		data = p;
		size++;
		p = nullptr;
	}



	vector& operator=(const vector& other) {

		if (this == &other)
			return *this;


		if (this->data) {
			delete[] this->data;
		}

		this->data = new int[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}

		this->size = other.size;
		return *this;
	}


	int& get_element_by_index(unsigned int index) {
		if (index >= size)
			throw exception("index out of range");

		return data[index];
	}

	int& operator[](unsigned int index) {
		if (index >= size)
			throw exception("index out of range");

		return data[index];
	}



	~vector() {
		delete[] data;
	}
};




//void set_array(int* arr, int size) {
//	for (int i = 0; i < size; i++)
//		*(arr + i) = rand() % 101 - 50;
//}







int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	
	/*vector v;
	v.add_element_end(100);
	v.add_element_end(200);
	v.add_element_end(300);

	v.add_element_start(50);
	v.add_element_start(78);

	v.print();*/


	/*vector v1(10);
	v1.print();

	vector v2(100);
	
	v1 = v1;


	v2.print();*/


	vector v; 
	v.add_element_end(100);  // 0
	v.add_element_end(500);  // 1
	v.add_element_end(300);  // 2
	v.add_element_end(400);  // 3
	v.add_element_end(200);  // 4

	v.print();

	// cout << v.get_element_by_index(2);


	v[2] = 1000;
	// v.get_element_by_index(2) = 1000;

	v.print();

	return 0;
}
