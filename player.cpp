#include "include/frameworki.hpp"
#include "include/entity.hpp"
#include "include/player.hpp"
#include "include/platforma.hpp"
#include <iostream>
#include "Menu.h"

extern float accelGravity;
extern float maxGravity;

Gracz::Gracz(float X,float Y,float W,float H,sf::Texture& t)
{
    szybkosc = 2.f;
    wysokoscSkoku=4.f;

    size.x=W;
    size.y=H;

    iloscKroku = 0;
    iloscPostojuL=0;
    iloscPostoju = 5;
    iloscSkoku=0;
    klatkiKrokow = 5;
    klatkiPostojow =7;
    klatkiPostojowL =7;
    klatkiSkoku =5;

    szybkoscPostojuL=6;
    szybkoscKroku =6;
    szybkoscPostoju =6;
    szybkoscSkoku=6;

    frameSize.x = 64;
    frameSize.y = 64;

    framesAmount.x = t.getSize().x/frameSize.x;
    framesAmount.y=t.getSize().y/frameSize.y;

    for(int y=0; y<framesAmount.y; y++)
    {
        for(int x = 0; x< framesAmount.x; x++)
        {
            sf::IntRect frame(x* frameSize.x, y* frameSize.y, frameSize.x, frameSize.y);
            frames.push_back(frame);
        }
    }
    setTextureRect(frames[0]);
    setTexture(t);
    setPosition(X,Y);
}

void Gracz::aktualizacjaGracza(bool &A, bool &D,bool &S,bool &W, std::vector<Platforma>&level)
{
    if(S and podloga)
    {
        velocity.y=wysokoscSkoku* -1;
    }
    if(podloga == false)
    {
        velocity.y += accelGravity;
        if(velocity.y > maxGravity) velocity.y = maxGravity;
    }
    if(A)
    {
        velocity.x=2.f;
        postoje();
    }
    else  if(D)
    {
        velocity.x=-2.f;
        postojeL();
    }
    else if(S)
    {
        skoki();
    }
    else kroki();
    if(!(A || D)) velocity.x = 0.f;

    move(velocity.x*szybkosc,0);
    kolidowanie(velocity.x,0, level);

    podloga=false;

    move(0,velocity.y);
    kolidowanie(0,velocity.y,level);

}

void Gracz::kolidowanie(float xvel, float yvel, std::vector<Platforma>&level)
{
    for(Platforma& p: level)
    {
        if(getPosition().x + 7.f  < p.hitbox.prawo  &&
                getPosition().x + size.x - 13.f  > p.hitbox.lewo   &&
                getPosition().y + 8.f < p.hitbox.dol &&
                getPosition().y + -8.f + size.y > p.hitbox.gora)
        {
            kolizja = true;
        }
        else
        {
            kolizja = false;
        }
        if(getPosition().y >900)
        {
            std::cout<<"PONIOSLES SMIERC!";
            exit(0);
            {

            }
        }
        if(kolizja)
        {
            if(xvel > 0)
            {
                setPosition(p.hitbox.lewo - size.x + 13.f, getPosition().y);
                velocity.x = 0.f;
            }
            if(xvel < 0)
            {
                setPosition(p.hitbox.prawo - 7.f, getPosition().y);
                velocity.x = 0.f;
            }
            if(yvel > 0)
            {
                setPosition(getPosition().x, p.hitbox.gora - size.y + 8.f);
                velocity.y = 0.f;
                podloga=true;
            }
            if(yvel < 0)
            {
                setPosition(getPosition().x, p.hitbox.dol - 0.f);
                velocity.y = 0.f;
            }
        }
    }
}

void Gracz::animacja()
{
    if(abs(velocity.x) > 0)
    {
        postoje();
    }
    else if(abs(velocity.x) == 0)
        kroki();
    else
        postojeL();

}

void Gracz::kroki()
{
    for(int i = 0; i< klatkiKrokow; i++)
        if(iloscKroku == (i+1) * szybkoscKroku)
            setTextureRect(frames[i]);
    if(iloscKroku == klatkiKrokow * szybkoscKroku)
        iloscKroku = 0;
    iloscKroku++;
}

void Gracz::postoje()
{
    for(int i = 0; i< klatkiPostojow; i++)
        if(iloscPostoju == (i+1) * szybkoscPostoju)
            setTextureRect(frames[i+klatkiKrokow]);
    if(iloscPostoju == klatkiPostojow * szybkoscPostoju)
        iloscPostoju = 0;
    iloscPostoju++;
}

void Gracz::postojeL()
{
    for(int i = 0; i< klatkiPostojowL; i++)
        if(iloscPostojuL == (i+1) * szybkoscPostojuL)
            setTextureRect(frames[i+klatkiKrokow+klatkiPostojow]);
    if(iloscPostojuL == klatkiPostojowL * szybkoscPostojuL)
        iloscPostojuL = 0;
    iloscPostojuL++;
}

void Gracz::skoki()
{
    for(int i = 0; i< klatkiSkoku; i++)
        if(iloscSkoku == (i+1) * szybkoscSkoku)
            setTextureRect(frames[i+klatkiKrokow+klatkiPostojow+klatkiPostojowL]);
    if(iloscSkoku == klatkiSkoku * szybkoscSkoku)
        iloscSkoku = 0;
    iloscSkoku++;
}

