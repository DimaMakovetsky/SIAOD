package com.company;

public class Mnogochlin
{
    private int stepen;
    private int osnova;
    private Mnogochlin next;
    Mnogochlin( int osnova,int stepen)
    {
        this.stepen=stepen;
        this.osnova=osnova;
    }
    Mnogochlin(Mnogochlin mnogochlin)
    {
        this.stepen=mnogochlin.stepen;
        this.osnova=mnogochlin.osnova;
        next=null;
    }
    public int getStepen()
    {
        return stepen;
    }
    public int getOsnova()
    {
        return osnova;
    }
    public void setOsnova(int osnova)
    {
       this.osnova=osnova;
    }
    public void setStepen(int stepen)
    {
        this.stepen=stepen;
    }
    public Mnogochlin getNext()
    {
        return next;
    }
    public void setNext(Mnogochlin next)
    {
        this.next=next;
    }
}
