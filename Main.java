package com.company;

import java.text.ParseException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static Boolean Equality(OwnLinckedList p, OwnLinckedList q)
    {
        OwnIterator iteratorP=new OwnIterator(p);
        OwnIterator iteratorQ=new OwnIterator(q);
        int i=0;
        while (i!=p.getSize()||i!=q.getSize())
        {
            if (iteratorP.getCurrent().getStepen()>iteratorQ.getCurrent().getStepen())
                return true;
            if (iteratorP.getCurrent().getStepen()<iteratorQ.getCurrent().getStepen())
                return false;
            if (iteratorP.getCurrent().getStepen()==iteratorQ.getCurrent().getStepen())
            {
                if (iteratorP.getCurrent().getOsnova()!=iteratorQ.getCurrent().getOsnova())
                {
                    if (iteratorP.getCurrent().getOsnova()>iteratorQ.getCurrent().getOsnova())
                        return true;
                    else return false;
                }
            }
            iteratorP.nextLink();
            iteratorQ.nextLink();
            i++;
        }
        return null;
    }

    public static double Meaning(OwnLinckedList p, int x)
    {
        OwnIterator iterator=new OwnIterator(p);
        double result=0;
        for (int i=0;i<p.getSize();i++)
        {
            result+=iterator.getCurrent().getOsnova()*(Math.pow(x,iterator.getCurrent().getStepen()));
            iterator.nextLink();
        }
        return result;
    }

    public static void Sum(OwnLinckedList q, OwnLinckedList r)
    {
        OwnLinckedList p=new OwnLinckedList();
        OwnIterator iteratorP=new OwnIterator(p);
        OwnIterator iteratorQ=new OwnIterator(q);
        OwnIterator iteratorR=new OwnIterator(r);
        int lenghtA=0,lenghtB=0;
        while(lenghtA!=q.getSize()||lenghtB!=r.getSize())
        {
            if (iteratorQ.getCurrent().getStepen()==iteratorR.getCurrent().getStepen())
            {
                iteratorP.putAfter(new Mnogochlin((iteratorQ.getCurrent().getOsnova()+iteratorR.getCurrent().getOsnova()),iteratorQ.getCurrent().getStepen()));
                iteratorQ.nextLink();
                iteratorR.nextLink();
                p.plusSize();
                lenghtA++;
                lenghtB++;
                continue;
            }
            if (lenghtA!=q.getSize()&&iteratorQ.getCurrent().getStepen()>iteratorR.getCurrent().getStepen())
            {
                iteratorP.putAfter(new Mnogochlin(iteratorQ.getCurrent().getOsnova(),iteratorQ.getCurrent().getStepen()));
                iteratorQ.nextLink();
                p.plusSize();
                lenghtA++;
                continue;
            }
            if (lenghtB!=r.getSize()&&iteratorR.getCurrent().getStepen()>iteratorQ.getCurrent().getStepen())
            {
                iteratorP.putAfter(new Mnogochlin(iteratorR.getCurrent().getOsnova(),iteratorR.getCurrent().getStepen()));
                iteratorR.nextLink();
                p.plusSize();
                lenghtB++;
            }
        }
        iteratorP.reset();
        for (int i=0;i<p.getSize();i++)
        {
            System.out.print(iteratorP.getCurrent().getOsnova()+"*x^"+iteratorP.getCurrent().getStepen());
            if (i+1!=p.getSize())
                System.out.print("+");
            iteratorP.nextLink();
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        ArrayList<Mnogochlin> list=new ArrayList<>();
        OwnLinckedList list1=new OwnLinckedList();
        OwnIterator iterator1=new OwnIterator(list1);
        OwnLinckedList list2=new OwnLinckedList();
        OwnIterator iterator2=new OwnIterator(list2);
        Scanner scan=new Scanner(System.in);
        int stepen,osnova;
        System.out.println("Ввод первого многочлена:");
        while(true)
        {
            System.out.println("Ввод множителя(чтобы закончить введите не цифру):");
            try{osnova=scan.nextInt();}
            catch (Exception ex)
            {scan.next();
                break;}
            if (osnova==0)
                continue;
            System.out.println("Ввод степени(чтобы закончить введите 0):");
            stepen=scan.nextInt();
            if (stepen==0)
                break;
            list.add(new Mnogochlin(osnova,stepen));
        }
        for (int i=list.size()-1;i>=0;i--)
        {
            for (int j=0;j<i;j++)
            {
                if (list.get(j).getStepen()<list.get(j+1).getStepen())
                {
                    int n=list.get(j).getStepen(),m=list.get(j).getOsnova();
                    list.get(j).setStepen(list.get(j+1).getStepen());
                    list.get(j).setOsnova(list.get(j+1).getOsnova());
                    list.get(j+1).setOsnova(m);
                    list.get(j+1).setStepen(n);
                }
            }
        }
        for (int i=0;i<list.size();i++)
        {
            list1.plusSize();
            iterator1.putAfter(new Mnogochlin(list.get(i).getOsnova(),list.get(i).getStepen()));
        }
        list.clear();
        System.out.println("Ввод второго многочлена:");
        while(true)
        {
            System.out.println("Ввод множителя(чтобы закончить введите не цифру):");
            try{osnova=scan.nextInt();}
            catch (Exception ex)
            {scan.next();
                break;}
            if (osnova==0)
                continue;
            System.out.println("Ввод степени(чтобы закончить введите -1):");
            stepen=scan.nextInt();
            if (stepen==-1)
                break;
            list.add(new Mnogochlin(osnova,stepen));
        }
        for (int i=list.size()-1;i>=0;i--)
        {
            for (int j=0;j<i;j++)
            {
                if (list.get(j).getStepen()<list.get(j+1).getStepen())
                {
                    int n=list.get(j).getStepen(),m=list.get(j).getOsnova();
                    list.get(j).setStepen(list.get(j+1).getStepen());
                    list.get(j).setOsnova(list.get(j+1).getOsnova());
                    list.get(j+1).setOsnova(m);
                    list.get(j+1).setStepen(n);
                }
            }
        }
        for (int i=0;i<list.size();i++)
        {
            list2.plusSize();
            iterator2.putAfter(new Mnogochlin(list.get(i).getOsnova(),list.get(i).getStepen()));
        }
        iterator1.reset();
        iterator2.reset();
        for (int i=0;i<list1.getSize();i++)
        {
            System.out.print(iterator1.getCurrent().getOsnova()+"*x^"+iterator1.getCurrent().getStepen());
            if (i+1!=list1.getSize())
                System.out.print("+");
            iterator1.nextLink();
        }
        System.out.println();
        for (int i=0;i<list2.getSize();i++)
        {
            System.out.print(iterator2.getCurrent().getOsnova()+"*x^"+iterator2.getCurrent().getStepen());
            if (i+1!=list2.getSize())
                System.out.print("+");
            iterator2.nextLink();
        }
        System.out.println();
        while(true)
        {
            int n;
            System.out.println("Выберите действие:");
            System.out.println("1 — Сравнить многочлены");
            System.out.println("2 — Вычислить многочлен с переменной х");
            System.out.println("3 — Сложить многочлены");
            System.out.println("Любой другой символ — закрыть программу");
            try{ n = scan.nextInt();}
            catch (Exception ex){ break;}
            switch (n)
            {
                case 1:
                {
                    Boolean equality = Equality(list1, list2);
                    if (equality == null)
                        System.out.println("Многочлены равны");
                    else if (equality)
                        System.out.println("Многочлен 1 больше второго");
                    else
                        System.out.println("Многочлен 1 меньше второго");
                    break;
                }
                case 2:
                {
                    int m,x;
                    double meaning;
                    System.out.println("Выберите какой многочлен вычислять:");
                    m=scan.nextInt();
                    System.out.println("Введите х:");
                    x=scan.nextInt();
                    if (m==1)
                        meaning=Meaning(list1,x);
                    else
                        meaning=Meaning(list2,x);
                    System.out.println(meaning);
                    break;
                }
                case 3:
                {
                    Sum(list1,list2);
                }
            }
        }
    }


}
