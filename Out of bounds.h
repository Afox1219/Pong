#pragma once
#include <SFML\Graphics.hpp>
class Oob
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_barshape;

public:
	Oob(float StartX, float StartY);
	sf::RectangleShape getshape();
	sf::FloatRect getPosition();
	void update(sf::Time dt);

	
};