#include "Headers/Invaders.h"

Invaders::Invaders(float x, float y, float movementSpeed)
{
    InvaderShip.setSize(sf::Vector2f(50.0f, 50.0f));        //statek rozmiaru 50x50 
    InvaderShip.setPosition(x, y);    
      //ustawienie pozycji- funkcja wbudowana sfml
    InvaderTexture.loadFromFile("invader2.png");
    InvaderShip.setTexture(&InvaderTexture);
    this->movementSpeed = movementSpeed;
    movingRight = true;
}

void Invaders::refreshInvader()
{
    if (movingRight)
    {
        InvaderShip.move(movementSpeed, 0.0f);
    }
    else
    {
        InvaderShip.move(-movementSpeed, 0.0f);
    }
}

void Invaders::invaderRender(sf::RenderWindow &window) const
{
    window.draw(InvaderShip);
}

void Invaders::changeDirection()
{
    movingRight = !movingRight;
}

sf::RectangleShape &Invaders::getShape()
{
    return InvaderShip;
}
