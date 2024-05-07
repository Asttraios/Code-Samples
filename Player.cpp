#include "Headers/Player.h"
#include <iostream>

Player::Player(float x, float y) : playerSpeed(0.1f)
{

    Milano.setPosition(x, y);       //ustawienie pozycji
    playerTexture.loadFromFile("playspaceship.png");    //wgranie tekstury
    Milano.setTexture(playerTexture);       //ustawienie tekstury
}

Player::~Player()
{
    std::cout << "Gracz zniszczony";    //
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        Milano.move(-playerSpeed, 0.0f);        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Milano.move(playerSpeed, 0.0f);
    }
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(Milano);
}

sf::Vector2f Player::getPosition()
{
    return Milano.getPosition();
}

sf::Sprite &Player::getPlayerShape()
{
    return Milano;
}