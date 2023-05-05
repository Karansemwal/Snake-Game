#include "headers/Background.h"

void Background::drawBackg()
{
    unsigned int row = win.getSize().x / background.getSize().x;
    unsigned int column = win.getSize().y / background.getSize().x;

    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < column; j++)
        {
            background.setPosition(i * background.getSize().x, j * background.getSize().x);
            win.draw(background);
        }
}
