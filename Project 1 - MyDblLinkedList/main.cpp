
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{

    clsDblLinkedList <int> MydblLinkedList;
    
    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    cout << "\nList after update : \n";
    MydblLinkedList.InsertAfter(0, 200);
    MydblLinkedList.PrintList();
    // int position = 3;
    // cout << "value in pos " << position << " is : " << MydblLinkedList.GetItem(position); 
    // clsDblLinkedList <int> ::Node *N;
    // N = MydblLinkedList.GetNode(0);

    //cout << "Node is : " << N->value << endl;

}