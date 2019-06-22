#include<stdio.h>
int main()
{
	int a[3],s1=0,s2=0,cnt1=0,cnt2=0,i,r1=0,r2=0;
	char id;
	while(1)
	{
		scanf("%c",&id);
		if(id=='#')
			break;
		for (i = 0; i < 3; i++)
		{
			scanf("%d",&a[i]);
		}
		if (id=='A' || id=='C')
		{
			cnt1+=a[0];
			s1=(s1+a[0]-a[1]+(5*a[2]));
			cnt2+=a[1];
			if(a[2]==1)
			{
				r1=a[2];
			}
			if(cnt1==9 || cnt2==9)
				{break;}
		}
		else if(id=='B' || id=='D')
		{
			cnt2+=a[1];
			s2=(s2+a[1]-a[0]+(5*a[2]));
			cnt1+=a[0];
			if(a[2]==1)
			{
				r2=a[2];
			}
			if(cnt2==9 || cnt1==9)
				{break;}
		}
		
	}
	if(cnt1==9 && r1==1)
		printf("Team-1 win and the score is %d",s1);
	else if(cnt2==9 && r2==1)
		printf("Team-2 win and the score is %d",s2);
	else
		printf("Incomplete Game");

	return 0;
}
