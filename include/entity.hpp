#pragma once
#include "frameworki.hpp"
#include "hitbpx.hpp"

/**
* \class entity
* \brief Klasa entity, ktora dziedziczy klase Sprite. Zawiera cztery wektory Vector2, kontener przechowujacy obiekty klasy InRect, obiekt klasy hitBox.
*/
class entity:public sf::Sprite
{
public:
    /**
    * Wektor okreslajacy predkosc wektora.
    */
    sf::Vector2f velocity;
    /**
    * Wektor okreslajacy ilosc elementow kontenera.
    */
    sf::Vector2f size;
    /**
    * Wektor okreslajacy rozmiar postaci.
    */
    sf::Vector2f frameSize;
    /**
    * Wektor okresla ilosc klatek postaci.
    */
    sf::Vector2f framesAmount;
    /**
    * Kontener przechowujacy obiekty klasy InRect, sluzacej do manipulowania prostokatami wyrownanymi do osi 2D.
    */
    std::vector<sf::IntRect> frames;
    /**
    * Obiekt klasy hitBox.
    */
    hitBox hitbox;
};

