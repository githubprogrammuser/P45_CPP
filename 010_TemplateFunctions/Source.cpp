#include <iostream>
using namespace std;



// Шаблонні функції


template<class T>
T sum(T a, T b) {
	return a + b;
}


template<class T>
double average(T* arr, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}


int main() {
	setlocale(LC_CTYPE, "ukr");
	srand(time(0));

	//double res = sum(3.33, 4.12);
	//cout << res;

	//const int size = 5;
	//int arr1[] = { 3, 0, 1 , 19, 4 };
	//double arr2[] = { 9.2, -4.2, 1.1 , 19.4, 4.3 };

	//double res1 = average(arr1, size);
	//cout << res1 << "\n";
	//double res2 = average(arr2, size);
	//cout << res2 << "\n";

	return 0;
}
