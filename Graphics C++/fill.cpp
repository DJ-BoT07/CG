#include <iostream>
#include <graphics.h>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int x1 = 100, yB = 100, xh = 300, yh = 300; // Clipping window coordinates

int getcode(int x, int y) {
    int code = 0;
    if (y > yh)
        code |= TOP;
    if (y < yB)
        code |= BOTTOM;
    if (x < x1)
        code |= LEFT;
    if (x > xh)
        code |= RIGHT;
    return code;
}

void cohenSutherland(int x1, int yB, int x2, int y2) {
    int code1 = getcode(x1, yB);
    int code2 = getcode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut = code1 ? code1 : code2;

            int x, y;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yh - yB) / (y2 - yB);
                y = yh;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yB - yB) / (y2 - yB);
                y = yB;
            } else if (codeOut & RIGHT) {
                y = yB + (y2 - yB) * (xh - x1) / (x2 - x1);
                x = xh;
            } else if (codeOut & LEFT) {
                y = yB + (y2 - yB) * (x1 - x1) / (x2 - x1);
                x = x1;
            }

            if (codeOut == code1) {
                x1 = x;
                yB = y;
                code1 = getcode(x1, yB);
            } else {
                x2 = x;
                y2 = y;
                code2 = getcode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(RED);
        line(x1, yB, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(x1, yB, xh, yh);

    int x2 = 200, y2 = 200; // Line segment coordinates

    setcolor(YELLOW);
    line(x1, yB, x2, y2);

   cohenSutherland(x1, yB, x2, y2);

    getch();
    closegraph();
    return 0;
}
