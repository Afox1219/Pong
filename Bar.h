#pragma once
#include <SFML\Graphics.hpp>
class Bar
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_barshape;

	float m_Speed = 1100.0f;

	bool Movingleft = false;
	bool MovingRight = false;

public:
	Bar(float StartX, float StartY);
	sf::RectangleShape getshape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(sf::Time dt);

};

