#pragma once
#include <SFML\Graphics.hpp>
class ball
{
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_ballshape;

	float m_speed = 500;
	float m_directionX = 1.0f;
	float m_directionY = 1.0f;


public:
		ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::RectangleShape getshape();

	float getXVelocity();

	void bouncesides();

	void missTop();

	void missBottom();
	
	void hitBall();

	void hitPiece();

	void update(sf::Time dt);
};

