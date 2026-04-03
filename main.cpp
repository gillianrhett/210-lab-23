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
    bool again;

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
        if (choice == 1) {
        // add a goat
            // random inputs
            add_goat(myTrip, "testn", 1, "testc");
        }
        if (choice == 2) {
        // delete a goat

        }
        if (choice == 3) {
        // list goats
            display_trip(myTrip);
        }
        if (choice == 4) {
        // quit
            cout << "Goodbye." << endl;
        }
    }
    return 0;
}

int select_goat(list<Goat> trip) {

}

void delete_goat(list<Goat> &trip) {

}

void add_goat(list<Goat> &trip, string name, int age, string color ) {
    // creates a new goat and adds it to the list
    Goat g(name, age, color);
    trip.push_back(g);
}

void display_trip(list<Goat> trip) { 
    int count = 0;
    for(Goat g : trip){
        count++;
        cout << "[" << count << "] " << g.get_name() << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
}

int main_menu() {
    // displays the menu and then obtains, validates, and returns the user's choice
    int choice = 0;
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