#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int A_PRICE = 80;
const int B_PRICE = 150;
const int C_PRICE = 175;
const int MAX_ROOMS = 10;

int hotel[3][MAX_ROOMS]; // 3 types of rooms, 10 rooms each
int occupied[MAX_ROOMS];  // Track the status of each room (0 = Available, 1 = Taken)

// Function declarations for the sign-up and sign-in features
bool validateUser(const string &filename, const string &username, const string &password);
bool isUsernameTaken(const string &filename, const string &username);
void signUp(const string &filename);
void signIn(const string &filename);

// Function for receipt
void Receipt(int price, int Checkin_Date, int Checkout_Date);

// Function for picking room number
void pickRoom(int occupied[], int MAX_ROOMS);

// Function to initialize rooms randomly (Available/Taken)
void getOccupied();

int main() {
    const string filename = "Userinfo.txt";  // For sign-in/sign-up functionality

    char choice;
    char again;
    double total = 0;
    double price = 0;
    int Checkin_Date;
    int Checkout_Date;

    do {
        // Menu for sign in and sign up
        cout << "*****************************************" << endl;
        cout << setw(16) << "Menu:" << endl << endl;
        cout << "a) User Sign In" << endl;
        cout << "b) User Sign Up" << endl;
        cout << "*****************************************" << endl;
        cin >> choice;

        while(choice != 'a' && choice != 'b') {
            cout << "Error: Please choose either 'a' or 'b'" << endl;
            cin >> choice;
        }

        switch (tolower(choice)) {
            case 'a':
                signIn(filename);  // Handle sign-in
                break;
            case 'b':
                signUp(filename);  // Handle sign-up
                break;
        }

        // Getting check-in and check-out dates
        cout << "Input check-in date (1-30): ";
        cin >> Checkin_Date;

        while (Checkin_Date < 1 || Checkin_Date > 30) {
            cout << "Error: The date has to be in the range of 1-30" << endl;
            cin >> Checkin_Date;
        }

        cout << "Input check-out date (greater than check-in date, 1-30): ";
        cin >> Checkout_Date;

        while (Checkout_Date <= Checkin_Date || Checkout_Date > 30) {
            cout << "Error: The date has to be in the range of " << (Checkin_Date + 1) << "-30" << endl;
            cin >> Checkout_Date;
        }

        // Call Room Type and pick Room
        int room_type;
        cout << "Choose room type:" << endl;
        cout << "1) Single (1 Bed 1 Bath)" << endl;
        cout << "2) Double (2 Beds 1 Bath)" << endl;
        cout << "3) Suite (3 Beds 2 Baths)" << endl;
        cin >> room_type;

        while (room_type != 1 && room_type != 2 && room_type != 3) {
            cout << "Error: Choose between the numbers 1, 2, or 3" << endl;
            cin >> room_type;
        }

        switch(room_type) {
            case 1:
                cout << "You picked the room type: Single (1 Bed 1 Bath)" << endl;
                price = A_PRICE;
                break;
            case 2:
                cout << "You picked the room type: Double (2 Beds 1 Bath)" << endl;
                price = B_PRICE;
                break;
            case 3:
                cout << "You picked the room type: Suite (3 Beds 2 Baths)" << endl;
                price = C_PRICE;
                break;
        }

        // Randomly set room availability
        getOccupied();

        // Show room availability for the selected room type
        cout << "\nRoom Availability: " << endl;
        cout << "-----------------------------------" << endl;

        // Displaying room numbers with fixed width for alignment
        for (int i = 0; i < MAX_ROOMS; i++) {
            cout << setw(7) << (i + 101);  // Set width to 7 for room numbers
        }
        cout << endl;

        // Displaying room availability status (Taken/Available) with fixed width for alignment
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (occupied[i] == 1)
                cout << setw(10) << "Taken";  // Set width to 10 for "Taken"
            else
                cout << setw(10) << "Available";  // Set width to 10 for "Available"
        }
        cout << endl << endl;

        // Allow the user to pick an available room
        int room_number;
        cout << "Choose a room number from the available ones: ";
        cin >> room_number;

        while (room_number < 101 || room_number > 110 || occupied[room_number - 101] == 1) {
            cout << "Error: Please choose an available room number between 101 and 110." << endl;
            cin >> room_number;
        }

        // Calculate subtotal
        double subtotal = price * (Checkout_Date - Checkin_Date);

        // Calculate total with tax (8.25%)
        double total = subtotal * 1.0825;

        // Call Receipt function to display details
        Receipt(price, Checkin_Date, Checkout_Date);

        cout << "(y/n) Do you want to continue? ";
        cin >> again;
    } while(tolower(again) == 'y');

    return 0;
}

// Function to print the receipt
void Receipt(int price, int Checkin_Date, int Checkout_Date) {
    double subtotal = price * (Checkout_Date - Checkin_Date);
    double total = subtotal * 1.0825;

    cout << "\n--- Receipt ---" << endl;
    cout << "Room type price: $" << price << endl;
    cout << "Total nights: " << (Checkout_Date - Checkin_Date) << endl;
    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "Tax (8.25%): $" << fixed << setprecision(2) << subtotal * 0.0825 << endl;
    cout << "Total amount due: $" << fixed << setprecision(2) << total << endl;
}

// Function to initialize room status randomly (Available/Taken)
void getOccupied() {
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < MAX_ROOMS; i++) {
        occupied[i] = rand() % 2;  // Randomly assign each room as either Taken (1) or Available (0)
    }
}

// Function to validate user during sign-in
bool validateUser(const string &filename, const string &username, const string &password) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }

    string fileUsername, filePassword;
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            return true;
        }
    }

    return false;
}

// Function to check if username is already taken during sign-up
bool isUsernameTaken(const string &filename, const string &username) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return false;
    }

    string fileUsername, filePassword;
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username) {
            return true;
        }
    }

    return false;
}

// Function to sign up a new user
void signUp(const string &filename) {
    string username, password;

    cout << "Enter a new username: ";
    cin >> username;

    if (isUsernameTaken(filename, username)) {
        cout << "Username already exists. Please try again." << endl;
        return;
    }

    cout << "Enter a new password: ";
    cin >> password;

    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "Sign up successful!" << endl;
}

// Function to sign in an existing user
void signIn(const string &filename) {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (validateUser(filename, username, password)) {
        cout << "Sign in successful!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}
