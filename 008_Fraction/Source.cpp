#include <iostream>
using namespace std;

class fraction {
    int numerator, denominator;
public:

    fraction() {
        numerator = 0;
        denominator = 1;
    }

    fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void set() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
    }

    int get_numerator() const {
        return numerator;
    }

    int get_denominator() const {
        return denominator;
    }


    int get_integer() {
        return numerator / denominator;
    }

    double get_double() {
        return (double)numerator / denominator;
    }

    fraction add(fraction other) {

        int res_numerator =
            this->numerator * other.denominator + this->denominator * other.numerator;

        int res_denominator = this->denominator * other.denominator;

        fraction res;
        res.set(res_numerator, res_denominator);

        return res;
    }



    void print() {
        cout << numerator << "/" << denominator << "\n";
    }

};

// Перевантажити оператори як функції:
// +, -, *, /, ==, !=, >, <, >=, <=

// cout <<, cin >>, int, double 


fraction operator+(const fraction& first, const fraction& second) {
    int res_numerator =
        first.get_numerator() * second.get_denominator()
                + first.get_denominator() * second.get_numerator();

    int res_denominator = first.get_denominator() * second.get_denominator();

    fraction res(res_numerator, res_denominator);
  
    return res;
}


fraction operator+(const fraction& first, int number) {  // 10 / 1
   /* int res_numerator =
        first.get_numerator()
        + first.get_denominator() * number;

    int res_denominator = first.get_denominator();

    fraction res(res_numerator, res_denominator);*/

   return  first + fraction(number, 1);


  
}



int main() {

    fraction f1(3, 4), f2(1, 2);
    /*fraction f3 = f1 + f2;
    f3.print()*/;
    
    f1 + 2
    2 + f1


    //cout << (double)f1; // 0.75


    return 0;
}
