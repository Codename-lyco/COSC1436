#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

int main() {
    const string filename = "Userinfo.txt";

    int choice;
    do {
        cout << "1. Sign In\n2. Sign Up\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signIn(filename);
                break;
            case 2:
                signUp(filename);
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
