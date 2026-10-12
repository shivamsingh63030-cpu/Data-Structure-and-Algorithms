#include <iostream>
using namespace std;

class Box {
    int l, b, h;

public:
    Box(int L, int B, int H) : l(L), b(B), h(H) {
        cout << "Full ctor (" << l << "," << b << "," << h << ")" << endl;
    }

    Box(int side) : Box(side, side, side) {
        cout << "Cube ctor delegated" << endl;
    }

    Box() : Box(1) {
        cout << "Default ctor delegated" << endl;
    }

    int volume() const {
        return l * b * h;
    }
};

int main() {
    Box c(4);
    cout << "volume = " << c.volume() << endl;

    Box d;
    cout << "volume = " << d.volume() << endl;

    return 0;
}