#include "SFML/Graphics.hpp"
#include "iostream"

using std::cout;
using std::endl;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Keyboard;

/**
 * M * N => Grid Dimension
 * S => Size Of Each Element In The Grid
 */
const int M = 25, N = 40, S = 25;
/**
 * Game Grid
 */
int grid[M][N];

/**
 * All Possible Status Of The Game
 */
const int PLAYING = 0, OVER = 1;
/**
 * All Possible State Of A Position In The Grid
 */
const int FREE = 0, BLOCKED = 1, BLOCKING = 2;
/**
 * Copter's Direction
 */
const int TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4;

int main() {
    int x, y, dir, status, score;

    RenderWindow window(VideoMode(N * S, M * S), "Stratagem Game!");
    window.setFramerateLimit(60);

    Event ev{};

    play_game:
    status = PLAYING;
    x = y = dir = score = 0;
    for (int row = 0; row < M; ++row) {
        for (int col = 0; col < N; ++col) {
            grid[row][col]
                    = row == 0 || col == 0 || row == M - 1 || col == N - 1
                      ? BLOCKED : FREE;
        }
    }

    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            if (ev.type == Event::Closed) {
                window.close();
            }
            if (ev.type == Event::KeyPressed) {
                if (Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    goto play_game;
                }
                Keyboard::isKeyPressed(Keyboard::Up) && (dir = TOP);
                Keyboard::isKeyPressed(Keyboard::Right) && (dir = RIGHT);
                Keyboard::isKeyPressed(Keyboard::Down) && (dir = BOTTOM);
                Keyboard::isKeyPressed(Keyboard::Left) && (dir = LEFT);
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
