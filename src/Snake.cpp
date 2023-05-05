#include "headers/Snake.h"

Snake::Snake(sf::RenderWindow& win)
    : dir(3), win(win)
{
    sf::Vector2f v = sf::Vector2f(150.f, 150.f);
    coords.push_back(sf::Vector2f(v));

    initSnake();
}

void Snake::drawSnake()
{
    for (size_t i = 0; i < coords.size(); i++)
    {
        m_snake.setPosition(coords[i]);
        win.draw(m_snake);
    }
}

void Snake::eatFruit(Fruit& fruit)
{
    if (coords[0].x == fruit.getFruitPosition().x && coords[0].y == fruit.getFruitPosition().y) {
        switch (dir)
        {
        case 1:
            coords.push_back(sf::Vector2f(coords[coords.size() - 1].x, coords[coords.size() - 1].y - 25.f));
            break;
        case 2:
            coords.push_back(sf::Vector2f(coords[coords.size() - 1].x + 25.f, coords[coords.size() - 1].y));
            break;
        case 3:
            coords.push_back(sf::Vector2f(coords[coords.size() - 1].x + 25.f, coords[coords.size() - 1].y));
            break;
        case 4:
            coords.push_back(sf::Vector2f(coords[coords.size() - 1].x - 25.f, coords[coords.size() - 1].y));
            break;
        }
        
        bool tmp = true;
        while (tmp)
        {
            fruit.setRandomPos();
            for (size_t i = 0; i < coords.size(); i++)
            {
                if (fruit.getFruitPosition().x == coords[i].x && fruit.getFruitPosition().y == coords[i].y)
                    break;
                else
                    tmp = false;
            }
        }
    }
}

bool Snake::isGameOver()
{
    for (size_t i = 1; i < coords.size(); i++)
    {
        if (coords[0].x == coords[i].x && coords[0].y == coords[i].y) 
            return true;
    }
    return false;
}

void Snake::changeDir()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir = 4;
}

void Snake::updateSnakePos()
{
    int width = win.getSize().x;
    int height = win.getSize().y;

    for (int i = coords.size() - 1; i > 0; i--)
    {
        coords[i].x = coords[i - 1].x;
        coords[i].y = coords[i - 1].y;
    }

    switch (dir)
    {
    case 1:
        coords[0].y -= 25.f;
        if (coords[0].y == 0 - 25.f) coords[0].y = height - 25.f;
        break;
    case 2:
        coords[0].x -= 25.f;
        if (coords[0].x == 0 - 25.f) coords[0].x = width - 25.f;
        break;
    case 3:
        coords[0].y += 25.f;
        if (coords[0].y == height) coords[0].y = 0;
        break;
    case 4:
        coords[0].x += 25.f;
        if (coords[0].x == width) coords[0].x = 0;
        break;
    }

}