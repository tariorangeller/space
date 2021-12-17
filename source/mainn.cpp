#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cmath>
#include "Header.hpp"

using namespace sf;
using namespace std;

int main()
{
    cl::Calc main_func;

    RenderWindow window(VideoMode(main_func.W, main_func.H), "My SFML WORKS!!!");
    CircleShape shape(0);
    
    Image Space;
    Space.loadFromFile("img//space.png");
    Texture SpaceTexture;
    SpaceTexture.loadFromImage(Space);
    Sprite BackGround;
    BackGround.setTexture(SpaceTexture);

    Image Earth;
    Earth.loadFromFile("img\\earth.png");
    Texture EarthTexture;
    EarthTexture.loadFromImage(Earth);

    Image Moon;
    Moon.loadFromFile("img\\moon.png");
    Texture MoonTexture;
    MoonTexture.loadFromImage(Moon);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        main_func.run();

        window.clear();

        window.draw(BackGround);

        CircleShape Earth(main_func.r1);
        shape.setOrigin(main_func.r1, main_func.r1);
        shape.setPosition(main_func.x1, main_func.y1);
        shape.setTexture(&EarthTexture);
        window.draw(shape);

        shape.setRadius(main_func.r2);
        shape.setOrigin(main_func.r2, main_func.r2);
        shape.setPosition(main_func.x2, main_func.y2);
        shape.setTexture(&MoonTexture);
        window.draw(shape);


        window.display();
        sleep(milliseconds(int(1000 / 30)));
    }
    _getch();
}