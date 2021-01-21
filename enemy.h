//
// Created by hotash on 1/21/21.
//

#include "global.h"

#ifndef STRATAGEM_ENEMY_H
#define STRATAGEM_ENEMY_H

struct Enemy {
    /**
     * (x, y) - Initial Position Of All Enemies
     * [dx, dy] - Enemy's Moving Factor
     */
    int x = 200, y = 200, dx, dy, rnd;

    Enemy();

    void move();
};

void observe(int row, int col);

#endif //STRATAGEM_ENEMY_H
