#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

void Boundary(int x,int y,int col1,int col2)
{
	if(getpixel(x,y)!=col2 && getpixel(x,y)!=col1)
	{
		putpixel(x,y,col1);
		Boundary(x+1,y,col1,col2);
		Boundary(x,y+1,col1,col2);
		Boundary(x-1,y,col1,col2);
		Boundary(x,y-1,col1,col2);
	}
}
void Flood(int x,int y,int old,int n)
{
	if(getpixel(x,y) == old)
	{
		putpixel(x,y,n);
		Flood(x+1,y,old,n);
		Flood(x,y+1,old,n);
		Flood(x-1,y,old,n);
		Flood(x,y-1,old,n);
	}
}

int main()
{
	int x,y,option,r,a=0,floodold,floodnew,color;
	int gm,gd=DETECT;
	for(int z=0;z<=15;z++)
	{
		gotoxy(100,1+z);
		textcolor(z);
		cprintf("note the number ---> %d for this color",z);
		cout<<endl;
	}
	getch();
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"Enter center of the circle \n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>r;
	while(a!=1){
	cout<<" enter the program to be implemented:\n1.Boundary Fill \n2.Flood Fill\n3.Exit\n";
	cin>>option;
	setcolor(15);
	circle(x,y,r);
    switch (option)
    {
    case 1 :
       {
	cout<<"enter the b.fill color number\n";
	cin>>color;
	Boundary(x,y,color,15);
	break;    }

    case 2 :
     {
     cout<<"enter the f.fill color number\n";
     cin>>floodnew;
     floodold=getpixel(x,y);
     setcolor(floodnew);
     circle(x,y,r);
     Flood(x,y,floodold,floodnew);
	break;  }
    case 3 :
    {
	a=1;}

    }	delay(500);
	getch();
    }
	closegraph();
	return 0;
}
