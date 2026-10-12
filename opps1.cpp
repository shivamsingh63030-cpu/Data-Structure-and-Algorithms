#include <iostream>
using namespace std;

class Student {
    int rollNo;
    static int count;   // One copy shared by all objects

public:
    Student() {
        count++;
        rollNo = count;

        cout << "Created student " << rollNo
             << " | total now = " << count << endl;
    }

    void show() const {
        cout << "Roll " << rollNo
             << " (count = " << count << ")" << endl;
    }
};

// Define static data member outside the class
int Student::count = 0;

int main() {
    cout << "Before objects, count = 0" << endl;

    Student a, b, c;

    a.show();
    b.show();
    c.show();

    return 0;
}
