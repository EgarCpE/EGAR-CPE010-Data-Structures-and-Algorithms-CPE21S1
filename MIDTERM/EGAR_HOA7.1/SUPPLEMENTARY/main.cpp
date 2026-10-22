#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "selectionAlgo.h"

using namespace std;

int main() {

    // Activity requires array A[0...100] -> total size of 101
    const int maxSize = 101;

    void displayArr(int arr[]);

    // Seed for random number generator
    srand(time(0));

    // Array creation for 101 elements A[0...100]
    int unsortedArr[maxSize];

    // Populate array with random vote values from 1 to 5
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = (rand() % 5) + 1;
    }

    cout << "Unsorted Array:" << endl;
    displayArr(unsortedArr);

    // Fixed candidate names according to the activity sheet
    string listofCandidates [5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // Sort the array using Selection Sort
    cout << "\nSorted Array (Selection Sort):" << endl;
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    // manual counter for each candidate
    int manualVoteCount [6] = {0};

    int currentVote = unsortedArr[0];
    int currentCount = 0;

    for (int i = 0; i < maxSize; i++) {
        currentCount++;
        // If we reach the end of array OR next element is a different candidate
        if (i == maxSize - 1 || unsortedArr[i + 1] != currentVote) {
            manualVoteCount[currentVote] = currentCount; // Save manual count

            if (i < maxSize - 1) {
                currentVote = unsortedArr[i + 1]; // Move to next candidate
                currentCount = 0; // Reset count for next candidate
            }
        }
    }

    // vote counting for winner determination
    int voteCount [6] = {0};

    for (int i = 0; i < maxSize; i++) {
        int vote = unsortedArr[i];
        if (vote >= 1 && vote <= 5) {
            voteCount[vote]++;
        }
    }

    // Logic to determine the winning candidate
    int winnerCandidate = 1;
    int maxVotes = voteCount[1];

    for (int i = 2; i <= 5; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winnerCandidate = i;
        }
    }

    // Display the results
    cout << "\n Vote Count Results:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Candidate " << i << " (" << listofCandidates [i - 1] << "):" << endl;
        cout << "  Manual Count: " << manualVoteCount[i] << endl;
        cout << "  Count Result of Algorithm: " << voteCount[i] << endl;
        cout << endl;
    }

    cout << "Winner: Candidate " << winnerCandidate << " ("
         << listofCandidates [winnerCandidate - 1] << ") with "
         << maxVotes << " votes!" << endl;

    return 0;
}

// Function to print array elements
void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}