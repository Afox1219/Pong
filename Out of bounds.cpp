#include "Out of bounds.h"

Oob::Oob(float StartX, float StartY)
{
	m_position.x = StartX;
	m_position.y = StartY;
	m_barshape.setSize(sf::Vector2f(1280, 10));
	m_barshape.setPosition(m_position);

	m_barshape.setFillColor(sf::Color::Black);
	m_barshape.setOutlineColor(sf::Color::Black);
	m_barshape.setOutlineThickness(3);
}



sf::FloatRect Oob::getPosition()
{
	return m_barshape.getGlobalBounds();
}

sf::RectangleShape Oob::getshape()
{
	return m_barshape;
}

void Oob::update(sf::Time dt)
{
	m_position.x* dt.asSeconds();
	m_position.y* dt.asSeconds();


	m_barshape.setPosition(m_position);



}
