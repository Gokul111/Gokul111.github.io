//PROGRAM TO PERFORM BASIC OPERATIONS ON A BINARY SEARCH TREE
 
#include<stdio.h>
 
#include<conio.h>
 
struct tree
 
{
 
          struct tree *left;
 
          int info;
 
          struct tree *right;
 
};
 
void insert(struct tree **ptr,int item)
 
{
 
          if(*ptr==NULL)
 
          {
 
                   *ptr=(struct tree *)malloc(sizeof(struct tree));
 
                   (*ptr)->left=(*ptr)->right=NULL;
 
                   (*ptr)->info=item;
 
                   return;
 
          }
 
          else
 
          {
 
                   if(item<(*ptr)->info)
 
                   {
 
                             insert(&((*ptr)->left),item);
 
                   }
 
                   else
 
                   {
 
                             insert(&((*ptr)->right),item);
 
                   }
 
                   return;
 
          }
 
}
 
void delete_tree(struct tree **ptr,int item)
 
{
 
          struct tree *move,*back,*temp;
 
          if(*ptr==NULL)
 
          {
 
                   printf("nEmpty tree..............n");
 
                   return;
 
          }
 
          else
 
          {
 
                   move=*ptr;
 
                   back=move;
 
                   while(move->info!=item)
 
                   {
 
                             back=move;
 
                             if(item<move->info)
 
                             {
 
                                      move=move->left;
 
                             }
 
                             else
 
                             {
 
                                      move=move->right;
 
                             }
 
                   }
 
                   if(move->left!=NULL&&move->right!=NULL)
 
                   {
 
                             temp=move->right;
 
                             while(temp->left!=NULL)
 
                             {
 
                                      back=temp;
 
                                      temp=temp->left;
 
                             }
 
                             move->info=temp->info;
 
                             move=temp;
 
                   }
 
                   if(move->left==NULL&&move->right==NULL)
 
                   {
 
                             if(back->right==move)
 
                             {
 
                                      back->right=NULL;
 
                             }
 
                             else
 
                             {
 
                                      back->left=NULL;
 
                             }
 
                             free(move);
 
                             return;
 
                   }
 
                   if(move->left==NULL&&move->right!=NULL)
 
                   {
 
                             if(back->left==move)
 
                             {
 
                                      back->left=move->right;
 
                             }
 
                             else
 
                             {
 
                                      back->right=move->right;
 
                             }
 
                             free(move);
 
                             return;
 
                   }
 
                   if(move->left!=NULL&&move->right==NULL)
 
                   {
 
                             if(back->left==move)
 
                             {
 
                                      back->left=move->left;
 
                             }
 
                             else
 
                             {
 
                                      back->right=move->left;
 
                             }
 
                             free(move);
 
                             return;
 
                   }
 
          }
 
}
 
void preorder(struct tree *ptr)
 
{
 
          struct tree *move;
 
          move=ptr;
 
	  if(move!="")
 
          {
 
                   printf(" %d ",move->info);
 
                   preorder(move->left);
 
                   preorder(move->right);
 
          }
 
          else
 
                   return;
 
}
 
void inorder(struct tree *ptr)
 
{
 
          struct tree *move;
 
          move=ptr;
 
	  if(move!="")
 
          {
 
                   inorder(move->left);
 
                   printf(" %d ",move->info);
 
                   inorder(move->right);
 
          }
 
          else
 
          return;
 
}
 
void postorder(struct tree *ptr)
 
{
 
          struct tree *move;
 
          move=ptr;
 
	  if(move!="")
 
          {
 
                   postorder(move->left);
 
                   postorder(move->right);
 
                   printf(" %d ",move->info);
 
          }
 
          else
 
                   return;
 
}
 
void main()
 
{

	  struct tree *root="";
 
	  int item,ch,order;
 
          char choice,ch1;
 
          clrscr();
 
          do
 
          {
 
                   printf("n____________Tree MENU_______________nn");
 
                   printf("1.Insert.n");
 
                   printf("2.Delete.n");
 
                   printf("3.Traversal.n");
 
                   printf("4.Exit.n");
 
                   printf("nEnter your choice   :         ");
 
                   scanf("%d",&ch);
 
                   switch(ch)
 
                    {
 
                             case 1: printf("nEnter the element to be inserted   :         ");
 
                                      scanf("%d",&item);
 
                                      insert(&root,item);
 
                                      break;
 
                             case 2: printf("nEnter the element to be deleted    :         ");
 
                                      scanf("%d",&item);
 
                                      delete_tree(&root,item);
 
                                      break;
 
                             case 3: printf("nna.Preorder.n");
 
                                      printf("b.inorder.n");
 
                                      printf("c.Postorder.n");
 
                                      printf("nEnter your choice   :         ");
 
                                      ch1=getche();
 
                                      printf("nnTree  :  ");
 
                                      switch(ch1)
 
                                      {
 
                                                case 'a': preorder(root);
 
                                                            break;
 
                                                case 'b': inorder(root);
 
                                                            break;
 
                                                case 'c': postorder(root);
 
                                                            break;
 
                                      }
 
                                      break;
 
                             default: exit(0);
 
                   }
 
                   fflush(stdin);
 
          }while(ch!=4);
 
}