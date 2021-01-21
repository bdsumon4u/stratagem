//
// Created by hotash on 1/21/21.
//

#include "iostream"
#include "global.h"

using std::cout;
using std::endl;
using std::vector;

/**
 * M * N => Grid Dimension
 * S => Size Of Each Element In The Grid
 */
const int M = 25, N = 40, S = 25;

/**
 * Game Grid
 */
vector<vector<int>> grid(M, vector<int>(N));

/**
 * All Possible Status Of The Game
 */
const int PLAYING = 0, OVER = 1, WIN = 2;
/**
 * All Possible State Of A Position In The Grid
 */
const int FREE = 0, BLOCKED = 1, BLOCKING = 2, TRANSITION = 3;
/**
 * Copter's Direction
 */
const int TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4;

void print2v(vector<vector<int>> grid) {
    for (auto row : grid) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
}

// |--|--|--|--|--|--|--|
// |--|--|--|--|--|--|--|
// |--|--|--|--|--|--|--|
// |--|--|--|--|--|--|--|
// |--|--|--|--|--|--|--|
// |--|--|--|--|--|--|--|
