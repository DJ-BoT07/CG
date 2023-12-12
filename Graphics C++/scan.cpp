#include <iostream>
#include <graphics.h>
using namespace std;

class Point {
public:
    int x, y;
};

void drawPixel(int x, int y, int color) {
    putpixel(x, y, color);
}

void drawLine(Point p1, Point p2) {
    line(p1.x, p1.y, p2.x, p2.y);
}

void scanlineFill(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        drawPixel(x, y, fillColor);

        // Check and fill to the right
        for (int i = x + 1; getpixel(i, y) != boundaryColor && getpixel(i, y) != fillColor; i++) {
            drawPixel(i, y, fillColor);
        }

        // Check and fill to the left
        for (int i = x - 1; getpixel(i, y) != boundaryColor && getpixel(i, y) != fillColor; i--) {
            drawPixel(i, y, fillColor);
        }

        // Recursively fill the above and below scanlines
        scanlineFill(x, y + 1, fillColor, boundaryColor);
        scanlineFill(x, y - 1, fillColor, boundaryColor);
    }
}


void drawConcavePolygon(Point vertices[], int n) {
    for (int i = 0; i < n; i++) {
        drawLine(vertices[i], vertices[(i + 1) % n]);
    }
}

void fillConcavePolygon(Point vertices[], int n, int fillColor, int boundaryColor) {
    for (int y = 0; y < getmaxy(); y++) {
        bool inside = false;
        for (int x = 0; x < getmaxx(); x++) {
            if (getpixel(x, y) != boundaryColor) {
                inside = !inside;
                getch();
            }
            if (inside) {
                scanlineFill(x, y, fillColor, boundaryColor);
            }
        }
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n;
    cout << "Enter the number of vertices of the concave polygon: ";
    cin >> n;

    Point* vertices = new Point[n];

    cout << "Enter the vertices (x, y): ";
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    int fillColor, boundaryColor;
    cout << "Enter fill color: ";
    cin >> fillColor;

    cout << "Enter boundary color: ";
    cin >> boundaryColor;

    drawConcavePolygon(vertices, n);
    fillConcavePolygon(vertices, n, fillColor, boundaryColor);

    getch();
    closegraph();

    delete[] vertices;
    return 0;
}
