#pragma once
#include <SFML/Graphics.hpp>
#include "Fruit.h"

class Snake
{
public:
    Snake(sf::RenderWindow& win);
    ~Snake() { }

    void drawSnake();
    void eatFruit(Fruit& fruit);
    bool isGameOver();
    void updateSnakePos();
    void changeDir();
    void restartSnake();

    inline void setSnakePosition(sf::Vector2f pos) { m_snake.setPosition(pos); }
    inline sf::Vector2f getSnakePosition() const { return m_snake.getPosition(); }

    int dir;
private:
    inline void initSnake()
    {
        m_snakeText.loadFromFile("./src/resources/snake_sprite.png");
        m_snake.setTexture(&m_snakeText);
        m_snake.setPosition(coords[0]);
        m_snake.setSize(sf::Vector2f(25.f, 25.f));

        m_scoreFont.loadFromFile("./src/resources/OpenSans-Regular.ttf");

        m_score.setFont(m_scoreFont);
        m_score.setPosition(5.f, 557.f);
        m_score.setString("000");
        m_score.setCharacterSize(25);
    }

    sf::RectangleShape  m_snake;
    sf::Texture         m_snakeText;
    std::vector<sf::Vector2f> coords;
    sf::Font m_scoreFont;
    sf::Text m_score;
    sf::RenderWindow& win;
};

