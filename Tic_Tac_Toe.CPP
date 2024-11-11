#include <iostream>
#include <cstdlib>  // For system()
#include <limits>   // For numeric_limits
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function declarations
int checkwin();       // Function for checking the result
void board();         // Function to draw the board
void guide();         // Function for user guide
void clear_screen();  // Function to clear the screen (platform-independent)

int main() {
    int player = 1, i, choice, option;
    char mark, choice1;
    int trial_attempts = 4;
    bool access_granted = false;

    // Password check
    for (int attempt = 0; attempt < trial_attempts; ++attempt) {
        string password;
        cout << "Enter the password within a trial period of 4 attempts: ";
        cin >> password;
        
        if (password == "password") {
            cout << "\nAccess Granted\n";
            access_granted = true;
            break;
        } else {
            cout << "\nAccess Denied\n";
        }
    }

    if (!access_granted) {
        cout << "You have entered the wrong password 4 times\n";
        return -1;
    }

    do {
        clear_screen();
        cout << "1. Enter the Game\n2. User Guide\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                do {
                    clear_screen();
                    board();
                    player = (player % 2) ? 1 : 2;
                    cout << "Player " << player << ", enter a number: ";
                    cin >> choice;

                    mark = (player == 1) ? 'X' : 'O';

                    // Validate input choice and mark the board
                    if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
                        square[choice] = mark;
                    } else {
                        cout << "Invalid move ";
                        player--;
                        cin.clear(); // Clear input
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover input
                        continue;
                    }

                    i = checkwin();
                    player++;
                } while (i == -1);

                board();
                if (i == 1)
                    cout << "==> Player " << --player << " wins!\n";
                else
                    cout << "==> Game draw!\n";
                break;

            case 2:
                guide();
                break;

            case 3:
                exit(0);
                break;

            default:
                cout << "Wrong Choice\n";
                break;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice1;
    } while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}

// Function to clear the screen
void clear_screen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Function to check the game's status
int checkwin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

// Function to display the game board
void board() {
    clear_screen();
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";

    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "\t\t     |     |     \n\n";
}

// Function to provide the game guide
void guide() {
    clear_screen();
    cout << "\nThe TIC-TAC-TOE game board is similar to a # key on a keypad.\n";
    cout << "It looks something like this:\n";
    cout << "    _|_|_\n";
    cout << "    _|_|_\n";
    cout << "     | |\n";
    cout << "\nIn the spaces, crosses and noughts are placed alternately.";
    cout << "\nThe goal is to complete 3 of the same symbol (X or O) in a row, column, or diagonal.\n";
}
