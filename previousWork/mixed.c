#include<stdio.h>

int main(){
	int a=1,b=1,c;
	clrscr();
	asm{

		mov ax,a
		mov bx,b
		add ax,bx
		mov c,ax
	}
	printf("C is- %d",c);
	return 0;
}