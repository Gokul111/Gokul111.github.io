#include<stdio.h>
int main()
{
	int n,a[50],i,j,k,c=0,low=0;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);	
	}
	for (i = 0; i < n; i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]%a[j]==0)
			{	
				if(c<a[j])
					c=a[j];
				continue;
			}
			else if(a[j]%a[i]==0)
			{
				if(c<a[i])
					c=a[i];
				continue;
			}
			if(a[i]<a[j])
				low=a[i];
			else
				low=a[j];
			for(k=1;k<low;k++)
			{
				if(a[i]%k==0 && a[j]%k==0)
				{
					if(c<k)
						c=k;
				}
			}
		}	
	}
	printf("%d",c);
	return 0;
}