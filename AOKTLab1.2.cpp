#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

struct Zveno
{
    int value;
    Zveno* Next, * Previous;
};

class List
{
private:
    Zveno *mainZveno;
    int currentSize;
public:
    void Build();
    void Show();
    void DeleteCurrent(Zveno*);
    int Schitalochka(int num, int remaining);
};
int counter,kolichestvo;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List list;
    int check = 0, i=1;
    list.Build();
    list.Show();
    cout << endl;
    while (check == 0)
    {
        i=list.Schitalochka(counter,i);
        list.Show();
        cout << endl;
        cout << "\nПродолжить — 0, закончить — любое другое число" << endl;
        cin >> check;
    }
    
    //list.Show();
}

void List::Build()
{
    Zveno* current;
    mainZveno = new(Zveno);
    current = mainZveno;
    (*mainZveno).Next = NULL;
    (*mainZveno).Previous = NULL;
    cout << "Введите количество детей" << endl;
    cin >> kolichestvo;
    currentSize = kolichestvo;
    cout << "Введите число для считалочки" << endl;
    cin >> counter;
    for (int i = 0; i < kolichestvo; i++)
    {
        (*current).Next = new(Zveno);
        (*((*current).Next)).Previous = current;
        current = (*current).Next;
        (*current).Next = NULL;
        (*current).value = i+1;
    }
    if ((*mainZveno).Next!=NULL)
    {
        (*((*mainZveno).Next)).Previous = current;
        (*current).Next = (*mainZveno).Next;
    }
}

void List::Show()
{
    Zveno* current;
    int i = 1;
    if ((*mainZveno).Next != NULL)
    {
        cout << (*((*mainZveno).Next)).value << " ";
        current = (*((*mainZveno).Next)).Next;
        while (current != (*mainZveno).Next)
        {
            cout << (*current).value << " ";
            current = (*current).Next;
        }
    }
    else
    {
        cout << "Пусто";
    }
}

void List::DeleteCurrent(Zveno *current)
{
    if ((*current).Next==current)
    {
        (*mainZveno).Next = NULL;
        delete current;
    }
    else
    {
        (*(*current).Next).Previous = (*current).Previous;
        (*(*current).Previous).Next = (*current).Next;
        if ((*mainZveno).Next==current)       
            (*mainZveno).Next = (*current).Next;
        delete current;
    }
}

int List::Schitalochka(int num, int remaining)
{
    Zveno* current= (*mainZveno).Next;
    int check = 0, i = remaining, deletedAmount = 0,j=0;
    while (j!=currentSize)
    {
        if (i == num)
        {
            //cout << (*current).value << "   " << j << "  " << i << endl;
            Zveno* temp = (*current).Next;
            DeleteCurrent(current);
            deletedAmount++;
            current = temp;
            i = 1;
            j++;
            continue;
        }
        i++;
        j++;
        current = (*current).Next;
    }
    currentSize -= deletedAmount;
    return i;
}


