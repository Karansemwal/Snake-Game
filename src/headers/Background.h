#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
    Background(sf::RenderWindow& win): win(win) { initBackg(); }
    ~Background() { }

    void drawBackg();

private:
    void initBackg()
    {
        backgText.loadFromFile("./src/resources/Background.png");
        background.setSize(sf::Vector2f(25.f, 25.f));
        background.setTexture(&backgText);
    }

    sf::RectangleShape background;
    sf::Texture backgText;
    sf::RenderWindow& win;
};

