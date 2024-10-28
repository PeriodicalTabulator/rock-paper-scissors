#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char generateComputerChoice() {
    srand(time(0));
    int num = rand() % 3;
    if (num == 0) {
        return 'r';
    }
    else if (num == 1) {
        return 's';
    }
    else {
        return 'p';
    }
}

char getPlayerChoice() {
    char choice;
    cout << "Enter r for Rock, p for Paper, or s for Scissors: ";
    cin >> choice;
    while (choice != 'r' && choice != 'p' && choice != 's') {
        cout << "Invalid choice. Please enter r, p, or s: ";
        cin >> choice;
    }
    return choice;
}

void determineWinner(char userChoice, char compChoice) {
    if (userChoice == compChoice) {
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == 'r' && compChoice == 's') ||
        (userChoice == 'p' && compChoice == 'r') ||
        (userChoice == 's' && compChoice == 'p')) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    char playerChoice = getPlayerChoice();
    char computerChoice = generateComputerChoice();

    cout << "You chose: " << (playerChoice == 'r' ? "Rock" : playerChoice == 'p' ? "Paper" : "Scissors") << endl;
    cout << "Computer chose: " << (computerChoice == 'r' ? "Rock" : computerChoice == 'p' ? "Paper" : "Scissors") << endl;

    determineWinner(playerChoice, computerChoice);

    return 0;
}