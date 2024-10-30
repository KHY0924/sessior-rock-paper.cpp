#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    srand(static_cast<unsigned int>(time(0)));  // Initialize the random number generator

    const int scissor = 0;
    const int rock = 1;
    const int paper = 2;
    int userChoice;
    int marks = 0;  // Initialize marks to track the user's score

    // Loop for 3 rounds
    for (int i = 0; i < 3; i++) {
        std::cout << "Round" << (i + 1) << "\n";
        std::cout << "Enter scissor (0), rock (1), paper (2): ";
        std::cin >> userChoice;

        // Check if the user's input is valid
        if (userChoice < 0 || userChoice > 2) {
            std::cout << "Invalid input\n";
            return 0;  // End the program if input is invalid
        }

        int computerChoice = rand() % 3;  // Generate the computer's choice

        // Check if it's a draw
        if (computerChoice == userChoice) {
            std::cout << "It's a tie, please try again\n\n";
        }
        // Check if the user wins
        else if ((userChoice == scissor && computerChoice == paper) ||
                 (userChoice == rock && computerChoice == scissor) ||
                 (userChoice == paper && computerChoice == rock)) {
            std::cout << "You win this round\n\n";
            marks++;  // Increment marks if the user wins
        }
        // If neither a draw nor a win, the user loses
        else {
            std::cout << "You lose this round\n\n";
        }

        // Display the computer's choice for this round
        std::cout << "The computer chose: " << computerChoice << "\n\n";
    }

    // After the loop, display the total score
    std::cout << "Game over! Your total score is: " << marks << " out of 3\n";

    return 0;
}
