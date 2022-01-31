#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int x[4],y[4],i,z,xm,ym;
float px,py;
xm=getmaxx ()/2;  
ym=getmaxy ()/2;
cout<<"Enter number of control points that you want to enter: \n";
cin>>z;
cout<<"Enter four control points of bezier curve: \n";
for(i=0;i<z;i++) 
	cin>>x[i]>>y[i];
double t;
if(z==2){
	setcolor(RED);
	line(x[0]+xm,ym-y[0],x[1]+xm,ym-y[1]);
	for(t=0.0;t<=1.0;t+=0.001){
	px=(1-t)*x[0]+t*x[1];
	py=(1-t)*y[0]+t*y[1];
	putpixel(px+xm,ym-py,WHITE);
	delay(10);
	}
}
else if(z==3)
{
	setcolor(RED);
	line(x[0]+xm,ym-y[0],x[1]+xm,ym-y[1]);
	line(x[1]+xm,ym-y[1],x[2]+xm,ym-y[2]);
	for(t=0.0;t<=1.0;t+=0.001){
	px=(1-t)*(1-t)*x[0]+2*t*(1-t)*x[1]+t*t*x[2];
	py=(1-t)*(1-t)*y[0]+2*t*(1-t)*y[1]+t*t*y[2];
	putpixel(px+xm,ym-py,WHITE);
	delay(10);
	}
}
else if(z==4)
{
	setcolor(RED);
	line(x[0]+xm,ym-y[0],x[1]+xm,ym-y[1]);
	line(x[1]+xm,ym-y[1],x[2]+xm,ym-y[2]);
	line(x[3]+xm,ym-y[3],x[2]+xm,ym-y[2]);
	for(t=0.0;t<=1.0;t+=0.001){
	px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
	py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
	putpixel(px+xm,ym-py,WHITE);
	delay(10);
	}
}
else
	cout<<"\nYet to make the program suitable for the control points you have given!!!!! ";
getch();
cleardevice();
cout<<"\nThanks for using the program..";
closegraph();
}