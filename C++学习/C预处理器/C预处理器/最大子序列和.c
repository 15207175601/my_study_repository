#include <stdio.h>

int MaxSubsqequenceSum1(int A[], int N)
{
	int i, j, k, temp1,result;
	temp1 =result= A[0];
	for (i = 1; i < N; i++)
	{
		int temp2 = A[i-1];
		for (j = i; j < N; j++)
		{
			temp2 += A[j];
			if (temp1 < temp2)
				temp1 = temp2;
		}
		if (result < temp1)
			result = temp1;
	}
	return result;
}

int MaxSubsqequenceSum2(int A[], int N)
{
	int i, j, k, left,right,middle1,middle2,temp, result;
	middle1 = middle2 = 0;
	for (i = 0; i < N/2; i++)
	{
		left = A[N/2-1];
		int temp1=0,middle1= A[N/2];
		for (j = N/2-1; j >=i; j--)
		{
			temp1 += A[j];
			if (left < temp1)
				left = temp1;
		}
		if (i == N / 2-1)
			middle1 = left;
	}
	for (i = N/2; i < N; i++)
	{
		right = A[i];
		int temp1 =0,middle2= A[i];
		for (j = i; j < N; j++)
		{
			temp1 += A[j];
			if (right < temp1)
				right = temp1;
		}
		if (j == N / 2)
			middle2 = right;
	}

	temp = right > left ? right : left;
	result = temp > (middle1 + middle2) ? temp : (middle1 + middle2);
	return result;
}