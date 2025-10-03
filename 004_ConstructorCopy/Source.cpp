#include <iostream>
using namespace std;

#define NAME_SIZE 100


class stud {
    char* surname;
 
public:

    stud() {
        surname = new char[NAME_SIZE];
       
    }

    stud(const char* surname) {

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);


    }


    // Конструктор копіювання
    stud(const stud& other) {

        this->surname = new char[strlen(other.surname) + 1];
        strcpy_s(this->surname, strlen(other.surname) + 1, other.surname);
    }



    void set() {

        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);
        

    }

    void print() {
        cout << "surname: " << surname << "\n";
        
    }

    ~stud() {
        delete[] surname;
    }

};



class point {

private:
    // дані, поля
    int x, y;

    // функції, методи
public:

    point(int a, int b) {
        x = a;
        y = b;
    }


    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x_value, int y_value) {
        x = x_value;
        y = y_value;
    }

    // Методи аксесори

    // Модифікатори
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // Інспектори
    int get_x() {
        return x;
    }

    int get_y() {
        return y;
    }


    void print() {
        cout << "X: " << x << ", Y:" << y << "\n";
    }
};


// Конструктор копіювання викликається в 3 випадках:
// - Ініціалізація одного об'єкта іншим
// - Передача в якості параметра об'єкта в функцію або метод по значенню
// - Повернення обє'кта з функції або метода по значенню

// Якщо ми виділяємо динамічну пам'ять і потім в деструкторі її 
// звільняємо, то ми маємо описати свій конструктор копіювання


void func1(stud s) {
    // ...
}


stud func2() {
    stud s("Jack");
    return s;
}


int main() {

    /*point p1(3, 4);
    p1.print();

    point p2 = p1;
    p2.print();*/


    stud s1("John");
    s1.print();

    stud s2 = s1;  // constructor copy // 1
    s2.print();

    /*func1(s1);*/  // 2

    //stud s2 = func2();        // 3
    //s2.print();


   




    return 0;
}
