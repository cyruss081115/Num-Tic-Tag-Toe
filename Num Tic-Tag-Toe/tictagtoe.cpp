//
//  tictagtoe.cpp
//  Num Tic-Tag-Toe
//
//  Created by Cyrus Wong on 24/5/2022.
//

#include "tictagtoe.hpp"
using namespace std;

// Constructors and deconstructors

TicTagToe:: TicTagToe() {
    grid = 0;
    player = A;
}

TicTagToe:: TicTagToe(int gridVal) {
    grid = gridVal;
    player = A;
}

TicTagToe:: ~TicTagToe(){}

// utils
int TicTagToe:: getGrid() {return grid;}


Player TicTagToe:: getPlayer() {return player;}


int TicTagToe:: gridContent(int pos) {
    if (pos < 1 || pos > 9) {
        cout << "Unexpected pos input" << endl;
        return -1;
    }
    
    int mask = 1;
    for (int i = 0; i < 9 - pos; i++) {
        mask *= 10;
    }
    return grid / mask % 10;
}


// Returns the char form of content
char TicTagToe:: printGridHelper(int gridPos) {
    int content = gridContent(gridPos);
    if (content >= 1 && content <= 9) {
        return '0' + content;
    } else {
        return ' ';
    }
}

void TicTagToe:: printGrid() {
    cout << " " << printGridHelper(1) << " | " << printGridHelper(2) << " | " << printGridHelper(3) << endl;
    cout << "---+---+---" << endl;
    cout << " " << printGridHelper(4) << " | " << printGridHelper(5) << " | " << printGridHelper(6) << endl;
    cout << "---+---+---" << endl;
    cout << " " << printGridHelper(7) << " | " << printGridHelper(8) << " | " << printGridHelper(9) << endl;
}


bool TicTagToe:: isPlaceable(int pos, int num) {
    if (pos < 1 || pos > 9 || num < 1 || num > 9) {
        return false;   // Input out of range (1-9)
    } else if (player == A && num % 2 == 0) {
        return false;   // Player A placed numbers for player B (even numbers)
    } else if (player == B && num % 2 == 1) {
        return false;   // Player B placed numbers for player A (odd numbers)
    } else if (gridContent(pos) != 0) {
        return false;   // Position occupied
    }
    
    int freqTable[10] = {0};
    int gridCpy = grid;
    while (gridCpy > 0) {
        freqTable[gridCpy % 10]++;
        gridCpy /= 10;
    }
    if (freqTable[num] != 0)
        return false;   // Number already placed
    
    return true;
}


void TicTagToe:: placeNum(int pos, int num) {
    int mask = 1;
    for (int i = 0; i < 9 - pos; i++) {
        mask *= 10;
    }
    grid += mask * num;
}

bool TicTagToe:: putToGrid(int pos, int num) {
    // Assume that the position has already been validated
    
    // Place the num
    placeNum(pos, num);
    
    // Check row
    for (int i = 1; i < 9; i+=3) {
        if (gridContent(i) + gridContent(i + 1) + gridContent(i + 2) == 15)
            return true;
    }
    // Check column
    for (int i = 1; i <= 3; i++) {
        if (gridContent(i) + gridContent(i + 3) + gridContent(i + 6) == 15)
            return true;
    }
    // Check diagonal
    if (
        gridContent(1) + gridContent(5) + gridContent(9) == 15 ||
        gridContent(3) + gridContent(5) + gridContent(7) == 15
        ) {
            return true;
        }
    
    return false;
}


bool TicTagToe:: isFull() {
    int gridCpy = grid;
    while (gridCpy > 0) {
        if (gridCpy % 10 == 0) {
            return false;
        }
        gridCpy /= 10;
    }
    return true;
}

void TicTagToe:: nextPlayer() {
    player = player == A ? B : A;
}
