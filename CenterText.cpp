//
// Created by hotash on 1/21/21.
//

#include "CenterText.h"

CenterText::CenterText() {
    if (!font.loadFromFile("assets/fonts/EastSeaDokdo-Regular.ttf")) {
        cout << "Font Couldn't Found." << endl;
        exit(1);
    }
    text.setFont(font);
    text.setFillColor(Color::Red);
    text.setCharacterSize(50);
}

void CenterText::setString(string str) {
    text.setString(str);
    bounds = text.getLocalBounds();
    text.setOrigin(bounds.width / 2.0, bounds.height / 2.0);
}

Text CenterText::position(int y) {
    int mid = csize / 2.0;
    text.setPosition(N * S / 2.0 - mid, M * S / 2.0 + y - mid);
    return text;
}
