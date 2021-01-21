//
// Created by hotash on 1/21/21.
//

#include "SFML/Graphics.hpp"

using sf::Font;
using sf::Text;

#ifndef STRATAGEM_LEVEL_H
#define STRATAGEM_LEVEL_H


class Level {
public:
    int current = 1, min_enemy = 3, max_level = 5;
    bool finished = false;
    char levelstr[20];

    Font font;
    Text leveltxt;

    Level();
    void update(int updated);
    void increment(int inc = 1);
    int enemy_count();
    int max_enemy_count();
};


#endif //STRATAGEM_LEVEL_H
