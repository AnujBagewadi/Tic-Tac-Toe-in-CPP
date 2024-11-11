# Tic-Tac-Toe Game in C++

### Overview
- This project is an implementation of the classic Tic-Tac-Toe game in C++. It allows two players to take turns marking a 3x3 grid with 'X' and 'O' symbols. The objective is to align three of the same symbols horizontally, vertically, or diagonally.

- The game includes a simple password protection mechanism, a user guide, and a platform-independent screen clearing function to enhance the user experience.

### Features
- **Password Protection**: Players must enter the correct password ("password") to access the game, with up to 4 attempts allowed.
- **Game Interface**: A text-based interface displays the game board, prompts players for input, and provides feedback on the game status.
- **Winner Detection**: The game checks for a winner after each move and announces the result (win or draw).
- **Cross-Platform**: The program includes a function to clear the terminal screen, which works on both Windows and Unix-based systems (Linux/macOS).
- **User Guide**: Provides instructions on how to play the game, explaining the layout and rules.
- **Game Continuation**: After a game ends, players can choose to play again or exit the game.

### Project Structure
- **tic_tac_toe.cpp**: The main implementation of the Tic-Tac-Toe game, including functions for handling user input, checking the game status, displaying the board, and managing the game flow.
- **clear_screen()**: Clears the console screen in a platform-independent manner.
- **checkwin()**: Checks the game board after each move to determine if there is a winner or if the game is a draw.
- **board()**: Displays the current state of the Tic-Tac-Toe board.
- **guide()**: Displays a guide to help players understand how to play the game.

### Compilation and Usage
1. **Compile the Project**
   - To compile the project, use the following command in the terminal:
     ```bash
     g++ -o tic_tac_toe tic_tac_toe.cpp
     ```
   
2. **Run the Game**
   - After compiling, run the executable to start the game:
     ```bash
     ./tic_tac_toe
     ```

### Game Options
- Upon running the program, players can choose from the following options:

1. **Enter the Game**: Start a new game of Tic-Tac-Toe.
2. **User Guide**: View a guide explaining how to play the game.
3. **Exit**: Exit the game program.

### Game Flow
- Players are prompted to enter a password to gain access to the game.
- After logging in, players can choose to start a new game, view the user guide, or exit the program.
- During the game, players take turns entering a number (1-9) to place their symbol on the grid.
- The game continues until there is a winner or the grid is full, resulting in a draw.

### Notes
- The game only supports two players (Player 1 with 'X' and Player 2 with 'O').
- The board is displayed after each move, and the current status of the game is checked to determine if there is a winner.
- The user guide explains the board layout and the goal of the game.
