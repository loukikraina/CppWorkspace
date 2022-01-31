#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
//#include<cmath.h>
float m[10][10],original[10][10];
int sides;
void multiply(float n[3][3]){
	int a,b;
	for(a=0;a<3;a++)
	{
		for(b=0;b<sides;b++)
		{
			m[a][b]=(n[a][0]*m[0][b])+(n[a][1]*m[1][b])+(n[a][2]*m[2][b]);
		}
	}

}
void trans(){
	float t[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	cout<<"\nEnter the (x,y) vectors for the translational matrix";
	cin>>t[0][2]>>t[1][2];
	multiply(t);
}
void ro(){
	float b,r[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	cout<<"\nEnter the angle of rotation(-ve angle for clockwise and +ve for anticlockwise)";
	cin>>b;
	b=b*0.0174532925;
	r[0][0]=cos(b);
	r[0][1]=-(sin(b));
	r[1][0]=sin(b);
	r[1][1]=cos(b);
	multiply(r);
}
void sc(){
	float s[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	float sx,sy;
	cout<<"\nEnter the scaling factor(sx and sy)";
	cin>>sx>>sy;
	s[0][0]=sx;s[1][1]=sy;
	multiply(s);
}
void reflect(){

	float ref[3][3];
	int cy,cx,co;
	cout<<"\nEnter the coeff. of eq of line in form y=mx+c or 0 three times for origin\n";
	cin>>cy>>cx>>co;
	int cx2=pow(cx,2);
	if(cy==0 && co==0)
	{
		if(cx==1)
			ref[1][1]=1;
		else
			ref[1][1]=-1;
		ref[0][0]=-1;

	}
	else{
	ref[0][0]=(1-cx2)/(cx2+1);
	ref[1][1]=-ref[0][0];
	}
	ref[0][1]=(2*cx)/(cx2+1);
	ref[1][0]=ref[0][1];
	ref[0][2]=(-2*co*cx)/(cx2+1);
	ref[1][2]=(2*co)/(cx2+1);
	ref[2][0]=0;
	ref[2][1]=0;
	ref[2][2]=1;
	multiply(ref);
}
void shear(){

	float sh[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	float shx,shy,xref,yref;
	cout<<"\nEnter shear for x, then y (0 if not given)\n";
	cin>>shx>>shy;
	cout<<"\nNow enter x and y for refrence(0 if not given)\n";
	cin>>xref>>yref;
	if(shy==0)
	{
		sh[0][1]=shx;
		sh[0][2]=(-shx)*yref;
	}
	else
	{
		sh[1][0]=shy;
		sh[1][2]=(-shy)*xref;
	}
	multiply(sh);
}
void display(){
	int a,b;
	for(a=0;a<3;a++)
	{
		for(b=0;b<sides;b++)
		{
			cout<<m[a][b]<<" ";
		}
		cout<<endl;
	}

}
void mo()
{	int a,b;
	for(a=0;a<3;a++)
	{
		for(b=0;b<sides;b++)
		{
			m[a][b]=original[a][b];;
		}
	}
}
void makefig(){

	int a,b;
	setcolor(WHITE);
	for(b=0;b<(sides-1);b++){
		line(original[0][b],original[1][b],original[0][b+1],original[1][b+1]);
		}
	if(sides>2)
	line(original[0][0],original[0][1],original[sides-1][0],original[sides-1][1]);
	setcolor(RED);
	for(b=0;b<(sides-1);b++){
		line(m[0][b],m[1][b],m[0][b+1],m[1][b+1]);
		}
	if(sides>2)
	line(m[0][0],m[0][1],m[sides-1][0],m[sides-1][1]);

}
void main()
{
	clrscr();
	int a,b,c;
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cout<<"Enter the no. of vertices of the fig.\n(for eg:- 2 for line and 3 for triangle)\n";
	cin>>sides;
	cout<<"\nEnter the coordinates of vertices in matrix format\n";
	for(a=0;a<2;a++)
	{
		for(b=0;b<sides;b++)
		{
			cin>>m[a][b];
			original[a][b]=m[a][b];
			m[2][b]=1;
			original[2][b]=m[2][b];
		}
	}
	a=1;
	xm=getmaxx ()/2;  
   	ym=getmaxy ()/2;
	while(a==1)
	{
		//cleardevice();
		cout<<endl<<"-------------MENU OF TRANSFORMATIONS-------------\n";
		cout<<"PRESS 1 FOR TRANSLATION\nPRESS 2 FOR ROTATION\nPRESS 3 FOR SCALING\nPRESS 4 TO DISPLAY MATRIX\nPRESS 5 TO DO REFELCTION\nPRESS 6 TO DO SHEARING\nPRESS 7 TO MAKE THE CURRENT MATRIX TO ORIGINAL ONE\nPRESS ANY OTHER NUMBER TO EXIT\n";
		cin>>b; 
    	line (xm, 0, xm, 2*ym);   
		switch(b)
		{
			case 1:
			{
				trans();
				display();
				break;
			}
			case 2:
			{
				ro();
				display();
				break;
			}
			case 3:
			{
				sc();
				display();
				break;
			}
			case 4:
			{
				display();
				break;
			}
			case 5:
			{
				reflect();
				break;
			}
			case 6:
			{
				shear();
				break;
			}
			case 7:
			{
				mo();
				break;
			}
			default:
			{
				a=0;
				break;

			}
		}
	getch();
	cleardevice();
	//moveto(0,0);
	makefig();
	getch();
	cleardevice();
	moverel(0,0);
	}
	cout<<"Thanks for using the program";
	getch();
	closegraph();
}




