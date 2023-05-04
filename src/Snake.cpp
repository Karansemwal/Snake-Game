#include "headers/Snake.h"

Snake::Snake() 
    : dir(3)
{
    sf::Vector2f v = sf::Vector2f(150.f, 150.f);
    coords.push_back(sf::Vector2f(v));

    initSnake();
}

void Snake::drawSnake(sf::RenderWindow& win)
{
    win.draw(m_score);

    for (size_t i = 0; i < coords.size(); i++)
    {
        m_snake.setPosition(coords[i]);
        win.draw(m_snake);
    }
}

void Snake::eatFruit(Fruit& fruit)
{
    if (coords[0].x == fruit.getFruitPosition().x && coords[0].y == fruit.getFruitPosition().y) 
    {
        if (coords.size() - 1 < 10)
            m_score.setString("00" + std::to_string(coords.size() - 1));
        else if (coords.size() - 1 > 9 && coords.size() - 1 < 100)
            m_score.setString("0" + std::to_string(coords.size() - 1));
        else
            m_score.setString(std::to_string(coords.size() - 1));

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir != 3) dir = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && dir != 4) dir = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir != 1) dir = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && dir != 2) dir = 4;
}

void Snake::updateSnakePos()
{
    for (int i = coords.size() - 1; i > 0; i--)
    {
        coords[i].x = coords[i - 1].x;
        coords[i].y = coords[i - 1].y;
    }

    switch (dir)
    {
    case 1:
        coords[0].y -= 25.f;
        if (coords[0].y == 0 - 25.f && (coords[0].x == 0.f || coords[0].x == 25.f)) coords[0].y = HEIGHT - 75.f;
        else if (coords[0].y == 0 - 25.f) coords[0].y = HEIGHT - 25.f;
        break;
    case 2:
        coords[0].x -= 25.f;
        if (coords[0].x == 25.f && (coords[0].y == HEIGHT - 25.f || coords[0].y == HEIGHT - 50.f)) coords[0].x = WIDTH - 25.f;
        else if (coords[0].x == 0 - 25.f) coords[0].x = WIDTH - 25.f;
        break;
    case 3:
        coords[0].y += 25.f;
        if (coords[0].y == HEIGHT - 50.f && (coords[0].x == 0.f || coords[0].x == 25.f)) coords[0].y = 0;
        else if (coords[0].y == HEIGHT) coords[0].y = 0;
        break;
    case 4:
        coords[0].x += 25.f;
        if (coords[0].x == WIDTH && (coords[0].y == HEIGHT - 25.f || coords[0].y == HEIGHT - 50.f)) coords[0].x = 50.f;
        else if (coords[0].x == WIDTH) coords[0].x = 0;
        break;
    }

}