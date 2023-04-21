#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "headers/Background.h"
#include "headers/Fruit.h"
#include "headers/Snake.h"

#define VELOCITY 25.f

#define WIDTH  800
#define HEIGHT 600

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game", sf::Style::Close);
    window.setFramerateLimit(60);

    Background backg;
    Snake snake;
    Fruit fruit;
    int tick = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
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
        backg.drawBackg(window);
        fruit.drawFruit(window);
        snake.drawSnake(window);
        window.display();
    }

    return 0;
}