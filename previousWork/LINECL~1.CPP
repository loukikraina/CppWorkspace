#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
float xm,ym;
void cohen_sutherland(float xw_min,float xw_max,float yw_min,float yw_max,float x1,float y1,float x2, float y2)
{
	float m=(y2-y1)/(x2-x1);
	while(1)
	{
		int p[2][4]={{0,0,0,0},{0,0,0,0}};
		int x=x1,y=y1;
		int inner=0,outer=0,inner2=0;
		for(int z=0;z<2;z++)
		{
			if(x-xw_min<0)
				p[z][0]=1;
			if(xw_max-x<0)
				p[z][1]=1;
			if(y-yw_min<0)
				p[z][2]=1;
			if(y-yw_min<0)
				p[z][3]=1;
			x=x2;
			y=y2;
		}
		for(z=0;z<4;z++)
		{
			if(p[0][z]==0)
				inner++;
			if(p[1][z]==0)
				inner2++;
			if(p[0][z]+p[1][z]==2)
				outer++;
		}
		if(inner!=4)
			{
				for(z=0;z<3;z++)
				{
					if(p[0][z]==1)
					{
						if(z==0)
						{
							y1=y1+m*(xw_min-x1);
							x1=xw_min;
						}
						if(z==1)
						{
							y1=y1+m*(xw_max-x1);
							x1=xw_max;
						}
						if(z==2)
						{
							y1=yw_min;
							x1=x1+m*(yw_min-y1);
						}
						if(z==3)
						{
							y1=yw_max;
							x1=x1+m*(yw_max-y1);
						}
					}
				}
			}
		if(inner2!=4)
			{
				for(z=0;z<3;z++)
				{
					if(p[0][z]==1)
					{
						if(z==0)
						{
							y1=y1+m*(xw_min-x1);
							x1=xw_min;
						}
						if(z==1)
						{
							y1=y1+m*(xw_max-x1);
							x1=xw_max;
						}
						if(z==2)
						{
							y1=yw_min;
							x1=x1+m*(yw_min-y1);
						}
						if(z==3)
						{
							y1=yw_max;
							x1=x1+m*(yw_max-y1);
						}
					}
				}
			}
		setcolor(WHITE);
		line(xm,0,xm,ym*2);
		line(0,ym,xm*2,ym);
		// box creation
		setcolor(RED);
		line(xw_min,yw_min,xw_min,yw_max);
		line(xw_min,yw_max,xw_max,yw_max);
		line(xw_max,yw_max,xw_max,yw_min);
		line(xw_max,yw_min,xw_min,yw_min);
		getch();
		//line clipping
		setcolor(GREEN);
		if(outer>0)
			setcolor(CYAN);
		line(x1,y1,x2,y2);
		if(outer>0)
		{
			cout<<"THIS LINE IS OUT OF WINDOW";
			break;
		}
		if(inner==4&&inner2==4)
			break;
	}
	getch();
}
void main()
{
	clrscr();
	int a,b,c;
	float xw_min,xw_max,yw_min,yw_max,x1,y1,x2,y2;
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cout<<"Enter the coodinates of vertices of the outer(window) fig. i.e. enter xw_min,yw_min,xw_max,yw_max respectively\n";
	cin>>xw_min>>yw_min>>xw_max>>yw_max;
	cout<<"\nEnter the coordinates of line in the given format:- x1,y1,x2,y2\n";
	cin>>x1>>y1>>x2>>y2;
	// for(a=0;a<2;a++)
	// {
	// 	for(b=0;b<sides;b++)
	// 	{
	// 		cin>>m[a][b];
	// 		original[a][b]=m[a][b];
	// 		m[2][b]=1;
	// 		original[2][b]=m[2][b];
	// 	}
	// }
	// a=1;
	xm=getmaxx()/2;
	ym=getmaxy()/2;
	getch();
	cleardevice();
	cohen_sutherland(xm+xw_min,xm+xw_max,ym-yw_min,ym-yw_max,xm+x1,ym-y1,xm+x2,ym-y2);
	getch();
	cout<<"Thanks for using the program";
	getch();
	closegraph();
}