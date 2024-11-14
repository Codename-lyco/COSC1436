// Ayden Bishop, Zach Tarske, and Joshua Bockerstette

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void userSignIn();
void userSignUp();
void guestAccess();

int main()
{
    const int MAX_FLOORS = 20;
    int floor1[MAX_FLOORS];
    int floor2[MAX_FLOORS];
    int floor3[MAX_FLOORS];

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

void userSignIn()
{

}

void userSignUp()
{

}

void guestAccess()
{

}
