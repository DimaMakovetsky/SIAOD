#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
struct Zveno
{
    string data;
    Zveno* Next;
};
class FifoRow
{
private:
    Zveno* first,*last;
    int currentSize = 0;
public:
    void Show();
    void Add(string num);
    void AddFirst(string num);
    int getSize();
    void deleteCurrent(string num);
    string find(string num);
    string solve();
    string solveFirst();
    void superSolve();
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FifoRow row;
    row.AddFirst("Окно");
    row.Add("Ручка");
    row.Add("Стул");
    row.Add("Пульт");
    row.Add("Диван");
    row.Add("Цветы");
    row.Add("И");
    row.Add("Он");
    row.Add("Диск");
    row.Add("Яд");
    row.Add("Л");
    row.Add("М");
    row.Add("К");
    row.Add("Уха");
    row.Add("Волк");
    row.Add("Ёж");
    row.Add("Чаша");
    row.Show();
    /*while (row.getSize()!=0)
    {
        cout << row.solveFirst() << endl;
        
    }*/
    int choise;
    while (true)
    {
        string word = "asdassad", found;
        cout << "Выберите действие:" << endl;
        cout << "1 — добавить в очередь" << endl;
        cout << "2 — удалить из очереди" << endl;
        cout << "3 — найти в очереди" << endl;
        cout << "4 — обработать очередь с приоритетом у слов из 3 букв и закрыть программу" << endl;
        cout << "Что-то ещё — закрыть программу" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            while (word.length() > 5)
            {
                cout << "Введите желаемое слово из 5 или меньше букв:" << endl;
                cin >> word;
            }
            if (row.getSize() == 0)
                row.AddFirst(word);
            else
                row.Add(word);
            row.Show();
            break;
        case 2:
            while (word.length() > 5)
            {
                cout << "Введите удаляемое слово из 5 или меньше букв:" << endl;
                cin >> word;
            }
            found = row.find(word);
            if (found == "NOTFOUND")
            {
                cout << "Введённое слово не обнаружено." << endl;
                break;
            }
            row.deleteCurrent(word);
            row.Show();
            break;
        case 3:
            while (word.length() > 5)
            {
                cout << "Введите искомое слово из 5 или меньше букв:" << endl;
                cin >> word;
            }
            found = row.find(word);
            if (found == "NOTFOUND")
            {
                cout << "Введённое слово не обнаружено." << endl;
            }
            else
            {
                cout << "Введённое слово найдено: " << found << endl;
            }
            break;
        case 4:
            row.superSolve();
            return 0;
        default:
            return 0;
        }
    } 
    //

}

void FifoRow::AddFirst(string data)
{
    Zveno* temp = new Zveno;
    (*temp).data = data;
    (*temp).Next = NULL;
    currentSize++;
    first = temp;
    last = temp;
}
void FifoRow::Add(string data)
{
    Zveno* temp = new Zveno;
    Zveno* current = first;
    if (currentSize == 1)
    {
        (*temp).data = data;
        currentSize++;
        (*temp).Next = current;
        first = temp;
        return;
    }
    (*temp).data = data;
    currentSize++;
    (*temp).Next = current;
    first = temp;
}
void FifoRow::Show()
{
    Zveno* current = first;
    if (currentSize == 0)
    {
        cout << "Пусто\n";
        return;
    }
    if (currentSize == 1)
    {
        cout << (*current).data<< endl;
        return;
    }
    if ((*current).Next != NULL)
    {
        do
        {
            cout <<  (*current).data << "  ";
            current = (*current).Next;
        } while ((*current).Next != NULL);
        cout << (*current).data << "  "<<endl;
    }
    
}
string FifoRow::solve()
{
    if (currentSize == 0)
    {
        return "Пусто";
    }
    string getData = last->data;
    Zveno* current = first;
    if (currentSize == 1)
    {
        first = last = NULL;
        currentSize--;
        return getData;
    }
    while ((*current).Next!=last)
    {
        current = (*current).Next;
        
    }
    current->Next = NULL;
    last = current;
    currentSize--;
    return getData;/**/
}
string FifoRow::solveFirst()
{
    if (currentSize == 0)
    {
        return "Пусто";
    }
    string getData = first->data;
    if (currentSize == 1)
    {
        first = last = NULL;
        currentSize--;
        return getData;
    }
    first = first->Next;
    currentSize--;
    return getData;/**/
}
int FifoRow::getSize()
{
    return currentSize;
}
void FifoRow::superSolve()
{
    FifoRow mas[5];
    Zveno* current = first;
    //cout << current->data;
    while (current!=NULL)
    {
        //cout << "abbbbb";
        int i = ((*current).data).length()-1;
        
        if (mas[i].getSize()==0)
        {
            //cout << i << ": " << current->data << endl;
            mas[i].AddFirst(current->data);
        }
        else
        {
            //cout << i << ": " << current->data << endl;
            mas[i].Add(current->data);
        }
        current = current->Next;
    }
    /**/for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ": ";
        mas[i].Show();
    }
    FifoRow temp= mas[2];
    mas[2] = mas[0];
    mas[0] = temp;
    for (int i = 1; i < 4; i++)
    {
        
        int min = i;
        for (int j = i+1; j < 5; j++)
        {
            if (mas[j].currentSize>mas[min].currentSize)
            {
                min = j;
            }
        }
        temp = mas[i];
        mas[i] = mas[min];
        mas[min] = temp;
    }
    /*for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ": ";
        mas[i].Show();
    }
    */for (int i = 0; i < 5; i++)
    {
        current = mas[i].first;
        while (mas[i].currentSize!=0)
        {
            cout<<mas[i].solveFirst()<<"  ";
        }
        //cout << endl;

    }
}
string FifoRow::find(string num)
{
    Zveno* current = first;
    while (current!=NULL)
    {
        if (current->data==num)
        {
            return num;
        }
        current = current->Next;
    }
    return "NOTFOUND";
}
void FifoRow::deleteCurrent(string num)
{
    if (first->data==num)
    {
        solveFirst();
        return;
    }
    if (last->data == num)
    {
        solve();
        return;
    }
    Zveno* current = first;
    while (current->Next->data!=num)
        current = current->Next;
    current->Next = current->Next->Next;
    currentSize--;
}