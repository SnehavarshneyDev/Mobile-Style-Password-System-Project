#include <iostream>
#include <string>
using namespace std;

string savedPassword = "";
string passType = "";
string secret = "code123";

void createPassword() {
    int choice;
    cout << "\nSelect password type:\n";
    cout << "1. PIN\n";
    cout << "2. Pattern\n";
    cout << "3. Alphanumeric\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter your password: ";
    getline(cin, savedPassword);

    if (choice == 1) passType = "PIN";
    else if (choice == 2) passType = "Pattern";
    else if (choice == 3) passType = "Alphanumeric";
    else passType = "Unknown";

    cout << "Password saved as [" << passType << "]\n";
}

bool checkPassword() {
    string input;
    cout << "Enter your " << passType << ": ";
    getline(cin, input);
    return input == savedPassword;
}

void resetPassword() {
    string key;
    cout << "Enter secret code to reset password: ";
    getline(cin, key);

    if (key == secret) {
        cout << "Verified. Set new password.\n";
        createPassword();
    } else {
        cout << "Wrong code. Cannot reset.\n";
    }
}

int main() {
    int option;
    bool running = true;

    cout << "Welcome to Simple Password System\n";
    createPassword();

    while (running) {
        cout << "\n1. Unlock\n2. Forgot Password\n3. Exit\nChoose option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            if (checkPassword())
                cout << "Access granted!\n";
            else
                cout << "Wrong password.\n";
        } else if (option == 2) {
            resetPassword();
        } else if (option == 3) {
            running = false;
            cout << "Thank you for using the system. See you again!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
