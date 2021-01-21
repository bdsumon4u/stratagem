//
// Created by hotash on 1/21/21.
//

#include "SFML/Graphics.hpp"
#include "string"

using std::string;
using sf::Color;
using sf::Font;
using sf::Text;
using sf::Rect;

#ifndef STRATAGEM_CENTERTEXT_H
#define STRATAGEM_CENTERTEXT_H


class CenterText {
public:
    int csize = 50;
    Font font;
    Text text;
    Rect<float> bounds;
    CenterText();
    void setString(string str);
    Text position(int y);
};


#endif //STRATAGEM_CENTERTEXT_H
