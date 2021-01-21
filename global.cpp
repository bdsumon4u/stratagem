//
// Created by hotash on 1/21/21.
//

#include "global.h"


/**
 * M * N => Grid Dimension
 * S => Size Of Each Element In The Grid
 */
const int M = 25, N = 40, S = 25;
/*
 * Minimum Score For Next Level
 */
int win_point = 650;

/**
 * Game Grid
 */
vector<vector<int>> grid(M, vector<int>(N));

/**
 * Copter Can Move in Every delay seconds
 */
float delay = 0.07;
int status;
/**
 * All Possible Status Of The Game
 */
const int PLAYING = 0, OVER = 1, WIN = 2, PAUSED = 3;
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
