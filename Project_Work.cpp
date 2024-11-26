// Ayden Bishop, Zach Tarske, and Joshua Bockerstette

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void userSignIn();
void userSignUp();
void Room_Type();
void Receipt(int, int, int, int);
bool getOccupied();
void pickRoom(int);

const int MAX_ROOMS = 10;
const int ROOM_TYPES = 3;
int floor1[MAX_ROOMS][ROOM_TYPES];
int floor2[MAX_ROOMS][ROOM_TYPES];
int floor3[MAX_ROOMS][ROOM_TYPES];

bool occupied[MAX_ROOMS];

const int A_PRICE = 80;
const int B_PRICE = 150;
const int C_PRICE = 175;

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

int signUp(const string &filename) {
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


int signIn(const string &filename) {
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

int main()
{
    int price,checkin_Date,checkout_Date;
    float total;


    char choice;
    char again;

    do
    {
        cout << "*****************************************" << endl;
        cout << setw(16) << "Menu:" << endl << endl;
        cout << "a) User Sign In" << endl;
        cout << "b) User Sign Up" << endl;
        cout << "*****************************************" << endl;
        cin >> choice;

        while(choice != 'a' || choice != 'b')
        {
            cout << "Error: Please choose either 'a' or 'b'" << endl;
            cin >> choice;
        }

        switch (tolower(choice)) {
            case 'a':
                userSignIn();
                break;
            case 'b':
                userSignUp();
                break;
                                 }

    Receipt(price,total,checkin_Date,checkout_Date)

    cout << "(y/n)" << endl;
    cin >> again;
    } while(tolower(again) == 'y');

    return 0;
}


void signup()
{
    string username;
    string password;

    cout << "Welcome to sign up for Hotel Overlook" << endl << endl;
	cout << "*****************************************" << endl;
	cout << "Please enter your username" << endl;
	cin >> username;
	cout << "Please enter your password" << endl;
	cin >> password;

	Pick_Dates();
}


int Pick_Dates()
{
    int Checkin_Date;
    int Checkout_Date;

	cout << "Input check in date" << endl;
	cin >> Checkin_Date;

	while(Checkin_Date < 1 && Checkin_Date > 30)
    {
        cout << "Error: The date has to be in the range of 1-30" << endl;
        cin >> Checkin_Date;
    }

    cout << "Input check out date" << endl;
    cin >> Checkout_Date;

    while(Checkout_Date <= Checkin_Date && Checkout_Date > 30)
    {
        cout << "Error: The date has to be in the range of " << (Checkin_Date + 1) << "-30" << endl;
        cin >> Checkout_Date;
    }

    Room_Type();
    return  Checkin_Date, Checkout_Date;
}


int Room_Type()
{
    int price;
    bool occupied;
    int room_type;

    cout << "Choose room type:" << endl;
    cout << "1) Single (1 Bed 1 Bath)" << endl << "2) Double (2 Beds 1 Bath)" << endl << "3) Suite (3 Beds 2 Baths)" << endl;
    cin >> room_type;

    while(room_type != 1 || room_type != 2 || room_type != 3)
    {
        cout << "Error: Choose between the numbers 1, 2, or 3" << endl;
        cin >> room_type;
    }

    switch(room_type)
    {
        case 1:
        cout << "You picked the room type: Single (1 Bed 1 Bath)" << endl;
        price = A_PRICE;     // Price, Random picked location based on type
        occupied = getOccupied();
        break;

        case 2:
        cout << "You picked the room type: Double (2 Beds 1 Bath)" << endl;
        price = B_PRICE;     // Price, Random picked location based on type
        occupied = getOccupied();
        break;

        case 3:
        cout << "You picked the room type: Suite (3 Beds 2 Baths)" << endl;
        price = C_PRICE;     // Price, Random picked location based on type
        occupied = getOccupied();
        break;
    }
	cout << "There are " << occupied << " rooms available for your dates" << endl;

	pickRoom(occupied);
}


bool getOccupied()
{
    srand(time(0));
    bool occupied;

    for (int )
    {
        occupied = rand() % 2;

        floor1[][]
        floor2[][]
        floor3[][]
    }
    return occupied;
}


int pickRoom(occupied)
{
    int choice;
    for (int row = 0; row <= MAX_ROOMS; row++)
    {
        cout << "Rooms: " << hotel[][] << " ";
        for (int column = 0; column <= MAX_ROOMS; column++)
        {

        }
    }
}


float Receipt(price,total,checkin_Date,checkout_Date)
{
    cout << "--- Receipt ---" << endl;
    cout << "Room type price: $" << price << endl;
    cout << "Total nights: " << (checkout_Date - checkin_Date) << endl;
    cout << "Total amount due: $" << total << endl;
}