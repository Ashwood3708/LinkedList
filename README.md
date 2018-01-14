# Assignment #2: List - Array Implementation

*Review pages 6-7 in "From Java to C++" notes.* 

*Due **Friday, September 8th, 2017 @ 11:59PM EST***

## Directions
Create a `List` object. Using the following definition (`List.h` file) for a list, implement the member functions (methods) for the List class and store the implementation in file `List.cpp`.  Use an array to implement the list. Write the client code (the main method and other non-class methods) and put those methods in file `main.cpp`. 

```
// file: List.h 
#include<string>
using namespace std;
typedef string ElementType;
const int MAX = 100;
class List
{
 public: 
   List(); // Create an empty list
   bool Empty(); // Return true if the list is empty, otherwise return false
   void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
   void Delete(ElementType x); // If value x is in the list, remove x (all instances)
   void Display(); // Display the data values in the list
   void Sort(); // Sort the list of strings based on length (shortest to longest)
   double Average(); // Compute amd return the average string length for the strings in the list
   double Median(); // Compute and return the median string length for the strings in the list
   void Shuffle(); // Shuffle the strings in the list around

 private:
	int N; // Number of values in list
ElementType listArray[MAX]; // The array to hold the list values
};
```

Write a program to create a single list. Your client code should be menu driven using the following menu options:

```
  1. Insert
  2. Delete
  3. Display
  4. Sort
  5. Average 
  6. Median
  7. Shuffle
  8. Exit
```
**Option 1:** Prompt the user for a non-empty string to insert at the end of the list.

**Option 2:** Prompt the user for which string to remove from list. Remove every instance of the value specified.

**Option 3:** Display all of the values in the list.

**Option 4:** Sort the values in the list based on string length from shortest to longest.

**Option 5:** Find the average length of the strings in the list and display it.

**Option 6:** Find the medium length of the strings in the list and display it.

**Option 7:** Shuffle the strings in the list around.

**Option 8:** Exit the program.

