#include <iostream>
#include <string>
using namespace std;


// ����� � ����������� - �� �����, � ��� ��������� ��� ���������
// �������� ���������� � ��������� �� �� ���������





void line(int count) {
    cout << "\n";
    for (int i = 0; i < count; i++)
        cout << "-";
    cout << "\n";
}

template<class T>
class priority_item {
    T data;
    int priority;

public:
    priority_item() {
        data = T();
        priority = 0;
    }

    priority_item(T data, int priority) {
        this->data = data;
        this->priority = priority;
    }

    int get_priority() const {
        return priority;
    }


    void print() const {
        cout << "Data: " << data << ", Priority: " << priority << "\n";
    }

};

template<class T>
ostream& operator<< (ostream& os, const priority_item<T>& obj) {
    obj.print();
    return os;
}





template<class T>
class vector {
private:
    T* data;
    int size;

public:
    vector() {
        data = nullptr;
        size = 0;
    }

    vector(const vector<T>& other) {
        this->data = new T[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
            // *(this->data + i) = *(other.data + i);
        }
    }

    void print_v() const {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
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

    void add_element_need(int wher, T number) {
        T* p = new T[size + 1];

        for (int i = 0; i < wher; i++) {
            p[i] = data[i];
        }

        p[wher] = number;

        for (int i = wher; i < size; i++) {
            p[i + 1] = data[i];
        }

        delete[] data;
        data = p;
        size++;
        p = nullptr;
    }

    void deletee_element_last() {
        size--;
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void deletee_element_first() {
        size--;
        int* p = new int[size];

        for (int i = 0; i < size; i++) {
            p[i] = data[i + 1];
        }

        delete[] data;
        data = p;
        p = nullptr;
    }

    void delete_element_position(int position) {
        int* p = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != position) {
                p[j++] = data[i];
            }
        }

        delete[] data;
        data = p;
        size--;
        p = nullptr;
    }

    int search_element_position(int element) {
        for (int i = 0; i < size; i++)
            if (data[i] == element)
                return i;
        return -1;
    }

    void delete_search_element(int element) {
        int position = search_element_position(element);
        if (position != -1)
            delete_element_position(position);
        else {
            cout << "Element not found";           
        }
    }

    void delete_elements_from_position(int count, int position) {
        for (int i = 0; i < count; i++)
            delete_element_position(position);
    }

    void delete_array() {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void change_element_by_value(int number, int change_number) {
        int position = search_element_position(number);
        if (position != -1)
            data[position] = change_number;
        else {
            cout << "Not found";
        }
    }

    void change_element_by_position(int position, int change_number) {
        data[position] = change_number;
    }

    void reverse_array() {
        for (int i = 0; i < size / 2; i++) {
            swap(data[i], data[size - i - 1]);
        }
    }

    int get_max() {
        if (size == 0) {
            cout << "Array is empty\n";
            return 0;
        }
        int max_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > max_val)
                max_val = data[i];
        return max_val;
    }

    int get_min() {
        if (size == 0) {
            cout << "Array is empty\n";

            return 0;
        }
        int min_val = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < min_val)
                min_val = data[i];
        return min_val;
    }

    int get_size() const {
        return size;
    }

    int get_element(int index) {
        if (index < 0 || index >= size) {
            cout << "Incorrect index!\n";
   
            return 0;
        }
        return data[index];
    }

    void sort_asc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void sort_desc() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] < data[j + 1])
                    swap(data[j], data[j + 1]);
            }
        }
    }

    void print() {
        line(100);
        for (int i = 0; i < size; i++)
            cout << *(data + i) << " ";
        line(100);
    }

    void print_info_max() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Max element: " << get_max() << endl;
   
    }

    void print_info_min() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Min element: " << get_min() << endl;
 
    }

    void print_info_size() {
        cout << "\n======= ARRAY INFO =======\n";

        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Size: " << size << endl;
   
    }

    void print_info_index() {
        if (size == 0) {
            cout << "Array is empty!\n";
          
            return;
        }
        cout << "\n======= ARRAY INFO =======\n";
        int index;
        cout << "Enter index: ";
        cin >> index;

        int value = get_element(index);
        cout << "Element at index " << index << " is: " << value << endl;
    
    }




    vector<T> operator=(const vector<T>& other) {
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

    //int& get_element_by_index(unsigned int index) {
    //    if (index >= size)
    //        throw exception("index out of range");
    //    return data[index];
    //}

    T& operator[](unsigned int index) {
        if (index >= size)
            throw exception("index out of range");

        return data[index];
    }


    bool is_empty() const {
        return size == 0;
    }


    ~vector() {
        delete[] data;
    }
};

template<class T>
ostream& operator<< (ostream& os, const vector<T>& obj) {
    obj.print_v();
    return os;
}

template<class T>
istream& operator>> (istream& is, vector<T>& obj) {
    obj.set_random(10);
    return is;
}



// ������ �������� ��� ������:
// 1. ��������� ������ ������� � ����� �����
// 2. �������� �������� �� ������� ��� ���� ���������
// 3. �������� �������� �� ������� � ���� ����������
// 4. ��������, �� ����� �����
// 5. �������� �����


template<class T>
class queue {
    vector<priority_item<T>> data;
public:

    void push(priority_item<T> value) {

        if (is_empty())
            data.add_element_start(value);
        else {
            int i = 0;
            while (i < data.get_size() &&
                data[i].get_priority() <= value.get_priority()) {
                i++;
            }
            data.add_element_need(i, value);
        }


    }

    void print() const {
        data.print_v();
    }

    priority_item<T> top() {
        if (!is_empty())
            return data[0];

        throw exception("Queue is empty");
    }


    bool is_empty() const {
        return data.is_empty();
    }

    priority_item<T> pop() {
        if (!is_empty()) {
            priority_item tmp = data[0];
            data.deletee_element_first();
            return tmp;
        }
        throw exception("Queue is empty");
    }

    void clear() {
        data.delete_array();
    }


};







int main() {
    srand(time(0));


    /*queue<int> q;

    q.push(priority_item<int>(100, 3));
    q.push(priority_item<int>(500, 2));
    q.push(priority_item<int>(200, 1));
    q.push(priority_item<int>(777, 4));
    q.push(priority_item<int>(24300, 5));

    q.print();*/


    queue<string> q;

    q.push(priority_item<string>("John", 3));
    q.push(priority_item<string>("Den", 2));
    q.push(priority_item<string>("Jack", 1));
    q.push(priority_item<string>("Ron", 4));
    q.push(priority_item<string>("Bob", 5));
    q.push(priority_item<string>("larry", 6));

    q.print();










    return 0;
}