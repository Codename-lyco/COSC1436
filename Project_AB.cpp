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
int Receipt(int, int, int, int);
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
        cout << "------------------------------" << endl;
        cout << setw(16) << "Menu:" << endl << endl;
        cout << "a) User Sign In" << endl;
        cout << "b) User Sign Up" << endl;
        cout << "c) Guest Access" << endl;
        cout << "------------------------------" << endl;
        cin >> choice;

        switch (tolower(choice)) {
            case 'a':
                userSignIn();
                break;
            case 'b':
                userSignUp();
                break;
            case 'c':
                guestAccess();
                break;
    }

    cout << "(y/n)" << endl;
    cin >> again;
    } while(tolower(again) == 'y');

    return 0;
}


void signin()
{

	display "Please enter your username"
	input username
	display "Please enter your password"
	input password

	do
    {
	Display "Input checkin date"
	input Checkin_Date
    } while(checkin_Date > 1 AND checkin_Date < 31);

    do
    {
        Display "Input Checkout date"
        input Checkout_Date
    } while(checkout_Date > 2 AND checkout_Date < 31);
}


void signup()
{

	display "Welcome to Signup for Hotel Overlook"
	display "                                                                      "
	display "                                                                      "
	display "**********************************************************************"
	display "Please enter your username"
	input username
	display "Please enter your password"
	input password
}


void Room_Type()
{
    int price;
    bool occupied;
    string room_type;

    cout << "Choose room type:" << endl;
    cout << "1) Single" << endl "2) Double" << endl << "3) Suite" << endl;
    cin >> room_type;

    switch(room_type)
        case 1: Single...
        price = A_PRICE;     // Price, Random picked location based on type
        randomNumber();
        break;

        case 2: Double...
        price = B_PRICE;     // Price, Random picked location based on type
        occupied = randomNumber();
        break;

        case 3: Suite...
        price = C_PRICE;     // Price, Random picked location based on type
        occupied = randomNumber();
        break;
	cout << "There are " << occupied << " rooms available for your dates" << endl;

	pickRoom(occupied);
}


int Receipt(price,total,checkin_Date,checkout_Date)
{
    Display "--- Receipt ---"
    Display "Room type price: $" + price
    Display "Total nights: " + (checkout_Date - checkin_Date)
    Display "Total amount due: $" + total
}


bool getOccupied()
{
    srand(time(0));
    bool occupied;

    for (int )
    {
        occupied = rand() % 2;

    }
}


void pickRoom(occupied)
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
