#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#define N 5
using namespace std;
int step;
int lastNumber;
struct Zveno
{
    int key;
    Zveno* left;
    Zveno* right;
    bool rTag=NULL, lTag=NULL;
};
Zveno* yPrevious;
class Tree
{
private:
    Zveno* first = NULL;
    Zveno* Head = new Zveno;
    
    int currentSize = 0;
public:
    void Add(int newKey);
    void PrintNormal(Zveno* node);
    void PrintSymmetry(Zveno* node); 
    void PrintSymmetrySewed(Zveno* node);
    void PrintReverse(Zveno* node);
    void Delete(Zveno* node, int deletable);
    void Delete2(Zveno* node, Zveno* zveno, int deletable);
    void Connect(Zveno* node);
    void ConnectSymmetry(Zveno* node);
    void SuperAdd(int newKey);
    void SuperPrintTree(Zveno* current, int floor);
    Zveno* Search(Zveno* node, int toFind);
    Zveno* SearchPrevious(Zveno* node, int toFind);
    void PrintTree(Zveno* current, int floor);
    Zveno* GetFirst();
    void SetHead();
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
    tree.Add(1);
    //tree.Add(13);
    cout << endl;
    cout << endl;
    tree.PrintTree(tree.GetFirst(), 0);
    cout << endl;
    cout << endl;
    tree.SetHead();
    yPrevious = tree.GetFirst();
    cout << "\nСимметричный обход: ";
    tree.PrintSymmetry(tree.GetFirst());
    cout << endl;
    tree.ConnectSymmetry(tree.GetFirst());
    cout << endl;
    cout << "Симметричный обход по прошитому дереву: ";
    tree.PrintSymmetrySewed(tree.GetFirst());
    int a;
    cout << "\nВыберите действие:\n";
    cout << "1 — Добавить\n";
    cout << "2 — Удалить\n";
    cin >> a;
    Zveno* found;

    switch (a)
    {
    case 1:
        cout << "Введите какой добавить:\n";
        cin >> a;
        tree.SuperAdd(a);
        cout << endl;
        cout << endl;
        tree.SuperPrintTree(tree.GetFirst(), 0);
        cout << endl;
        cout << endl;
        break;
    case 2:
        cout << "Выберите какой удалить:\n";
        cin >> a;
        tree.Delete(tree.GetFirst(), a);
        cout << endl;
        cout << endl;
        tree.SuperPrintTree(tree.GetFirst(), 0);
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
    if (first == NULL)
    {
        Zveno* temp = new Zveno;
        temp->key = newKey;
        temp->left = NULL;
        temp->right = NULL;
        first = temp;
        return;
    }
    Zveno* current = first;
    Zveno* temp = new Zveno;
    temp->key = newKey;
    temp->left = NULL;
    temp->right = NULL;
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
            
            current->right = temp;
            currentSize++;
            break;
        }
        if (current->key > newKey)
        {

            current->left = temp;
            currentSize++;
            break;
        }
    }
}

void Tree::PrintNormal(Zveno* node)
{
    if (node != NULL)
    {
        cout << node->key << "  ";
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
        lastNumber = node->key;
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
    step = 0;
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
    step = 0;
    while (true)
    {
        if (current->left != NULL && current->left->key == toFind)
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
    if (deletable == first->key)
    {
        cout << "Первый удалять нельзя." << endl;
        return;
    }
    if (node == NULL)
        cout << "Не найдено" << endl;
    else
    {
        if (deletable < node->key)
        {
            Delete(node->left, deletable);
        }
        else
        {
            if (deletable > node->key)
            {
                Delete(node->right, deletable);
            }
            else
            {
                current = node;
                if (current->left == NULL && current->rTag==FALSE)
                {
                    Zveno* previous = SearchPrevious(GetFirst(), deletable);
                    if (previous->left == current)
                    {
                        cout << previous->key << endl;
                        previous->left = NULL;
                    }
                    else
                    {
                        cout << previous->key << endl;
                        if (current->key==lastNumber)
                        {
                            previous->right = Head;
                            previous->rTag = FALSE;
                            delete current;
                            return;
                        }
                        previous->right = NULL;
                    }
                    delete current;
                    return;
                }
                if (current->rTag == FALSE)
                {
                    
                    Zveno* previous = SearchPrevious(GetFirst(), deletable);
                    node = current->left;
                    node->right = previous;
                    previous->left = node;
                    delete current;
                }
                else
                {
                    if (current->left == NULL)
                    {
                        Zveno* previous = SearchPrevious(GetFirst(), deletable);
                        node = current->right;
                        previous->left = node;
                        node->right = previous;
                        delete current;
                    }
                    else
                    {
                        Delete2(current->left, current, deletable);
                    }
                }
            }
        }
    }
}

void Tree::Delete2(Zveno* node, Zveno* zveno, int deletable)
{
    Zveno* current;
    if (node->rTag == FALSE)
    {
        Zveno* previous = SearchPrevious(GetFirst(), deletable);


        if (previous->right == zveno)
            previous->right = node;
        else
            previous->left = node;
        node->right= zveno->right;
        
        node->rTag = zveno->rTag;
    }
    else
    {
        Zveno* previous = SearchPrevious(GetFirst(), deletable);


        if (previous->right == zveno)
            previous->right = node;
        else
            previous->left = node->right;
        current = previous->left;
        current->right = zveno->right;
        current->left = node;
        current->rTag = zveno->rTag;
        node->right = NULL;

    }
}

void Tree::Connect(Zveno* node)
{
    if (yPrevious!=NULL)
    {
        if (yPrevious->right==NULL)
        {
            yPrevious->rTag = FALSE;
            yPrevious->right = node;
        }
        else
        {
            yPrevious->rTag = TRUE;
        }        
    }
    yPrevious = node;
}

void Tree::ConnectSymmetry(Zveno* node)
{
    if (node != NULL)
    {
        ConnectSymmetry(node->left);
        Connect(node);
        ConnectSymmetry(node->right);
        if (node->key == lastNumber)
        {
            node->right = Head;
            node->rTag = FALSE;
        }
        
    }
}

void Tree::PrintSymmetrySewed(Zveno* node)
{
    while (node!=Head)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
            cout << node->key << "  ";
            while (node->rTag == FALSE)
            {
                node = node->right;
                if (node == Head)
                {
                    return;
                }
                cout << node->key << "  ";
            }
            node = node->right;
        
    }
}

void Tree::SuperAdd(int newKey)
{
    Zveno* current = first;
    Zveno* temp = new Zveno;
    temp->key = newKey;
    temp->left = NULL;
    temp->right = NULL;
    
    while (true)
    {
        if (current->rTag==TRUE&&current->right != NULL && current->key < newKey)
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
            current->right = temp;
            current->rTag = TRUE;
            temp->rTag = FALSE;
            if (current->key==lastNumber)
            {
                temp->right = Head;
                break;
            }
            temp->right = SearchPrevious(first, current->key);
            cout << "SUPERFUCK " << current->key <<"  " <<temp->key<<"  " << temp->right->key << endl;
            break;
        }
        if (current->key > newKey)
        {
            
            current->left = temp;
            temp->rTag = FALSE;
            temp->right = current;
            break;
        }
    }
    
    if (current->key == lastNumber)
    {
        temp->right = Head;
        temp->rTag = FALSE;
    }
}

Zveno* Tree::GetFirst()
{
    return first;
}
void Tree::SetHead()
{
    Head->left = first;
    Head->right = Head;
    Head->key = 1055050;
}
void Tree::SuperPrintTree(Zveno* current, int floor)
{

    if (current == NULL)
        return;
    floor += N;
    if (current->rTag == TRUE)
    {       
        SuperPrintTree(current->right, floor);
    }
    for (int i = N; i < floor; i++)
        cout << " ";
    cout << current->key << "\n";
    SuperPrintTree(current->left, floor);
}
