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
	float sum,a[500],sm;
	int n,w,i,ch,j;
	char line[1024];
	FILE *f=fopen("data.csv","r");
	fgets(line,1024,f);
	while(fgets(line,1024,f))
	{
		//printf("\n%s",line);
		a[i++]=getf(line,5);
				
	}
	do{
		printf("\n1. SMA\n2. Exit \n Option:");
		scanf("%d",&ch);
		if(ch==1)
		{	
			sum =0;
			printf("Enter window size:");
			
			scanf("%d",&w);
			
			for(j=0;j<i;j++)
			{
				printf("\nInput :%f ",a[j]);
				
				if(j<w) { sum+=a[j]; sm=sum/w; }
				if(j==w-1) printf("\tSMA:%f",sm);
				if(j>=w)
				{	sm=sm+(a[j]-a[j-w])/w;
					printf("\tSMA:%f",sm);
					
				}
			}					
		}
		else if(ch==2);
		else printf("\nIncorrect");
	}while(ch!=2);
	return 0;
}
