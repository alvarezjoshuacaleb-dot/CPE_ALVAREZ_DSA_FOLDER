#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "suppH.h"

const int SIZE = 100;
const int CANDIDATE_COUNT = 5;

// Function declaration
void displayArray(int values[], int length);

int main() {
    int votes[SIZE];

    std::string names[CANDIDATE_COUNT] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(static_cast<unsigned>(time(0)));

    // Generate random votes
    for (int x = 0; x < SIZE; x++) {
        votes[x] = (rand() % CANDIDATE_COUNT) + 1;
    }

    std::cout << "Original Votes:\n";
    displayArray(votes, SIZE);

    // Sort the votes
    insertionSort(votes, SIZE);

    std::cout << "\nVotes After Sorting:\n";
    displayArray(votes, SIZE);

    // Count the votes
    getVoteResults(votes, SIZE, names);

    return 0;
}

// Display the array
void displayArray(int values[], int length) {
    for (int x = 0; x < length; x++) {
        std::cout << values[x] << " ";

        if ((x + 1) % 20 == 0) {
            std::cout << "\n";
        }
    }

    std::cout << "\n";
}