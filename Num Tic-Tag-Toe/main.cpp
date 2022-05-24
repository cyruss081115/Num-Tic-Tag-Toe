//
//  main.cpp
//  Num Tic-Tag-Toe
//
//  Created by Cyrus Wong on 24/5/2022.
//

#include "tictagtoe.hpp"
using namespace std;


void playGame() {
//    TicTagToe ttt(6750120);
//    ttt.printGrid();
//    cout << ttt.putToGrid(2, 8) << endl;
//    ttt.printGrid();
    TicTagToe ttt = TicTagToe();
    
    int pos, num;
    bool hasWinner = false;
    bool boardIsFull = false;
    
    ttt.printGrid();

    while (true){
        // Prompt input from user
        while (true) {
            cout << "Player " << (ttt.getPlayer() == A ? 'A' : 'B') << "'s move (pos num): ";
            cin >> pos; cin >> num;
            if (ttt.isPlaceable(pos, num)) {
                break;
            }
            cout << "Invalid! Try again." << endl;
        }
        
        hasWinner = ttt.putToGrid(pos, num);
        boardIsFull = ttt.isFull();
        ttt.printGrid();
        
        if (hasWinner || boardIsFull) {
            break;
        }
        ttt.nextPlayer();
    }
    
    if (hasWinner) {
        cout << "Player " << (ttt.getPlayer() == A ? 'A' : 'B') << " wins!" << endl;
    } else if (boardIsFull) {
        cout << "Draw Game!" << endl;
    } else {
        cout << "Unexpected Ending" << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    // 406750120
    playGame();
    return 0;
}
