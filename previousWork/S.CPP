#include<stdlib.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int main()
{
    int gd = DETECT, gm;
    int P[2][2], T[2][2];
    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
    cout<<"Program to implement the scaling of objects\n";
    cout<<"Enter the co-ordinates of rectangle in (x1,y1,x2,y2) order\n";
    for( int i = 0; i <2; i++)
	{
		for(int j = 0; j<2; j++)
			{
				cin>>P[i][j];
			}
	}
     setcolor(5);
     rectangle (P[0][0], P[0][1], P[1][0], P[1][1]);
     delay(370);
     cout<<"Enter the scaling factor:\n ( please enter second and third value as 0) \n";
	 for( i = 0; i <2; i++)
	{
		for(int j = 0; j<2; j++)
			{
				cin>>T[i][j];
			}
	}
    P[0][0] = P[0][0] * T[0][0];
    P[0][1] = P[0][1] * T[1][1];
    P[1][0] = P[1][0] * T[0][0];
    P[1][1] = P[1][1] * T[1][1];
    cout<<"the new rectangle is:";
    setcolor(5);
    rectangle (P[0][0], P[0][1], P[1][0], P[1][1]);
    delay(400);
     closegraph();
     getch();
     return 0;
}