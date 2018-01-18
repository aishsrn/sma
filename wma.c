#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
float getf(char* line, int num)
{
	int i,k=0;
	char s[100];
	for(i=0;line[i];i++)
	{
		if(line[i]==',')
			num--;
		if(num==1)
		{	i++;
			while(line[++i]!='"')
				s[k++]=line[i];
			//printf("\n%s",s);
			return atof(s);
		}
	}
	return 1;
}
int main()
{
	float sum,a[500],wm;
	int n,w,i,ch,j,nu,de;
	char line[1024];
	FILE *f=fopen("data.csv","r");
	fgets(line,1024,f);
	while(fgets(line,1024,f))
	{
		//printf("\n%s",line);
		a[i++]=getf(line,5);
				
	}
	do{
		printf("\n1. WMA\n2. Exit \n Option:");
		scanf("%d",&ch);
		if(ch==1)
		{	
			sum =0; nu=0; de=0; 
			printf("Enter window size:");
			
			scanf("%d",&w);
			de=w*(w+1)/2;
			for(j=0;j<i;j++)
			{
				printf("\nInput :%f ",a[j]);
				
				if(j<w) { nu+=(j+1)*a[j]; sum+=a[j];  }
				if(j==w-1)
				{
					wm=nu/de; 
					printf("\tWMA:%f",wm);
				}
				if(j>=w)
				{	nu=nu+w*a[j]-sum;
					sum=sum+a[j]-a[j-w];
					wm=nu/de;
					printf("\tWMA:%f",wm);
					
				}
			}					
		}
		else if(ch==2);
		else printf("\nIncorrect");
	}while(ch!=2);
	return 0;
}

