#include <iostream>
#include <iomanip>
using namespace std;

#define ROWS 4
#define COLS 3


class matrix {

    int data[ROWS][COLS] = {
        {10, 2, 4},
        {-3, 12, 4},
        {10, 55, 51},
        {-2, 2, 5},
    };

public:

    void print() const {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << setw(5) << data[i][j];
            }
            cout << "\n";
        }
    }

    int& operator()(unsigned int row_index, unsigned int col_index) {
        return data[row_index][col_index];
    }


};



class my_class {
    double x;
public:

    my_class() {
        x = 0;
    }

    my_class(double x) {
        this->x = x;
    }

    void set_x(double x) {
        this->x = x;
    }

    double get_x() const {
        return x;
    }


    void print() const {
        cout << "x: " << x << "\n";
    }

    //my_class operator+(const my_class& other) {
    //    my_class res;
    //    res.x = this->x + other.x;
    //    return res;
    //}

    operator int() {
        return (int)x;
    }



};


// <<, >>


my_class operator+(const my_class& first, const my_class& second) {
    /*my_class res;
    res.set_x(first.get_x() + second.get_x());
    return res;*/

    return my_class(first.get_x() + second.get_x());
}

my_class operator-(const my_class& first, const my_class& second) {
   /* my_class res;
    res.set_x(first.get_x() - second.get_x());
    return res;*/

    return my_class(first.get_x() - second.get_x());
}

bool operator==(const my_class& first, const my_class& second) {
    return first.get_x() == second.get_x();
}

bool operator!=(const my_class& first, const my_class& second) {
    return !(first == second);
}

bool operator>(const my_class& first, const my_class& second) {
    return first.get_x() > second.get_x();
}

ostream& operator << (ostream& os, const my_class& obj) {
    os << "x = " << obj.get_x() << "\n";
    return os;
}

istream& operator >> (istream& is, my_class& obj) {
    double x;
    is >> x;
    obj.set_x(x);
    return is;
}




// 1 - �����
// 2 - �������



int main() {

    /*int a = 5, b = 4;

    int sum = a - b;*/

   /* my_class a(5);
    my_class b(4);

    bool res = a == b;
    cout << res;*/

    
    //matrix m;   // 2, 1

    //m(2, 1) = 1000;

    //m.print();


    //my_class obj;

    //// obj.print();
    //cin >> obj;

    //cout << obj;


    //cout << (int)obj;




    return 0;
}
