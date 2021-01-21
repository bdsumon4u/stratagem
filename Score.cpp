//
// Created by hotash on 1/21/21.
//

#include "Score.h"

Score::Score() {
    font.loadFromFile("assets/fonts/EastSeaDokdo-Regular.ttf");
    scoretxt.setFont(font);
    scoretxt.setFillColor(Color::Red);
    scoretxt.setStyle(Text::Bold);
    scoretxt.setCharacterSize(40);
}

void Score::update(int updated) {
    current = updated;
    sprintf(scorestr, "SCORE: %d", current);
    scoretxt.setString(scorestr);
    scoretxt.setPosition(N * S - 185, 40);
}

void Score::increment(int inc) {
    update(current + inc);
}
