#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
	clrscr();
	int a,b,c,d,e;
	while(d!=0)
	{
		cout<<"press 1 for addition"<<endl;
		cout<<"press 2 for subtraction"<<endl;
		cout<<"press 3 for multiplication"<<endl;
		cout<<"press 4 for division"<<endl;
		cin>>a;
		int z[100];
		if(a==1)
		{
			e=0;
			cout<<"write the no of numbers you want to add"<<endl;
			cin>>b;
			cout<<"enter the numbers you want to add"<<endl;
			for(c=0;c<b;c++)
			{
				cin>>z[c];
			}
			for(c=0;c<b;c++)
			{
				e=e+z[c];
			}
			cout<<e<<endl;
		}
		else if(a==2)
		{
			cout<<"enter the nos you want to sub"<<endl;
			cout<<"enter the 1st number"<<endl;
			cin>>z[0];
			cout<<"enter the 2nd no"<<endl;
			cin>>z[1];
			cout<<endl<<z[0]-z[1]<<endl;
		}
		getch();
		cout<<"if you want to continue press any key, if not press 0"<<endl;
		cin>>d;
		clrscr();
	}
}






