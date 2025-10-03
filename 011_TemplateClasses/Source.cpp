#include <iostream>
using namespace std;



// Шаблонні класи

template<class T>
class my_class {
	T a;
public:
	my_class() { a = 0; }
	my_class(T a) { this->a = a; }
	void set_a(T a) { this->a = a; }
	T get_a() const { return a; }
	void print() const { cout << a << "\n"; }
	friend void func(my_class<T> obj1);
};


void func(my_class<int> obj1) {

	cout << obj1.a;
}


template<class T>
class point {
	T x, y, z;
public:
	point(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<class T>
	friend double distance(point<T> a, point<T> b);

};


template<class T>
double distance(point<T> a, point<T> b) {
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	/*my_class<int> obj1(4);

	func(obj1);*/

	/*my_class<int> obj1(100);
	obj1.print();

	my_class<double> obj2(123.22);
	obj2.print();

	my_class<char> obj3('h');
	obj3.print();*/

	point<int> p1(1, 2, 4);
	point<int> p2(5, 7, 4);
	cout << distance(p1, p2);


	return 0;
}
