#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ta-lib/ta_libc.h>

int main()
{
	TA_RetCode ta=TA_Initialize();
	int i,n;
	if(ta!=TA_SUCCESS)
	{
		perror("Initialisation"); exit(1);
	}
	float a[100]={1,2,3,4,5,6,7,8,9,10},b[100];
	ta=TA_S_MA(0,10,a,5,TA_MAType_SMA,&i,&n,b);
	for(i=0;i<10;i++)
		printf("\n%f",b[i]);
	return 0;
}
