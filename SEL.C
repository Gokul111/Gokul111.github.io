 #include<stdio.h>
 #include<conio.h>
 void main()
 {int a[20],n,i,j,temp,f=0;
 clrscr();
 printf("enter limit:");
 scanf("%d",&n);
 printf("enter array elmts:\n");
 for(i=0;i<n;i++)
   { scanf("%d",&a[i]);}
    for(i=0;i<n;i++)
     { temp=a[i];
       for(j=i-1;j>=0;j--)
       if(a[j]<temp)

	{ a[j+1]=a[j];
	 f=1;
	}
       else if(f==1)
	 { break; }
     }
     if(f==1)
      {
      a[j+1]=temp;
      }
   }
   printf("sorted array is:\n");
   for(i=0;i<n;i++)
   {printf("%d",a[i]);}
   getch();
 }