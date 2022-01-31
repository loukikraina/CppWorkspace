#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>


void makeEllipse(float x,float y,float Ra, float Rb)
{
	float p,a,b, x1, y1,q;
	p = (Rb*Rb) - (Ra * Ra)*Rb - (0.25)*(Ra * Ra);
	x1 = 0;
	y1 = Rb;
	while((2*(Rb)*(Rb)*x1)<(2*(Ra)*(Ra)*y1)) //Region1
	{
		x1+=1;
		if(p<0)
		{
			p = p + 2*(Rb)*(Rb)*x1 + (Rb*Rb);
		      //	x1 = x1 +1;
			y1 = y1;
		}
		else
		{
			p = p + 2*(Rb)*(Rb)*x1 - 2*(Ra)*(Ra)*y1 + (Rb*Rb);
		      //	x1 = x1 + 1;
			y1 = y1 - 1;
		}
		putpixel(x1 +x ,y1+y,WHITE);
		delay(1);
		putpixel(x - x1, y - y1,WHITE);
		delay(1);
		putpixel(x - x1, y + y1,WHITE);
		delay(1);
		putpixel(x + x1, y - y1,WHITE);
		delay(1);

	}
	q = (Rb)*(Rb)*(x1 + 0.5)*(x1 + 0.5) + (Ra)*(Ra)*(y1 - 1)*(y1 - 1) - (Ra)*(Ra)*(Rb)*(Rb);

	while( y > 0)
	{
		putpixel(x1 +x ,y1 +y,WHITE );
		delay(1);
		putpixel(x - x1, y - y1, WHITE );
		delay(1);
		putpixel(x - x1, y + y1, WHITE );
		delay(1);
		putpixel(x + x1, y - y1, WHITE );
		delay(1);
		if( q <= 0)
		{
			q = q + 2*(Rb)*(Rb)*x1 - 2*(Ra)*(Ra)*y1 + (Ra)*(Ra);
			x1= x1;
			y1 = y1 -1;
		}
		else
		{
			q = q - 2*(Ra)*(Ra)*y1 + (Ra)*(Ra);
			x1= x1 -1;
			y1 = y1 -1;
		}
	}

}

int main ()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();
	float x, y, Ra, Rb;
	cout<<"PROGRAM TO DISPLAY ELLIPSE IS BEING IMPLEMENTED \n";
	cout<<"Enter the co-ordinates of centre of the ellipse: \n";
	cin>>x>>y;
	cout<<"enter the Ra and Rb values \n";
	cin>>Ra>>Rb;
	void makeEllipse(float x,float y,float Ra, float Rb);
	getch();
	closegraph();
	return 0;
}