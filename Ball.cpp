#include "Ball.h"

ball::ball(float StartX, float StartY)
{
	m_position.x = StartX;
	m_position.y = StartY;
	
	m_ballshape.setSize(sf::Vector2f(10, 10));
	m_ballshape.setPosition(m_position);
}



sf::FloatRect ball::getPosition()
{
	return m_ballshape.getGlobalBounds();
}

sf::RectangleShape ball::getshape()
{
	return m_ballshape;
}

float ball::getXVelocity()
{
	return m_directionX;
}

void ball::bouncesides()
{
	m_directionX = -m_directionX;
}

void ball::missTop()
{
	m_position.x = 1280 / 2;
	m_position.y = 720 / 2;
}

void ball::missBottom()
{
	m_position.x = 1280 / 2;
	m_position.y = 720 / 2;


}
void ball::hitBall()
{
	m_directionY = -m_directionY;
}

void ball::hitPiece() 
{
	m_directionY = -m_directionY;
}


void ball::update(sf::Time dt)
{
	m_position.x += m_directionX * m_speed * dt.asSeconds();
	m_position.y += m_directionY * m_speed * dt.asSeconds();


	m_ballshape.setPosition(m_position);



}