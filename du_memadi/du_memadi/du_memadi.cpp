#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 4
void create_ar(int ar[][N])
{
	int k,i;
		for(k=0;k<N;k++)
		{
			for(i=0;i<N;i++)
			{
			ar[k][i]=rand()%50;
			}
		}
}
void print_ar(int ar[][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
	       printf("%3d ",ar[i][j]);
	    }
		printf("\n");
	}
    printf("\n");
}
void max_num(int ar[][N])
{
	int i,j,big;
	big=ar[0][0];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(ar[i][j]>big)
				big=ar[i][j];
		}
	}
	printf("max number is:%d\n",big);
}
void sum_2(int ar[][N])
{
	int i,count_r=0,count_m=0;
	/*
	        N-1=3
	  0 1 2 3 
	0 r     m
	1   r m
	2   m r
	3 m     r
	*/
	for(i=0;i<N;i++){
		count_m+=ar[i][(N-1)-i];
		count_r+=ar[i][i];
	}

	printf("total of main diagonal is:%d\n",count_r);
	printf("total of other diagonal is:%d\n",count_m);
}
int sum_row(int ar[])
{
	int i,sum=0;
	for(i=0;i<N;i++)
	{
		sum+=ar[i];
	}
	return sum;
}
int sum_cols(int ar[][N],int cols)
{
	int i,sum=0;
	for(i=0;i<N;i++)
	{
		sum+=ar[i][cols];
	}
	return sum;
}
int *func1(int ar[][N],int *ptr)//�������� ������ ����� ������ ���� ������ �������� ���� ��-���� 
	//������ ����� �� ����� ���� ��� ����
{
	int *h,k,j;//������ ��� ���� ���� ����� ���� ��� ���� , 
	//����� ����� ��� ����� �� ����� ��� ����, ���' ����� ��� ����� �� ����� ��� ����
	h=(int*)calloc(N*2,sizeof(int));//���� ���� ������ ����� ����� ����
	//h=(int *)malloc(N*2*size(int));
	if(h==NULL)//��� ����� �� ���� �� ������� ���� ���� ����� �����
	{
		*ptr=0;
		return NULL;
	}
	for(k=j=0;k<N;k++)
	{
		if(ar[k][k]%2==0)
			h[j++]=ar[k][k];
		if(ar[k][N-1-k]%2==0)
			h[j++]=ar[k][N-1-k];
	}
	*ptr=j;
	return h;
}

int func2(int ar[][N],int **new_ptr)
{//��������� ����� �������� ���� �� ���� ��� ����� �� ����� ������ ���� 
	//������  ���� ������ �� ���� ����� ����� ������� ���� ������
	//������ ������� �� ���� ������ �������// ���� �������� ��� ��� ����� �������� ����
	//�� ���� ��� ����� �� ����� ������ ���� �������� ����� ���� ������ �� ���� ����� ������,
	// ������ ���� ������ ������ ���� ��������� ������� �� ���� �������

	int *h,k,j=0;
	for(k=0;k<N;k++)
	{
		if(ar[k][k]%2==0)
			j++;
		if(ar[k][N-1-k]%2==0)
			j++;
	}
	if(j==0)
	{
		*new_ptr=NULL;
	    return 0;
	}
	h=(int*)malloc(j*sizeof(int));
	if(h==NULL)
	{
		*new_ptr=NULL;
		return 0;
	}
	for(k=j=0;k<N;k++)
	{
		if(ar[k][k]%2==0)
			h[j++]=ar[k][k];
		if(ar[k][N-1-k]%2==0)
			h[j++]=ar[k][N-1-k];
	}
	*new_ptr=h;
	return j;
}

int *func3(int ar[][N],int *num)
{ // �������� ��� ����� �������� ���� �� ���� ��� ����� �� ���� ��� �������� ����� ���� ������ 
	//�� ���� ����� ������, ������ ���� ������ ������ ���� ������� �� ����� �����. 
	// ��� ����� ���� �������� ������� ���� ������� ��������
	int *h,k,j=0,i;
		for(k=0;k<N;k++)
		   for(i=0;i<N;i++)
		     if(ar[k][i]%2==0)
			    j++;
	if(j==0)
	{
		*num=0;
	    return NULL;
	}
	h=(int*)malloc(j*sizeof(int));
	if(h==NULL)
	{
		*num=0;
		return NULL;
	}
	for(k=j=0;k<N;k++)
	{
		for(i=0;i<N;i++)
		{
		    if(ar[k][i]%2==0)
			   h[j++]=ar[k][i];
		}
	}
	*num=j;
	return h;
}

int func4(int ar[][N],int **new_new_ptr)
{//��������� ����� �������� ���� �� ���� ��� ����� �� ����� ������ ���� ������  ���� �������� 
	//���� ����� ����� ������� ���� ������ ������ ������� �� ���� ������ �������
	int *h,k,j=0,i;
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
		if(ar[k][i]%2==0)
			j++;
	//��� ����� ���� �������� ������ ����� ����� (�� ������)�
	if(j==0)
	{
		*new_new_ptr=NULL;
	    return 0;
	}

	h=(int*)malloc(j*sizeof(int));
	if(h==NULL)
	{
		*new_new_ptr=NULL;
		return 0;
	}
	for(k=j=0;k<N;k++)
		for(i=0;i<N;i++)
		if(ar[k][i]%2==0)
			h[j++]=ar[k][i];
	*new_new_ptr=h;
	return j;
}
void main()
{
	int arr[N][N],i,*p,len,k;
	srand((unsigned)time(NULL));
	create_ar(arr);
	print_ar(arr);
	max_num(arr);
	sum_2(arr);
	for(i=0;i<N;i++)
	{
	printf("row:%d,sum=%d\n",i,sum_row(arr[i]));
	printf("col:%d,sum=%d\n",i,sum_cols(arr,i));
	}
	p=func1(arr,&len);
	if(p)
		for(k=0;k<len;k++)
			printf("%d ",p[k]);
		printf("\n");
		len=func2(arr,&p);
	if(p)
		for(k=0;k<len;k++)
		{
			printf("%d ",p[k]);
		}
		printf("\n");
		p=func3(arr,&len);
	if(p)
		for(k=0;k<len;k++)
			printf("%d ",p[k]);
		printf("\n");
	    len=func4(arr,&p);
	if(p)
		for(k=0;k<len;k++)
			printf("%d ",p[k]);
		printf("\n");
	system("pause");
}

//FUNC1
//���� �������� ��� ����� �������� ���� �� ���� ��� ����� �� ���� ���� �������� ����� 
//���� ������ �� ���� ����� ������� �����, ������ ���� ������ ������ ���� ��������� ������� �� ������. 
// ��� ����� ���� ������� ������ ���� ������� �������� . 
//���� ���� ������ ��������� ���� �����
//