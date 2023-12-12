#include <iostream>
#include <graphics.h>

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
const int X_MIN = 50, Y_MIN = 50, X_MAX = 300, Y_MAX = 200;

int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < X_MIN) code |= LEFT;
    else if (x > X_MAX) code |= RIGHT;
    if (y < Y_MIN) code |= BOTTOM;
    else if (y > Y_MAX) code |= TOP;
    return code;
}

void cohenSutherlandClip(double &x1, double &y1, double &x2, double &y2) {
    int code1 = computeCode(x1, y1), code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) { accept = true; break; }
        else if (code1 & code2) break;
        else {
            int codeOut = code1 ? code1 : code2;
            double x, y;

            if (codeOut & TOP) x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1), y = Y_MAX;
            else if (codeOut & BOTTOM) x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1), y = Y_MIN;
            else if (codeOut & RIGHT) y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1), x = X_MAX;
            else if (codeOut & LEFT) y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1), x = X_MIN;

            if (codeOut == code1) x1 = x, y1 = y, code1 = computeCode(x1, y1);
            else x2 = x, y2 = y, code2 = computeCode(x2, y2);
        }
    }

    if (accept) { setcolor(RED); line(x1, y1, x2, y2); }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    double x1 = 30, y1 = 40, x2 = 300, y2 = 200;  // Create variables
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

