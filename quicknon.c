#include<conio.h>
#include<stdio.h>
 void main()
 {
 int i,j,temp,beg,end,mid,item;
 int arr[]={34,67,23,1,89,2,36,12,20,61};
 clrscr();
 /*printf("Enter value:\n");
 for(i=0;i<=9;i++)
 {
  scanf("%d",&arr[i]);
 } */
 for(i=0;i<=9;i++)
 {
  for(j=i+1;j<=9;j++)
  {
   if(arr[i]>arr[j])
   {
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
  }
 }
 for(i=0;i<=9;i++)
 {
  printf("\n%d",arr[i]);
 }
 printf("Enter the number to find:");
 scanf("%d",&item);
 beg=0;
 end=9;
 mid=(int)(end+beg)/2;
 while(item!=arr[mid] && beg<=end)
 {
  if(item>arr[mid])
  {
   beg=mid+1;
  }
  else
  {
   end=mid-1;
  }
  mid=(int)(end+beg)/2;
 }
 if(beg<=end)
 {
  printf("\nPosition is %d",mid+1);
 }
 else
  printf("\nPosition may be become %d",mid+1);
 getch();
 }