#pragma once

/**
* \class hitBox
* \brief Klasa hitBox, ktora zawiera cztery zmienne typu float. Sluzy do okreslenia strony kolidowania z platforma.
*/
class hitBox
{
public:
    /**
    * Zmienna typu float, okreslajaca polozenie kolizji z lewej strony.
    */
    float lewo;
    /**
    * Zmienna typu float, okreslajaca polozenie kolizji z prawej strony.
    */
    float prawo;
    /**
    * Zmienna typu float, okreslajaca polozenie kolizji od gory.
    */
    float gora;
    /**
    * Zmienna typu float, okreslajaca polozenie kolizji od dolu.
    */
    float dol;
};
