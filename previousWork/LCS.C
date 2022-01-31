#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct sub{
	int value;
	int mark;
}table[30][30];


void main(){
	int i,j,l1=0,l2=0,max,z;
	char first_str[30],second_str[30],third_str[30];
	clrscr();
	printf("Enter first string:- \n");
	// scanf("%s",&first_str);
	gets(first_str);
	printf("Enter second string:- \n");
	// scanf("%s",&sec
	gets(second_str);
	for(i=0;first_str[i]!='\0';i++)
	l1++;

	for(j=0;second_str[j]!='\0';j++)
	l2++;
	printf("\n%d %d\n",l1,l2);
getch();
	for(i=0;i<l1+1;i++)
		for(j=0;j<l2+1;j++)
		{
			if(i==0 || j==0) {
				table[i][j].value=0;
				table[i][j].mark=2;
		}
			else{
				if(first_str[i-1]!=second_str[j-1])
				{
					if(table[i-1][j].value>=table[i][j-1].value){
						table[i][j].value=table[i-1][j].value;
						table[i][j].mark=1;
					}
					else{
						table[i][j].value=table[i][j-1].value;
						table[i][j].mark=-1;
					}
				}
				else{
					table[i][j].value=table[i-1][j-1].value+1;
					table[i][j].mark=0;
				}
			}
		}
		z=0;
		i=l1;
		j=l2;
	       //	printf("\ntill while\n");
		getch();
	while(1){
		if(table[i][j].mark==0){
			third_str[z] = first_str[i-1];
			z++;
			i--;
			j--;
		}
		if(table[i][j].mark==1)
			i--;
		if(table[i][j].mark==-1)
			j--;
		if(table[i][j].mark==2)
			break;
	}
       //	printf("\nwhile done\n");

	getch();
	printf("\t");
	for(i=0;i<l1;i++)
	printf("%c   \t",second_str[i]);
	printf("\n");
	for(i=0;i<l1;i++){
		printf("%c\t",first_str[i]);
		for(j=0;j<l2;j++)
		{
			printf("%d(%d)\t",table[i+1][j+1].value,table[i+1][j+1].mark);
		}
		printf("\n");
	}
	printf("Therefore longest common subsequence:- \n");
	for(i=z-1;i>=0;i--)
		printf("%c",third_str[i]);
	getch();
}