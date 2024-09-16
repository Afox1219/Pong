#include "Bar.h"

Bar::Bar(float StartX, float StartY)
{
	m_position.x = StartX;
	m_position.y = StartY;
	m_barshape.setSize(sf::Vector2f(60, 5));
	m_barshape.setPosition(m_position);
	
	m_barshape.setFillColor(sf::Color::Red);
	m_barshape.setOutlineColor(sf::Color::White);
	m_barshape.setOutlineThickness(3);


}

sf::FloatRect Bar::getPosition()
{
	return m_barshape.getGlobalBounds();
}

sf::RectangleShape Bar::getshape()
{
	return m_barshape;
}

void Bar::moveLeft()
{
	Movingleft = true;
}
void Bar::moveRight()
{
	MovingRight = true;
}

void Bar::stopLeft()
{
	Movingleft = false;
}
void Bar::stopRight()
{
	MovingRight = false;
}

void Bar::update(sf::Time dt)
{
	if (Movingleft)
	{
		m_position.x -= m_Speed * dt.asSeconds();
	}

	if (MovingRight)
	{
		m_position.x += m_Speed * dt.asSeconds();
	}

	m_barshape.setPosition(m_position);
}