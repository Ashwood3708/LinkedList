/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <cstdlib>   // for srand and rand
#include <ctime>     // for time
#include "DoubleLinkedList.h"


using namespace std;

bool LinkedList::Empty() {
    bool k = false;
    if (first == NULL) { //loop checks if array has a first value
        k = true;
    }

    return k;
}

void LinkedList::Previous() {

    cout << "enter word to see prev. of" << endl;
    string x;
    cin>>x;

    node * travel;
    travel = first;
    while (travel->data != x) {
        travel = travel->next;
    }

    cout << "the prev. = " << travel->prev->data << endl;
}

void LinkedList::InsertAtEnd(ElementType x) {

    node *newNode = new node; //makes new node
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    node *travel; //node to traverse list
    travel = first;

    if (Empty() == true) {
        first = newNode;
        N++;
    } else {
        while (travel->next != NULL) { //loop to have node find last position
            travel = travel->next;
        }
        travel->next = newNode;
        newNode->prev = travel;
        N++;
    }
}

void LinkedList::Delete(ElementType x) {
    node*tempA = first;
    node*tempB = first;

    while (tempB != NULL) {
        if (tempB->data == x) {
            if (tempA == tempB) { //if deleting first node
                tempB->prev = NULL;
                first = tempB->next;
                delete tempB;
                tempA = first;
                tempB = first;

            } else { //if deleting non first node, A is behind B
                tempA->next = tempB->next;
                if(tempB->next!=NULL){
                    tempB->next->prev = tempA;
                }
               
                delete tempB;
                tempB = tempA->next;
            }
            N--;
        } else if (tempA == tempB) { //if don't find delete value first node exclusive
            tempB = tempB->next;
        } else { //if don't find delete value move on
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }
}

void LinkedList::Display() {
    node*traverse;
    traverse = first;

    cout << endl;
    if (Empty() == true) {
        cout << "the list is empty " << endl;

    } else {
        cout << "the list contains: " << endl;
        cout << endl;
        while (traverse != NULL) {
            cout << traverse->data << endl;
            traverse = traverse->next;
        }
        cout << endl;
    }
}

void LinkedList::Sort() {
    string g;
    node*ptrA;
    node*ptrB;
    ptrA = first;
    ptrB = first->next;

    for (int i = 0; i < N + 1; i++) { //loop to go through array one by one
        ptrA = first;
        ptrB = first->next;
        while (ptrB != NULL) { // loops the if statement until value is not bigger than next one
            if (ptrA->data.length() > ptrB->data.length()) {
                g = ptrB->data; // switches tested value with one to the right
                ptrB->data = ptrA->data; //
                ptrA->data = g; //
            }
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }

    }


}

double LinkedList::Average() {
    double num = 0; //add lengths of all values and divides by number of values
    node*travel;
    travel = first;
    while (travel != NULL) { //as long as travel is not null add length of all values then go to next node
        num += travel->data.length();
        travel = travel->next;
    }


    num = num / N; //divide by total number of nodes
    cout << endl;
    return num;
}

double LinkedList::Median() {
    Sort();
    double num = 0, i = 0;
    node*travel;
    travel = first;
    if (N % 2 == 1) { //if odd number of strings return length of middle value
        while (i < N / 2) {
            travel = travel->next;
            i++;
        }
        num += travel->data.length();
    } else { // if even add lengths of two middle values then divide by 2
        while (i < N / 2 - 1) {
            travel = travel->next;
            i++;
        }
        num += travel->data.length();
        travel = travel->next;
        num += travel->data.length();
        num = num / 2;


    }

    cout << endl;
    return num;
}

void LinkedList::Shuffle() {
    int i = 0, checker = N;
    int r = rand() % N;
    node*tempA = first;
    string array[N];
    string array2[N];

    while (tempA != NULL) {
        array[i] = tempA->data;
        tempA = tempA->next;
        i++;
    }
    i = 0; //travel through 2nd array
    bool end = false; //when to stop looping

    while (end == false) {
        if (array[r] != "") {
            array2[i] = array[r];
            array[r] = "";
            i++;
            checker--;
        }
        if (checker == 0) {
            end = true;
        }
        r = rand() % N;
    }
    tempA = first;
    i = 0;
    while (tempA != NULL) {
        tempA->data = array2[i];
        tempA = tempA->next;
        i++;
    }


    Display();

}

LinkedList::LinkedList() {
    N = 0;
    first = NULL;
}
