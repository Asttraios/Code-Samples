#include "Headers/LaserBeam.h"

LaserBeam::LaserBeam(float Sx, float Sy)
{
    bullet.setSize(sf::Vector2f(10, 30));
    bullet.setFillColor(sf::Color::Yellow);
    bullet.setPosition(Sx, Sy);
}

void LaserBeam::updatePlayerBeam()
{

    bullet.move(0.0f, -0.2f);
}

void LaserBeam::updateInvadersBeam()
{
    bullet.move(0.0f, 0.2f);
}

void LaserBeam::beamRender(sf::RenderWindow &window)
{
    window.draw(bullet);
}

sf::RectangleShape &LaserBeam::getShape()
{
    return bullet;
}
