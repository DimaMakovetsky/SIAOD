#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
struct OneSidedZveno
{
    string number;
    int key;
    OneSidedZveno* Next; 
};

class OneSidedList
{
private:
    OneSidedZveno* first;
    int currentSize = 0;
public:
    void Show();
    void Add(string num, int inputKey);
    void AddFirst(string num, int inputKey);
    int getSize();
    void deleteCurrent(int inputKey);
    OneSidedZveno* find(int inputKey);
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size=8;
    OneSidedList list[size];
    /*
    list[0].AddFirst("Манго", 9);
    list[1].AddFirst("Абрикос", 2);
    list[2].AddFirst("Яблоко", 35);
    list[3].AddFirst("Груша", 20);
    list[4].AddFirst("Апельсин", 13);
    list[5].AddFirst("Ананас", 14);
    list[6].AddFirst("Арбуз", 7);
    list[7].AddFirst("Дыня", 16);
    list[0].Add("Помидор", 1);
    list[1].Add("Огурец", 26);
    list[1].Add("Картошка", 34);
    list[2].Add("Гранат", 19);
    list[3].Add("Кабачок", 4);
    list[4].Add("Лук", 5);
    list[5].Add("Лайм", 22);
    list[6].Add("Лимон", 15); 
    list[6].Add("Чеснок", 23);
    list[6].Add("Капуста", 39);
    list[7].Add("Грейпфрут", 32);*/
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ":";
        list[i].Show();
    }
    
    OneSidedZveno* found;
    int choise;
    string value;
    while (true)
    {
        cout << "Выберите действие:" << endl;
        cout << "1 — поиск по ключу." << endl;
        cout << "2 — добавить элемент." << endl;
        cout << "3 — удалить элемент." << endl;
        cout << "Что-то ещё — закончить." << endl;
        int originalKey, key;
        cin >> choise;
        switch (choise)
        {
        case 1:
            
            cout << "Введите ключ для поиска:" << endl;
            cin >> originalKey;
            key = originalKey;
            while (key > size)
                key -= size;
            key--;
            found = list[key].find(originalKey);
            if (found == NULL)
                cout << "Элемент с таким ключом не обнаружен."<<endl;
            else
                cout << "Ряд " << key + 1 << ": (" << (*found).key << ", " << (*found).number << "); " << endl;
            break;
        case 2:            
            cout << "Введите ключ(больше 0): " << endl;
            cin >> originalKey;
            if (originalKey <= 0)
            {
                cout << "Неверный ввод." << endl;
                break;
            }
            cout << "Введите значение: " << endl;
            cin >> value;
            key = originalKey;
            while (key > size)
                key -= size;
            key--;
            if (list[key].getSize()==0)
                list[key].AddFirst(value, originalKey);
            else
                list[key].Add(value, originalKey);
            for (int i = 0; i < size; i++)
            {
                cout << i + 1 << ":";
                list[i].Show();
            }
            break;
            
            case 3:
                cout << "Введите ключ для удаления:" << endl;
                cin >> originalKey;
                key = originalKey;
                while (key > size)
                    key -= size;
                key--;
                list[key].deleteCurrent(originalKey);
                for (int i = 0; i < size; i++)
                {
                    cout << i + 1 << ":";
                    list[i].Show();
                }
                break;
           default:
               return 0;
        }
    }
    
}

void OneSidedList::Show()
{
    OneSidedZveno* current = first;
    if (currentSize==0)
    {
        cout << "Пусто\n";
        return;
    }
    if (currentSize == 1)
    {
        cout << " (" << (*current).key << ", " << (*current).number << "); "<<endl;
        return;
    }
    if ((*current).Next != NULL)
    {
        do
        {
            cout << " ("<<(*current).key << ", " << (*current).number<<"); ";
            current = (*current).Next;
        } while ((*current).Next != NULL);
        cout << " (" << (*current).key << ", " << (*current).number << "); " << endl;
    }
    
}

void OneSidedList::deleteCurrent(int inputkey)
{
    OneSidedZveno* current=find(inputkey);
    if (current==NULL)
    {
        cout << "Элемента с таким ключом нет."<<endl;
        return;
    }
    if (first==current)
    {
        if (currentSize==1)
        {
            first = NULL;
            currentSize--;
        }
        else
        {
            first=(*first).Next;
            currentSize--;
        }
        return;
    }
    OneSidedZveno* previous=first;
    while ((*previous).Next!=current)
    {
        previous = (*previous).Next;
    }
    (*previous).Next = (*current).Next;
    currentSize--;
}

void OneSidedList::AddFirst(string num, int inputKey)
{
    OneSidedZveno* temp = new OneSidedZveno;
    (*temp).number = num;
    (*temp).key = inputKey;
    (*temp).Next = NULL;
    currentSize++;
    first = temp;
}

void OneSidedList::Add(string num, int inputKey)
{
    OneSidedZveno* temp = new OneSidedZveno;
    if (currentSize==1)
    {
        (*first).Next = temp;
        (*temp).number = num;
        (*temp).key = inputKey;
        currentSize++;
        (*temp).Next = NULL;
        return;
    }
    OneSidedZveno* current = first;
    while ((*current).Next!=NULL)
        current=(*current).Next;
    (*current).Next = temp;
    (*temp).number = num;
    (*temp).key = inputKey;
    currentSize++;
    (*temp).Next = NULL;
}

OneSidedZveno* OneSidedList::find(int inputKey)
{
    if (currentSize==0)
    {
        return NULL;
    }
    OneSidedZveno* current = first;
    if (currentSize==1)
    {
        if ((*current).key==inputKey)
        {
            return current;
        }
        else
        {
            return NULL;
        }
    }
    while ((*current).Next!=NULL)
    {
        if ((*current).key == inputKey)
        {
            return current;
        }
        current = (*current).Next;
    }
    if ((*current).key == inputKey)
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

int OneSidedList::getSize()
{
    return currentSize;
}

