#include <iostream>
using namespace std;

int qu[5];
int front = -1, rear = -1;
 void dequeue(){
    if (front == -1)
    {
        cout << "Queue Underflow\n";
        return;
    }
    int x=qu[front];
    cout << "Deleted = " << x << endl;
    if (front == rear)
        front = rear = -1;
    else if (front == 4)
        front = 0;
    else
        front++;
 }
 int main(){
    qu[0]=10;
    qu[1]=20;
    qu[2]=30;
    front=0;
    rear=2;
    dequeue();
    dequeue();

    return 0;
 }


