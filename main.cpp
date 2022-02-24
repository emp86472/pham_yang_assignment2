#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream file;
    file.open(argv[1]); // file with ints
    setbuf(stdout, NULL);

    if (!file.is_open()) {
        cout << "Error: cannot parse information from ";
        cout << argv[1] << endl;
    } // if
    else {
        //int count = 0;
        int numInts;
        SortedLinkedList list;
        while (file >> numInts) {
            //cout << numInts << endl;
            list.insertItem(ItemType(numInts));
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
        while (true) {
            cout << "Enter Command: ";
            char command;
            cin >> command;
            cout << endl;

            if (command == 'i') { // insert value
                list.printList();
                cout << "Enter number: ";
                int number;
                cin >> number;
                cout << endl;
                list.insertItem(number);
                list.printList();
                continue;
            } // if

            if (command == 'd') { // delete value
                list.printList();
                cout << "Enter value to delete: ";
                int number;
                cin >> number;
                cout << endl;
                list.deleteItem(number);
                list.printList();
                continue;
            } // if

            if (command == 's') { // search value
                cout << "Enter a value to search: ";
                int number;
                cin >> number;
                cout << endl;
                int index = list.searchItem(number, true);
                if (index != -1) {
                    cout << index << endl;
                } //if
                continue;
            } // if

            if (command == 'n') { // print next iterator value
                ItemType t = list.getNextItem();
                if (!t.isNull()) {
                    cout << t.getValue() << endl;
                } //if
                continue;
            } // if
            if (command == 'r') { // reset iterator
                list.resetList();
                cout << "Iterator reset." << endl;
                continue;
            } // if
            if (command == 'a') { // delete alternate nodes
                cout << "List before alternate delete: ";
                list.printList();
                list.deleteAlt();
                cout << "List after alternate delete: ";
                list.printList();
                continue;
            } // if
            if (command == 'm') { // merge two lists
                cout << "Length of list to merge: ";
                int mergeLength;
                cin >> mergeLength;
                cout << endl;
                SortedLinkedList list2;
                string input;
                cout << "List elements seperated by spaces in order: ";

                //*************input stuff***
                vector<int> nums;
                cin.ignore();
                getline(cin, input);
                istringstream os(input);
                int i;
                while(os >> i) {
                    nums.push_back(i);
                } //while
                for (int i = 0; i < mergeLength; i++) {
                    list2.insertItem(ItemType(nums[i]));
                } //for
                //*********************

                cout << "list 1: ";
                list.printList();

                cout << "list 2: ";
                list2.printList();

                list.merge(list2);
                list.printList();
                list2.~SortedLinkedList();
                continue;
            } // if
            if (command == 't') { // intersection
               cout << "Length of list to find intersection: ";
               int interLength;
               cin >> interLength;
               cout << endl;
               SortedLinkedList list2;
               string input;
               cout << "List elements seperated by spaces in order: ";

               //*********************
               vector<int> nums;
                cin.ignore();
                getline(cin, input);
                istringstream os(input);
                int i;
                while(os >> i) {
                    nums.push_back(i);
                } //while
                for (int i = 0; i < interLength; i++) {
                    list2.insertItem(ItemType(nums[i]));
                } //for
                //*****************


               cout << "List 1: ";
               list.printList();

               cout << "List 2: ";
               list2.printList();

               cout << "Intersection: ";
               list.intersection(list2);
               list.printList();
               list2.~SortedLinkedList();
               continue;

            } // if
            if (command == 'p') { // print list
                list.printList();
                continue;
            } // if
            if (command == 'l') { // print length
                cout << "List length is " << list.getLength() << endl;
                continue;
            } // if
            if (command == 'q') { // quit program
                cout << "Quiting program..." << endl;
                break;
            } // if
            else {
                cout << "Invalid command, try again!" << endl;
            } //if
        } // while
    }//if
} //main
