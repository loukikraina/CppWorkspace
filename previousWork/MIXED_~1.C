// #include<stdio.h>
// #include<conio.h>

// void main(){
// 	int a,b=0,c[20],s,d,temp,temp2,temp3;
// 	clrscr();
// 	printf("Enter the number:- ");
// 	scanf("%d",&a);
// 	printf("Enter the source location and destination location:- \n");
// 	scanf("%d %d",&s,&d);
// 	while(a!=0){
// 		c[b]=a%10;
// 		a/=10;
// 		b++;
// 	}
// 	temp=c[s-1];
// 	c[s-1]=c[d-1];
// 	for(a=d-1;a<s-2;a++){
// 		temp2=c[a];
// 		// temp3=c[a+1];
// 		c[a]=c[a+1];
// 		c[a+1]=temp2;
// 		// asm{
// 		// 	mov ax,temp2
// 		// 	mov bx,temp3
// 		// 	mov temp3,ax
// 		// 	mov temp2,bx
// 		// }
// 		// c[a]=temp2;
// 		// c[a+1]=temp3;

// 	}
// 	c[s-2]=temp;
// 	printf("\nResultant no.:- ");
// 	for(a=b-1;a>=0;a--)
// 		printf("%d",c[a]);
// 	getch();
// 	// asm{
// 	// 	mov bl,a
// 	// 	mov cl,0Ah
// 	// 	l1:
// 	// 	mov ax,00h
// 	// 	mov al,bl
// 	// 	div cl
// 	// 	cmp al,00h
// 	// 	jz l2
// 	// 	mov c,al



// 	// }
// }
#include<stdio.h>
#include<conio.h>

int main(){
	int a,b=0,c[20],s,d,temp,temp2;
	clrscr();
	printf("Enter the number:- ");
	scanf("%d",&a);
	printf("Enter the source location and destination location:- \n");
	scanf("%d %d",&s,&d);
	b=0;
	while(a!=0){
		c[b]=a%10;
		a=a/10;
		b++;
	}
	for(a=b-1;a>=0;a--)
	printf("%d",c[a]);

	temp=c[s-1];
	c[s-1]=c[d-1];
	for(a=d-1;a<s-2;a++){
		temp2=c[a];
		c[a]=c[a+1];
		c[a+1]=temp2;

	}
	c[s-2]=temp;
	printf("\nResultant no.:- ");
	for(a=b-1;a>=0;a--)
		printf("%d",c[a]);
	getch();
	return 0;
}