#include<iostream>
#include<graphics.h>
#include<process.h>

using namespace std;
void display(int n,int in[])
{   
    int pix=-60;
    for(int j=0;j<n;j++)
    {   
        char *c;
        sprintf(c,"%d",in[j]);
        pix=pix+70;
        for(int i=0;i<4;i++)
        {  
            line(pix,100,pix+50,100);
            line(pix+50,100,pix+50,150);
            line(pix+50,150,pix,150);
            line(pix,150,pix,100);
            settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
            outtextxy(pix+15,115,c);
            setfillstyle(1,RED);
            floodfill(pix+1,101,WHITE);
        }  
    }
    delay(100);
}

void bubbleSort(int n,int arr[])
{
	int i,j;
    char a[10],b[10];
    int pix=-60;
	for (i=0;i<n-1;i++)
    {
        pix=-60;
        sprintf(a,"PASS %d",i+1);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
        outtextxy(100,50,a);
        delay(500);
	    for (j=0;j<n-i-1;j++)
        {   
            pix=pix+70;
            {   
                setfillstyle(1,BLUE);
                floodfill(pix+1,101,WHITE);
                floodfill(pix+71,101,WHITE);
                delay(1000);
                if (arr[j] > arr[j + 1])
				{   
                    sprintf(b,"Swap %d & %d",arr[j],arr[j + 1]);
                    outtextxy(100,200,b);
                    delay(1000);
                    swap(arr[j], arr[j + 1]);
                    cleardevice();
                    system("cls");
                    display(n,arr);
                    delay(1000);
                }
            }
            setfillstyle(1,RED);
            floodfill(pix+1,101,WHITE);
            floodfill(pix+71,101,WHITE);
            delay(1000);
        }
    }
    display(n,arr);
    delay(1000);
    getch();
}

int main()
{

    int gd = DETECT, gm,n,j,c[10];
    initgraph(&gd, &gm, NULL);
    // initwindow(1680,1050);
    cout<<"Enter no. of elements (max 9): ";
    cin>>n;
    int in[n];
    
    for(j=0;j<n;j++)
    {   
        cout<<"Enter the element "<<j+1<<": ";
        cin>>in[j];
    }
    display(n,in);
    getch();
    bubbleSort(n,in);
    delay(1000);
    getch();
    closegraph();
    return 0;
}
