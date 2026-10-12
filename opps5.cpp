#include <iostream>
#include <string>
using namespace std;

class Tracer {
    string tag;

public:
    Tracer(string t) : tag(t) {
        cout << "+ " << tag << endl;
    }

    ~Tracer() {
        cout << "- " << tag << endl;
    }
};

int main() {
    Tracer outer("outer");

    {
        cout << "Entering inner block" << endl;

        Tracer inner1("inner-1");
        Tracer inner2("inner-2");

        cout << "Leaving inner block" << endl;
    }

    cout << "Back in main" << endl;

    return 0;
}