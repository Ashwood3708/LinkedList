/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List_Array.h
 * Author: Abdul
 *
 * Created on September 1, 2017, 5:34 PM
 */

#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

//file: LinkedList.h
#include <iostream>

using namespace std;

typedef string ElementType;

struct node{
     ElementType data;
    node * next;
    node * prev;
};

class LinkedList {
public:
    LinkedList(); // Create an empty list
    bool Empty(); // Return true if the list is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
    void Delete(ElementType x); // If value x is in the list, remove x (all instances)
    void Display(); // Display the data values in the list
    void Sort(); // Sort the list of strings based on length (shortest to longest)
    double Average(); // Compute and return the average string length for the strings in the list
    double Median(); // Compute and return the median string length for the strings in the list
    void Shuffle(); // Shuffle the strings in the list around
    void Previous();  // find previous node

private:
    node * first; // Pointer
    int N;
};

#endif /* LIST_ARRAY_H */

