#include "headers/Fruit.h"
#include <random>

void Fruit::initFruit()
{
    m_fruitText.loadFromFile("./src/resources/fruit_sprite.png");
    m_fruit.setTexture(&m_fruitText);
    m_fruit.setSize(sf::Vector2f(25.f, 25.f));
    m_fruit.setPosition(200.f, 200.f);
}

void Fruit::setRandomPos()
{
    int x = random(0, WIDTH);
    int y = random(0, HEIGHT);

    int n;
    n = x % 25;
    x -= n;
    n = y % 25;
    y -= n;
    this->setFruitPosition(sf::Vector2f(x, y));
}

int Fruit::random(int min, int max)
{
    // random engine is initialized once
    static std::default_random_engine randomEngine(time(NULL));
    std::uniform_int_distribution<int> distr(min, max);
    int n = distr(randomEngine);

    // for keeping the position of fruit aligned with grid
    int r = n % 25;
    return (n - r);
}