#include <iostream> 
using namespace std;

class student {
    string name;
    public:
    student(string n) : name(n){
        cout << "constructor:"<<name << "created" << endl;
    }
    ~student() {
        cout << "destructor:"<<name << "destroyed" << endl;
    }
};
int main(){
    cout << 
    
}
