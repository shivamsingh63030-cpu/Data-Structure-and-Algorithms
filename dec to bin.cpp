#include <iostream>
#include <cmath>
using namespace std;

int stack[100];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    cin>>n;
    while(n!=0){
        push(n%2);
        n=n/2;
    }
    while(top!=-1){
        cout<<pop();
    }

    return 0;
} 