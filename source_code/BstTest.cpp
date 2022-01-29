#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include "Date.h"
#include "Bst.h"
using namespace std;

//BST UNIT TEST----------------------------------------------------------
//-----------------------------------------------------------------------

void print(int &data);
void print(Date &data);

int test1(); //integer inorder traversal test
int test2(); //integer preorder traversal test
int test3(); //integer postorder traversal test
void test4(); //integer search element test
void test5(); //integer delete element test
void test6(); //copy constructor test
void test7(); //assignment operator test
void test8(); //searchElement(), findNode() method test

Date test9(); //Date inorder traversal test
Date test10(); //Date preorder traversal test
Date test11(); //Date postorder traversal test
void test12(); //Date search element test
void test13(); //Date delete element test
void test14(); //copy constructor test
void test15(); //assignment operator test
void test16(); //searchElement(), findNode() method test

void test17(); //IsEmpty() method test

int main()
{
    test1();
    cout<<endl;

    test2();
    cout<<endl;

    test3();
    cout<<endl;

    test4();
    cout<<endl;

    test5();
    cout<<endl;

    test6();
    cout<<endl;

    test7();
    cout<<endl;

    test8();
    cout<<endl;

    test9();
    cout<<endl;

    test10();
    cout<<endl;

    test11();
    cout<<endl;

    test12();
    cout<<endl;

    test13();
    cout<<endl;

    test14();
    cout<<endl;

    test15();
    cout<<endl;

    test16();
    cout<<endl;

    test17();
    cout<<endl;

    return 0;
}

void print(int &data)
{
    cout << data << "  ";
}

void print(Date &data)
{
    cout << data << "  ";
}
//-----------------------------------------------------------------------
//Integer Test
//-----------------------------------------------------------------------
int test1()
{
    Bst<int>  intTree;
    srand(time(NULL));

    for (int i =0; i< 20; i++)
    {
        intTree.insertElement(rand()%100);
    }
    cout<<"Inorder traversal"<<endl;
    intTree.inOrderTraversal(print);
    cout<<endl;

    return 0;
}

int test2()
{
    Bst<int>  intTree;
    srand(time(NULL));

    for (int i =0; i< 20; i++)
    {
        intTree.insertElement(rand()%100);
    }

    cout<<"Preorder traversal"<<endl;
    intTree.preOrderTraversal(print);
    cout<<endl;

    return 0;
}

int test3()
{
    Bst<int>  intTree;
    srand(time(NULL));

    for (int i =0; i< 20; i++)
    {
        intTree.insertElement(rand()%100);
    }

    cout<<"Postorder traversal"<<endl;
    intTree.postOrderTraversal(print);
    cout<<endl;

    return 0;
}

void test4()
{
    Bst<int>  intTree;

    int searchValue = 10;
    intTree.insertElement(searchValue);

    std::cout<<"Search element test - expected result: found"<<std::endl;
    if(intTree.searchElement(searchValue))
    {
        std::cout<<"found"<<std::endl;
    }
    else
    {
        std::cout<<"not found"<<std::endl;
    }
}

void test5()
{
    Bst<int>  intTree;

    int searchValue = 10;
    intTree.insertElement(searchValue);
    intTree.deleteElement(searchValue);

    std::cout<<"Delete element test - expected result: not found"<<std::endl;
    if(intTree.searchElement(searchValue))
    {
        std::cout<<"found"<<std::endl;
    }
    else
    {
        std::cout<<"not found"<<std::endl;
    }
}

void test6() //copy constructor test
{
    Bst<int>  intTree;

    for(int i=1; i<=5; i++)
    {
        intTree.insertElement(i);
    }

    Bst<int> copyTree(intTree);

    std::cout<<"Copy constructor test - expected result: 1,2,3,4,5"<<std::endl;
    copyTree.inOrderTraversal(print);
}

void test7() //assignment operator test
{
    Bst<int>  intTree;

    for(int i=1; i<=5; i++)
    {
        intTree.insertElement(i);
    }

    Bst<int> copyTree = intTree;

    std::cout<<"Assignment operator test - expected result: 1,2,3,4,5"<<std::endl;
    copyTree.inOrderTraversal(print);

}

void test8() //searchElement(), findNode() test
{
    Bst<int>  intTree;

    for(int i=1; i<=5; i++)
    {
        intTree.insertElement(i);
    }

    int intToFind = 5;
    std::cout<<"searchElement(), findNode() test - expected result: \"Integer found: 5\""<<std::endl;
    if(intTree.searchElement(intToFind))
    {
        cout<<"Integer found: "<<intTree.findNode(intToFind)->data<<endl;
    }
}
//-----------------------------------------------------------------------
// Date object Test
//-----------------------------------------------------------------------
Date test9()
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);
    Date dt4(1,4,2011);
    Date dt5(1,5,2011);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);
    dateTree.insertElement(dt4);
    dateTree.insertElement(dt5);

    std::cout<<"In-order traversal"<<std::endl;
	dateTree.inOrderTraversal(print);
	std::cout<<std::endl;
}

Date test10()
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);
    Date dt4(1,4,2011);
    Date dt5(1,5,2011);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);
    dateTree.insertElement(dt4);
    dateTree.insertElement(dt5);

    std::cout<<"Pre-order traversal"<<std::endl;
	dateTree.preOrderTraversal(print);
	std::cout<<std::endl;
}

Date test11()
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);
    Date dt4(1,4,2011);
    Date dt5(1,5,2011);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);
    dateTree.insertElement(dt4);
    dateTree.insertElement(dt5);

    std::cout<<"Post-order traversal"<<std::endl;
	dateTree.postOrderTraversal(print);
	std::cout<<std::endl;
}

void test12()
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);
    Date dt4(1,4,2011);
    Date dt5(1,5,2011);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);
    dateTree.insertElement(dt4);
    dateTree.insertElement(dt5);

    Date findDate(1,5,2011);
    std::cout<<"Search element test - expected result: found"<<std::endl;
	std::cout<<"Search result of "<<findDate<<": ";
	if(dateTree.searchElement(findDate))
    {
        std::cout<<"found"<<std::endl;
    }
    else
    {
        std::cout<<"not found"<<std::endl;
    }
}

void test13()
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);
    Date dt4(1,4,2011);
    Date dt5(1,5,2011);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);
    dateTree.insertElement(dt4);
    dateTree.insertElement(dt5);

    Date findDate(1,5,2011);
    std::cout<<"Delete element test - expected result: not found"<<std::endl;
	std::cout<<"Delete result of "<<findDate<<": ";
	dateTree.deleteElement(findDate);

	if(dateTree.searchElement(findDate))
    {
        std::cout<<"found"<<std::endl;
    }
    else
    {
        std::cout<<"not found"<<std::endl;
    }

}


void test14() //copy constructor test
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);

    Bst<Date> copyTree(dateTree);

    std::cout<<"Copy constructor test - expected result: 01/01/2012  01/02/2012  02/02/2012"<<std::endl;
    copyTree.inOrderTraversal(print);
    std::cout<<std::endl;
}

void test15() //assignment operator test
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);

    Bst<Date> copyTree = dateTree;

    std::cout<<"Assignment operator test - expected result: 01/01/2012  01/02/2012  02/02/2012"<<std::endl;
    copyTree.inOrderTraversal(print);
    std::cout<<std::endl;
}

void test16() //searchElement(), findElement test
{
    Bst<Date> dateTree;

    Date dt1(1,1,2012);
    Date dt2(1,2,2012);
    Date dt3(2,2,2012);

    dateTree.insertElement(dt1);
    dateTree.insertElement(dt2);
    dateTree.insertElement(dt3);

    std::cout<<"searchElement(), findNode() test - expected result: \"Date found: 01/01/2012\""<<std::endl;
    if(dateTree.searchElement(dt1))
    {
        Date dateFound;
        dateFound= dateTree.findNode(dt1)->data;
        cout<<"Date found: "<<dateFound<<endl;
    }

}

void test17()
{
    Bst<int> randomTree;

    std::cout<<"IsEmpty() test - expected result: Empty"<<std::endl;
    if(randomTree.IsEmpty())
    {
        std::cout<<"Empty"<<std::endl;
    }
    else
    {
        std::cout<<"Not empty"<<std::endl;
    }
}
