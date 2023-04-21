#include "headers/Background.h"

void Background::drawBackg(sf::RenderWindow& win)
{
    unsigned int row = WIDTH / background.getSize().x;
    unsigned int column = HEIGHT / background.getSize().x;

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < column; j++)
        {
            background.setPosition(i * background.getSize().x, j * background.getSize().x);
            win.draw(background);
        }
}
