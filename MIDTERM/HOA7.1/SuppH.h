#ifndef SUPP_H
#define SUPP_H
#include <iostream>
#include <string>

// Insertion Sort
template <typename T>
void insertionSort(T data[], int length) {
    for (int current = 1; current < length; current++) {

        T selected = data[current];
        int previous = current - 1;
        while (previous >= 0 && data[previous] > selected) {
            data[previous + 1] = data[previous];
            previous--;
        }
        data[previous + 1] = selected;
    }
}
// Count votes from the sorted array
void getVoteResults(
    int data[],
    int length,
    std::string names[]
) {
    int position = 0;
    int mostVotes = 0;
    int winner = 0;

    std::cout << "\n===== VOTE RESULTS =====\n";

    while (position < length) {

        int voteValue = data[position];
        int total = 1;

        position++;

        while (position < length && data[position] == voteValue) {
            total++;
            position++;
        }

        std::cout << names[voteValue - 1]
                  << " = "
                  << total
                  << " votes\n";

        if (total > mostVotes) {
            mostVotes = total;
            winner = voteValue;
        }
    }

    std::cout << "\nWinner: "
              << names[winner - 1]
              << "\nTotal Votes: "
              << mostVotes
              << "\n";
}

#endif