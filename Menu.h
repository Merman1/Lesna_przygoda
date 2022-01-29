#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

/**
* \class Menu
* \brief Klasa Menu, ktora tworzy menu gry.
*/
class Menu
{
public:
    /**
    * Konstruktor zawiera zmienne typu float okreslajace os wysokosc oraz szerokosc ekranu.
    * @param width zmienna typu float okreslajaca szerokosc ekranu.
    * @param height zmienna typu float okreslajaca wysokosc ekranu.
    */
    Menu(float width, float height);
    /**
    * Destruktor.
    */
    ~Menu();

    /**
    * Funkcja rysujaca okno menu.
    * @param window zmienna odwolujaca sie do okna.
    */
    void draw(sf::RenderWindow &window);

    /**
    * Funkcja pozwalajaca zaznaczyc wybrany element poruszajac sie w gore.
    */
    void MoveUp();

    /**
    * Funkcja pozwalajaca zaznaczyc wybrany element poruszajac sie w dol.
    */
    void MoveDown();

    /**
    * Funkcja pozwalajaca zaznaczyc wybrany element.
    * @return zwraca wybrany element menu.
    */
    int GetPressedItem()
    {
        return selectedItemIndex;
    }

private:
    /**
    * Zmienna sluzaca okresleniu ktory element menu zostal wybrany.
    */
    int selectedItemIndex;

    /**
    * Zmienna sluzaca do ustawienie czcionki tekstu.
    */
    sf::Font font;

    /**
    * Zmienna sluzaca do ustawienie tekstu w menu.
    */
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

