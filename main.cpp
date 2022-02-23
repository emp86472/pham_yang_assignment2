#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"

int main(int argc, char *argv[]) {

    ifstream file;
    file.open(argv[1]); // file with ints

    if (!file.is_open()) {
        cout << "Error: cannot parse information from ";
        cout << argv[1] << endl;
    } // if
    else {
        int count = 0;
        int numInts;
        SortedLinkedList list();
        while (file >> numInts) {
            list.insertItem(numInts)
        } // while

        file.close();

        cout << "Commands:" << endl;
        cout << "(i) - Insert value" << endl;
        cout << "(d) - Delete value" << endl;
        cout << "(s) - Search value" << endl;
        cout << "(n) - Print next iterator value" << endl;
        cout << "(r) - Reset iterator" << endl;
        cout << "(a) - Delete alternate nodes" << endl;
        cout << "(m) - Merge two lists" << endl;
        cout << "(t) - Intersection" << endl;
        cout << "(p) - Print list" << endl;
        cout << "(l) - Print length" << endl;
        cout << "(q) - Quit program" << endl;

// main loop
        While (true) {
            cout << "Enter Command: ";
            char command;
            cin >> command;
            cout << endl;

            if (command == i) { // insert value
                list.printList();
                cout << "Enter number: "
                int number;
                cin >> number;
                cout << endl;
                list.insertItem(number);
                list.printList();
                continue;
            } // if

            if (command == d) { // delete value
                list.printList();
                cout << "Enter value to delete: ";
                int number;
                cin >> number;
                cout << endl;
                list.deleteItem(number);
                list.printList();
                continue;
            } // if

            if (command == s) { // search value
                cout << "Enter a value to search: ";
                int number;
                cin >> number;
                cout << endl;
                list.searchItem(number);
                continue;
            } // if

            if (command == n) { // print next iterator value
                cout << list.getNextItem().getValue(); << endl;
                continue;
            } // if
            if (command == r) { // reset iterator
                list.resetList();
                cout << "Iterator reset." << endl;
                continue;
            } // if
            if (command == a) { // delete alternate nodes
                cout << "List before alternate delete: ";
                list.printList();
                deleteAlt();
                cout << "List after alternate delete: ";
                list.printList();
                continue;
            } // if
            if (command == m) { // merge two lists
                cout << "Length of list to merge: ";
                int mergeLength;
                cin >> mergeLength;
                cout << endl;
                SortedLinkedList list2();
                String input;
                cout << "List elements seperated by spaces in order: ";
                getline(cin, input);
                stringstream stream(input);
                while(true) {
                    int n;
                    stream >> n;
                    if (!stream) {
                        break;
                    } // if
                    list2.insertItem(n);
                } // while

                cout << "list 1: ";
                list.printList();

                cout << "list 2: ";
                list2.printList();

                list.merge(list2);
                list.printList();
                continue;
            } // if
            if (command == t) { // intersection
               cout << "Length of list to find intersection: ";
               int interLength;
               cin >> interLength;
               cout << endl;
               SortedLinkedList list2();
               String input;
               cout << "List elements seperated by spaces in order: ";
               getline(cin, input);
               cout << endl;
               stringstream stream(input);
               while(true) {
                   int n;
                   stream >> n;
                   if (!stream) {
                       break;
                   } // if
                   list2.insertItem(n);
                } // while

               cout << "List 1: ";
               list.printList();

               cout << "List 2: ";
               list2.printList();

               list.intersection(list2);
               list.printList();
               continue;

            } // if
            if (command == p) { // print list
                list.printList();
                continue;
            } // if
            if (command == l) { // print length
                cout << "List length is " << list.length() << endl;
                continue;
            } // if
            if (command == q) { // quit program
                cout << "Quiting program..." << endl;
                break;
            } // if
            else {
                cout << "Invalid command, try again!" << endl;
        } // while
} //main
