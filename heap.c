#include<stdio.h>
#include<conio.h>
void manage(int *, int);
void heapsort(int *, int, int);
int main()
{
 int arr[20]; 
 int i,j,size,tmp,k;clrscr();
 printf("\n\t------- Heap sorting method -------\n\n");
 printf("Enter the number of elements to sort : ");
 scanf("%d",&size);
 for(i=1; i<=size; i++)
 {
   printf("Enter %d element : ",i);
   scanf("%d",&arr[i]);
   manage(arr,i);
 }
 j=size;
 for(i=1; i<=j; i++)
 {
   tmp=arr[1];
   arr[1]=arr[size];
   arr[size]=tmp;
   size--;
   heapsort(arr,1,size);
 }
 printf("\n\t------- Heap sorted elements -------\n\n");
 size=j;
 for(i=1; i<=size; i++)
     printf("%d ",arr[i]);
 getch();
 return 0;
}


void manage(int *arr, int i)
{
 int tmp; 
 tmp=arr[i];
 while((i>1)&&(arr[i/2]<tmp))
 {
   arr[i]=arr[i/2];
   i=i/2;
 }
 arr[i]=tmp;
}


void heapsort(int *arr, int i, int size)
{
 int tmp,j;
 tmp=arr[i];
 j=i*2;
 while(j<=size)
 {
   if((j<size)&&(arr[j]<arr[j+1]))
      j++;
   if(arr[j]<arr[j/2]) 
      break;
   arr[j/2]=arr[j];
   j=j*2;
 }
 arr[j/2]=tmp;
}