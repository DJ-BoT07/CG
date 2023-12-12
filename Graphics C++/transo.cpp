#include<iostream>
#include<graphics.h>
#include<math.h>
#include<cmath> // Add this line to include the <cmath> header
using namespace std;

class Matrix {
public:
    float data[3];

    Matrix operator*(const float M2[][3]) const {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            result.data[i] = 0;
            for (int j = 0; j < 3; j++) {
                result.data[i] += data[j] * M2[j][i];
            }
        }
        return result;
    }
};

int main() {
    int gd = DETECT, gm;

    int ch;
    cout << "1.Translate \n 2.Rotate \n 3.Scaling " << endl;
    cout << "Enter the choice: " << endl;
    cin >> ch;

    Matrix p1 = {5, 8, 1};
    Matrix p2 = {100, 164, 1};

    float Tm[3][3] = {0};

    switch(ch) {
    case 1: {
        cout << "Enter the Value of tx and ty : " << endl;
        float tx, ty;
        cin >> tx >> ty;
        Tm[0][0] = 1;
        Tm[1][1] = 1;
        Tm[2][2] = 1;
        Tm[2][0] = tx;
        Tm[2][1] = ty;
        initgraph(&gd, &gm, NULL);

        line(5, 8, 100, 164);

        Matrix result1 = p1 * Tm;
        float x1 = result1.data[0] / result1.data[2];
        float y1 = result1.data[1] / result1.data[2];

        Matrix result2 = p2 * Tm;
        setcolor(9);
        line(int(x1), int(y1), int(result2.data[0] / result2.data[2]), int(result2.data[1] / result2.data[2]));
        break;
    }
    case 2: {
        cout << "Enter value of Theta : " << endl;
        float th, sinA, cosA;
        cin >> th;
        sinA = sin(th);
        cosA = cos(th);

        Tm[0][0] = cosA;
        Tm[0][1] = -sinA;
        Tm[1][0] =  sinA;
        Tm[1][1] = cosA;
        Tm[2][2] = 1;

        initgraph(&gd, &gm, NULL);

        line(5, 8, 100, 164);

        Matrix result1 = p1 * Tm;
        float x1 = result1.data[0] / result1.data[2];
        float y1 = result1.data[1] / result1.data[2];

        Matrix result2 = p2 * Tm;
        setcolor(9);
        line(int(x1), int(y1), int(result2.data[0] / result2.data[2]), int(result2.data[1] / result2.data[2]));
        break;
    }
    case 3: {
        cout << "Enter the Value of sx and sy : " << endl;
        float sx, sy;
        cin >> sx >> sy;
        Tm[0][0] = sx;
        Tm[1][1] = sy;
        Tm[2][2] = 1;
        initgraph(&gd, &gm, NULL);

        line(5, 8, 100, 164);

        Matrix result1 = p1 * Tm;
        float x1 = result1.data[0] / result1.data[2];
        float y1 = result1.data[1] / result1.data[2];

        Matrix result2 = p2 * Tm;
        setcolor(9);
        line(int(x1), int(y1), int(result2.data[0] / result2.data[2]), int(result2.data[1] / result2.data[2]));
        break;
    }
    default:
        cout << "Invalid Input" << endl;
    }
    getch();
    closegraph();
    return 0;
}
