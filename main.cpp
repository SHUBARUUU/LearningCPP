#include<iostream>

/*
    #include <iostream> = gives you the tools - like importing in java
    using namespace std; = shortcut so you don’t have to type the toolbox path every time (std::cout) - like instantiating a scanner object

    std stands for standard — it’s the standard C++ library namespace. Everything is in standard library.
    :: is called the scope resolution operator - it tells the program to look in a specific path std::cout, means "hey look on std for a cout"

*/
using namespace std;

int main() {
//  Makes an array of names.
    string names[8];
//  In c++, no length method instead uses this sizeof method returns byte of data types. Ex. int = 4 byte
//  Sample code is, length = 4 x 8 bytes / 4 bytes
//  4 = one int X 8 = quantity of int's in array / 4 bytes = pick any int in array.
//  Final value = the length of an array.
    int length = sizeof(names) / sizeof(names[0]);
    int var;


    while (true) {
        // using cin reads the space, tab newline, BUT will leave \n in the input buffer
        // using cin, automatically reads the left over \n
        // becomes a problem after we use getline
        cin >> var;
        // using ignore method for cin, discard leftover newline before proceeding
        cin.ignore();

        // every stream (like cin) has a set of internal flags that describe its current state.
        // putting different data types than the one declared will make fail state
        if (cin.fail()) {
            cout << "Invalid input!" << endl;
            cin.clear(); // clear the error state
            cin.ignore(1000, '\n'); // discard the bad input
        }else{
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        cout << "Enter a name: " << endl;
        // reads everything up to the next \n
        // if there's a left over \n in the input buffer it'll read that and skip
        getline(cin, names[i]);
    }

    int counter = 0;
    while (counter < length) {
        cout << names[counter];
        counter++;
    }

    return 0;
}
