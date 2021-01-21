//
// Created by hotash on 1/21/21.
//

#include "SFML/Graphics.hpp"
#include "Level.h"

using sf::Color;

Level::Level() {
    font.loadFromFile("assets/fonts/EastSeaDokdo-Regular.ttf");
    leveltxt.setFont(font);
    leveltxt.setFillColor(Color::Red);
    leveltxt.setStyle(Text::Bold);
    leveltxt.setCharacterSize(50);
    leveltxt.setPosition(50, 520);
    sprintf(levelstr, "Level: %d", current);
    leveltxt.setString(levelstr);
}

void Level::update(int updated) {
    if (updated > max_level) {
        finished = true;
    } else {
        current = updated;
    }
    sprintf(levelstr, "Level: %d", current);
    leveltxt.setString(levelstr);
}

void Level::increment(int inc) {
    update(current + inc);
}

int Level::enemy_count() {
    return min_enemy + current - 1;
}

int Level::max_enemy_count() {
    return min_enemy + max_level - 1;
}
