//
//  main.cpp
//  Num Tic-Tag-Toe
//
//  Created by Cyrus Wong on 24/5/2022.
//

#include "tictagtoe.hpp"
using namespace std;

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


int main(int argc, const char * argv[]) {
    // insert code here...
    TicTagToe ttt(406750120);
    cout << ttt.getPlayer() << endl;
    cout << ttt.gridContent(10) << endl;
    return 0;
}
