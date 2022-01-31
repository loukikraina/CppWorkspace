#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void create_cll()
{
	struct node *new_node, *ptr;
	int num;
	printf("Enter -1 to end \n");
	printf("Enter the data:--->\n");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{	start=new_node;
			new_node->next=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
		//new_node->next=NULL;
		printf("\nEnter the data:----> \n");
		scanf("%d",&num);
	}
}
void display()
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	printf("\nNO ELEMENT PRESENT IN THE L.LIST, ENTER DATA TO DISPLAY !\n");
	else
	{
		while(ptr->next!=start)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
	}
}
void insert_beg()
{
	struct node *new_node,*ptr;
	int num;
	ptr=start;
	printf("\nEnter the data :--->\n");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	if(ptr==NULL)
	new_node->next=new_node;
	else
	new_node->next=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	start=new_node;
}
void insert_end()
{
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter the data :--->\n");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	if(ptr==NULL)
	start=new_node;
	else{
	while(ptr->next!=start)
		ptr=ptr->next;
	ptr->next=new_node;    }
	new_node->next=start;
}
void insert_before()
{
	struct node *preptr ,*ptr, *new_node;
	int num,gnum;
	printf("\nEnter the data :- ");
	scanf("%d",&num);
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	preptr=start;
	while(ptr->data!=gnum)
	{
		if(ptr==NULL)
			break;
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr==NULL)
		printf("\nNode is not found !!!");
	else{
	if(ptr==start)
	{
		new_node->next=start;
		start=new_node;
	}
	else
	{
		new_node->next=ptr;
		preptr->next=new_node;
	}
	}
}
void insert_after()
{
	struct node *ptr, *new_node;
	int num,gnum;
	printf("\nEnter the data :- ");
	scanf("%d",&num);
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=gnum)
	{
		if(ptr==NULL)
			break;
		ptr=ptr->next;
	}
	if(ptr==NULL)
		printf("\nNode is not found !!!");
	else{
	new_node->next=ptr->next;
	ptr->next=new_node;
	}
}
void delete_beg()
{
	struct node *ptr,*temp;
	ptr=start;
	temp=start;
	while(temp->next!=start)
		temp=temp->next;
	if(start==start->next)
		start=NULL;
	else{
	start=start->next;
	temp->next=start;
	}
	free(ptr);
}
void delete_end()
{
	struct node *ptr,*temp;
	ptr=start;
	while(ptr->next!=start)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	if(ptr==start)
	{
		start=NULL;
	}
	else
	temp->next=start;
	free(ptr);
}
void delete_before()
{
	struct node *ptr,*preptr,*prepreptr;
	int gnum;
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	ptr=start;
	if(ptr->data==gnum)
		printf("\nTHIS IS THE FIRST NODE, CANT DELETE BEFORE IT");
	else{
	while(ptr->data!=gnum)
	{
		if(ptr->next==start)
			break;
		prepreptr=preptr;
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr->next==start && ptr->data!=gnum)
		printf("\nNode is not found !!!");
	else{
	if(preptr==start)
		delete_beg();
	else
	{
		prepreptr->next=ptr;
		free(preptr);
	}   }
	}
}
void delete_after()
{
	struct node *ptr,*temp;
	int gnum;
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	ptr=start;
	while(ptr->data!=gnum)
	{
		if(ptr->next==start)
			break;
		ptr=ptr->next;
	}
	if(ptr->next==start && ptr->data!=gnum)
		printf("\nNode is not found !!!");
	else{
	temp=ptr->next;
	if(temp!=NULL)
	{
		ptr->next=temp->next;
		free(temp);
	}
	else
		printf("\nThere is no node after the given node !!!");
	}
}
void delete_given()
{
	struct node *ptr,*temp;
	int gnum,b=0;
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	ptr=start;
	while(ptr->data!=gnum)
	{
		if(ptr->next==start)
		{	
			b=1;
			break;
		}
		temp=ptr;
		ptr=ptr->next;		
	}
	if(b==1)
		printf("\nNode is not found !!!");
	else
	{
		if(ptr==start)
			delete_beg();
		else
		{
			temp->next=ptr->next;
			free(ptr);
		}
	}
}
void search()
{
	struct node *ptr;
	int gnum,a;
	printf("\nEnter the data of given node:- ");
	scanf("%d",&gnum);
	ptr=start;
	while(ptr->next!=start)
	{
		if(ptr->data==gnum)
		{
			printf("\nDATA FOUND IN THE LIST !!!!\ndata is -> %d and its addres is --> %p",gnum,ptr);
			a=1;
			break;
		}
	       //	else
	       ptr=ptr->next;
	}
	if(ptr->data==gnum)
		{
			printf("\nDATA FOUND IN THE LIST !!!!\ndata is -> %d and its addres is --> %p",gnum,ptr);
			a=1;
		}
	if(a==0)
	printf("\nSORRY, DATA NOT FOUND IN LIST !");
}
void main()
{
	int a,b=0;
	clrscr();
	printf("WELCOME TO THE CIRCULAR LINKED LIST PROGRAM\n");
	while(b==0)
	{
		printf("                          ------------MAIN MENU-------------\n");
		printf("1. CREATE\n2. DISPLAY\n3. INSERT AT BEGINNING\n4. INSERT AT END\n5. INSERT BEFORE\n6. INSERT AFTER\n7. DELETE FROM BEGINNING\n8. DELETE FROM END\n9. DELETE AFTER GIVEN NODE\n10. DELETE BEFORE GIVEN NODE\n11. DELETE GIVEN NODE\n12. SEARCH A NODE\n13. EXIT(ENTER ANY NUMBER GREATER THAN 12)\nENTER YOUR CHOICE NUMBER FROM THE MENU ------>>>> ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			{
				create_cll();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				insert_beg();
				break;
			}
			case 4:
			{
				insert_end();
				break;
			}
			case 5:
			{
				insert_before();
				break;
			}
			case 6:
			{
				insert_after();
				break;
			}case 7:
			{
				delete_beg();
				break;
			}
			case 8:
			{
				delete_end();
				break;
			}
			case 9:
			{
				delete_after();
				break;
			}
			case 10:
			{
				delete_before();
				break;
			}
			case 11:
			{
				delete_given();
				break;
			}
			case 12:
			{
				search();
				break;
			}
			default:
			b=1;
		}
		getch();
		clrscr();
	}
	printf("\n\t\tTHANKS");
	getch();
}

