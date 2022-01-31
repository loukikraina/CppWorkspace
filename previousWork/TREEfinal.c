#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
   struct node *left;
   int data;
   struct node *right;
  };

struct node *insert(struct node *tree ,int val){
   struct node *ptr,*nodeptr,*parentptr;

   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=val;
   ptr->left=NULL;
   ptr->right=NULL;
   if(tree==NULL)
   {  tree=ptr;
      tree->left=NULL;
      tree->right=NULL;}
   else
   {  parentptr=NULL;
      nodeptr=tree;
      while(nodeptr!=NULL)
       { parentptr=nodeptr;
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
   return tree;
 }

void preorder(struct node *tree)
{

 if(tree!=NULL)
   {printf("%d\t",tree->data);
    preorder(tree->left);
    preorder(tree->right);
   }

}

void inorder(struct node *tree)
{
 if(tree!=NULL)
   {inorder(tree->left);
    printf("%d\t",tree->data);
    inorder(tree->right);
   }

}

void postorder(struct node *tree)
{
 if(tree!=NULL)
   {postorder(tree->left);
    postorder(tree->right);
    printf("%d\t",tree->data);
    }

}

struct node *smallest(struct node *tree)
{
if((tree==NULL)||(tree->left==NULL))
      {printf("\nsmallest: %d",tree->data);
      return tree;}
 else
      return smallest(tree->left);
}

struct node *largest(struct node *tree)
{
if((tree==NULL)||(tree->right==NULL))
     { printf("\nlargest: %d",tree->data);
      return tree; }
 else
      return largest(tree->right);
}

struct node *del(struct node *tree,int val){
 if(tree==NULL)
     printf("\nvalue not found");
 else if(val<(tree->data))
     tree->left=del((tree->left),val);
 else if(val>(tree->data))
    tree->right=del((tree->right),val);
 else if((tree->left)!=NULL&&(tree->right)!=NULL){
     struct node *temp=largest(tree->left);
     tree->data=temp->data;
     tree->left=del((tree->left),(temp->data));}
 else{
     struct node *temp=tree;
     if((tree->left)==NULL && (tree->right)==NULL)
	tree=NULL;
     else if((tree->left)!=NULL)
	tree=tree->left;
     else if((tree->right)!=NULL)
	tree=tree->right;
     printf("deleted");
     free(temp);
     }
 return tree;
}

int total(struct node *tree)
{if(tree==NULL)
   return 0;
 else
   return(total(tree->left)+total(tree->right)+1);
}

int totalint(struct node *tree)
{if((tree==NULL)||((tree->left==NULL)&&(tree->right==NULL)))
    return 0;
 else
   return(totalint(tree->left)+totalint(tree->right)+1);
}

int totalext(struct node *tree)
{if(tree==NULL)
    return 0;
 else if((tree->left==NULL)&&(tree->right==NULL))
    return 1;
 else
    return(totalext(tree->left)+totalext(tree->right));
}

int height(struct node *tree)
{int leftheight,rightheight;
 if(tree==NULL)
     return -1;
 leftheight=height(tree->left);
 rightheight=height(tree->right);
 if(leftheight>rightheight)
     return (leftheight+1);
 else
     return (rightheight+1);
}

struct node *delall(struct node *tree)
{
if(tree!=NULL){
tree->left=delall(tree->left);
tree->right=delall(tree->right);
free(tree);
}
else return;}

void main(){
int opt=0,val;
struct node *tree;
clrscr();
tree=NULL;
while(opt<13){
printf("\n\n1.insert  2.preorder  3.inorder  4.postorder  5.smallest number 6.largest number7.delete  8.count total nodes   9.count internal nodes   10.count external nodes11.height of tree  12.delete tree   13.exit\nenter option: ");
scanf("%d",&opt);
printf("\n");

switch(opt){
case 1:printf("enter value to be inserted: ");
       scanf("%d",&val);
       tree=insert(tree,val);
       break;
case 2:preorder(tree);
       break;
case 3:inorder(tree);
       break;
case 4:postorder(tree);
       break;
case 5:val=smallest(tree);
       break;
case 6:val=largest(tree);
       break;
case 7:printf("enter value to be deleted: ");
       scanf("%d",&val);
       val=del(tree,val);
       break;
case 8:val=total(tree);
       printf("total nodes: %d",val);
       break;
case 9:val=totalint(tree);
       printf("total internal nodes: %d",val);
       break;
case 10:val=totalext(tree);
       printf("total external nodes: %d",val);
       break;
case 11:val=height(tree);
       printf("height of tree: %d",val);
       break;
case 12:val=delall(tree);
       printf("deleted");
       tree=NULL;
       break;
default:printf("exiting..");}}
getch();
}