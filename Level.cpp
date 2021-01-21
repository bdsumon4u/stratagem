//
// Created by hotash on 1/21/21.
//

#include "Level.h"

using sf::Color;

Level::Level() {
    enemy_count = min_enemy;
    font.loadFromFile("assets/fonts/EastSeaDokdo-Regular.ttf");
    leveltxt.setFont(font);
    leveltxt.setFillColor(Color::Red);
    leveltxt.setStyle(Text::Bold);
    leveltxt.setCharacterSize(40);
    sprintf(levelstr, "LEVEL: %d", current);
    leveltxt.setString(levelstr);
    leveltxt.setPosition(N * S - 185, 10);
}

void Level::update(int updated) {
    if (updated > max_level) {
        finished = true;
    } else {
        current = updated;
        enemy_count = min_enemy + current - 1;
    }
    sprintf(levelstr, "LEVEL: %d", current);
    leveltxt.setString(levelstr);
    leveltxt.setPosition(N * S - 185, 10);
}

void Level::increment(int inc) {
    update(current + inc);
}

int Level::max_enemy_count() {
    return min_enemy + max_level - 1;
}
