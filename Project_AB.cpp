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

const int MAX_FLOORS = 3;
const int MAX_ROOMS = 10;
int hotel[MAX_FLOORS][MAX_ROOMS];

bool occupied[MAX_ROOMS];

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

    Receipt(price,total,checkin_Date,checkout_Date)

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
        occupied = getOccupied();
        break;

        case 2:
        cout << "You picked the room type: Double (2 Beds 1 Bath)" << endl;
        occupied = getOccupied();
        break;

        case 3:
        cout << "You picked the room type: Suite (3 Beds 2 Baths)" << endl;
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



    for(int row; row <= 3; row++)
    {
        occupied = rand() % 2;

        for(int col; col <= MAX_ROOMS; col++)
        {
            if()
                floor1[row][col];
            else if()
                floor2[row][col];
            else
                floor3[row][col];
        }
    }
    return occupied;
}


void pickRoom(occupied)
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


void Receipt(price,total,checkin_Date,checkout_Date)
{
    cout << "--- Receipt ---" << endl;
    cout << "Room type price: $" << price << endl;
    cout << "Total nights: " << (checkout_Date - checkin_Date) << endl;
    cout << "Total amount due: $" << total << endl;
}

