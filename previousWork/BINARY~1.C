#include<conio.h>
#include<stdio.h>
struct node
{
	struct node *left,*right;
	int data;
};
int ch;
struct node *tree=NULL;
void insert_element()
{
	int val;
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data to insert into BST\n");
	scanf("%d",&val);
	ptr->data=val;
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
			if(val<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
		}
		if(val<parentptr->data)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;
	}
}
void preorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		printf("%d\t",tree1->data);
		preorder(tree1->left);
		preorder(tree1->right);
	}
}
void inorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		inorder(tree1->left);
		printf("%d\t",tree1->data);
		inorder(tree1->right);
	}
}
void postorder(struct node *tree1)
{
	if(tree1!=NULL)
	{
		postorder(tree1->left);
		postorder(tree1->right);
		printf("%d\t",tree1->data);
	}
}
struct node *smallest(struct node *tree1)
{
	if((tree1==NULL)||(tree1->left==NULL))
		return tree1;
	else
		return smallest(tree1->left);
}
struct node *largest(struct node *tree1)
{
	if((tree1==NULL)||(tree1->right==NULL))
		return tree1;
	else
		return largest(tree1->right);
}
struct node* deleteNode(struct node* root, int key)
{
	struct node *temp;
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
	root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
	root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
	// node with only one child or no child
	if (root->left == NULL)
	{
	    struct node *temp = root->right;
	    free(root);
	    return temp;
	}
	else if (root->right == NULL)
	{
	    struct node *temp = root->left;
	    free(root);
	    return temp;
	}

	// node with two children: Get the inorder successor (smallest
	// in the right subtree)
	temp = smallest(root->right);

	// Copy the inorder successor's content to this node
	root->data = temp->data;

	// Delete the inorder successor
	root->right = deleteNode(root->right, temp->data);
    }
    return root;
} /*
void del(struct node *tree2,int value)
{
	struct node *temp1;
	if(tree2==NULL)
		printf("Value not found in the tree\n");
	else if(value<tree2->data)
		del(tree2->left,value);
	else if(value>tree2->data)
		del(tree2->right,value);
	else if(tree2->left && tree2->right)
	{
		// if(ch==1)
		// {
			temp1=largest(tree2->left);
			tree2->data=temp1->data;
			del(tree2->left,temp1->data);
		// }
		// else
		// {
		// 	temp1=smallest(tree2->right);
		// 	tree2->data=temp1->data;
		// 	del(tree2->right,temp1->data);
		// }
	}
	else
	{
		temp1=tree2;
		if(tree2->left==NULL && tree2->right==NULL)
			tree2=NULL;
		else if(tree2->left!=NULL)
			tree2=tree2->left;
		else
			tree2=tree2->right;
	}
	free(temp1);
}*/
int totalnodes(struct node *tree1)
{
	if(tree1==NULL)
		return 0;
	else
		return(totalnodes(tree1->left)+totalnodes(tree1->right)+1);
}
int totalextnodes(struct node *tree1)
{
	if(tree1==NULL)
		return 0;
	else if((tree1->left==NULL) && (tree1->right==NULL))
		return 1;
	else
		return(totalextnodes(tree1->left)+totalextnodes(tree1->right));
}
int totalintnodes()
{
	return totalnodes(tree)-totalextnodes(tree);
}
int height(struct node *tree1)
{
	int lefth,righth;
	if(tree1==NULL)
		return -1;
	else
	{
		lefth=height(tree1->left);
		righth=height(tree1->right);
		if(lefth>righth)
			return (lefth+1);
		else
			return (righth+1);
	}
}
void deltree(struct node *tree1)
{
	if(tree1!=NULL)
	{
		deltree(tree1->left);
		deltree(tree1->right);
		free(tree1);
	}
}
void main()
{
	int a,b=0,val,out;
	struct node *temp1;
	clrscr();
	printf("WELCOME TO THE BINARY SEARCH TREE PROGRAM\n");
	while(b==0)
	{
		printf("\t------------MAIN MENU-------------\n");
		printf("1. INSERT ELEMENT IN THE BST\n2. PREORDER DISPLAY\n3. INORDER DISPLAY\n4. POSTORDER DISPLAY\n5. SMALLEST VALUE IN BST\n6. LARGEST VALUE IN BST\n7. DELETION OF A NODE IN BST\n8. TOTAL NUMBER OF NODES\n9. TOTAL NUMBER OF EXT. NODES\n10. TOTAL NUMBER OF INTERNAL NODES\n11. HEIGHT OF TREE\n12. DELETE WHOLE TREE\n13. EXIT(ENTER ANY NUMBER GREATER THAN 12)\nENTER YOUR CHOICE NUMBER FROM THE MENU ------>>>> ");
		scanf("%d",&a);
		ch=0;
		switch(a)
		{
			case 1:
			{
				insert_element();
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
				temp1=smallest(tree);
				if(temp1!=NULL)
				printf("SMALLEST NODE IS %d\n",temp1->data);
				else
					printf("NO DATA IS THEIR IN THE TREE\n");
				break;
			}
			case 6:
			{
				temp1=largest(tree);
				if(temp1!=NULL)
					printf("LARGEST NODE IS %d\n",temp1->data);
				else
					printf("NO DATA IS THEIR IN THE TREE\n");
				break;
			}
			case 7:
			{
				printf("Enter the value you want to delete\n");
				scanf("%d",&val);
				// printf("If node having the req value has both left and right child\nPlease press 1 if you want largest of left to take its place.\nOr press 2 if you want smallest of right to take its place.\n");
				// scanf("%d",&ch);
				deleteNode(tree,val);
				break;
			}
			case 8:
			{
				out=totalnodes(tree);
				printf("THERE ARE %d NODES IN THE BST\n",out);
				break;
			}
			case 9:
			{
				out=totalextnodes(tree);
				printf("THERE ARE %d EXTRENAL NODES IN THE BST\n",out);
				break;
			}
			case 10:
			{
				out=totalintnodes(tree);
				printf("THERE ARE %d INTERNAL NODES IN THE BST\n",out);
				break;
			}
			case 11:
			{
				out=height(tree);
				printf("THE HEIGHT OF TREE IS :- %d \n",out);
				break;
			}
			case 12:
			{
				deltree(tree);
				break;
			}
			default:
			b=1;
		}
		getch();
	}
	printf("\n\t\tTHANKS");
	getch();
}