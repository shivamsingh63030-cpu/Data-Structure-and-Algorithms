#include <iostream>
#include <string>
using namespace std;

char st[100];
int top = -1;

void push(char a)
{
    top = top + 1;
    st[top] = a;
}


char pop()
{
    char x = st[top];
    top = top - 1;
    return x;
}

bool isMatched(char a, char b)
{
    return ((a == '(' && b == ')') ||
            (a == '[' && b == ']') ||
            (a == '{' && b == '}'));
}

// Balance checking function
bool isBalance(string &str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
                return false;

            if (isMatched(pop(), str[i]) == false)
                return false;
        }

        i++;
    }

    return (top == -1);
}

int main()
{
    string str;

    cout << "Enter expression: ";
    cin >> str;

    if (isBalance(str))
        cout << "Balanced";
    else
        cout << "Imbalanced";

    return 0;
}