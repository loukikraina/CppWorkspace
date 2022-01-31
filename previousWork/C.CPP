#include<stdlib.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void translate( int P[2][2], int T[2])
{
    rectangle (P[0][0], P[0][1], P[1][0], P[1][1]);
    delay(270);
    setcolor (YELLOW);
    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];
    setcolor(GREEN);
    rectangle (P[0][0], P[0][1], P[1][0], P[1][1]);
    delay(270);
}
int main()
{
    int gd = DETECT, gm, errorcode;
    int P[2][2], T[2];
    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
    cout<<"Program to implement the translation of objects";
    cout<<"Enter the co-ordinates of rectangle in (x1,y1,x2,y2) order";
    for( int i = 0; i <2; i++)
	{
		for(int j = 0; j<2; j++)
			{
				cin>>P[i][j];
			}
	}
    cout<<"Enter the translation factor:";
    for(int j = 0; j<2; j++)
			{
				cin>>T[j];
			}
     translate(P,T);
     closegraph();
     getch();
     return 0;
} 