#include<conio.h>
#include<iostream.h>
void main()
{
	clrscr();
	int a,b,c,d,e[1000],f=0,g=0;
	cin>>c;
	cout<<endl;
	for(b=1;b<=c;b++)
	{
		d=0;
		for(a=1;a<b;a++)
		{
			if(b%a==0)
			d++;
		}
		if(d==1)
		{
			cout<<b<<endl;
			e[f]=b;
			f++;
		}
	}
	getch();
	for(b=0;b<f;b++)
	{
		for(a=0;a<=b;a++)
		{
			d=e[b]+e[a];
			if(d==c)
			cout<<endl<<"the "<<++g<<" set is "<<e[b]<<" and "<<e[a]<<endl;
			d=0;
		}
	}
	getch();
}
