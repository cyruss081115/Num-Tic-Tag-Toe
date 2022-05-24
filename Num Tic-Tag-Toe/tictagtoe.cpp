//
//  tictagtoe.cpp
//  Num Tic-Tag-Toe
//
//  Created by Cyrus Wong on 24/5/2022.
//

#include "tictagtoe.hpp"

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

void TicTagToe:: nextPlayer() {
    player = player == A ? B : A;
}
