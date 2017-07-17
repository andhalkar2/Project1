#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int mat1[10][10],mat2[10][10],result[10][10],i,j,k,l,m,r1,c1,r2,c2,res,sum;
void *thread_Matrix_Multiply(void*);
void main()
{	
	pthread_t tid;
	printf("\nEnter number of row and column of first matrix::");
	scanf("%d%d",&r1,&c1);
	printf("\nEnter number of row and column of second matrix::");
	scanf("%d%d",&r2,&c2);

	printf("\nEnter the element of first matrix\n");
	for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
				{
					scanf("%d",&mat1[i][j]);
				}
		}

	printf("\nEnter the element of second matrix\n");
	for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
				{
					scanf("%d",&mat2[i][j]);
				}
		}

	printf("\n\nMatrix 1 is::\n");
	for(i=0;i<r1;i++)
		{
			printf("\n");
			for(j=0;j<c1;j++)
				{
					printf("%d\t",mat1[i][j]);
				}
		}
			
	printf("\n\nMatrix 2 is::\n");
	for(i=0;i<r2;i++)
		{
			printf("\n");
			for(j=0;j<c2;j++)
				{
					printf("%d\t",mat2[i][j]);
				}
		}
		
	if(c1==r2)	
	{
		for (i=0;i<c1;i++) 
		{
     			for (j=0;j<r2;j++) 
			{
         			sum=0;
				pthread_create(&tid,NULL,thread_Matrix_Multiply,NULL);
		         }
		}
				
		pthread_join(tid,NULL);
		printf("\nResultant matrix after multiplication::\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d\t",result[i][j]);
			}
			printf("\n");
		}
	}	
	else
	{
		printf("\nMultiplication cannot be done (please enter proper no. of rows and columns).");	
	}
}

void *thread_Matrix_Multiply(void*para)
{
	for(k=0;k<r1;k++)
	{
		for(l=0;l<c2;l++)
		{	
			res=0;
			for(m=0;m<r2;m++)
			{
				res=res+mat1[k][m]*mat2[m][l];
			}
			result[k][l]=res;
		}
	}
	pthread_exit(NULL);
}


