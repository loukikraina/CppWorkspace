#include<stdlib.h>
#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)
int main()
{
    int gd = DETECT, gm;
    int P[2][2],a,Q[2][2];
    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
    cout<<"Program to implement the rotation of objects\n";
    cout<<"Enter the co-ordinates of line in (x1,y1,x2,y2) order\n";
     for( int i = 0; i <2; i++)
	{
		for(int j = 0; j<2; j++)
			{
				cin>>P[i][j];
			}
	}
      setcolor(5);
     line (P[0][0], P[0][1], P[1][0], P[1][1]);
     delay(400);
     cout<<"Enter the Rotation Angle:\n (anticlockwise rotation = positive angle and clockwise rotation = negative angle) \n";
     cin>>a;
    Q[0][0] = P[0][0] * COS(a) + P[0][1]*SIN(a);
    Q[0][1] = P[0][0] * -SIN(a) + P[0][1]*COS(a) ;
    Q[1][0] = P[1][0] * COS(a)  + P[1][1]*SIN(a);
    Q[1][1] = -P[1][0] * SIN(a) + P[1][1]*COS(a) ;
    setcolor(2);
     line (Q[0][0], Q[0][1], Q[1][0], Q[1][1]);
     delay(400);
     closegraph();
     getch();
     return 0;
}