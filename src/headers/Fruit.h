#pragma once
#include <SFML/Graphics.hpp>
#include <random>

#define WIDTH  800
#define HEIGHT 600

class Fruit
{
public:
    Fruit(sf::RenderWindow& win): win(win) { initFruit(); }
    ~Fruit() { }

    void drawFruit() { win.draw(m_fruit); }
    void setRandomPos();
    int random(int min, int max);

    inline void setFruitPosition(sf::Vector2f pos) { m_fruit.setPosition(pos); }
    inline sf::Vector2f getFruitPosition() const { return m_fruit.getPosition(); }

private:
    void initFruit();

    sf::RectangleShape m_fruit;
    sf::Texture        m_fruitText;
    sf::RenderWindow& win;
};

