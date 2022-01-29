#include "include/frameworki.hpp"
#include "include/entity.hpp"
#include "include/monster.hpp"
#include "include/platforma.hpp"
#include <iostream>


extern float accelGravity;
extern float maxGravity;

int counter;

Potwor::Potwor(float X,float Y,float W,float H,sf::Texture& t)
{
    szybkosc = 1.f;
    wysokoscSkoku=4.f;

    size.x=W;
    size.y=H;

    iloscKroku = 0;
    iloscPostojuL=0;
    iloscPostoju = 0;
    iloscSkoku=0;
    klatkiKrokow = 0;
    klatkiPostojow =5;
    klatkiPostojowL =5;
    klatkiSkoku =0;

    szybkoscPostojuL=8;
    szybkoscKroku =6;
    szybkoscPostoju =8;
    szybkoscSkoku=6;

    frameSize.x = 32;
    frameSize.y = 32;

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

void Potwor::aktualizacjaPotwora(bool &J, bool &L,bool &K,bool &I, std::vector<Platforma>&level)
{
    if(velocity.x < 1.f)
    {
        if(counter < 100)
        {
            velocity.x=1.f;
        }
        if(counter>100 && counter < 200)
        {
            velocity.x=-1.f;
        }
        counter++;
        if(counter>200)
            counter=0;
        move(velocity.x*szybkosc,0);
        kolidowanie(velocity.x,0, level);
        postoje();
    }

    if(K and podloga)
    {
        velocity.y=wysokoscSkoku* -1;
    }
    if(podloga == false)
    {
        velocity.y += accelGravity;
        if(velocity.y > maxGravity) velocity.y = maxGravity;
    }
    if(J)
    {
        velocity.x=2.f;
        postoje();
    }
    else  if(L)
    {
        velocity.x=-2.f;
        postojeL();
    }
    else if(K)
    {
        skoki();
    }
    else kroki();
    if(!(J || L)) velocity.x = 0.f;

    move(velocity.x*szybkosc,0);
    kolidowanie(velocity.x,0, level);

    podloga=false;

    move(0,velocity.y);
    kolidowanie(0,velocity.y,level);
    //animacja();
}

void Potwor::kolidowanie(float xvel, float yvel, std::vector<Platforma>&level)
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

void Potwor::kroki()
{
    for(int i = 0; i< klatkiKrokow; i++)
        if(iloscKroku == (i+1) * szybkoscKroku)
            setTextureRect(frames[i]);
    if(iloscKroku == klatkiKrokow * szybkoscKroku)
        iloscKroku = 0;
    iloscKroku++;
}

void Potwor::postoje()
{
    for(int i = 0; i< klatkiPostojow; i++)
        if(iloscPostoju == (i+1) * szybkoscPostoju)
            setTextureRect(frames[i+klatkiKrokow]);
    if(iloscPostoju == klatkiPostojow * szybkoscPostoju)
        iloscPostoju = 0;
    iloscPostoju++;
}

void Potwor::postojeL()
{
    for(int i = 0; i< klatkiPostojowL; i++)
        if(iloscPostojuL == (i+1) * szybkoscPostojuL)
            setTextureRect(frames[i+klatkiKrokow+klatkiPostojow]);
    if(iloscPostojuL == klatkiPostojowL * szybkoscPostojuL)
        iloscPostojuL = 0;
    iloscPostojuL++;
}

void Potwor::skoki()
{
    for(int i = 0; i< klatkiSkoku; i++)
        if(iloscSkoku == (i+1) * szybkoscSkoku)
            setTextureRect(frames[i+klatkiKrokow+klatkiPostojow+klatkiPostojowL]);
    if(iloscSkoku == klatkiSkoku * szybkoscSkoku)
        iloscSkoku = 0;
    iloscSkoku++;
}
