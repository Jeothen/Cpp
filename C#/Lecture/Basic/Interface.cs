
using System;
using static System.Console;
using System.Collections;


interface IList
{
    void Clear();
}

// there's many interface in the Collections library

class Stack : IList // class must be implemented All method in the interface
{
    public void Clear() { }
}

class Queue : IList
{
    public void Clear() { }
}

//-----------------------

interface ICamera
{
    void Take();
    void Erase();
}

class MP3
{
    public virtual void Play() { }
}


class SmartPhone : MP3, ICamera
{
    public override void Play() // redefined
    {
//        base.Play();
    }

    //    public override void Take() {}  For the implement, there's no override


    // interface not using override, but using no virtual or virtual
    public void Take() { }
    public virtual void Erase() { }
}

class Interface
{
    static void Main()
    {

    }   
}
