#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

struct OneSidedZveno
{
    string number, fio;
    OneSidedZveno* Next;
};

class OneSidedList
{
private:
    OneSidedZveno* first;
    int currentSize=0;
public:
    void Show();
    OneSidedZveno* Add(string num, string fio, OneSidedZveno*);
    OneSidedZveno* AddFirst(string num, string fio);
    void SearchFio(string fio);
    void SearchNumber(string number);
    int GetCurrentSize();
    OneSidedZveno* GetFirst();
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    OneSidedList list;
    string fio,fio1, number;
    cout << "Введите ФИО:" << endl;
    cin >> fio;
    cin >> fio1;
    fio += " ";
    fio += fio1;
    cin >> fio1;
    fio += " ";
    fio += fio1;
    cout << "Введите номер:" << endl;
    cin >> number;
    OneSidedZveno* current = list.AddFirst(number, fio);
    do
    {
        cout << "Введите ФИО(или 0 чтобы закончить):" << endl;
        cin >> fio;
        if (fio=="0")
            break;
        cin >> fio1;
        fio += " ";
        fio += fio1;
        cin >> fio1;
        fio += " ";
        fio += fio1;
        cout << "Введите номер(или 0 чтобы закончить):" << endl;
        cin >> number;
        if (number == "0")
            break;
        current = list.Add(number, fio, current);
    } while (true);
    /*OneSidedZveno* current = list.AddFirst("3754618", "Иванов И. И.");
    current = list.Add("6457819", "Петрова К. В.", current);
    current = list.Add("5746246", "Сидоров М. К.", current);
    current = list.Add("9754612", "Щеглов П. В.", current);
    current = list.Add("3164275", "Ижевская Т. Д.", current);*/
    if (list.GetCurrentSize() != 1)
    {
        string* masFio = new string[list.GetCurrentSize()];
        string* masNum = new string[list.GetCurrentSize()];
        current = list.GetFirst();
        for (int i = 0; i < list.GetCurrentSize(); i++)
        {
            masFio[i] = (*current).fio;
            masNum[i] = (*current).number;
            current = (*current).Next;
        }
        for (int i = 0; i < list.GetCurrentSize(); i++)
        {
            for (int h = 0; h < list.GetCurrentSize() - (i + 1); h++)
            {
                if (masFio[h] > masFio[h + 1])
                {
                    string temp = masFio[h];
                    masFio[h] = masFio[h + 1];
                    masFio[h + 1] = temp;
                    string temp1 = masNum[h];
                    masNum[h] = masNum[h + 1];
                    masNum[h + 1] = temp1;
                }
            }
        }
        current = list.GetFirst();
        for (int i = 0; i < list.GetCurrentSize(); i++)
        {
            (*current).fio= masFio[i];
            (*current).number= masNum[i];
            current = (*current).Next;
        }
    }
    list.Show();
    if (list.GetCurrentSize()==1)
    {
        cout << "В списке всего 1 элемент,поиск бессмысленен" << endl;
        return 0;
    }
    int x;
    string a,b;
    cout << "Выберите действие:" << endl;
    cout << "1 — поиск по ФИО" << endl;
    cout << "2 — поиск по номеру" << endl;
    cout << "Любой другой символ — закончить" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "Введите ФИО:" << endl;
        cin >> a;
        cin >> b;
        a += " ";
        a += b;
        cin >> b;
        a += " ";
        a += b;
        list.SearchFio(a);
        break;
    case 2:
        cout << "Введите номер:" << endl;
        cin >> a;
        list.SearchNumber(a);
        break;
    }
   
}

OneSidedZveno* OneSidedList::AddFirst(string num, string fio)
{
    OneSidedZveno* temp = new OneSidedZveno;
    (*temp).number = num;
    (*temp).fio = fio;
    (*temp).Next = NULL;
    currentSize++;
    first = temp;
    return temp;
}

void OneSidedList::Show()
{
    OneSidedZveno* current = first;
    if (currentSize==1)
    {
        cout << (*first).fio << ": " << (*first).number << endl;
        return;
    }
    if ((*current).Next != NULL)
    {
        do
        {
            cout <<(*current).fio<<": "<< (*current).number <<endl;
            current = (*current).Next;
        } while ((*current).Next != NULL);
        cout << (*current).fio << ": " << (*current).number << endl;
    }
    else
    {
        cout << "Пусто\n";
    }
}

OneSidedZveno* OneSidedList::Add(string num, string fio, OneSidedZveno* current)
{
    OneSidedZveno* temp = new OneSidedZveno;
    (*temp).number = num;
    (*temp).fio = fio;
    (*current).Next = temp;
    (*temp).Next = NULL;
    currentSize++;
    return temp;
}
void OneSidedList::SearchFio(string fio)
{
    
    OneSidedZveno* current = first;
    while ((*current).Next != NULL)
    {
        if ((*current).fio==fio)
        {
            cout << (*current).fio << ": " << (*current).number << endl;
            return;

        }
        //cout << "|"<<(*current).fio <<"|"<< fio<<endl;
        current = (*current).Next;
        
    }
    if ((*current).fio == fio)
    {
        cout << (*current).fio << ": " << (*current).number << endl;
        return;
    }
    //cout << (*current).fio << endl;
    cout << "По запросу ничего не найдено."<<endl;
}

void OneSidedList::SearchNumber(string number)
{
    OneSidedZveno* current = first;
    while ((*current).Next != NULL)
    {
        if ((*current).number == number)
        {
            cout << (*current).fio << ": " << (*current).number << endl;
            return;

        }
        //cout << "|"<<(*current).fio <<"|"<< fio<<endl;
        current = (*current).Next;

    }
    if ((*current).number == number)
    {
        cout << (*current).fio << ": " << (*current).number << endl;
        return;
    }
    //cout << (*current).fio << endl;
    cout << "По запросу ничего не найдено." << endl;
}
int OneSidedList::GetCurrentSize()
{
    return currentSize;
}
OneSidedZveno* OneSidedList::GetFirst()
{
    return(first);
}