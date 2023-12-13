#include <iostream>
#include <graphics.h>
#include <cmath> // Include <cmath> for abs() function
using namespace std;

int sign(int t)
{
    if (t > 0)
        return 1;
    else if (t == 0)
        return 0;
    else
        return -1;
}
void ddaline(int x1, int y1, int x2, int y2, int col = 1)
{
    int x, y, len, i;
    float dx, dy;

    if (x1 == x2 && y1 == y2)
    {
        putpixel(x1, y1, col);
    }
    else
    {
        dx = abs(x2 - x1);
        dy = abs(y2 - y1);
        if (dx > dy) /* |dx| > |dy| */
        {
            len = dx;
        }
        else
        {
            len = dy;
        }

        dx = (x2 - x1) / len;
        dy = (y2 - y1) / len;
        x = x + 0.5 * sign(dx);
        y = y + 0.5 * sign(dy);
        i = 1;
        while (i < len)
        {
            putpixel(x, y, col);
            x = x + (dx);
            y = y + dy;
            i++;
        }
    }
}

void bbline(int x1, int y1, int x2, int y2, int col = 1)
{
    int dx, dy, e, x, y, i = 1;
    dx = x2 - x1;
    dy = y2 - y1;
    x = x1;
    y = y1;
    e = 2 * dy - dx;

    while (i <= dx)
    {
        while (e >= 0)
        {
            y++;
            e = e - 2 * dx;
        }

        x++;
        e = e + 2 * dy;
        putpixel(x, y, col);
        i++;
    }
}
void drawcircle(int xc, int yc, int r)
{
    long d, x, y;
    x = 0;
    y = r;
    d = 3 - 2 * r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, 9);
        putpixel(xc - x, yc + y, 9);
        putpixel(xc + x, yc - y, 9);
        putpixel(xc - x, yc - y, 9);
        putpixel(xc + y, yc + x, 9);
        putpixel(xc - y, yc + x, 9);
        putpixel(xc + y, yc - x, 9);
        putpixel(xc - y, yc - x, 9);
        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    ddaline(0, 0, 300, 0);
    ddaline(0, 0, 0, 200);
    ddaline(0, 200, 300, 200);
    ddaline(300, 0, 300, 200);

    ddaline(150, 0, 0, 100);
    ddaline(0, 100, 150, 200);
    ddaline(150, 200, 300, 100);
    ddaline(150, 0, 300, 100);

    drawcircle(150, 100, 84);
    delay(10000);
    closegraph();
    return 0;
}