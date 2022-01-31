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
	int x,y;
	setbkcolor(WHITE);
	int h=50;
	int r=5;
	int turn=35,k;
	for(int i=10;i<100;i++)
	{
// x=i+20;y=i+40;
setcolor(RED);
	     //	float g=(r+10)/2;
		circle(100+r+10,r+10+i,r);
	   //	circle(100+(r+10)-g+2,i+2+(r+10)-(r+10)/2,5);
	    //	circle(100+(r+10)+g+2,i+2+(r+10)-(r+10)/2,5);
	     //	circle(100+r+10,i+r+10,3);
	     //	rectangle((100+r+10)-g+2,i+2+5+(r+10)+(r+10)/2,100+-2+(r+10)+g,i-2-5+(r+10)+(r+10)/2);
		line(100+r+10,i+(2*r)+10,100+r+10,i+r+h-3);

	line(100+r+10,12+i+((2*r)+h-30)/2,100+r+3,i+(((2*r)+h-30)/2)+25);
	line(100+r+10,12+i+((2*r)+h-30)/2,100+r+17,i+(((2*r)+h-30)/2)+25);
	line(100+r+10,i+r+h-5,100+r-2,i+(r+h-30)+40);
	line(100+r+10,i+r+h-5,100+r+22,i+(r+h-30)+40);
		delay(50);
		cleardevice();
		}
	getch();
	closegraph();
}