/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "List_Array.h"

using namespace std;





bool List:: Empty(){
    bool k = false;
    if (listArray[0] == ""){ //loop checks if array has a first value
        k = true;
    }

   return k;
}

void List::InsertAtEnd(ElementType x) {

    for (int i = 0; i < MAX; i++) {
        if (listArray[i] == "") {
            listArray[i] = x;
            N++;
            break;
        }


    }

}

void List::Delete(ElementType x) {
    int counter = 0,i=0;

    for (int i = 0; i <N ; ++i) {      //loop to count number of values that equal x
        if (listArray[i] == x) {
            counter++;
        }
    }
int NHolder=N-counter;                //holds the number of values that dont equal x

    for (int m = 0; m < N; ++m) {           //loop to test all values
        if(listArray[m] == x){            //if value equals  x replace it with next value
            for (int j = m; j < N; ++j) {     //loop replaces all values with one to next
                listArray[j] = listArray[j+1];
            }
        }
    }
             //does twice incase same values are side by side


    for (int m = 0; m < N; ++m) {           //loop to test all values
        if(listArray[m] == x){            //if value equals  x replace it with next value
            for (int j = m; j < N; ++j) {     //loop replaces all values with one to next
                listArray[j] = listArray[j+1];
            }
        }
    }
    N=NHolder;                            //resets N to NHolder

}

void List::Display() {
    cout << endl;
    if (Empty() == true) {
        cout << "the list is empty " << endl;

    } else {
        cout<<"the list contains: "<<endl;
    for (int i = 0; i < N; i++) {
        cout << listArray[i] << endl;        //prints out values of ListArray

    }
    cout << endl;
}
}

void List::Sort() {
    int num = 0;
    for (int i = 0; i < N; i++) {    //loop to go through array one by one
        while (num < N) {            // loops the if statement until value is not bigger than next one
            if (listArray[num].length() > listArray[i].length()) {
                string g = listArray[i];                 // switches tested value with one to the right
                listArray[i] = listArray[num];           //
                listArray[num] = g;                      //
            }
            num++;
        }
        num = 0;
    }


}

double List::Average() {
    double num = 0;                   //add lengths of all values and divides by number of values
    for (int i = 0; i < N; i++) {
        num += listArray[i].length();

    }
    num = num / N;
    return num;
}

double List::Median() {
    double num = 0;
    if (N % 2 == 1) {      //if odd number of strings return length of middle value
        num += listArray[N / 2].length();
    } else {              // if even add lengths of two middle values then divide by 2
        num += listArray[N / 2-1].length();
        num += listArray[N / 2].length();
        num=num/2;


    }


    return num;
}

void List::Shuffle() {
    int second[N];   // array to hold random integers

    int place = 0;
    for (int k = N; k > 0; k--) {   //loop to place random integers
        second[place] = k;
        place++;
    }

    string third[N];      //array to hold string values in coorespondence to numbers in second array
    for (int i = 0; i < N; i++) {
        third[i] = listArray[second[i]-1];

    }
    for (int j = 0; j < N; j++) {   //fills listArray values from third array
        listArray[j] = third[j];
    }
Display();

}

List::List() {
    N = 0;
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
            InsertAtEnd(k);

        } else if (t == "2") {
            cout << "Enter a String to delete" << endl;
            string k;
            cin >> k;
            cout<<"all "<<k<<"'s have been deleted"<<endl;
            Delete(k);
            Display();

        } else if (t == "3") {

            Display();
        } else if (t == "4") {
            Sort();
            cout<<"the list has been sorted least to greatest "<<endl;
            Display();
        } else if (t == "5") {
            double f =  Average();
            cout<<"the average is "<<f<<endl;
        } else if (t == "6") {
            double p =  Median();
            cout<<"the median is "<<p<<endl;
        } else if (t == "7") {
            cout<<"the list has been shuffled"<<endl;
            Shuffle();
        } else if (t == "8") {
            t == "8";
        } else {
            cout << "Thats not a valid command, Try again" << endl;
        }
    }

}




