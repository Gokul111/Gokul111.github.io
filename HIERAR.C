#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct tree_element{
char name[20];
int x,y,ftype, hr,rx,nc,level;
struct tree_element *link[5];
};
typedef struct tree_element node;
void main()
{
  int gd=DETECT, gm;
  node *root; root=NULL;
  clrscr();
  create(&root,0,"root",0,639,320);
  clrscr();
  initgraph(&gd,&gm,"d:\\tc\\BGI");
  display(root);
  getch();
  closegraph();}
  create(node **root, int lev, char *dname, int lx, int rx, int x)
  {
     int i, gap;
     if(*root==NULL){
     (*root)=(node*)malloc(sizeof(node));
     printf("enter name of directory/file (under%):",dname);
     fflush(stdin);
     gets((*root)->name);
     printf("Enter 1 for dir/ 2 for file");
     scanf("%d",&(*root)->ftype);
     (*root)->level=lev;
     (*root)->y=50+lev*50;
     (*root)->x=x;
     (*root)->hr=lx;
     (*root)->rx=rx;
     for(i=0;i<5;i++)
     {
       (*root)->link[i]=NULL;}
       if((*root)->ftype==1){
	  printf("\nNumber of subdirectories file for %s", (*root)->name);
	  scanf("%d",&(*root)->nc);
	  if((*root)->nc==0)
	  { gap=rx-lx;}
	  else
	     gap=(rx-lx)/(*root)->nc;
	  for(i=0;i<(*root)->nc;i++)
	  create(&((*root)->link[i]),lev+1,(*root)->name,lx+gap*i,lx+gap*i+gap,lx+gap*i+gap/2);
	  }
	  else
	  (*root)->nc=0;}


	  return 0;}
	  display(node *root){

	  int i;
	  settextstyle(2,0,4);
	  settextjustify(1,1);
	  setfillstyle(1,BLUE);
	  setcolor(14);
	  if(root!=NULL)
	  {
	    for(i=0;i<root->nc;i++)
	    { line(root->x,root->y,root->link[i]->x,root->link[i]->y);
	    }
	    if(root->ftype==1)
	    bar3d(root->x-20,root->x-10,root->x+20,root->y+10,0,0);
	    else
	      fillellipse(root->x,root->y,20,20);
	      outtextxy(root->x,root->y,root->name);
	      for(i=0;i<root->nc;i++)
	      {display(root->link[i]);
	      }
	      }
	      return 0;}
