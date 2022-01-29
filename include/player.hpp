#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include "entity.hpp"
#include "platforma.hpp"

#define MAX_NUMBER_OF_ITEMS 1

/**
* \class Gracz
* \brief Klasa Gracz, ktora dziedziczy po klasie entity. Zawiera zmienne oraz metody wykorzystywane do poruszania sie postacia.
*/
class Gracz : public entity
{
private:
    /**
    * Zmienna typu bool sluzaca do powiadomienia czy postac napotkala kolizje. Jesli tak to zmienna bedzie miala wartosc true, a w przeciwnym wypadku false.
    */
    bool kolizja;
    /**
    * Zmienna typu bool sluzaca do okreslenia czy znajdujemy sie na podlodze. Jesli tak to zmienna bedzie miala wartosc true, a w przeciwnym wypadku false.
    */
    bool podloga;
    /**
    * Zmienna typu float okreslajaca szybkosc z jaka porusza sie postac.
    */
    float szybkosc;
    /**
    * Zmienna typu float okreslajaca wysokosc skoku.
    */
    float wysokoscSkoku;
    /**
    * Zmienna typu int okreslajaca ilosc krokow jaka zrobila postac.
    */
    int iloscKroku;
    /**
    * Zmienna typu int okreslajaca ilosc postoju jaka zrobila postac w prawo.
    */
    int iloscPostoju;
    /**
    * Zmienna typu int okreslajaca ilosc klatek krokow.
    */
    int klatkiKrokow;
    /**
    * Zmienna typu int okreslajaca ilosc klatek postoju w prawo.
    */
    int klatkiPostojow;
    /**
    * Zmienna typu int okreslajaca szybkosc krokow w prawo.
    */
    int szybkoscKroku;
    /**
    * Zmienna typu int okreslajaca szybkosc postoju w prawo.
    */
    int szybkoscPostoju;
    /**
    * Zmienna typu int okreslajaca ilosc spadku.
    */
    int iloscSpadek;
    /**
    * Zmienna typu int okreslajaca ilosc postoju jaka zrobila postac w lewo.
    */
    int iloscPostojuL;

    /**
    * Zmienna typu int okreslajaca ilosc klatek spadku.
    */
    int klatkiSpadek;
    /**
    * Zmienna typu int okreslajaca ilosc klatek postoju w lewo.
    */
    int klatkiPostojowL;
    /**
    * Zmienna typu int okreslajaca szybkosc spadku.
    */
    int szybkoscSpadek;
    /**
    * Zmienna typu int okreslajaca szybkosc postoju w lewo.
    */
    int szybkoscPostojuL;
    /**
    * Zmienna typu int okreslajaca szybkosc skoku.
    */
    int szybkoscSkoku;
    /**
    * Zmienna typu int okreslajaca ilosc skoku.
    */
    int iloscSkoku;
    /**
    * Zmienna typu int okreslajaca ilosc klatek skoku.
    */
    int klatkiSkoku;

public:
    /**
        * Konstruktor zawiera zmienne typu float okreslajace os X i Y, wysokosc oraz szerokosc, parametry tekstury.
        * @param X zmienna typu float okreslajaca os X.
        * @param Y zmienna typu float okreslajaca os Y.
        * @param W zmienna typu float okreslajaca szerokosc.
        * @param H zmienna typu float okreslajaca wysokosc.
        * @param t ustawia parametry tekstury.
        */
    Gracz(float X, float Y, float W, float H, sf::Texture& t);

    /**
        * Funkcja sluzy do poruszania postacia, aktualizuje jego pozycje.
        * @param A Zmienna typu bool. Jesli zostanie wcisniety klawisz A to wartosc bedzie true, w przeciwnym wypadku false.
        * @param D Zmienna typu bool. Jesli zostanie wcisniety klawisz D to wartosc bedzie true, w przeciwnym wypadku false.
        * @param W Zmienna typu bool. Jesli zostanie wcisniety klawisz W to wartosc bedzie true, w przeciwnym wypadku false.
        * @param S Zmienna typu bool. Jesli zostanie wcisniety klawisz S to wartosc bedzie true, w przeciwnym wypadku false.
        * @param level Kontener, ktory przechowuje obiekty klasy Platforma.
        */
    void aktualizacjaGracza(bool &A, bool &D,bool &W,bool &S, std::vector<Platforma>& level);

    /**
      * Funkcja sluzaca do obslugi kolizji.
      * @param xvel Zmienna typu float okreslajaca polozenie kolizji na osi X.
      * @param yvel Zmienna typu float okreslajaca polozenie kolizji na osi Y.
      * @param level Kontener, ktory przechowuje obiekty klasy Platforma.
      */
    void kolidowanie(float xvel, float yvel,std::vector<Platforma>& level);

    /**
      * Funkcja sluzaca do obslugi animacji.
      */
    void animacja();

    /**
      * Funkcja sluzaca do oblugi krokow.
      */
    void kroki();

    /**
      * Funkcja sluzaca do obslugi postojow w prawo.
      */
    void postoje();

    /**
      * Funkcja sluzaca do obslugi postojow w lewo.
      */
    void postojeL();

    /**
    * Funkcja sluzaca do obslugi skokow.
    */
    void skoki();

    /**
      * Funkcja sluzaca do obslugi spadku.
      */
    void spadek();
};
