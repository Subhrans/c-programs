#include<stdio.h>
// to know the question as well as input as well as output then please check pooling matix.jpg file in this current directory (c:\TURBOC3\BIN\)

int pooling_matrix(int arr,int pool)
{
//	int maxx=0,i,j;
//	for(i=0;i<pool;i++)
//	{
//		for(j=0;j<pool;j++)
//		{
//			if(arr[i][j]>max)
//			{
//				max=arr[i][j];
//			}
//		}
//	}
//	return max;
}
int main()
{
	int a[10][10],pool_r[10][10],tempar[10][10],max;
	int i,j,k,n,pool,pool2,c,count=0,temp,temp2,x,hold_i=0,hold_j=0;
	puts("Enter a number for matrix");
	scanf("%d",&n);
	puts("Enter a number for pooling filter");
	scanf("%d",&pool);
	pool2=pool;
	for(i=0;i<n;i++)
	{
		printf("\n row %d\n",i);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
//		printf("\n row %d\n",i);
		for(j=0;j<n;j++)
		{
			printf("%2d\t",a[i][j]);
		}
		printf("\n");
	}
	
//	pooling filter aplied
	
	count=0;
	for(i=0;i<n;i++)
	{
		temp=0;
		for(j=hold_i;j<pool2;j++)
		{
			temp2=0;
			for(k=hold_j;k<pool;k++)
			{
				printf("\nhold j is %d j is %d and k is %d\n",hold_j,j,k);
				tempar[temp][temp2]=a[j][k];
				printf("tempar %d\t",a[j][k]);
				temp2++;
			}
			printf("\n");
			temp++;
		}
//		x=pooling_matrix(tempar[],pool2);
//		printf("%d\t",x);
		if(pool<=(n-k))    			// for horizontal
		{
			if(n/pool==count-1)				// problem creating here
			{
				puts("inside if 1");
				if(count==1)
				{
					pool2=pool;
				}
			}
			hold_j=k;
			puts("inside horizontal");
			if((n%2==0 && pool%2==0)||(n%2==1 && pool%2==1))
			{
				if(n>=pool)
				{
					pool+=pool2;
				}	
			}
			else if((n%2==1 && pool%2==0)||(n%2==0 && pool%2==1))
			{
				if((n/2)>=pool)
				{
					pool+=pool2;
				}
			}	
		}
		printf("\nj %d k is %d and pool is %d\n",j,k,pool);
		if(n/pool2==count)
		{
			
			pool=pool2;
			printf("\n\t after reseting j %d k is %d and pool is %d\n",j,k,pool);
			
				hold_i=j;
				hold_j=0;
				printf("control loc");
				if((n%2==0 && pool%2==0)||(n%2==1 && pool%2==1))
				{
					if(n>=pool2)
					{
						pool2+=pool;
					}	
				}
				else if((n%2==1 && pool%2==0)||(n%2==0 && pool%2==1))
				{
					if((n/2)>=pool2)
					{
						pool2+=pool;
					}
				}
		}
		count++;
		
	}

	puts("-----------------------");
	for(i=0;i<pool2;i++)
	{
		for(j=0;j<pool2;j++)
		{
			printf("%d\t",tempar[i][j]);
		}
		printf("\n");
	}
//	temp=0;
//	hold_i=0;
//	hold_j=0;
//	for(k=0;k<n;k++)
//	{
//		max=0;
//		c=0;
//		printf("\nk is now %d\n",k);
//		for(i=hold_i;i<pool;i++)
//		{
//			
//	//		printf("\n row %d\n",i);
//			printf(" i is %d",i);
//			for(j=hold_j;j<pool;j++)
//			{
//				printf(" \nj is %d\n",j);
//				if(max<a[i][j])
//				{
//					max=a[i][j];
//				}
//			}
//			
//			if(temp<max)
//			{
//				temp=max;
//			}
//		}
//		pool_r[k][c]=temp;
//		c++;
//		hold_i=i;
//		hold_j=j;
//		if((n%2==0 && pool%2==0)||(n%2==1 && pool%2==1))
//		{
//			if(n>=pool)
//			{
//				pool+=pool2;
//			}	
//		}
//		else if((n%2==1 && pool%2==0)||(n%2==0 && pool%2==1))
//		{
//			if((n/2)>=pool)
//			{
//				pool+=pool2;
//			}
//		}
//		
//		
//	}
//	for(i=0;i<n;i++)
//		{
//			for(j=0;j<n;j++)
//			{
//				printf("%2d\t",pool_r[i][j]);
//			}
//			printf("\n");
//		}
	
printf(" c is %d",c);
//	for(i=0;i<c;i++)
//		{
//	//		printf("\n row %d\n",i);
//			for(j=0;j<c;j++)
//			{
//				printf("%2d\t",pool_r[i][j]);
//			}
//			printf("\n");
//		}
	return 0;
}
