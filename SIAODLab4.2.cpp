#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
struct Zveno
{
    char data;
    Zveno* Next;
};
class Stack
{
private:
    Zveno* first;
    int currentSize = 0;
public:
    void Show();
    void Add(char num);
    void AddFirst(char num);
    int getSize();
    char pop();
    char watch();
};
int getPriority(char symb);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack stack;
    string //line1 = "((A-(B+C))*D)^(E+F)",
        //line1 = "A+B*C-D/(A+B)",
        //line1= "(A + B * C + D * T - M * L)",
        line1="(A+B*C)^(V+B)-(S*D)^J",
        //line1 = "(A+B)*C-(D-E)*(F+G)",
        //line1="(A+B)*C",
        result = "",
        line = "";
    for (int i = 0; i < line1.length(); i++)
    {
        if (line1[line1.length() - i - 1]=='(')
        {
            line += ')';
            continue;
        }
        if (line1[line1.length() - i - 1] == ')')
        {
            line += '(';
            continue;
        }
        line += line1[line1.length() - i - 1];
        //cout << line[line.length() - i - 1] << endl;
    }
    char previousOperation = '(';
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '(')
        {

            if (stack.getSize() == 0)
                stack.AddFirst(line[i]);
            else
                stack.Add(line[i]);
            continue;
        }

        if (isalpha(line[i]))
        {

            result += line[i];
            continue;
        }
        if (line[i] == '+' || line[i] == '-')
        {
            if (getPriority(previousOperation) > getPriority(line[i]))
            {
                while (stack.getSize() != 0 && stack.watch() != '(')
                {
                    result += stack.pop();
                }
            }
            if (getPriority(stack.watch()) > getPriority(line[i]))
            {
                while (stack.getSize() != 0 && stack.watch() != '(')
                {
                    result += stack.pop();
                }
            }
            if (stack.getSize() == 0)
                stack.AddFirst(line[i]);
            else
                stack.Add(line[i]);
            previousOperation = line[i];
            continue;
        }
        if (line[i] == '*' || line[i] == '/')
        {
            if (getPriority(previousOperation) > getPriority(line[i]))
            {
                while (stack.getSize() != 0 && stack.watch() != '(')
                {
                    result += stack.pop();
                }
            }
            if (getPriority(stack.watch()) > getPriority(line[i]))
            {
                while (stack.getSize() != 0 && stack.watch() != '(')
                {
                    result += stack.pop();
                }
            }
            if (stack.getSize() == 0)
                stack.AddFirst(line[i]);
            else
                stack.Add(line[i]);
            previousOperation = line[i];
            continue;
        }
        if (line[i] == '^')
        {
            if (getPriority(previousOperation) > getPriority(line[i]))
            {
                while (stack.getSize() != 0 && stack.watch() != '(')
                {
                    result += stack.pop();
                }
            }
            if (stack.getSize() == 0)
                stack.AddFirst(line[i]);
            else
                stack.Add(line[i]);
            previousOperation = line[i];
            continue;
        }
        if (line[i] == ')')
        {
            char a = stack.pop();
            while (a != '(')
            {
                result += a;
                a = stack.pop();

            }

            continue;
        }
    }
    if (stack.getSize() != 0)
    {
        while (stack.getSize() != 0)
        {
            result += stack.pop();
        }
    }
    string finalResult = "";
    for (int i = 0; i < result.length(); i++)
    {
        if (result[result.length() - i - 1] == '(')
        {
            finalResult += ')';
            continue;
        }
        if (result[result.length() - i - 1] == ')')
        {
            finalResult += '(';
            continue;
        }
        finalResult += result[result.length() - i - 1];
        //cout << line[line.length() - i - 1] << endl;
    }
    cout << finalResult << endl;;
}

void Stack::AddFirst(char num)
{
    Zveno* current = new Zveno;
    current->data = num;
    current->Next = NULL;
    first = current;
    currentSize++;
}
void Stack::Add(char num)
{
    Zveno* current = first;
    Zveno* temp = new Zveno;
    temp->data = num;
    temp->Next = current;
    first = temp;
    currentSize++;
}
char Stack::pop()
{
    Zveno* current = first;
    char getData = current->data;
    first = current->Next;
    currentSize--;

    return getData;
}
void Stack::Show()
{
    Zveno* current = first;
    if (currentSize == 0)
    {
        cout << "Пусто\n";
        return;
    }
    if (currentSize == 1)
    {
        cout << (*current).data << endl;
        return;
    }
    if ((*current).Next != NULL)
    {
        do
        {
            cout << (*current).data << "  ";
            current = (*current).Next;
        } while ((*current).Next != NULL);
        cout << (*current).data << "  " << endl;
    }
}
int Stack::getSize()
{
    return currentSize;
}

int getPriority(char symb)
{
    if (symb == '(')
    {
        return 0;
    }
    if (symb == ')')
    {
        return 1;
    }
    if (symb == '-' || symb == '+')
    {
        return 2;
    }
    if (symb == '*' || symb == '/')
    {
        return 3;
    }
    if (symb == '^')
    {
        return 4;
    }
}
char Stack::watch()
{
    if (first == NULL)
        return 0;
    return first->data;
}