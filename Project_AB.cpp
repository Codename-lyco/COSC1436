// Ayden Bishop, Zach Tarske, and Joshua Bockerstette

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int userSignIn();
int userSignUp();
int Room_Type();
void Receipt(int, float, int, int);
bool getOccupied();
void pickRoom(int, int);

const int MAX_FLOORS = 3;
const int MAX_ROOMS = 10;
int hotel[MAX_FLOORS][MAX_ROOMS];

int occupied[MAX_ROOMS];

const int A_PRICE = 80;
const int B_PRICE = 150;
const int C_PRICE = 175;



int main()
{
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

    Receipt(price,total,Checkin_Date,Checkout_Date)

    cout << "(y/n)" << endl;
    cin >> again;
    } while(tolower(again) == 'y');

    return 0;
}

int userSignIn()
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

int userSignUp()
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

    return;
}


int Room_Type()
{
    int price;
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
        occupied[MAX_ROOMS] = getOccupied();
        break;

        case 2:
        cout << "You picked the room type: Double (2 Beds 1 Bath)" << endl;
        occupied[MAX_ROOMS] = getOccupied();
        break;

        case 3:
        cout << "You picked the room type: Suite (3 Beds 2 Baths)" << endl;
        occupied[MAX_ROOMS] = getOccupied();
        break;
    }
	cout << "There are " << occupied << " rooms available for your dates" << endl;

	pickRoom(occupied, MAX_ROOMS);
}


bool getOccupied()
{
    srand(time(0));

    bool occupied[MAX_ROOMS];

    for(int index; index <= MAX_ROOMS; index++)
        occupied[MAX_ROOMS] = rand() % 2;

    return occupied[MAX_ROOMS];
}


void pickRoom(occupied, MAX_ROOMS)
{
    int choice;
    for (int row = 0; row <= MAX_FLOORS; row++)
    {
        for (int col = 0; col <= MAX_ROOMS; col++)
        {
            cout << "Rooms: " << hotel[row][col] << " " << endl;
            cout << "Status: " << occupied[col] << " " << endl << endl;
        }
    }
}


void Receipt(price,total,Checkin_Date,Checkout_Date)
{
    cout << "--- Receipt ---" << endl;
    cout << "Room type price: $" << price << endl;
    cout << "Total nights: " << (Checkout_Date - Checkin_Date) << endl;
    cout << "Total amount due: $" << (total * (Checkout_Date - Checkin_Date) * 0.08) << endl;
}

