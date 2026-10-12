#include <iostream>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;


void push(char ch)
{
if (top == MAX - 1){
 cout << "Stack Overflow";
  return;
}
    stack[++top] = ch;
}
char pop(){
    if (top == -1){
    cout << "Stack Underflow";
    return '\0';
    }
    return stack[top--];    
}
int main(){
    char str[MAX];

cout << "Enter a string: ";
 cin.getline(str, MAX);

 for (int i = 0; str[i] != '\0'; i++){
    push(str[i]);
 }
cout << "Reversed string: ";

 while (top != -1){
 cout << pop();
}
cout << endl;

    return 0;
}