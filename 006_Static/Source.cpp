#include <iostream>
using namespace std;


// Статичні поля - це поля, які використовуються спільно всіма об'єктами класу.
// Кажуть, що вони належать не конкретному об'єкту, а класу вцілому

class point {

private:
    // дані, поля
    int x, y;

    // функції, методи
public:

    static int count;
    static int liveObjects;

    point() {
        x = y = 0;
        count++;
        liveObjects++;
    }

    point(int x, int y) {
        this->x = x;
        this->y = y;
        count++;
        liveObjects++;
    }


    void set() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
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

    ~point() {
        liveObjects--;
    }
};


int point::count = 0;
int point::liveObjects = 0;



// Створити клас Employee(Працівник).
// Прізвище(last_name), унікальний ідентифікатор(id, int).
// При створенні об'єкта йому автоматично присвоється ідентифікатор.
// Першому працівникові - 1, другому - 2 ...
// Свторити декілька працівників і виіести інфо про них.


class employee {
    char* last_name;
    int id;
    static int last_id;
public:


    employee(const char* last_name) {
        this->last_name = new char[strlen(last_name) + 1];
        strcpy_s(this->last_name, strlen(last_name) + 1, last_name);
        last_id++;
        id = last_id;
    }

    static int get_last_id() {
        return last_id;
    }


    void print() {
        cout << "LastName: " << last_name << ", Id: " << id << "\n";
    }

};

int employee::last_id = 0;


class my_math {

public:
    static const double PI;


    static int sum(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }

    static int mul(int a, int b) {
        return a * b;
    }

    static int div(int a, int b) {
        return a / b;
    }

    static int square(int a) {
        return a * a;
    }
};

const double my_math::PI = 3.14;


int main() {

    cout << my_math::mul(3, 4) << "\n";

    cout << my_math::PI;

    

    //point p1(3, 4);
    //point p2(1, 0);
    //point p3(-1, 9);

    //{
    //    point p4(1, 2);
    //}


    //cout << point::count << "\n"; // 4
    //cout << point::liveObjects;   // 3

    /*employee e1("Smith");
    employee e2("Doe");
    employee e3("King");

    e1.print();
    e2.print();
    e3.print();

    cout << employee::get_last_id();*/
    


    return 0;
}
