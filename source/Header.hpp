#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>   //коорд центра
#include <cmath>      //движение по коорд

namespace cl
{
    class Calc
    {
    public:
        const int W = 640;
        const int H = 480;

        float x1 = W / 4;
        float y1 = H / 2;
        float x2 = W / 4 * 3;
        float y2 = H / 2;
        float r1 = 50;
        float r2 = 50;
        float dx1 = rand() % 10;
        float dy1 = rand() % 10;
        float dx2 = rand() % 10;
        float dy2 = rand() % 10;
        sf::Color col1 = sf::Color(255, 0, 255);
        sf::Color col2 = sf::Color(255, 255, 0);

        void run();
    };
}