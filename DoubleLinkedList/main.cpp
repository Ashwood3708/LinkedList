/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Abdul Ashwood
 *
 * Created on August 30, 2017, 6:03 PM
 */

#include <iostream>
#include "DoubleLinkedList.h"
#include <cstdlib>   // for srand and rand
#include <ctime>     // for time



using namespace std;


int main() {
    srand(time(NULL));

   LinkedList  r;
string t = "0";
    while (t != "8") {
        cout << "1. Insert" << "\n" << "2. Delete" << "\n" << "3. Display" << "\n" << "4. Sort" << "\n" <<
                "5. Average" << "\n" << "6. Median" << "\n" << "7. Shuffle" << "\n" << "8. Exit" << "\n" <<
                "Enter Command " << endl;

        cin >> t;
        if (t == "1") {
            cout << "Enter a String" << endl;
            string k;
            cin >> k;
            r.InsertAtEnd(k);

        } else if (t == "2") {
            cout << "Enter a String to delete" << endl;
            string k;
            cin >> k;
            cout << "all " << k << "'s have been deleted" << endl;
            r.Delete(k);
            r.Display();

        } else if (t == "3") {

            r.Display();
        } else if (t == "4") {
            r.Sort();
            cout << "the list has been sorted least to greatest " << endl;
            r.Display();
        } else if (t == "5") {
            double f = r.Average();
            cout << "the average is " << f << endl;
            cout<<endl;
        } else if (t == "6") {
            double p = r.Median();
            cout<<"The list has been auto sorted"<<endl;
            cout << "the median is: " << p << endl;
            cout<<endl;
        } else if (t == "7") {
            cout << "the list has been shuffled" << endl;
            r.Shuffle();
            cout<<endl;
        } else if (t == "8") {
            t == "8";
        } else {
            cout << "Thats not a valid command, Try again" << endl;
        }
    }


}


