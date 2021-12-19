
#include <iostream>

//function decloration
void TicTacToeUI();
void Turn(bool* turnPtr);
void WinCheck(int horInput, int verInput);

//variables
bool win = false;
char* Horizontal[3];

void Turn(bool* turnPtr) {
    int horInput;
    int verInput;

    if (*turnPtr) {
        std::cout << "O's turn: ";
        std::cin >> horInput >> verInput;

        if (Horizontal[horInput - 1][verInput - 1] != 'O' && Horizontal[horInput - 1][verInput - 1] != 'X') {
            Horizontal[horInput - 1][verInput - 1] = 'O';
            *turnPtr = false;
            std::system("cls");
        }
        else {
            std::cout << "Spot already taken\n";
            Turn(turnPtr);
        }
    }
    else {
        std::cout << "X's turn: ";
        std::cin >> horInput >> verInput;

        if (Horizontal[horInput - 1][verInput - 1] != 'O' && Horizontal[horInput - 1][verInput - 1] != 'X') {
            Horizontal[horInput - 1][verInput - 1] = 'X';
            *turnPtr = true;
            std::system("cls");
        }
        else {
            std::cout << "Spot already taken\n";
            Turn(turnPtr);
        }

    }
    WinCheck(horInput, verInput);
}

void WinCheck(int horInput, int verInput) {
    for (int i = 0; i < 3; i++) {
        //Vertical
        if (Horizontal[i][0] == Horizontal[i][1] && Horizontal[i][0] == Horizontal[i][2]) {
            if (Horizontal[i][0] != '.') {
                win = true;
                std::cout << "   " << Horizontal[i][0] << " won!\n\n";
            }
        }

        //Horizontal
        if (Horizontal[0][i] == Horizontal[1][i] && Horizontal[0][i] == Horizontal[2][i]) {
            if (Horizontal[0][i] != '.') {
                win = true;
                std::cout << "   " << Horizontal[0][i] << " won!\n\n";
            }
        }
    }

    //Diagonals
    if (Horizontal[0][0] == Horizontal[1][1] && Horizontal[0][0] == Horizontal[2][2]) {
        if (Horizontal[0][0] != '.') {
            win = true;
            std::cout << "   " << Horizontal[0][0] << " won!\n\n";
        }
    }
    if (Horizontal[2][0] == Horizontal[1][1] && Horizontal[2][0] == Horizontal[0][2]) {
        if (Horizontal[1][1] != '.') {
            win = true;
            std::cout << "   " << Horizontal[1][1] << " won!\n\n";
        }
    }
}

void TicTacToeUI() {
    std::cout << "    1   2   3\n\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << "   ";
        for (int j = 0; j < 3; j++) {
            std::cout << Horizontal[i][j] << "   ";
        }
        std::cout << "\n\n";
    }
}

int main()
{
    bool turn;
    bool* turnPtr = &turn;

    //creating tictactoe chart
    for (int i = 0; i < 3; i++) {
        Horizontal[i] = new char[3];
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            Horizontal[j][i] = '.';
        }
    }


    do {
        TicTacToeUI();
        Turn(turnPtr);
    } while (win == false);
    TicTacToeUI();

}
