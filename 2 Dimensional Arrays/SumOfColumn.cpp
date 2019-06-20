#include<iostream>
using namespace std;
int main()
{
	int r,c,i,j,sum;
	cout<<"Code to find the sum of each column of the matrix\n\n";
	cout<<"Number of rows: ";
	cin>>r;
	cout<<"Number of columns: ";
	cin>>c;
	int mat[r][c];
	printf("Enter %d values for matrix to be filled row wise from top\n",r*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>mat[i][j];
		}
	}
	for(i=0;i<c;i++)
	{
		sum=0;
		for(j=0;j<r;j++)
		{
			sum+=mat[j][i]; //index according to the for loop!
		}
		printf("Sum of the %d column of the matrix = %d\n",i+1,sum);
	}
}
