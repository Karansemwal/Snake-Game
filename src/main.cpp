#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "headers/Background.h"
#include "headers/Fruit.h"
#include "headers/Snake.h"

#define VELOCITY 25.f

const int defaultWidth = 800;
const int defaultHeight = 600;

int currentWidth = defaultWidth;
int currentHeight = defaultHeight;

void SetFullScreen(bool fullScreen, sf::RenderWindow& window);

int main()
{
    sf::RenderWindow window(sf::VideoMode(currentWidth, currentHeight), "Snake Game", sf::Style::Close);
    window.setFramerateLimit(60);

    Background backg(window);
    Snake snake(window);
    Fruit fruit(window);
    int tick = 0;
    bool fullScreen = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            fullScreen = !fullScreen;
            SetFullScreen(fullScreen, window);
        }

        // change snake direction with key input (WASD)
        snake.changeDir();
        if (tick == 10)
        {
            // TODO: Fix Game over functionality
            //if (snake.isGameOver()) break;
            snake.updateSnakePos();
            snake.eatFruit(fruit);
            tick = 0;
        }
        tick++;

        // rendering
        window.clear();
        backg.drawBackg();
        fruit.drawFruit();
        snake.drawSnake();
        window.display();
    }

    return 0;
}

void SetFullScreen(bool fullScreen, sf::RenderWindow& window)
{
    if(fullScreen)
        window.create(sf::VideoMode::getFullscreenModes()[0], "Snake Game", sf::Style::Fullscreen);
    else
        window.create(sf::VideoMode(defaultWidth, defaultHeight), "Snake Game", sf::Style::Close);
}