#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

using namespace std;
template <typename T>

void singlylist() {
    SinglyLinkedList<T> list;
    cout << "Inserting 3 items at end " << endl;
    list.insertAtEnd(1.1);
    list.insertAtEnd(2.2);
    list.insertAtEnd(3.3);
    cout << list << endl;

    cout << "Inserting 4 items at beginning " << endl;
    list.insertAtBeginning(0);
    list.insertAtBeginning(-1);
    list.insertAtBeginning(-2);
    list.insertAtBeginning(-3);
    cout << list << endl;

    cout << "Removing from end: " << endl;
    list.removeFromEnd();
    cout << list << endl;

    cout << "Removing from beginning: " << endl;
    list.removeFromBeginning();
    cout << list << endl;

    cout << "Inserting at index 4 value 23" << endl;
    list.insertAtIndex(4, 23);
    cout << list << endl;

    cout << "Removing at index 2 " << endl;
    list.removeAtIndex(2);
    cout << list << endl;

    cout << "Item at position 3: " << list[3] << endl;
    cout << "Does value 23 exist? " << list.search(23) << endl;
    cout << "Size of list: " << list.getSize() << endl;
}

template <typename T>

void doubleList() {
    DoubleLinkedList<T> list;
    cout << "Inserting 3 items at end " << endl;
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    cout << list << endl;

    cout << "Inserting 4 items at beginning " << endl;
    list.insertAtBeginning(0);
    list.insertAtBeginning(-7);
    list.insertAtBeginning(-8);
    list.insertAtBeginning(-9);
    cout << list << endl;

    cout << "Removing from end: " << endl;
    list.removeFromEnd();
    cout << list << endl;

    cout << "Removing from beginning: " << endl;
    list.removeFromBeginning();
    cout << list << endl;

    cout << "Inserting at index 2 value 56" << endl;
    list.insertAtIndex(2, 56);
    cout << list << endl;

    cout << "Removing at index 1 " << endl;
    list.removeAtIndex(1);
    cout << list << endl;

    cout << "Item at position 4: " << list[4] << endl;
    cout << "Does value 56 exist? " << list.search(56) << endl;
    cout << "Size of list: " << list.getSize() << endl;
}

int main() {
    singlylist<double>();
    doubleList<int>();
    return 0;
}
