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

const int MAX_ROOMS = 10;
const int ROOM_TYPES = 3;
int floor1[MAX_ROOMS][ROOM_TYPES];
int floor2[MAX_ROOMS][ROOM_TYPES];
int floor3[MAX_ROOMS][ROOM_TYPES];

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
        cout << "------------------------------" << endl;
        cin >> choice;

        while(choice != 'a' || choice != 'b')
        {
            "Error: Please choose either 'a' or 'b'" << endl;
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

    cout << "(y/n)" << endl;
    cin >> again;
    } while(tolower(again) == 'y');

    return 0;
}


void Pick_Dates()
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
    {
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
    }
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
