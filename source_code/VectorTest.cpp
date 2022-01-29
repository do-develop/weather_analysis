#include <iostream>
#include "Vector.h"
using namespace std;

//VECTOR UNIT TEST-----------------------------------------------
//---------------------------------------------------------------
void VectorTest1();//Unit test Vector constructor
void VectorTest2();//Unit test Vector copy constructor
void VectorTest3();//Unit test Vector for Insert() and At() method
void VectorTest4();//Unit test Vector for get method, GetLast()
void VectorTest5();//Unit test Vector for get method, Resize() & GetCapacity()
void VectorTest6();//Unit test Vector for overloaded assignment operator
void VectorTest7();//Remove test
void VectorTest8();//IsEmpty() test

int main()
{
    VectorTest1(); //contructor test
    VectorTest2(); //copy constructor test
    VectorTest3(); //Insert() and At() method test
    VectorTest4(); //GetLast() test
    VectorTest5(); //Resuze() and GetCapacity() test
    VectorTest6(); //overloaded assingment operator test
    VectorTest7(); //Remove() test
    VectorTest8(); //IsEmpty() test

    return 0;
}
//VECTOR UNIT TEST-----------------------------------------------
//---------------------------------------------------------------
void VectorTest1()
{
    cout<<"=> Vector conctructor and GetCapacity() test"<<endl;
    cout<<"Expected result: 10"<<endl;
    cout<<endl;
}

void VectorTest2()
{
    cout<<"=> Vector copy constructor test"<<endl;
    cout<<"1) Expected result: different address for each vector(deep copy)"<<endl;
    Vector<int> vc1;
    vc1.Insert(10);
    vc1.Insert(20);
    vc1.Insert(30);
    Vector<int> vc2(vc1);
    cout<<"Address of Vector1: "<<&vc1<<endl;
    cout<<"Address of Vector2: "<<&vc2<<endl;
    cout<<"2) Expected result: same size, 3"<<endl;
    cout<<"Size of Vector1: "<<vc1.GetLast()<<endl;
    cout<<"Size of Vector2: "<<vc2.GetLast()<<endl;
    cout<<endl;
}

void VectorTest3()
{
    cout<<"=> Vector Push_back() and At() test"<<endl;
    cout<<"Expected result: 99"<<endl;
    Vector<int> vc;
    vc.Insert(99);
    cout<<vc.At(0)<<endl;//expected result = 99
    cout<<endl;
}

void VectorTest4()
{
    cout<<"=> Vector Insert() and GetLast() test"<<endl;
    cout<<"Expected result: 1"<<endl;
    Vector<int> vc;
    vc.Insert(99);
    cout<<vc.GetLast()<<endl;//expected result = 1
    cout<<endl;
}

void VectorTest5()
{
    cout<<"=> Vector Resize() test"<<endl;
    cout<<"Expected result: 15"<<endl;
    Vector<int> vc;
    for(int i=0; i<11; i++)
    {
        vc.Insert(i);
    }
    cout<<vc.GetCapacity()<<endl; //expected result = 15, size increases by 1.5
    cout<<endl;
}

void VectorTest6()
{
    cout<<"=>Vector overloaded assignment operator test"<<endl;
    cout<<"Expected result: different address for each vector(deep copy)"<<endl;
    Vector<int> vc1;
    Vector<int> vc2;
    vc2 = vc1;

    cout<<"Address of Vector1: "<<&vc1<<endl;
    cout<<"Address of Vector2: "<<&vc2<<endl;
    cout<<endl;
}

void VectorTest7()
{
    cout<<"=> Vector Remove() test"<<endl;
    cout<<"Expected result: 9"<<endl;
    Vector<int> vc;
    for(int i=0; i<10; i++)
    {
        vc.Insert(i);
    }

    vc.Remove();
    cout<<vc.GetLast()<<endl; //expected result = 9, 10-1
    cout<<endl;
}

void VectorTest8()
{
    cout<<"=> Vector IsEmpty() test_1"<<endl;
    cout<<"Expected result: True"<<endl;
    Vector<int> vc;
    if(vc.IsEmpty())
    {
        cout<<"True: the vector is empty"<<endl;
    }
    else
    {
        cout<<"False: the vector is not empty"<<endl;
    }

    cout<<"=> Vector IsEmpty() test_2"<<endl;
    cout<<"Expected result: False"<<endl;
    vc.Insert(1);
    if(vc.IsEmpty())
    {
        cout<<"True: the vector is empty"<<endl;
    }
    else
    {
        cout<<"False: the vector is not empty"<<endl;
    }


    cout<<endl;
}
