#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
int stack[20];
int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	return stack[top--];
}
void doub(int a, int b)
{
	int c;
	c=(a*10)+b;
	printf("\ndouble --- > %d\n",c);
	printf("\npushing %d",c);
	push(c);
}
void tri(int a, int b,int c)
{
	int d;
	d=(a*100)+(b*10)+c;
	printf("\ntriple ---- > %d\n",d);
	printf("\npushing %d",d);
	push(d);
}

void main()
{
	char exp[20],nume[5];
	char e,d;
	int n1,n2,n3,num,c=0,val,i,a,y,z,numb=0;
	clrscr();
	printf("Enter the expression :: ");
	gets(exp);
     //	puts(exp);
      // scanf("%s",exp);
	i= 0;
	while(exp[i]!='\0')
	{
		e=exp[i];
		i++;
	       ///	printf("\n%c\n",e);
		if(c>5)
		{
			printf("limit exceded");
			exit(1);
		}
		if(e!='^'&&e!='*'&&e!='/'&&e!='+'&&e!='-'&&e!=' ')
		{
		       printf("\nThe %d is ---- > %d",c,(int)e-48);
			getch();
			nume[c]=e;
			c++;
			continue;
		}
		else if(e==' '&&c!=0)
		{
			numb=0;
			for(a=0;a<c;a++)
			{
			 //	printf("array is -- > %d ",nume[a]);
				y=(int)nume[a]-48;
				z=c-a-1;
				numb=numb+(y*pow(10,z));
			}
			push(numb);
			printf("\nThe number is -----> %d and digits are -- >%d\n",numb,c);
			printf("\nPushing the number\n");
			getch();
			c=0;

			/*
			if(c==1)
			{
				val=(int)nume[0]-48;
				printf("\npushing %d",val);
				push(val);
				getch();
				c=0;
			}
			else if(c==2)
			{
				doub((int)nume[0]-48,(int)nume[1]-48);
				c=0;
			}
			else if(c==3)
			{
				tri((int)nume[0]-48,(int)nume[1]-48,(int)nume[2]-48);
				c=0;
			}
			else
			{
			printf("\ndigits above 3 not included in this\nError!");
			exit();
			}
			//c=0;        */
			continue;
		}
		 n1 = pop();
		 n2 = pop();
		 switch(e)
		 {
			case '+':
			{
				printf("\nCalculating %d + %d\n",n1,n2);
				n3 = n1 + n2;
				break;
			}
			case '-':
			{
				n3 = n2 - n1;
				printf("\nCalculating %d - %d\n",n1,n2);
				break;
			}
			case '*':
			{
				n3 = n1 * n2;
				printf("\nCalculating %d * %d\n",n1,n2);
				break;
			}
			case '/':
			{
				n3 = n2 / n1;
				printf("\nCalculating %d / %d\n",n1,n2);
				break;
			}
			case '^':
			{
				n3=pow(n2,n1);
				printf("\nCalculating %d ^ %d\n",n1,n2);
				break;
			}
			default:continue;
		 }
		 push(n3);
		 printf("\nDone calculations, now pushing result --> %d\n",n3);
	}
	printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
	getch();

}