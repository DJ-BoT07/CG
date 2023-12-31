#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    float edge[4][4] = {{100, 10, 200, 300},
                        {200, 300, 100, 250},
                        {100, 250, 0, 300},
                        {0, 300, 100, 10}};
    int i, m, n, k;
    int intr[5];
    float c;

    for (int i = 0; i < 4; i++)
    {
        line(edge[i][0], edge[i][1], edge[i][2], edge[i][3]);
    }
    int ymax = edge[0][1];
    int ymin = edge[0][1];
    for (int i = 0; i < 4; i++)
    {
        if (ymax < edge[i][1])
            ymax = edge[i][1];
        if (ymax < edge[i][3])
            ymax = edge[i][3];
        if (ymin < edge[i][1])
            ymin = edge[i][1];
        if (ymin < edge[i][3])
            ymin = edge[i][3];
    }

    for (int i = 0; i < 4; i++)
    {
        if (edge[i][1] > edge[i][3])
        {
            float ty = edge[i][1];
            edge[i][1] = edge[i][3];
            edge[i][3] = ty;
            float tx = edge[0][0];
            edge[0][0] = edge[0][2];
            edge[0][2] = tx;
        }
    }

    int y;
    for (y = ymax - 1; y > ymin; y--)
    {
       c = 0;
        for (i = 0; i < 4; i++)
        {
            if (y > edge[i][1] && y < edge[i][3])
            {
                float x = ((y - edge[i][3]) * (edge[i][0] - edge[i][2])) / (edge[i][1] - edge[i][3]) + edge[i][2];
                intr[c] = x;
                c++;
            }
        }
    }
}