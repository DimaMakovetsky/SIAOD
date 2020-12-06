#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#define N 5
using namespace std;
int step;
struct Zveno
{
    int key;
    Zveno* left;
    Zveno* right;
};
class Tree
{
private:
    Zveno* first=NULL;
public:
    void Add(int newKey);
    void PrintNormal(Zveno* node);
    void PrintSymmetry(Zveno* node);
    void PrintReverse(Zveno* node);
    void Delete(Zveno* node, int deletable);
    void Delete2(Zveno* node, Zveno* zveno,int deletable);
    Zveno* Search(Zveno* node, int toFind);
    Zveno* SearchPrevious(Zveno* node, int toFind);
    void PrintTree(Zveno* current, int floor);
    Zveno* GetFirst();
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tree tree;
    tree.Add(10);
    tree.Add(15);

    tree.Add(5);
    tree.Add(7);
    tree.Add(2);
    tree.Add(20);
    tree.Add(12);
    //tree.Add(3);
    //tree.Add(3);
    //tree.Add(13);
    cout << endl;
    cout << endl;
    tree.PrintTree(tree.GetFirst(), 0);
    cout << endl;
    cout << endl;
    cout << "Прямой обход: ";
    tree.PrintNormal(tree.GetFirst());
    cout << "\nСимметричный обход: ";
    tree.PrintSymmetry(tree.GetFirst());
    cout << "\nОбратный обход: ";
    tree.PrintReverse(tree.GetFirst());
    int a;
    cout << "\nВыберите действие:\n";
    cout << "1 — Добавить\n";
    cout << "2 — Найти\n";
    cout << "3 — Удалить\n";
    cin >> a;
    Zveno* found;

    switch (a)
    {
    case 1:
        cout << "Введите какой добавить:\n";
        cin >> a;
        tree.Add(a);
        cout << endl;
        cout << endl;
        tree.PrintTree(tree.GetFirst(), 0);
        cout << endl;
        cout << endl;
        break;
    case 2:
        cout << "Введи какой найти:\n";
        cin >> a;
        found = tree.Search(tree.GetFirst(), a);
        if (found == NULL)
        {
            cout << "Не найдено" << endl;
        }
        else
        {
            cout << "Элемент " << found->key << " найден на " << step + 1 << " ступени." << endl;
        }
        break;
    case 3:
        cout << "Выберите какой удалить:\n";
        cin >> a;
        tree.Delete(tree.GetFirst(), a);
        cout << endl;
        cout << endl;
        tree.PrintTree(tree.GetFirst(), 0);
        cout << endl;
        cout << endl;
        break;
    default:
        break;

    } 
}
void Tree::PrintTree(Zveno* current, int floor)
{
    if (current == NULL)
        return;
    floor += N;
    PrintTree(current->right, floor);
    for (int i = N; i < floor; i++)
        cout << " ";
    cout << current->key << "\n";
    PrintTree(current->left, floor);
}
void Tree::Add(int newKey)
{
    if (first==NULL)
    {
        Zveno* temp=new Zveno;
        temp->key = newKey;
        temp->left = NULL;
        temp->right = NULL;
        first = temp;
        return;
    }
    Zveno* current = first;
    while (true)
    {
        if (current->right != NULL && current->key < newKey)
        {
            current = current->right;
            continue;
        }
        if (current->left != NULL && current->key > newKey)
        {
            current = current->left;
            continue;
        }
        if (current->key < newKey)
        {
            Zveno* temp = new Zveno;
            temp->key = newKey;
            temp->left = NULL;
            temp->right = NULL;
            current->right = temp;
            break;
        }
        if (current->key > newKey)
        {
            Zveno* temp = new Zveno;
            temp->key = newKey;
            temp->left = NULL;
            temp->right = NULL;
            current->left = temp;
            break;
        }
    }
}

void Tree::PrintNormal(Zveno* node)
{
    if (node!=NULL)
    {
        cout << node->key<<"  ";
        PrintNormal(node->left);
        PrintNormal(node->right);
    }
}
void Tree::PrintSymmetry(Zveno* node)
{
    if (node != NULL)
    {
        PrintSymmetry(node->left);
        cout << node->key << "  ";
        PrintSymmetry(node->right);
        
    }
}
void Tree::PrintReverse(Zveno* node)
{
    if (node != NULL)
    {
        PrintReverse(node->left);
        PrintReverse(node->right);
        cout << node->key << "  ";
    }
}

Zveno* Tree::Search(Zveno* node, int toFind)
{
    Zveno* current = first;
    step =0;
    while (true)
    {
        if (current == NULL)
        {
            return NULL;
        }
        if (current->key == toFind)
        {
            return current;
        }
        if (toFind > current->key)
        {
            current = current->right;
            step++;
            continue;
        }
        if (toFind < current->key)
        {
            step++;
            current = current->left;
        }
    }
}

Zveno* Tree::SearchPrevious(Zveno* node, int toFind)
{
    Zveno* current = first;
    while (true)
    {
        if (current->left!=NULL&&current->left->key == toFind)
        {
            return current;
        }
        if (current->right != NULL && current->right->key == toFind)
        {
            return current;
        }
        if (toFind > current->key)
        {
            current = current->right;
            step++;
            continue;
        }
        if (toFind < current->key)
        {
            step++;
            current = current->left;
        }
    }
}

void Tree::Delete(Zveno* node, int deletable)
{
    Zveno* current;
    if (deletable==first->key)
    {
        cout << "Первый удалять нельзя." << endl;
        return;
    }
    if (node==NULL)
        cout << "Не найдено"<<endl;
    else
    {
        if (deletable<node->key)
        {
            Delete(node->left, deletable);
        }
        else
        {
            if (deletable>node->key)
            {
                Delete(node->right, deletable);
            }
            else
            {
                current = node;
                if (current->left==NULL&&current->right==NULL)
                {
                    Zveno* previous=SearchPrevious(GetFirst(), deletable);
                    if (previous->left==current)
                    {
                        previous->left = NULL;
                    }
                    else
                    {
                        previous->right = NULL;
                    }
                    delete current;
                    return;
                }
                if (current->right==NULL)
                {
                    cout << "Biba" << endl;
                    Zveno* previous = SearchPrevious(GetFirst(), deletable);
                    node = current->left;
                    previous->left = node;
                    delete current;
                }
                else
                {
                    if (current->left==NULL)
                    {
                        Zveno* previous = SearchPrevious(GetFirst(), deletable);
                        node = current->right;
                        previous->left = node;
                        delete current;
                    }
                    else
                    {
                        Delete2(current->left, current,deletable);
                    }
                }
            }
        }
    }
}

void Tree::Delete2(Zveno* node, Zveno* zveno,int deletable)
{
    Zveno* current = zveno;
    if (node->right==NULL)
    {
        Zveno* previous = SearchPrevious(GetFirst(), deletable);
        
        
        if (previous->right==zveno)
        {
            previous->right = node;
        }
        else
        {
            previous->left = node;
        }
        node->right = zveno->right;

    }
    else
    {

        Zveno* previous = SearchPrevious(GetFirst(), deletable);


        if (previous->right == zveno)
        {
            previous->right = node;
        }
        else
        {
            previous->left = node->right;
        }
        current = previous->left;
        current->right = zveno->right;
        current->left = node;
        node->right = NULL;
    }
}


Zveno* Tree::GetFirst()
{
    return first;
}
