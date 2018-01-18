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
	float sum,a[500],em,mu;
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
		printf("\n1. EMA\n2. Exit \n Option:");
		scanf("%d",&ch);
		if(ch==1)
		{	
			sum =0; mu=0; 
			printf("Enter window size:");
			
			scanf("%d",&w);
			mu=(2.0/(w+1));
			for(j=0;j<i;j++)
			{
				printf("\nInput :%f ",a[j]);
				
				if(j<w) { sum+=a[j];  }
				if(j==w-1)
				{
					
					em=sum/w;
					printf("\tEMA:%f",em);
				}
				if(j>=w)
				{	
					em+=(a[j]-em)*mu;
					printf("\tEMA:%f",em);
					
				}
			}					
		}
		else if(ch==2);
		else printf("\nIncorrect");
	}while(ch!=2);
	return 0;
}

