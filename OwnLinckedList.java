package com.company;

public class OwnLinckedList
{
    private Mnogochlin first; //ссылка на первое значение списка
    private int size = 0; //размер списка
    public Mnogochlin getFirst(){ return first; }//получить первый элемент
    public void setFirst(Mnogochlin mnog){ first = mnog; } //поставить первым
    public int getSize(){ return size; } //получить размер списка
    public void plusSize(){ size++; }//увеличить длину списка на 1
    public void minusSize(){ size--; } //уменьшить длину списка на 1
    OwnLinckedList(){ first = null; } //конструктор LinckedList'а
    public boolean isEmpty(){ return first == null; } //проверка на пустоту списка
    public void clear() {first=null; size=0;}//очистка списка
}