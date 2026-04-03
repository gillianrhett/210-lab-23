#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <limits> // for try-catch
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string, int, string);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    //bool again; // I didn't use this, I just compare the input to 4

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // create a list for goats
    list <Goat> myTrip;

    int choice = 0;
    while (choice != 4) {
    // keep showing the menu after doing the action until user chooses 4 to quit
        choice = main_menu();
        if (choice == 1) { // add a goat
            // random inputs
            string rnd_name = names[rand() % (SZ_NAMES)];
            int rnd_age = rand() % (MAX_AGE + 1);
            string rnd_color = colors[rand() % (SZ_COLORS)];
<<<<<<< HEAD
            
            add_goat(myTrip, rnd_name, rnd_age, rnd_color);
        }
        if (choice == 2) { // delete a goat
=======
            add_goat(myTrip, rnd_name, rnd_age, rnd_color);
        }
        if (choice == 2) {
        // delete a goat
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
            delete_goat(myTrip);
        }
        if (choice == 3) { // list goats
            display_trip(myTrip);
        }
<<<<<<< HEAD
        if (choice == 4) { // quit
=======
        if (choice == 4) {
        // quit
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
            cout << "\tGoodbye." << endl;
        }
    }
    return 0;
}

int select_goat(list<Goat> trip) {
<<<<<<< HEAD
// return the index of a goat given the name input by user
=======
    // returns the index of a goat given the name input by user
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
    string nameIn; // user enters name of goat to delete
    cout << "Enter name of goat to delete: ";
    cin >> nameIn;
    int count = 0; // for checking whether we've reached the end of the list
    // search for a goat with this name
    for(const Goat g : trip){
        if (g.get_name() == nameIn) 
            break;
        count++;
    }
    if (count == trip.size()) {
        cout << "\tName not found." << endl;
        count = -1;
    }
    return count;
}

void delete_goat(list<Goat> &trip) {
<<<<<<< HEAD
// prompt the user for a name and delete the first instance of the goat with that name
    if(trip.size() == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    int i = select_goat(trip); // i = index of the goat to delete
    int cur = 0; // current index in the for loop
    if (i != -1) { // if the goat was found
        for (Goat g : trip) {
            if (i == cur)
                trip.remove(g);
                break;
=======
    // prompts the user for a name and deletes the first instance of the goat with that name
    int i = select_goat(trip); // i = index of the goat to delete
    int cur = 0; // current index in the for loop
    if (i != -1) { // the function returns -1 if the goat is not found
        // delete the goat at index i
        for(Goat g : trip) {
            if (i == cur) {
                trip.remove(g);
                break;
            }
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
            cur++;
        }
    }
}

void add_goat(list<Goat> &trip, string name, int age, string color ) {
<<<<<<< HEAD
// create a new goat and add it to the list
=======
    // create a new goat and add it to the list
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
    Goat g(name, age, color);
    trip.push_back(g);
}

<<<<<<< HEAD
void display_trip(list<Goat> trip) {
// display a list of all the goats and their info
    if(trip.size() == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    int count = 0; // for numbering the list of goats displayed
=======
void display_trip(list<Goat> trip) { 
    int count = 0;
>>>>>>> 88d7627f803d63fabe609fc7c31a06723f95cc1e
    for(const Goat g : trip){
        count++;
        cout << "\t[" << count << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
}

int main_menu() {
// display the menu and then obtain, validate, and return the user's choice
    int choice = 0; // will store user input
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    while (!(choice >= 1 && choice <=4)) {
        cout << "Choice --> ";
        try {
            cin >> choice;
            if (cin.fail() || !(choice >= 1 && choice <=4))
                throw invalid_argument("Invalid input. Enter a number 1, 2, 3, or 4.");
        }
        catch(invalid_argument& e)
        {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}