#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
char first_str[30],second_str[30];
int first[30],second[30];

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

int rabin_karp(int d,int q,int n,int m){
	int h,p=0,t=0,i,s,g,tag;
	h = (int)pow(d,m-1)%q;
	for(i=0;i<n;i++)
	printf("%d ",first[i]);
	getch();
	printf("\n");
	for(i=0;i<m;i++)
	printf("%d ",second[i]);
	getch();
	for(i=0;i<m;i++){
		p = (d*p + second[i])%q;
		t = (d*t + first[i])%q;
	}
	printf("\np0=%d,t0=%d,h=%d,d=%d,m=%d,n=%d\n",p,t,h,d,m,n);
	getch();
	for(s=0;s<=n-m;s++){
	printf("\nFor s = %d:- \n",s);
		if(p==t){
			tag=0;
			printf("p and t are matching, therefore proceeding:-\n",s);
			for(g=0;g<m;g++){
				printf("Comparing %c with %c.....",second_str[g],first_str[s+g]);
				if(second[g]==first[s+g]){
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
		}
		else
		printf("p and t value doesnt match!\n");
		if(s<n-m){
			printf("Getting new value of t:-\nPrevious- %d",t);
			t = mod((d*(t-first[s]*h) + first[s+m]),q);
			printf(" New- %d\n",t);
		}
		getch();
	}
	return -1;
}


void main(){
	int i,j,l1=0,l2=0,prime=13,max,h,res;
	clrscr();
	printf("Enter main string:- \n");
	// scanf("%s",&first_str);
	gets(first_str);
	printf("Enter sub-string to match with:- \n");
	// scanf("%s",&sec
	gets(second_str);
	max = (int)(first_str[0])-97;
	for(i=0;first_str[i]!='\0';i++){
		l1++;
		first[i]=(int)(first_str[i])-97;
		if(i!=0 && max<(int)(first_str[i])-97)
			max=(int)(first_str[i])-97;
	}
	for(j=0;second_str[j]!='\0';j++){
		l2++;
		second[j]=(int)(second_str[j])-97;
	}
	printf("Enter the prime number value:- \n");
	scanf("%d",&prime);
	max++;
	res = rabin_karp(max,prime,l1,l2);
	if(res==-1)
		printf("\nPattern doesn't match in the given string!");
	else
		printf("\nPattern occurs with shift %d",res);
getch();
}


	
