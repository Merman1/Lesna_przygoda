#include "include/frameworki.hpp"
#include "include/entity.hpp"
#include "include/platforma.hpp"


Platforma::Platforma(float X,float Y,float W,float H, sf::Texture& t)
{
    size.x=W;
    size.y=H;

    hitbox.lewo = X + 0.f;
    hitbox.prawo = X+ size.x -0.f;
    hitbox.gora = Y+ 0.f;
    hitbox.dol =Y + size.y - 0.f;

    setTexture(t);
    setPosition(X,Y);
}

