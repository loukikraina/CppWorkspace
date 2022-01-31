#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
void bresenhams(int x1,int y1,int x2,int y2)
{
	int dx,dy,p,x,y,dash=0,dot=0,option;
	do{
	cout<<"\nEnter 1 for normal line\n2 for dotted line\n3 for dashed line\nAny other number to exit.\n";
	cin>>option;
	x=x1;y=y1;
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	clrscr();
	cleardevice();
	do
	{
		if(p<0)
		{
			x+=1;
			p=p+2*dy;
			cout<<endl<<x<<" "<<y;
		}
		else
		{
			x+=1;

			y+=1;
			p=p+(2*dy)-(2*dx);
		 //	printf("\n%d , %d",x,y);
		}
		cout<<endl<<x<<" "<<y;

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
			if(option==3)
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
       //	delay(50);
	}while(x!=x2 && y!=y2);
	getch();
	}while(option==1||option==2||option==3);
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
	cout<<"BRESENHAM'S Line generating algorithm\n";
	cout<<"Enter the starting coordinates --- >\n";
	cin>>x1>>y1;
	cout<<"Enter the ending co-ordinates ---- >";
	cin>>x2>>y2;
	bresenhams(x1,y1,x2,y2);
	closegraph();
}
