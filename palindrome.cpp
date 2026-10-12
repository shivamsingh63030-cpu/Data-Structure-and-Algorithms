#include<bits/stdc++.h>
 using namespace std;

 #define MAX 100

 char mystack[MAX];
// int top = -1;

// void push(char ch) {
//     if(top == MAX - 1) {
//         cout << "Stack Overflow";
//         return;
//     }
//     top++;
//     mystack[top] = ch;
// }

// char pop() {
//      if(top == -1)
//       return 0;
        
//     return mystack[top--];
// }
// int main() {
//     char str[100];
//     cout << "Enter a string: ";
//     cin >> str;
//     int i = 0;
//     while(str[i] != '\0') {
//         push(str[i]);
//         i++;
//     }
    

//     int flag = 1;
//     for(int j=0;j<i;j++){
//         if(str[j] != pop()){
//             flag = 0;
//             break;
//         }
//     }

//     if(flag)
//     cout<<" PALINDROME";
//     else
    cout<<" NOT PALINDROME";
    return 0;
}