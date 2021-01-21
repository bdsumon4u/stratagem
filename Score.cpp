//
// Created by hotash on 1/21/21.
//

#include "SFML/Graphics.hpp"
#include "Score.h"

using sf::Color;

Score::Score() {
    font.loadFromFile("assets/fonts/EastSeaDokdo-Regular.ttf");
    scoretxt.setFont(font);
    scoretxt.setFillColor(Color::Red);
    scoretxt.setStyle(Text::Bold);
    scoretxt.setCharacterSize(50);
    scoretxt.setPosition(500, 20);
}

void Score::update(int updated) {
    current = updated;
    sprintf(scorestr, "Score: %d", current);
    scoretxt.setString(scorestr);
}

void Score::increment(int inc) {
    update(current + inc);
}
