#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Header.hpp"

using namespace sf;

void cl::Calc::run()
{
    x1 += dx1;
    y1 += dy1;
    if ((x1 + r1 > W) || (x1 - r1 < 0)) {
        dx1 = -dx1;
    }
    if ((y1 + r1 > H) || (y1 - r1 < 0)) {
        dy1 = -dy1;
    }
    x2 += dx2;
    y2 += dy2;
    if ((x2 + r2 > W) || (x2 - r2 < 0)) {
        dx2 = -dx2;
    }
    if ((y2 + r2 > H) || (y2 - r2 < 0)) {
        dy2 = -dy2;
    }


    float Dx = x1 - x2;
    float Dy = y1 - y2;
    float d = sqrt(Dx * Dx + Dy * Dy); if (d == 0) d = 0.01;
    float s = Dx / d; // sin
    float e = Dy / d; // cos
    if (d < r1 + r2)
    {
        float Vn1 = dx2 * s + dy2 * e;
        float Vn2 = dx1 * s + dy1 * e;
        float dt = (r2 + r1 - d) / (Vn1 - Vn2);
        if (dt > 0.6) dt = 0.6;
        if (dt < -0.6) dt = -0.6;
        x1 -= dx1 * dt;
        y1 -= dy1 * dt;
        x2 -= dx2 * dt;
        y2 -= dy2 * dt;
        Dx = x1 - x2;
        Dy = y1 - y2;
        d = sqrt(Dx * Dx + Dy * Dy);
        if (d == 0) d = 0.01;
        s = Dx / d; // sin
        e = Dy / d; // cos
        Vn1 = dx2 * s + dy2 * e;
        Vn2 = dx1 * s + dy1 * e;
        float Vt1 = -dx2 * e + dy2 * s;
        float Vt2 = -dx1 * e + dy1 * s;

        float o = Vn2;
        Vn2 = Vn1;
        Vn1 = o;

        dx1 = Vn2 * s - Vt2 * e;
        dy1 = Vn2 * e + Vt2 * s;
        dx2 = Vn1 * s - Vt1 * e;
        dy2 = Vn1 * e + Vt1 * s;
        x1 += dx1 * dt;
        y1 += dy1 * dt;
        x2 += dx2 * dt;
        y2 += dy2 * dt;
    }
}