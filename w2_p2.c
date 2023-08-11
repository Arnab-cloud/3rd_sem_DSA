#include <stdio.h>

void print_matrix(int row, int col, int mat[][col])
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}

void print_sparse(int mat[][3])
{
	for(int i=0; i<=mat[0][2]; i++)
	{
		for(int j=0; j<3; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int count_non_zero_element(int row, int col, int mat[][col])
{
	int count=0;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(mat[i][j])
				count++;
	return count;
}

void spersiFY(int row, int col, int mat[][col], int size, int sparse[][3])
{
	int k=1;
	sparse[0][0] = row;
	sparse[0][1] = col;
	sparse[0][2] = size;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			if(mat[i][j])
			{
				sparse[k][0] = i;
				sparse[k][1] = j;
				sparse[k++][2] = mat[i][j];
			}
	printf("%d %d %d\n", sparse[sparse[0][2]][0], sparse[sparse[0][2]][1], sparse[sparse[0][2]][2]);
}

void diagonal_using_sparse(int sparse[][3], int diag[][3])
{
	int i,j = 0,k, size = sparse[0][2];
	
	for(i=0; i<3; i++)
		diag[0][i] = sparse[0][i];
		
	for(k=1,i=1; k<=size i++)
	{	
			if(i == sparse[0][2])
			{
				i=1;
				j++;
			}
			if(j == sparse[i][1])
			{
				diag[k][0] = sparse[i][1];
				diag[k][1] = sparse[i][0];
				diag[k++][2] = sparse[i][2];
			}
	}
}

void input_matrix(int row, int col, int mat[][col])
{
	printf("Enter the matrix: \n");
	for(int i=0; i<row; i++)
	{
		printf("row %d: ", i+1);
		for(int j=0; j< col; j++)
			scanf("%d", &mat[i][j]);
	}
}

int main()
{
	int row, col;
	printf("Enter the row and column of the matrix: ");
	scanf("%d%d", &row, &col);
	int mat[row][col];
	input_matrix(row,col,mat);
	printf("The matrix is: \n");
	print_matrix(row,col,mat);
	
	int size = count_non_zero_element(row,col,mat), sparse[size+1][3], diag[size+1][3];
	printf("%d", size);
	spersiFY(row,col,mat,size,sparse);
	printf("%d %d %d", sparse[sparse[0][2]][0], sparse[sparse[0][2]][1], sparse[sparse[0][2]][2]);
	printf("The sparse represntation is: \n");
	print_sparse(sparse);
	printf("ok");
	
	diagonal_using_sparse(sparse,diag);
	printf("The diagonal sparse represtation is: \n");
	print_matrix(size+1,3,diag);
	
	return 0;
}
