#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char first_str[30],second_str[30];


int string_matcher(int n,int m ){
	int s,g,tag;
	for(s=0;s<=n-m;s++){
		tag=0;
		printf("\nFor s = %d :-\n",s);
		for(g=0;g<m;g++){
			printf("Comparing %c with %c.....",second_str[g],first_str[s+g]);
			if(second_str[g]==first_str[s+g]){
				printf("  Charater matched!!!\n");
				tag++;
			}
			else
				printf("  Charater donot match!!!\n");
		}
		if(tag==m){
			printf("All characters matched !! Returning value of s\n");
			return s;
			}
		getch();
	}
	return -1;
}

void main(){
	int i,j,l1=0,l2=0,max,z;
	clrscr();
	printf("Enter main string:- \n");
	// scanf("%s",&first_str);
	gets(first_str);
	printf("Enter sub-string to match with:- \n");
	// scanf("%s",&sec
	gets(second_str);
	for(i=0;first_str[i]!='\0';i++)
	l1++;
	for(j=0;second_str[j]!='\0';j++)
	l2++;
	max = string_matcher(l1,l2);
	if(max==-1)
		printf("\nPattern doesn't match in the given string!");
	printf("\nPattern occurs with shift %d",max);
getch();
}