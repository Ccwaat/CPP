
#include <iostream>

//FunctionDecloration
void UserSignUp();
void Start();
void UserBankUI();
void PasswordCheck();

//variables
int password;
char input;
int inputInt;
float inputFloat;
float balance = 0;

void UserSignUp() {
    std::string username;

    std::cout << "pw create(y), pw change(n):";
    std::cin >> input;

    if (input == 'n') {
        PasswordCheck();
    }

    std::cout << "Account Password: ";
    std::cin >> password;

    std::cout << "Your account has been successfuly created\n" << "press y to go back: ";
    std::cin >> input;
    if (input == 'y') {
        std::system("cls");
        Start();
    }
}
void Start() {
    std::cout << "------Bank------\n";
    std::cout << " 1.Login\n";
    std::cout << " 2.Password create/change\n";
    std::cout << " Input: "; std::cin >> inputInt;

    std::system("cls");
    switch (inputInt) {
    case 1:
        PasswordCheck();
        UserBankUI();
        break;
    case 2: UserSignUp();
        break;
    default: Start();
    }

}
void UserBankUI() {
    std::cout << "------UserBank------\n";
    std::cout << " 1.Balance\n";
    std::cout << " 2.Deposit\n";
    std::cout << " 3.Withdraw\n";
    std::cout << "Input: ";
    std::cin >> inputInt;
    switch (inputInt) {
    case 1:
        std::system("cls");
        std::cout << balance << std::endl;
        UserBankUI();
        break;
    case 2:
        std::cout << "Deposit amount: ";
        std::cin >> inputFloat;
        balance += inputFloat;
        UserBankUI();
        break;
    case 3:
        std::cout << "Withdraw amount: ";
        std::cin >> inputFloat;
        if (inputFloat < balance) {
            balance -= inputFloat;
            UserBankUI();
        }
        else {
            std::cout << "Balance insufficent\n";
            UserBankUI();
        }
        break;
    default:std::system("cls");
        UserBankUI();
    }
}
void PasswordCheck() {
    std::cout << "enter password: ";
    std::cin >> inputInt;
    if (inputInt != password) {
        std::cout << "Wrong password\n";
        Start();
    }
    else
        std::cout << "Success!\n";
}

int main() {
    Start();
}
