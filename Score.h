//
// Created by hotash on 1/21/21.
//

#include "SFML/Graphics.hpp"

using sf::Font;
using sf::Text;

#ifndef STRATAGEM_SCORE_H
#define STRATAGEM_SCORE_H


class Score {
public:
    int current = 0;
    char scorestr[20];

    Font font;
    Text scoretxt;

    Score();
    void update(int updated);
    void increment(int inc = 1);
};


#endif //STRATAGEM_SCORE_H
