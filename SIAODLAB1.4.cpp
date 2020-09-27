#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

struct Zveno
{
    string number;
    Zveno* Next, * Previous;
};

class List
{
private:
    Zveno* mainZveno;
    int currentSize=0;
public:
    void Build();
    void Show();
    Zveno* Add(string num, Zveno*);
    Zveno *AddFirst(string num);
    void SortNotspecial(List list);
};

struct OneSidedZveno
{
    string number;
    OneSidedZveno* Next;
};

class OneSidedList
{
private:
    OneSidedZveno* first;
public:
    void Show();
    OneSidedZveno* Add(string num, OneSidedZveno*);
    OneSidedZveno* AddFirst(string num);
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List list;
    list.Build();
    string number;
    cout << "Введите номер:" << endl;
    cin >> number;
    Zveno* current = list.AddFirst(number);
    do
    {
        cout << "Введите номер(или 0 чтобы закончить):" << endl;
        cin >> number;
        if (number == "0")
            break;
        current = list.Add(number,current);
    } while (true);
    /*Zveno* current= list.AddFirst("3461527");
    current=list.Add("102",current);
    current =list.Add("3152648", current);
    current = list.Add("3124652", current);
    current = list.Add("103", current);
    current = list.Add("9754216", current);
    current = list.Add("112", current);
    current = list.Add("104", current);
    current = list.Add("3461259", current);
    current = list.Add("6243436", current);
    current = list.Add("5781642", current);
    current = list.Add("3764825", current);*/
    list.Show();
    cout <<endl;
    list.SortNotspecial(list);
}

Zveno *List::AddFirst(string num)
{
    Zveno* temp = new Zveno;
    (*temp).number = num;
    (*temp).Next = temp;
    (*temp).Previous = temp;
    (*mainZveno).Next = temp;
    currentSize++;
    return temp;
}

Zveno *List::Add(string num, Zveno* current)
{
    Zveno* temp = new Zveno;
    (*temp).number = num;
    (*temp).Next = (*mainZveno).Next;
    (*temp).Previous = current;
    (*current).Next = temp;
    currentSize++;
    return temp;
}

void List::Build()
{
    Zveno* current;
    mainZveno = new(Zveno);
    current = mainZveno;
    (*mainZveno).Next = NULL;
    (*mainZveno).Previous = NULL;

    if ((*mainZveno).Next != NULL)
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
        cout << (*((*mainZveno).Next)).number << endl;
        current = (*((*mainZveno).Next)).Next;
        while (current != (*mainZveno).Next)
        {
            cout << (*current).number << endl;
            current = (*current).Next;
        }
    }
    else
    {
        cout << "Пусто";
    }
}

void List::SortNotspecial(List list)
{
    OneSidedList oneSidedList;
    OneSidedZveno* oneSidedCurrent;
    Zveno* current = (*(*mainZveno).Next).Next;
    int j = 0;
    do
    {
        if (((*current).number).length() == 7)
        {
            j++;
        }
        current=(*current).Next;
    }while (current != (*(*mainZveno).Next).Next);
    string* mas=new string[j];
    j = 0;
    do
    {
        if (((*current).number).length() == 7)
        {
            mas[j] = (*current).number;
            j++;
        }
        current = (*current).Next;
    } while (current != (*(*mainZveno).Next).Next);
    for (int i = 0; i < j; i++)
    {
        for (int h = 0; h < j-(i+1); h++)
        {
            if (mas[h]>mas[h+1])
            {
                string temp = mas[h];
                mas[h] = mas[h + 1];
                mas[h + 1] = temp;
            }
        }
    }
    oneSidedCurrent = oneSidedList.AddFirst(mas[0]);
    for (int i = 1; i < j; i++)
    {
        oneSidedCurrent = oneSidedList.Add(mas[i], oneSidedCurrent);
    }
    oneSidedList.Show();
}

OneSidedZveno* OneSidedList::AddFirst(string num)
{
    OneSidedZveno* temp = new OneSidedZveno;
    (*temp).number = num;
    (*temp).Next = NULL;
    first = temp;
    return temp;
}

void OneSidedList::Show()
{
    OneSidedZveno* current=first;
    if ((*current).Next != NULL)
    {
        do 
        {
            cout << (*current).number << endl;
            current = (*current).Next;
        } while ((*current).Next != NULL);
        cout << (*current).number << endl;
    }
    else
    {
        cout << "Пусто";
    }
}

OneSidedZveno* OneSidedList::Add(string num, OneSidedZveno* current)
{
    OneSidedZveno* temp = new OneSidedZveno;
    
    (*temp).number = num;
    (*current).Next = temp;
    (*temp).Next = NULL;
    return temp;
}




