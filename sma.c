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
	int n,w,i,ch;
	char line[1024];
	do{
		printf("\n1. SMA\n2. Exit \n Option:");
		scanf("%d",&ch);
		if(ch==1)
		{	
			sum =0;i=0;
			printf("Enter number of inputs and window size:");
			scanf("%d",&n);
			scanf("%d",&w);
			FILE *f=fopen("data.csv","r");
			fgets(line,1024,f);
			while(fgets(line,1024,f))
			{
				//printf("\n%s",line);
				a[i++]=getf(line,5);
				
			}
			for(i=0;i<n;i++)
			{
				printf("\nInput :%f ",a[i]);
				
				if(i<w) { sum+=a[i]; sm=sum/w; }
				if(i==w-1) printf("\tSMA:%f",sm);
				if(i>=w)
				{	sm=sm+(a[i]-a[i-w])/w;
					printf("\tSMA:%f",sm);
					
				}
			}					
		}
		else if(ch==2);
		else printf("\nIncorrect");
	}while(ch!=2);
	return 0;
}
