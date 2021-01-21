//
// Created by hotash on 1/21/21.
//

#include "vector"

using std::vector;

#ifndef STRATAGEM_GLOBAL_H
#define STRATAGEM_GLOBAL_H

extern const int M, N, S;
extern vector<vector<int>> grid;
extern const int PLAYING, OVER;
extern const int FREE, BLOCKED, BLOCKING, TRANSITION;
extern const int TOP, RIGHT, BOTTOM, LEFT;

void print2v(vector<vector<int>> grid);

#endif //STRATAGEM_GLOBAL_H
