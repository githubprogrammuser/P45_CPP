#include <iostream>
using namespace std;


void line(int count) {
	cout << "\n";
	for (int i = 0; i < count; i++)
		cout << "-";
	cout << "\n";
}




template<class T>
class vector {
	T* data;
	int size;
public:
	vector() {
		data = nullptr;
		size = 0;
	}

	//vector(int size) { // 10
	//	// this->data = new int[size];
	//	for (int i = 0; i < size; i++)
	//		add_element_end(rand() % 101 - 50);
	//}

	vector(const vector<T>& other) {
		this->data = new T[other.size];
		this->size = other.size;

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
			// *(this->data + i) = *(other.data + i);
		}
	}

	//void set_random(int size) {
	//	for (int i = 0; i < size; i++) {
	//		add_element_end(rand() % 101 - 50);
	//	}
	//}


	void print() {
		line(100);
		for (int i = 0; i < size; i++)
			cout << *(data + i) << " ";
		line(100);
	}

	void add_element_end(T number) {
		T* p = new T[size + 1];

		for (int i = 0; i < size; i++)
			*(p + i) = *(data + i);

		p[size] = number;
		delete[] data;
		data = p;
		size++;
		p = nullptr;
	}



	void add_element_start(T number) {
		T* p = new T[size + 1];

		for (int i = 1; i < size + 1; i++)
			*(p + i) = *(data + i - 1);

		p[0] = number;

		delete[] data;
		data = p;
		size++;
		p = nullptr;
	}



	vector<T>& operator=(const vector<T>& other) {

		if (this == &other)
			return *this;


		if (this->data) {
			delete[] this->data;
		}

		this->data = new T[other.size];

		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}

		this->size = other.size;
		return *this;
	}


	/*T& get_element_by_index(unsigned int index) {
		if (index >= size)
			throw exception("index out of range");

		return data[index];
	}*/

	T& operator[](unsigned int index) {
		if (index >= size)
			throw exception("index out of range");

		return data[index];
	}


	~vector() {
		delete[] data;
	}
};

template<class T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
	obj.print();
	return os;
}

template<class T>
istream& operator>> (istream& is, vector<T>& obj) {
	obj.set_random(10);
	return is;
}


template<class T>
class point {
	T x, y, z;
public:
	point() {
		x = y = z = 0;
	}

	point(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void print() const {
		cout << "X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	}

	template<class T>
	friend double distance(point<T> a, point<T> b);

};


template<class T>
double distance(point<T> a, point<T> b) {
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}


template<class T>
ostream& operator<< (ostream& os, const point<T>& obj) {
	obj.print();
	return os;
}




int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));


	/*vector<int> v;

	v.add_element_end(100);
	v.add_element_end(200);
	v.add_element_end(300);
	v.add_element_end(0);
	v.add_element_end(50040);
	v.print();


	vector<double> v2;
	v2.add_element_end(1.23);
	v2.add_element_end(765.3);
	v2.add_element_end(-0.44);
	v2.print();*/


	vector<point<int>> points;
	points.add_element_end(point<int>(3, 4, 5));
	points.add_element_end(point<int>(1, 7, -4));
	points.add_element_end(point<int>(3, 4, 3));
	points.add_element_end(point<int>(3, 4, 10));
	points.add_element_end(point<int>(3, 4, 4));
	points.print();


	



	return 0;
}