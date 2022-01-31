#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<ctype.h>
#include<math.h>
#include<dos.h>



void Drawcircle(int x1, int y1,int rx,int ry)
{
     float x = 0;
     float y = ry;
     float ry2=pow(ry,2),rx2=pow(rx,2);
     float p = ry2-(rx2*ry)+((0.25)*rx2);
     //  region 1:-
    while(((2*ry2*x)<(2*rx2*y)))
    {
	putpixel(x1 + x, y1 + y, WHITE);
	delay(5);
	putpixel(x1 + x, y1 - y, WHITE);
	delay(5);
	putpixel(x1 - x, y1 - y, WHITE);
	delay(5);
	putpixel(x1 - x, y1 + y, WHITE);
	delay(5);
	x=x+1;
	if (p<0)
	{
		y=y;
		p = p+(2*ry2*x)+ry2;
	}
	else
	{
		y = y-1;
		p = p + (2*ry2*x) -(2*rx2*y) + ry2;
	}
    }
    p=ry2*(pow((x+(0.5)),2)) + rx2*(pow((y-1),2)) -rx2*ry2;
    while(y>=0)
    {
	putpixel(x1 + x, y1 + y, WHITE);
	delay(5);
	putpixel(x1 + x, y1 - y, WHITE);
	delay(5);
	putpixel(x1 - x, y1 - y, WHITE);
	delay(5);
	putpixel(x1 - x, y1 + y, WHITE);
	delay(5);
	y=y-1;
	if(p>0)
	{
		x=x;
		p=p - 2*rx2*y + rx2;
	}
	else
	{
		x+=1;
		p=p+ 2*ry2*x - 2*rx2*y + rx2;
	}
    }
}

void main()
{
    clrscr();
    int x1,y1,rx,ry;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cleardevice();
    cout<< "Enter the centre of the ellipse --- >\n";
    cin>>x1>>y1;
    cout<<"enter the value of radius of x axis and then y axis --- >\n";
    cin>>rx>>ry;
    Drawcircle(x1,y1,rx,ry);
    getch();
    closegraph();
}