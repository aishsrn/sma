#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float sum,a[500],sm;
	int n,w,i,ch;
	do{
		printf("\n1. SMA\n2. Exit \n Option:");
		scanf("%d",&ch);
		if(ch==1)
		{	
			sum =0;
			printf("Enter number of inputs and window size:");
			scanf("%d",&n);
			scanf("%d",&w);
			printf("Enter data:\n");
			for(i=0;i<n;i++)
			{
				printf("Input %d: ",i+1);
				scanf("%f",&a[i]);
				if(i<w) { sum+=a[i]; sm=sum/w; }
				if(i==w-1) printf("SMA:%f\n",sm);
				if(i>=w)
				{	sm=sm+(a[i]-a[i-w])/w;
					printf("SMA:%f\n",sm);
					
				}
			}					
		}
		else if(ch==2);
		else printf("\nIncorrect");
	}while(ch!=2);
	return 0;
}
