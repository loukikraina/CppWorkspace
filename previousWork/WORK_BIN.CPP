#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
//#include <cstdlib>
struct node{
	struct node *left,*right;
	int low,high,max;
};
struct node *tree=NULL;
int count=0;
void insert_interval()
{
	int lo,hi,ma,tagger;
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	// printf("\nEnter interval to insert into BST in the given format:- low_num high_num \n");
	cout<<"\nEnter interval to insert into BST in the given format:- low_num high_num \n";
	cin>>lo>>hi;
	// scanf("%d %d",&lo,&hi);
	// printf("Enter Maximum high value in subtree rooted with this node\n");
	cout<<"Enter Maximum high value in subtree rooted with this node\n";
	cin>>ma;
	// scanf("%d",&ma);
	ptr->low=lo;
	ptr->high=hi;
	ptr->max=ma;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
		tree=ptr;
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(parentptr->max<ma)
				parentptr->max=ma;
			if(lo==nodeptr->low && hi==nodeptr->high)
			{
				// printf("Node already present in the tree.\nPress 1 to insert it or Press 2 to not insert it\n");
				cout<<"Node already present in the tree.\nPress 1 to insert it or Press 2 to not insert it\n";
				cin>>tagger;
				// scanf("%d",&tagger);
				if(tagger==2){
					ptr=NULL;
				}
			}
			if(lo<nodeptr->low)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
		}
		if(lo<parentptr->low)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;
	}
}
void preorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		// printf("[%d,%d]\t",tree1->low,tree1->high);
		cout<<"["<<tree1->low<<","<<tree1->high<<"]\t";
		// printf("%d\t",tree1->data);
		preorder(tree1->left);
		preorder(tree1->right);
	}
}
void inorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		inorder(tree1->left);
		// printf("[%d,%d]\t",tree1->low,tree1->high);
		cout<<"["<<tree1->low<<","<<tree1->high<<"]\t";
		// printf("%d\t",tree1->data);
		inorder(tree1->right);
	}
}
void postorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		postorder(tree1->left);
		postorder(tree1->right);
		// printf("[%d,%d]\t",tree1->low,tree1->high);
		cout<<"["<<tree1->low<<","<<tree1->high<<"]\t";
		// printf("%d\t",tree1->data);
	}
}
void find_interval(struct node *tree1,int lo,int hi)
{
	//int c=0;
	if(tree1!=NULL)
	{
			if(tree1->low==lo && tree1->high==hi)
			{
				count=1;
				// printf("\nInterval found, it is in the tree !\n");
				cout<<"\nInterval found, it is in the tree !\n";
			}
			else if(tree1->low<lo)
				find_interval(tree1->right,lo,hi);
			else
				find_interval(tree1->right,lo,hi);
	}

}
struct node *smallest_interval(struct node *tree1)
{

	if((tree1==NULL)||(tree1->left==NULL))
		return tree1;
	else
		return smallest_interval(tree1->left);

}
struct node *deleteNode(struct node *tree1, int lo,int hi)
{
	struct node *temp;

    if (tree1 == NULL)
	return tree1;


    if (lo < tree1->low)
		tree1->left = deleteNode(tree1->left,lo,hi);


    else if (lo > tree1->low)
	tree1->right = deleteNode(tree1->right, lo,hi);


    else
    {

	    if(tree1->high==hi)
		{
						if (tree1->left == NULL)
						{
						    struct node *temp = tree1->right;
						    free(tree1);
						    return temp;
						}
						else if (tree1->right == NULL)
						{
						    struct node *temp = tree1->left;
						    free(tree1);
						    return temp;
						}


						temp = smallest_interval(tree1->right);

						tree1->low = temp->low;
						tree1->high = temp->high;

						tree1->right = deleteNode(tree1->right, temp->low,temp->high);
		}
    }
    return tree1;
}
// int intersection(int lo1,int hi1){
// 	if((tofind_lo>lo1 && tofind_lo<hi1)||(tofind_hi>lo1 && tofind_hi<hi1))
// 		return 1;
// 	else
// 		return 0;

// }
void find_interval_intersection(struct node *tree2,int lo,int hi)
{

	int d=0;
	while(tree2!=NULL && d==0)
	{
		// d=intersection(tree2->low,tree2->high);
		if((lo>tree2->low && lo<tree2->high)||(hi>tree2->low && hi<tree2->high))
		{
			// printf("Intersection found!!\tWith Interval [%d,%d]\n",tree2->low,tree2->high);
			cout<<"Intersection found!!\tWith Interval ["<<tree1->low<<","<<tree1->high<<"]\n";
		       //	d=1;
		       //2	tree2=NULL;
			d+=1;
			break;
		}
		else if(tree2->left==NULL)
			find_interval_intersection(tree2->right,lo,hi);
		else if(tree2->left->max<lo)
			find_interval_intersection(tree2->right,lo,hi);
		else
			find_interval_intersection(tree2->left,lo,hi);
	}
	if(d==0)
		printf("No interval is intersecting the given interval\n");
		// cout<<"No interval is intersecting the given interval\n";
}
void main()
{
	int a,b,c,out=0;
	struct node *temp1;
	clrscr();
	// printf("WELCOME TO THE INTERVAL TREE PROGRAM\n");
	cout<<"WELCOME TO THE INTERVAL TREE PROGRAM\n";
	while(out==0)
	{
		cout<<"\t------------MAIN MENU-------------\n";
		// printf("\t------------MAIN MENU-------------\n");
		cout<<"1. INSERT INTERVAL IN THE TREE\n2. PREORDER DISPLAY\n3. INORDER DISPLAY\n4. POSTORDER DISPLAY\n5. FIND INTERVAL IN THE TREE\n6. DELETE AN INTERVAL FROM THE TREE\n7. FIND INTERSECTION WITH AN INTERVAL\n8. EXIT(ENTER ANY NUMBER GREATER THAN 8)\nENTER YOUR CHOICE NUMBER FROM THE MENU ------>>>> ";
		// printf("1. INSERT INTERVAL IN THE TREE\n2. PREORDER DISPLAY\n3. INORDER DISPLAY\n4. POSTORDER DISPLAY\n5. FIND INTERVAL IN THE TREE\n6. DELETE AN INTERVAL FROM THE TREE\n7. FIND INTERSECTION WITH AN INTERVAL\n8. EXIT(ENTER ANY NUMBER GREATER THAN 7)\nENTER YOUR CHOICE NUMBER FROM THE MENU ------>>>> ");
		cin>>a;
		// scanf("%d",&a);
		// ch=0;
		switch(a)
		{
			case 1:
			{
				insert_interval();
				break;
			}
			case 2:
			{
				preorder(tree);
				break;
			}
			case 3:
			{
				inorder(tree);
				break;
			}
			case 4:
			{
				postorder(tree);
				break;
			}
			case 5:
			{
				// printf("Enter the interval to find in the same format as given at the time of insertion\n");
				cout<<"Enter the interval to find in the same format as given at the time of insertion\n";
				cin>>b>>c;
				// scanf("%d %d",&b,&c);
				find_interval(tree,b,c);
				if(count==0){
					cout<<"Interval not found in the tree !\n";
					// printf("Interval not found in the tree !\n");
				}
				count=0;
				break;
			}
			case 6:
			{
				// break;
				// printf("Enter the interval to delete in the same format as given at the time of insertion\n");
				// scanf("%d %d",&b,&c);

				cout<<"Enter the interval to DELETE in the same format as given at the time of insertion\n";
				cin>>b>>c;
				tree=deleteNode(tree,b,c);
				break;
			}
			case 7:
			{
				// printf("Enter the interval to find in the same format as given at the time of insertion\n");
				// scanf("%d %d",&b,&c);

				cout<<"Enter the interval to find intersection with in the same format as given at the time of insertion\n";
				cin>>b>>c;
				find_interval_intersection(tree,b,c);
				break;				
			}
			default:
				out=1;
		}
		getch();
	}
	cout<<"\n\t\tTHANKS FOR USING THE PROGRAM, MADE WITH LOVE BY LOUKIK RAINA";
	// printf("\n\t\tTHANKS FOR USING THE PROGRAM, MADE WITH LOVE BY LOUKIK RAINA");
	getch();

}