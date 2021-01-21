#include "SFML/Graphics.hpp"
#include "iostream"

using std::cout;
using std::endl;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Keyboard;
using sf::Texture;
using sf::Sprite;

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

    Texture blueTile, redTile, enemy, copter, gameOver, gameWin;
    blueTile.loadFromFile("assets/blue-tile.png");
    redTile.loadFromFile("assets/red-tile.png");
    enemy.loadFromFile("assets/enemy.png");
    copter.loadFromFile("assets/copter.png");
    gameOver.loadFromFile("assets/game-over.png");
    gameWin.loadFromFile("assets/game-win.png");

    Sprite sBlueTile(blueTile), sRedTile(redTile), sEnemy(enemy), sCopter(copter), sGameOver(gameOver), sGameWin(gameWin);
    sGameOver.setColor(sf::Color::Red);
    sGameOver.setPosition(100, 100);
    sGameWin.setColor(sf::Color::Red);
    sGameWin.setPosition(110, 10);
    sEnemy.setOrigin(12.5, 12.5); // Origin Of Enemy is Center.

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

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == FREE) {
                    continue;
                } else if (i == y && j == x) {
                    sCopter.setPosition(j * S, i * S);
                    window.draw(sCopter);
                } else if (grid[i][j] == BLOCKED) {
                    sBlueTile.setPosition(j * S, i * S);
                    window.draw(sBlueTile);
                } else { // BLOCKING
                    sRedTile.setPosition(j * S, i * S);
                    window.draw(sRedTile);
                }
            }
        }

        window.display();
    }

    return 0;
}
