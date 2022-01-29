#include "include/frameworki.hpp"
#include "include/entity.hpp"
#include "include/player.hpp"
#include "include/monster.hpp"
#include "include/platforma.hpp"
#include "Menu.h"
#include "include/Opcje.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
/**
* Stala typu int okreslajaca szerokosc okna gry.
*
*/
const int szerokoscEkranu = 1920;
/**
* Stala typu int okreslajaca wysokosc okna gry
*/
const int wysokoscEkranu = 1080;
/**
* Zmienna typu float okreslajaca przyciaganie ziemskie.
*
*/
float accelGravity = 0.2f;
/**
* Zmienna typu float okreslajaca grawitacje.
*/
float maxGravity = 4.f;


/**
* \class engine
* \brief Klasa engine, ktora zawiera podstawowa funkcje potrzbna do obslugi gry, m.in. tworzenie okna, obluga klawiatury, oblsuga myszki, ustawianie tekstury.
*/
class engine
{

public:
    /**
    * Zmienna typu float sluzaca do obslugi lewego przycisku myszy.
    */
    float lewyPrzycisk;
    /**
    * Zmienna typu float sluzaca do obslugi prawego przycisku myszy.
    */
    float prawyPrzycisk;
    /**
    * Zmienna typu float sluzaca do obslugi srodkowego przycisku myszy.
    */
    float srodkowyPrzycisk;

    /**
    * Funkcja uruchamiajaca platforme gry.
    */
    void Graaa()
    {
        // Create the main window
        sf::RenderWindow window(sf::VideoMode(szerokoscEkranu,wysokoscEkranu), "Lesna przygoda");
        window.setFramerateLimit(60);
        bool W,A,S,D;
        bool I,J,K,L;
        sf::Music music2;
        music2.openFromFile("audio/Music-Box-Game-Over-2.ogg");
        music2.setVolume(100);
        music2.setLoop(true);
        music2.play();

        sf::Texture teksturaGracza;
        sf::Texture teksturaPotwora;


        sf::Texture teksturaPlatformy;
        sf::Texture teksturaPlatformy1;
        sf::Texture teksturaPlatformy2;
        sf::Texture teksturaPlatformy3;
        sf::Texture teksturaPlatformy4;
        sf::Texture teksturaPlatformy5;

        sf::Texture sciana;

        teksturaGracza.loadFromFile("assets/image/knight9.png");
        teksturaPotwora.loadFromFile("assets/image/potwor2.png");

        teksturaPlatformy.loadFromFile("assets/image/plat22.png");
        teksturaPlatformy2.loadFromFile("assets/image/plat22.png");
        teksturaPlatformy3.loadFromFile("assets/image/plat22.png");
        teksturaPlatformy1.loadFromFile("assets/image/plat12.png");
        teksturaPlatformy4.loadFromFile("assets/image/kostka1.png");

        teksturaPlatformy5.loadFromFile("assets/image/plat13.png");
        sciana.loadFromFile("assets/image/sciana2.png");

        int levelArray[10][200] =
        {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {2,2,2,2,2,2,2,2,2,0,0,0,0,2,0,2,2,0,2,2,2,0,0,2,0,2,2,0,0,2,0,2,2,2,0,6,6,0,0,0,6,6,0,6,6,0,0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

        };
        std::vector<Platforma> level;
        for(int i =0; i<10; i++)
        {
            for(int j =0; j<200; j++)
            {
                if(levelArray[i][j] == 1)
                {
                    Platforma p(j*32, i*90,32,32, teksturaPlatformy);

                    level.push_back(p);

                }
                else if(levelArray[i][j] == 2)
                {
                    Platforma p(j*96, i*83,96,96, teksturaPlatformy1);

                    level.push_back(p);
                }
                else if(levelArray[i][j] == 3)
                {
                    Platforma p(j*32, i*100,32,32, teksturaPlatformy2);

                    level.push_back(p);
                }
                else if(levelArray[i][j] == 4)
                {
                    Platforma p(j*32, i*111,32,32, teksturaPlatformy3);

                    level.push_back(p);
                }
                else if(levelArray[i][j] == 5)
                {
                    Platforma p(j*64, i*87,64,64, sciana);

                    level.push_back(p);
                }
                else if(levelArray[i][j] == 6)
                {
                    Platforma p(j*96, i*83,96,96, teksturaPlatformy5);

                    level.push_back(p);
                }
                else if(levelArray[i][j] == 7)
                {
                    Platforma p(j*32, i*104,32,32, teksturaPlatformy4);

                    level.push_back(p);
                }
            }
        }

        Gracz gracz(500,650,64,64, teksturaGracza);

        Potwor potwor(700,680,32,32, teksturaPotwora);

        sf::Texture texture;
        sf::Texture texture1;

        texture.loadFromFile("assets/image/background.jpg");


        sf::Sprite sprite(texture);
        sf::Sprite sprite1(texture1);

        sprite.setTextureRect(sf::IntRect(0, 0, 7400, 793));

        sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(1920,1080));

        view.zoom(0.3f);
        while (window.isOpen())
        {
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right )
                    window.close();
                if(event.type==Event::KeyPressed)
                {
                    if(event.key.code==Keyboard::Escape)
                    {
                        window.close();
                    }
                }
            }

            lewyPrzycisk = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            prawyPrzycisk = sf::Mouse::isButtonPressed(sf::Mouse::Right);
            srodkowyPrzycisk = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
            W = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            S = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            A = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            D = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

            I = sf::Keyboard::isKeyPressed(sf::Keyboard::L);
            K = sf::Keyboard::isKeyPressed(sf::Keyboard::J);
            J = sf::Keyboard::isKeyPressed(sf::Keyboard::I);
            L = sf::Keyboard::isKeyPressed(sf::Keyboard::K);

            gracz.aktualizacjaGracza(W,S,A,D,level);
            potwor.aktualizacjaPotwora(I, K, J, L, level);
            view.setCenter(gracz.getPosition().x + gracz.size.x/2.f,gracz.getPosition().y + gracz.size.y/8.f);
            window.setView(view);
            window.clear();
            window.draw(sprite);
            window.draw(sprite1);

            window.draw(gracz);
            window.draw(potwor);


            for(Platforma& p : level)
            {
                window.draw(p);
            }
            window.display();
        }
    }

    /**
    * Funkcja towrzaca okno opcji.
    */
    void opcjee()
    {

        sf::RenderWindow window(sf::VideoMode(szerokoscEkranu,wysokoscEkranu), "Lesna przygoda-opcje");
        RectangleShape background;
        background.setSize(Vector2f(szerokoscEkranu,wysokoscEkranu));
        sf::Texture t;
        t.loadFromFile("assets/image/tol.png");
        sf::Sprite s(t);

        background.setTexture(&t);
        Opcje opcje(window.getSize().x, window.getSize().y);

        sf::Music music;
        music.openFromFile("audio/final_bell.ogg");
        music.setVolume(50);
        music.play();

        while (window.isOpen())
        {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));
            while (window.pollEvent(event))
            {
                if(event.type==Event::Closed)
                {
                    window.close();
                }

                //KLAWIATURA
                if(event.type==Event::KeyReleased )
                {
                    if(event.key.code==Keyboard::Up)
                    {
                        opcje.MoveUp();
                        break;
                    }
                    if(event.key.code==Keyboard::Down)
                    {
                        opcje.MoveDown();
                        break;
                    }

                    if(event.key.code==Keyboard::Return )
                    {

                        int x=opcje.GetPressedItem();
                        if(x==0)
                        {
                            music.play();
                        }
                        if(x==1)
                        {
                            music.stop();
                        }
                        if(x==2)
                            window.close();
                        break;
                    }
                }
            }

            window.clear();
            window.draw(background);
            opcje.draw(window);
            window.display();
        }
    }

    /**
    * Funkcja tworzaca glowne okno oraz obluguje glowne menu.
    */
    void menii()
    {


        sf::RenderWindow window(sf::VideoMode(szerokoscEkranu,wysokoscEkranu), "Lesna przygoda");
        RectangleShape background;
        background.setSize(Vector2f(szerokoscEkranu,wysokoscEkranu));
        sf::Texture t;
        t.loadFromFile("assets/image/dark.jpg");
        sf::Sprite s(t);

        background.setTexture(&t);
        Menu menu(window.getSize().x, window.getSize().y);

        sf::Music music;
        music.openFromFile("audio/final_bell.ogg");
        music.setVolume(50);
        music.play();

        while (window.isOpen())
        {
            Event event;
            Vector2f mouse(Mouse::getPosition(window));
            while (window.pollEvent(event))
            {
                if(event.type==Event::Closed)
                {
                    window.close();
                }

                //KLAWIATURA
                if(event.type==Event::KeyReleased )
                {
                    if(event.key.code==Keyboard::Up)
                    {
                        menu.MoveUp();
                        break;
                    }
                    if(event.key.code==Keyboard::Down)
                    {
                        menu.MoveDown();
                        break;
                    }

                    if(event.key.code==Keyboard::Return )
                    {

                        int x=menu.GetPressedItem();
                        if(x==0)
                        {
                            music.stop();
                            Graaa();
                        }
                        if(x==1)
                        {
                            //window.close();
                            music.stop();
                            opcjee();
                        }
                        if(x==2)
                            window.close();
                        break;
                    }
                }
            }
            window.clear();
            window.draw(background);
            menu.draw(window);
            window.display();
        }
    }

};

int main()
{
    engine start;
    start.menii();
}

