#include <iostream>
using namespace std;
//
//#define NAME_SIZE 100
//
//// Конструктор - метод класу, який автоматично викликається
//// при створенні об'єкта.
//// Завдання конструктора:
//// - ініціалізація об'єкта
//// - виділення пам'яті
//
//// Конструктори переважно описують в public секції 
//
//// Конструктори можна перевантажувати.
//// Якщо ми не описуємо свого власного конструктора, то нам надається
//// то нам надається конструктор за замовчуванням
//// Якщи ми описали власний конструктор, то конструктор за замовчуванням видаляється
//
//class point {
//
//private:
//    // дані, поля
//    int x, y;
//
//public:
//    // конструктори
//
//    point() {
//        x = 0;
//        y = 0;
//    }
//
//
//    point(int x_value, int y_value) {
//        x = x_value;
//        y = y_value;
//    }
//
//    // функції, методи
//
//    void set() {
//        cout << "Enter x: ";
//        cin >> x;
//        cout << "Enter y: ";
//        cin >> y;
//    }
//
//    void set(int x_value, int y_value) {
//        x = x_value;
//        y = y_value;
//    }
//
//    // Методи аксесори
//
//    // Модифікатори
//    void set_x(int x_value) {
//        x = x_value;
//    }
//
//    void set_y(int y_value) {
//        y = y_value;
//    }
//
//    // Інспектори
//    int get_x() {
//        return x;
//    }
//
//    int get_y() {
//        return y;
//    }
//
//
//    void print() {
//        cout << "X: " << x << ", Y:" << y << "\n";
//    }
//};
//
//
//class student {
//    char* name;
//    int age;
//public:
//
//    student() {
//        name = new char[NAME_SIZE];
//        age = 0;
//    }
//
//    student(const char* name, int age) {
//
//        this->name = new char[strlen(name) + 1];
//        strcpy_s(this->name, strlen(name) + 1, name);
//
//        this->age = age;
//    }
//
//    void set() {
//        cout << "Enter name: ";
//        gets_s(name, NAME_SIZE);
//        cout << "Enter age: ";
//        cin >> age;
//    }
//
//
//    void print() {
//        cout << "Name: " << name << ", Age: " << age << "\n";
//    }
//
//
//    ~student() {
//        delete[] name;
//    }
//
//};
//
//
//
//
//
//
//
//int main() {
//
//
//   /* student s1;
//    s1.set();
//    s1.print();*/
//
//    student s2("John", 10);
//    s2.print();
//
//
//
//   /* point p1;
//    p1.print();
//
//
//    point p2(1, 2);
//
//    p2.print();*/
//
//
//    // int* marks = new int[5] {1, 2, 3, 10, 12};
//
//
//    return 0;
//}

#define NAME_SIZE 100
#define SCORE_SIZE 5


class stud {
char* surname;
int* score;
public:

    stud() {
        surname = new char[NAME_SIZE];
        score = new int[SCORE_SIZE];
    }

    stud(const char* surname, int* score) {

        this->surname = new char[strlen(surname) + 1];
        strcpy_s(this->surname, strlen(surname) + 1, surname);

        this->score = new int[SCORE_SIZE];
        for (int i = 0; i < SCORE_SIZE; i++)
        {
            this->score[i] = score[i];
        }

    }

    void set() {

        cout << "enter surname: ";
        gets_s(surname, NAME_SIZE);
        for (int i = 0; i < SCORE_SIZE; i++) {
            cout << "enter score" << i + 1 << ": ";

            (cin >> score[i]).get();
        }

    }

    void print() {
        cout << "surname: " << surname;
        for (int i = 0; i < SCORE_SIZE; i++) {
            cout << "\n score " << i + 1 << ": "; 

            cout << score[i];
        }
    }

    ~stud() {
        delete[] surname;
        delete[] score;
    }

};

class group {
    char* name;
    stud* student;
    int number_s;
public:

    group(int number_s) {
        this->number_s = number_s;
        student = new stud[number_s];
        name = new char[NAME_SIZE];
    }

    void set() {
        cout << "enter group name: ";
        gets_s(name, NAME_SIZE);
        for (int i = 0; i < number_s; i++)
        {
            student[i].set();
        }

    }

    void print() {
        cout << "----------------\n" << "name of group: " << name << " | number of students: " << number_s;
        for (int i = 0; i < number_s; i++) {
            cout << "\n";
            cout << "student " << i + 1 << ": \n";
            student[i].print();
        }
    }

    ~group() {
        delete[] student;
        delete[] name;
    }
};
int main() {
    group g1(2);   
    g1.set();
    g1.print();

    group g2(3);
    g2.set();
    g2.print();







    return 0;
}
