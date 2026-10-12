#include <iostream>
using namespace std;
int top =-1;
int st[100];
void push(int a){
    st[++top] = a;
}
int pop(){
    return st[top--];
}
int main(){
    int i=0;
    int res;
    string exp;
    cin>>exp;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            int  num = 0;
            while(exp[i] !=','){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            push(num);
        }
        else{
            int n1 = pop();
            int n2 = pop();
            switch(exp[i]){
                case '+':  res = n1 + n2;
                        break;
                case '-' : 
                            res = n2 - n1;
                            break;
                 case '*' : res = n1*n2;
                            break;
                case '/' : 
                         
                         res = n2/n1;
                         break;

               
            }
            push(res);
        }
        i++;
        if(i < exp.length() && exp[i] == ',')
                i++;
                
    }
    cout<<pop();
}