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


    // ����������� ���������
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
    // ���, ����
    int x, y;

    // �������, ������
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

    // ������ ��������

    // ������������
    void set_x(int x_value) {
        x = x_value;
    }

    void set_y(int y_value) {
        y = y_value;
    }

    // ����������
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


// ����������� ��������� ����������� � 3 ��������:
// - ����������� ������ ��'���� �����
// - �������� � ����� ��������� ��'���� � ������� ��� ����� �� ��������
// - ���������� ��'��� � ������� ��� ������ �� ��������

// ���� �� �������� �������� ���'��� � ���� � ���������� �� 
// ���������, �� �� ���� ������� ��� ����������� ���������


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
