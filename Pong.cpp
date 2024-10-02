// Snake game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <conio.h> 
#include <iostream> 
#define NOMINMAX
#include <windows.h>
#include "SFML\Graphics.hpp"
#include "SFML\Graphics\Font.hpp"
#include "ball.h"
#include"Bar.h"
#include "Out of bounds.h"
#include <sstream>
void init() 
{
    
}

int main()
{
    sf::Vector2f viewsize(1280, 720);
    sf::VideoMode vm(viewsize.x, viewsize.y);
    sf::RenderWindow window(vm, "ping pong!");
    sf::Clock clock;
    ball myball(1280/2, 720/ 2);
    Bar myBar(1280/ 2, 700);
    Bar myBar2(1280 / 2, 30);
    Oob OutB(0,10);
    Oob OutB2(0, 710);
    sf::Time dt;
    sf::Event event;
    sf::Font font;
    font.loadFromFile("pixel.ttf");
    
    sf::Text fontHud;
    fontHud.setFont(font);
    fontHud.setPosition(100, 5);
    fontHud.setCharacterSize(30);
    fontHud.setOutlineThickness(2);
    fontHud.setOutlineColor(sf::Color::White);
    fontHud.setFillColor(sf::Color::Green);

    int lives = 3;
    std::stringstream ss;
    ss << "Lives: " << lives;

    fontHud.setString(ss.str());

    sf::Text qfontHud;
    qfontHud.setFont(font);
    qfontHud.setPosition(1100, 680);
    qfontHud.setCharacterSize(30);
    qfontHud.setOutlineThickness(2);
    qfontHud.setOutlineColor(sf::Color::White);
    qfontHud.setFillColor(sf::Color::Green);

    int qlives = 3;
    std::stringstream qss;
    qss << "Lives: " << qlives;

    fontHud.setString(ss.str());
    qfontHud.setString(qss.str());

    float bounce_timer = 0.10;

    

    while (window.isOpen())
    {

        dt = clock.restart();
        bounce_timer -= dt.asSeconds();


        if (myball.getPosition().intersects(myBar.getPosition()))
        {
            if (bounce_timer < 0)
            {
                myball.hitBall();
                bounce_timer = 0.10f;
            }
        }

        if (myball.getPosition().intersects(myBar2.getPosition()))
        {
            if (bounce_timer < 0)
            {
                myball.hitBall();
                bounce_timer = 0.10f;
            }
        }

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }


        if (myball.getPosition().left < 0 || myball.getPosition().left + myball.getPosition().width > 1280)
            
            if (bounce_timer < 0) 
            {
                myball.bouncesides();
                bounce_timer = 0.10f;
            }
    
        if (myball.getPosition().top < 0 && bounce_timer < 0)
        {
            myball.missBottom();
            
        }

        if (myball.getPosition().top + myball.getPosition().height > 720)
        {
            myball.missBottom();
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            myBar.moveLeft();
        }
        else
        {
            myBar.stopLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            myBar2.moveLeft();
        }
        else
        {
            myBar2.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            myBar.moveRight();
        }
        else
        {
            myBar.stopRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            myBar2.moveRight();
        }
        else
        {
            myBar2.stopRight();
        }
    
    
        window.clear();
        
        myball.update(dt);
        myBar.update(dt);
        myBar2.update(dt);
        OutB.update(dt);
        OutB2.update(dt);

        window.draw(myball.getshape());
        window.draw(myBar.getshape());
        window.draw(myBar2.getshape());
        window.draw(OutB.getshape());
        window.draw(OutB2.getshape());
        window.draw(fontHud);
        window.draw(qfontHud);

        window.display();
    }

            

    return 0;
}