//
// Created by hotash on 1/21/21.
//

#include "global.h"
#include "enemy.h"

Enemy::Enemy() {
    rnd = 8 - rand() % 16; // from -7 to 8
    if (rnd > 0) {
        /**
         * if rnd > 5 then it's ok,
         * otherwise, rnd = 8
         */
        dx = rnd > 5 ? rnd : 8;
    } else {
        /**
         * if rnd < -4 then it's ok,
         * otherwise, rnd = -7
         */
        dx = rnd < -4 ? rnd: -7;
    }
    /**
     * -7 <= dx < -4, 5 < dx <= 8
     * dx = [-7, -6, -5, 6, 7, 8]
     */

    rnd = 8 - rand() % 16;
    if (rnd > 0) {
        dy = rnd > 5 ? rnd : 8;
    } else {
        dy = rnd < -5 ? rnd: -8;
    }
}

void Enemy::move()  {
    x += dx;
    if (grid[y / S][x / S] == BLOCKED) {
        dx = -dx;
        x += dx;
    }
    y += dy;
    if (grid[y / S][x / S] == BLOCKED) {
        dy = -dy;
        y += dy;
    }
}

/*
 * Observe, Which Positions are Free For Enemies
 */
void observe(int row, int col) {
    grid[row][col] || (grid[row][col] = TRANSITION);

    if (row > 0 && grid[row - 1][col] == FREE) {
        observe(row - 1, col);
    }
    if (row < M - 1 && grid[row + 1][col] == FREE) {
        observe(row + 1, col);
    }
    if (col > 0 && grid[row][col - 1] == FREE) {
        observe(row, col - 1);
    }
    if (col < N - 1 && grid[row][col + 1] == FREE) {
        observe(row, col + 1);
    }
}
