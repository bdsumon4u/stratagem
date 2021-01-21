#include "SFML/Graphics.hpp"
#include "global.h"
#include "enemy.h"
#include "iostream"

using std::cout;
using std::endl;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;
using sf::Keyboard;
using sf::Texture;
using sf::Sprite;
using sf::Clock;
using sf::Vector2f;

int main() {
    float time, delay = 0.07; // Copter Can Move in Every delay seconds
    int enemy_count = 4, x, y, dir, status, score, win_point = 650;
    Enemy enemies[enemy_count];

    RenderWindow window(VideoMode(N * S, M * S), "Stratagem Game!");
    window.setFramerateLimit(60);

    Event ev{};
    Clock clock;

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
    sEnemy.setOrigin(S / 2.0, S / 2.0); // Origin Of Enemy is Center.

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
                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    status = status == PAUSED ? PLAYING : PAUSED;
                }
                if (status == PAUSED) {
                    continue;
                }
                Keyboard::isKeyPressed(Keyboard::Up) && (dir = TOP);
                Keyboard::isKeyPressed(Keyboard::Right) && (dir = RIGHT);
                Keyboard::isKeyPressed(Keyboard::Down) && (dir = BOTTOM);
                Keyboard::isKeyPressed(Keyboard::Left) && (dir = LEFT);
            }
        }

        if (status != PLAYING) {
            continue;
        }

        time = clock.getElapsedTime().asSeconds();
        if (time > delay) {
            if (dir == TOP) {
                y--;
                y < 0 && (y = 0);
            } else if (dir == RIGHT) {
                x++;
                x >= N && (x = N - 1);
            } else if (dir == BOTTOM) {
                y++;
                y >= M && (y = M - 1);
            } else if (dir == LEFT) {
                x--;
                x < 0 && (x = 0);
            } else {
                // Not Moving
            }

            if (grid[y][x] == BLOCKING) {
                status = OVER;
            } else if (grid[y][x] == FREE) {
                grid[y][x] = BLOCKING;
                score++;
            } else if (grid[y][x] == BLOCKED) {
                dir = 0;
            }

            cout << "Score: " << score << endl;
            if (status == OVER) {
                cout << "Game Over" << endl;
            }

            clock.restart();
            time = 0;
        }

        /**
         * Keep Moving Enemies
         */
        for (int i = 0; i < enemy_count; ++i) {
            enemies[i].move();
            if (grid[enemies[i].y / S][enemies[i].x / S] == 2) {
                status = OVER;
            }
        }

        /*
         * After Reaching Safe Position
         */
        if (grid[y][x] == BLOCKED) {
            for (int i = 0; i < enemy_count; i++) {
                observe(enemies[i].y / S, enemies[i].x / S);
            }

            score = 4 - 2 * (M + N);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] == TRANSITION) {
                        grid[i][j] = FREE;
                    } else {
                        grid[i][j] = BLOCKED;
                        score++;
                    }
                }
            }
        }

        if (score >= win_point) {
            status = WIN;
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

        for (int i = 0; i < enemy_count; ++i) {
            sEnemy.setPosition(Vector2f(enemies[i].x, enemies[i].y));
            window.draw(sEnemy);
        }

        if (status == OVER) {
            window.draw(sGameOver);
        } else if (status == WIN) {
            window.draw(sGameWin);
        }

        window.display();
    }

    return 0;
}
