#include "include/Opcje.hpp"

#include "SFML/Audio.hpp"


Opcje::Opcje(float width, float height)
{
    if (!font.loadFromFile("assets/font/consola.ttf"))
    {
        // handle error
    }

    opcje[0].setFont(font);
    opcje[0].setColor(sf::Color::Green);
    opcje[0].setString("Wlacz muzyke");
    opcje[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    opcje[1].setFont(font);
    opcje[1].setColor(sf::Color::White);
    opcje[1].setString("Wylacz muzyke");
    opcje[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    opcje[2].setFont(font);
    opcje[2].setColor(sf::Color::White);
    opcje[2].setString("Exit");
    opcje[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Opcje::~Opcje()
{

}

void Opcje::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(opcje[i]);
    }
}

void Opcje::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        opcje[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        opcje[selectedItemIndex].setColor(sf::Color::Green);
    }
}

void Opcje::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        opcje[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        opcje[selectedItemIndex].setColor(sf::Color::Green);
    }
}

