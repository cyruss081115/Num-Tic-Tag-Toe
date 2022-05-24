//
//  tictagtoe.hpp
//  Num Tic-Tag-Toe
//
//  Created by Cyrus Wong on 24/5/2022.
//

#ifndef tictagtoe_hpp
#define tictagtoe_hpp

#include <stdio.h>
#include <iostream>

enum Player{A, B};

class TicTagToe{
private:
    int grid;
    Player player;
public:
    TicTagToe();
    TicTagToe(int);
    ~TicTagToe();
    
    // utils
    int getGrid();
    Player getPlayer();
    
    // Returns the content in position of grid, which can only be 0-9
    // E.g., 406750120 represents the left-sided grid in Figure 1. Thus, the call gridContent(406750120, 3) shall return 6
    int gridContent(int pos);
    
    void printGrid();
    
    // To determine whether player P can put the number num to position pos of grid
    bool isPlaceable(int pos, int num, char p);
    
    // Place the number num to position pos of grid.
    // The function returns true if the players makes a sum of 15 of three non-zero numbers on any row, column, or diagonal after putting the number, false otherwise
    bool putToGrid(int pos, int num);
    
    void nextPlayer();
    
    // Driver function
    void playGame();
};

#endif /* tictagtoe_hpp */

