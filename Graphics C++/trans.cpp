#include<iostream>
#include<graphics.h>
#include<math.h>
#include<cmath> // Add this line to include the <cmath> header
using namespace std;

float pro[3] = {0,0,0};

void multi(float M1[], float M2[][3]){
    pro[0] = 0;
    pro[1] = 0;
    pro[2] = 0;

    for(int i  = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++){
            pro[i] = pro[i] + M1[j] * M2[j][i];
        }
    }
}

int main(){
    int gd = DETECT, gm;

    int ch;
    cout<<"1.Translate \n 2.Rotate \n 3.Scaling "<<endl;
    cout<<"Enter the choice: "<<endl;
    cin>>ch;

    float p1[3] = {5,8,1};
    float p2[3] = {100,164,1};

    float Tm[3][3] = {0};

    switch(ch){
    case 1:
        cout<<"Enter the Value of tx and ty : "<<endl;
        float tx,ty,x1,y1;
        cin>>tx>>ty;
        Tm[0][0] = 1;
        Tm[1][1] = 1;
        Tm[2][2] = 1;
        Tm[2][0] = tx;
        Tm[2][1] = ty;
        initgraph(&gd,&gm,NULL);

        line(5,8,100,164);

        multi(p1,Tm);


        x1 = pro[0];
        y1 = pro[1];

        multi(p2,Tm);
        setcolor(9);
        line(int(x1),int(y1),int(pro[0]),int(pro[1]));
        break;
    case 2:
        cout<<"Enter value of Theta : "<<endl;
        float th,sinA,cosA;
        cin>>th;
        sinA = sin(th);
        cosA = cos(th);

        Tm[0][0] = cosA;
        Tm[0][1] = -sinA;
        Tm[1][0] =  sinA;
        Tm[1][1] = cosA;
        Tm[2][2] = 1;
        
        initgraph(&gd,&gm,NULL);

        line(5,8,100,164);

        multi(p1,Tm);


        x1 = pro[0];
        y1 = pro[1];

        multi(p2,Tm);
        setcolor(9);
        line(int(x1),int(y1),int(pro[0]),int(pro[1]));
        break;
    case 3:
        cout<<"Enter the Value of sx and sy : "<<endl;
        float sx,sy;
        cin>>sx>>sy;
        Tm[0][0] = sx;
        Tm[1][1] = sy;
        Tm[2][2] = 1;
        initgraph(&gd,&gm,NULL);

        line(5,8,100,164);

        multi(p1,Tm);


        x1 = pro[0];
        y1 = pro[1];

        multi(p2,Tm);
        setcolor(9);
        line(int(x1),int(y1),int(pro[0]),int(pro[1]));
        break;
    default:
        cout<<"INvalid Input"<<endl;
    }
    delay(10000);
    closegraph();
    return 0;
}
