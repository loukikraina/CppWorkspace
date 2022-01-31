#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void jacobiseidal(int a,int b[3][4],int g)
{
	float x[50],y[50],z[50];
	x[0]=0;y[0]=0;z[0]=0;
	for(int c=1;c<=a;c++)
	{
		if(g==1)
		{
			x[c]=(b[0][3]-z[c-1]*b[0][2]-y[c-1]*b[0][1])/b[0][0];
			y[c]=(b[1][3]-z[c-1]*b[1][2]-x[c-1]*b[1][0])/b[1][1];
			z[c]=(b[2][3]-y[c-1]*b[2][1]-x[c-1]*b[2][0])/b[2][2];
		}
		if(g==2)
		{
			x[c]=(b[0][3]-z[c-1]*b[0][2]-y[c-1]*b[0][1])/b[0][0];
			y[c]=(b[1][3]-z[c-1]*b[1][2]-x[c]*b[1][0])/b[1][1];
			z[c]=(b[2][3]-y[c]*b[2][1]-x[c]*b[2][0])/b[2][2];
		}
	}
	for(c=1;c<=a;c++)
	{
		cout<<"For "<<c<<" iteration values of x,y,z are :-"<<endl;
		delay(1000);
		cout<<x[c]<<" "<<y[c]<<" "<<z[c]<<endl;
	}
 }
void main()
{
	clrscr();
	int z;
	while(z!=0)
       {	int a,b,c,d[3][4],e,f;
		cout<<"press 1 if want gauss jacobi and press 2 if want gauss seidal"<<endl;
		cin>>a;
		cout<<"how many iterations you want till"<<endl;
		cin>>e;
		cout<<"now enter the coefficients of all equations in order"<<endl;
		for(b=0;b<3;b++)
		{
			for(c=0;c<4;c++)
			{
				cin>>d[b][c];
			}
		}
		jacobiseidal(e,d,a);
		cout<<endl<<"press any no. if want to continue else press 0 to exit"<<endl;
		cin>>z;
		getch();
		clrscr();
       }
}