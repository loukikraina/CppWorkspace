#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
int abso(int a)
{
	if(a<0)
	a=a*-1;
	return a;
}
void dda(int x1, int x2, int y1,int y2)
{
	int dx,dy,dash=1,dot=1,option;
      //		cout<<"points are ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<")\n";
	float xi,yi,steps;
	dx=x2-x1;
	dy=y2-y1;
       //	cout<<"\ndx is "<<dx<<" and dy is "<<dy;
	if(abs(dx)>abs(dy))
	steps=abso(dx);
	else
	steps=abso(dy);
       //	cout<<"\nsteps = "<<steps<<endl;
	xi=dx/steps;
	yi=dy/steps;
       //	cout<<xi<<endl<<yi<<endl;
	cout<<"Which line you want.\nPress 1 for normal line.\n2 for dotted line.\n3 for dashed line\n";
	cin>>option;
	getch();
       clrscr();
       cleardevice();
	float x=x1,y=y1;
	putpixel(int(x),int(y),WHITE);
	for(int a=1;a<steps;a++)
	{
		x=x+xi;
		y=y+yi;
		//delay(70);
		if(option==1)
		{       putpixel(int(x),int(y),WHITE);
			continue;
		}
		else
		{
			if(option==2)
			{
				if(dot==1)
				{
					dot=0;
					continue;
				}
				putpixel(int(x),int(y),WHITE);
				dot++;
			}
			else
			{
				if(dash==5)
				{
					dash=0;
					continue;
				}
				putpixel(int(x),int(y),WHITE);
				dash++;
			}
		}
	       //	cout<<"x1 is "<<x<<" y1 is "<<y<<endl;

	}
	putpixel(x2,y2,WHITE);
}


void main()
{
	clrscr();
	int gd=DETECT,gm;
	//detect the graphics drivers automatically
	int x1,x2,y1,y2;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//initilize to graphics mode
	cleardevice();
	cout<<"DDA Line generation algorithm";
	cout<<"\nenter the starting co-ordinates for drawing line\n";
	cin>>x1>>y1;
	cout<<"\nenter the ending coordinates\n";
	cin>>x2>>y2;
	dda(x1,x2,y1,y2);
	getch();
	closegraph();
}
