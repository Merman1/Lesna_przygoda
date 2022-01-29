#pragma once
#include "frameworki.hpp"
#include "entity.hpp"

/**
* \class Platforma
* \brief Klasa Platforma, ktora dziedziczy klase entity. Zawiera konstruktor, ktory okresla os X i Y, wysokosc oraz szerokosc, parametry tekstury.
*/
class Platforma : public entity
{
public:
    /**
    * \brief Konstruktor zawiera zmienne typu float okreslajace os X i Y, wysokosc oraz szerokosc, parametry tekstury.
    * @param X zmienna typu float okreslajaca os X.
    * @param Y zmienna typu float okreslajaca os Y.
    * @param W zmienna typu float okreslajaca szerokosc.
    * @param H zmienna typu float okreslajaca wysokosc.
    * @param t ustawia parametry tekstury.
    */
    Platforma(float X, float Y, float W, float H,sf::Texture&  t);
};
