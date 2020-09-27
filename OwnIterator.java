package com.company;

public class OwnIterator
{
        private Mnogochlin current;         // Текущий элемент списка
        private Mnogochlin previous;
        private OwnLinckedList list;       // Связанный список

        public OwnIterator(OwnLinckedList list){   // Конструктор
            this.list = list;
            reset();
        }

        public void reset(){                // Возврат итератора на первую позицию в списке
            current = list.getFirst();
            previous = null;
        }

        public void nextLink(){                      // Переход к следующему элементу
            previous = current;
            current = current.getNext();
        }

        public Mnogochlin getCurrent(){ // Получение текущего элемента
            return current;
        }

        public void putBefore(Mnogochlin mnogochlin) {      //вставка перед текущим элементом
            Mnogochlin newMnogochlin = new Mnogochlin(mnogochlin);
            if (previous == null){                     //в случае пустого списка или его начала
                newMnogochlin.setNext(list.getFirst());
                list.setFirst(newMnogochlin);
                reset();
            } else {                                   //если не в начале списка
                newMnogochlin.setNext(previous.getNext());
                previous.setNext(newMnogochlin);
                current = newMnogochlin;
            }
        }

        public void putAfter(Mnogochlin mnogochlin) {         // Вставка после текущего элемента
            Mnogochlin newMnogochlin = new Mnogochlin(mnogochlin);
            if (list.isEmpty()) {                    //в случае пустого списка
                list.setFirst(newMnogochlin);
                current = newMnogochlin;
            } else {                                   //если писок не пуст
                newMnogochlin.setNext(current.getNext());
                current.setNext(newMnogochlin);
                nextLink();                     //переход к новому элементу
            }
        }

        public boolean atEnd(){                     //true, текущий элемент — последний
            return (current.getNext() == null);
        }

        public void deleteCurrent()
        {                  //удаление текущего элемента
            if (previous == null)
            {                   //если начало списка
                list.setFirst(current.getNext());
                reset();
            }
            else
            {                                   //если не начало списка
                previous.setNext(current.getNext());
                if (atEnd())
                    reset();
                else
                    current = current.getNext();
            }
        }
}
