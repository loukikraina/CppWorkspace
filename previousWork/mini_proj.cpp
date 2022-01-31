#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>


void rotate(float x1, float y1, float x2, float y2, int turns, int turn){
	float delx,dely,theta;
	delx=x2-x1;
	dely=y2-y2;
	theta=-turn*0.0174532925;
	if(turns==1){
			x2=((delx*cos(theta))-(dely*sin(theta))+x1);
			y2=((delx*sin(theta))+(dely*cos(theta))+y1);}
	else{
			x2=((delx*cos(theta))+(dely*sin(theta))+x1);
			y2=(-(delx*sin(theta))+(dely*cos(theta))+y1);}
	line(x1,y1,x2,y2);
}

void main()
{
	// int xm=getmaxx();
	// int ym=getmaxy();
	int gdriver = DETECT,gmode;
	// int x1,y1,x2,y2;
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
	setcolor(YELLOW);
	int h=250;
	int r=50;
	int turn=35,k;
	for(int i=0;i<getmaxx()-70;i++)
	{
		float g=(r+10)/2;
		circle(r+10+i,r+10,r);
		circle((r+10)-g+i+2,2+(r+10)-(r+10)/2,5);
		circle((r+10)+g+i+2,2+(r+10)-(r+10)/2,5);
		circle(r+10+i,r+10,3);
		rectangle((r+10)-g+i+2,2+5+(r+10)+(r+10)/2,-2+(r+10)+g+i,-2-5+(r+10)+(r+10)/2);
		line(r+10+i,(2*r)+10,r+10+i,r+h-30);
		rotate(r+10+i,((2*r)+h-30)/2,r+10+i-40,(((2*r)+h-30)/2)-40,1,turn);
		rotate(r+10+i,((2*r)+h-30)/2,r+10+i+40,(((2*r)+h-30)/2)+40,0,turn);
		rotate(r+10+i,r+h-30,r+10+i-80,(r+h-30)-80,1,turn);
		rotate(r+10+i,r+h-30,r+10+i+80,(r+h-30)+80,0,turn);
		if(turn>90)
			k=-1;
		if(turn==35)
			k=1;
		turn+=k;
		delay(10);
		cleardevice();
	}
	cout<<"THANKS FOR WATCHING THIS SMALL ANIMATION";
	getch();
	closegraph();
}