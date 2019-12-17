/*#include<stdio.h>
int count = 0;

int notDanger(int row, int j, int *(*chess)[8])
{
	int i,flag1=0;
	for (i = 0; i < 8; i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}
	for(i=row,k=j;i>=0&&k>=0;i--,k--)

}
EightQueen(int row,int col,int (*chess)[8])
{
	int chess2[8][8],i,j;
	for (i = 0 ; i < 8; i++)
		for (j = 0; j < 8; j++)
			chess2[i][j] = chess[i][j];
	if (8 == row)
	{
		printf("µÚ%dÖÖ£º ");
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d ", *(*(chess2 + i) + j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{
		for (j = 0; j < col; j++)
		{
			if (notDanger(row,j,chess))
			{
				for (i = 0; i < 8; i++)
				{
					*((*chess + row) + i) = 0;
				}
				*(*(chess2 + row) + j) = 1;
				EightQueen(row+1,col,)
			}
		}
	}
}

int main(void)
{
	int chess[8][8] = {0}, i, j;

	EightQueen();
}*/